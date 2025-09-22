import logging
import ssl
import time
import pymodbus
from pymodbus.client import ModbusTlsClient

SERVER_HOST = "192.168.1.179"
SERVER_PORT = 802

SERVER_HOSTNAME = "secure-modbus-demo"
CERT_DIR = "./certs/"
SERVER_CA_PATH = CERT_DIR + "ca_cert.pem"

def print_menu():
    print("\n" + "="*60)
    print("        Secure Modbus/TLS Interactive Test Client")
    print("="*60)
    print("1. Read Coil Status (FC01, address: start from 0)")
    print("2. Read Holding Registers (FC03, address: as is, e.g., 40000, 40001, 0...)")
    print("3. Write Single Coil (FC05, address: start from 0)")
    print("4. Write Single Register (FC06, address: as is, e.g., 40000...)")
    print("5. Write Multiple Registers (FC16, address: as is, e.g., 40000...)")
    print("99. Exit")
    print("-"*60)

def get_user_input(prompt, type_cast=int):
    while True:
        try:
            return type_cast(input(prompt))
        except ValueError:
            print("Invalid input. Please enter a number.")
        except Exception as e:
            print(f"Error occurred: {e}")
            return None

def test_read_coils(client):
    print("\n--- [Read Coil Status] ---")
    address = get_user_input("Enter starting coil address (e.g., 0): ")
    count = get_user_input("Enter number of coils to read: ")
    if address is None or count is None: return

    response = client.read_coils(address, count=count)
    if not response.isError():
        print(f"  -> Success! Values read: {response.bits[:count]}")
    else:
        print(f"  -> Modbus Error: {response}")

def test_read_holding_registers(client):
    print("\n--- [Read Holding Registers] ---")
    address = get_user_input("Enter starting register address (e.g., 40000): ")
    count = get_user_input("Enter number of registers to read: ")
    if address is None or count is None: return

    modbus_addr = address  # No conversion!
    response = client.read_holding_registers(modbus_addr, count=count)
    if not response.isError():
        print(f"  -> Success! Values read: {response.registers}")
    else:
        print(f"  -> Modbus Error: {response}")

def test_write_single_coil(client):
    print("\n--- [Write Single Coil] ---")
    address = get_user_input("Enter coil address to write (e.g., 0): ")
    value_str = input("Enter value (ON/TRUE/1 or OFF/FALSE/0): ").upper()
    value = value_str in ["ON", "TRUE", "1"]

    response = client.write_coil(address, value)
    if not response.isError():
        print(f"  -> Success! Wrote {value} to coil address {address}.")
    else:
        print(f"  -> Modbus Error: {response}")

def test_write_single_register(client):
    print("\n--- [Write Single Register] ---")
    address = get_user_input("Enter register address to write (e.g., 40000): ")
    value = get_user_input(f"Enter value to write at register address {address}: ")
    if address is None or value is None: return

    modbus_addr = address  # No conversion!
    response = client.write_register(modbus_addr, value)
    if not response.isError():
        print(f"  -> Success! Wrote {value} to register address {address}.")
    else:
        print(f"  -> Modbus Error: {response}")

def test_write_multiple_registers(client):
    print("\n--- [Write Multiple Registers] ---")
    address = get_user_input("Enter starting register address (e.g., 40000): ")
    count = get_user_input("Enter number of registers to write: ")
    if address is None or count is None: return

    modbus_addr = address  # No conversion!
    values = []
    for i in range(count):
        val = get_user_input(f"  Enter value for register address {address + i}: ")
        if val is None: return
        values.append(val)

    response = client.write_registers(modbus_addr, values)
    if not response.isError():
        print(f"  -> Success! Wrote {len(values)} values starting from register address {address}.")
    else:
        print(f"  -> Modbus Error: {response}")

def run_secure_client():
    print("--- Starting Secure Modbus/TLS Client ---")
    try:
        ssl_ctx = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
        ssl_ctx.check_hostname = False
        if hasattr(ssl, "OP_LEGACY_SERVER_CONNECT"):
            ssl_ctx.options |= ssl.OP_LEGACY_SERVER_CONNECT
        ssl_ctx.load_verify_locations(cafile=SERVER_CA_PATH)
    except ssl.SSLError as e:
        print(f"[ERROR] Failed to create SSL context. Please check certificate path/format: {e}")
        return
    except FileNotFoundError:
        print(f"[ERROR] Certificate file not found: {SERVER_CA_PATH}")
        print("Please ensure the certs folder and ca_cert.pem file exist in the same directory as the script.")
        return

    client = ModbusTlsClient(SERVER_HOST, port=SERVER_PORT, sslctx=ssl_ctx)

    try:
        if not client.connect():
            print(f"[ERROR] Failed to connect to {SERVER_HOST}:{SERVER_PORT}. Please check server/certificates.")
            return

        print(f"Successfully connected to server at {SERVER_HOST}:{SERVER_PORT}.")

        while True:
            print_menu()
            choice = get_user_input("Enter menu number: ")

            if choice == 1:
                test_read_coils(client)
            elif choice == 2:
                test_read_holding_registers(client)
            elif choice == 3:
                test_write_single_coil(client)
            elif choice == 4:
                test_write_single_register(client)
            elif choice == 5:
                test_write_multiple_registers(client)
            elif choice == 99:
                print("Exiting client.")
                break
            else:
                print("Invalid choice. Please try again.")

            time.sleep(1)

    except Exception as e:
        print(f"\n[CRITICAL ERROR] An exception occurred: {e}")

    finally:
        if client.is_socket_open():
            client.close()
            print("Connection to the server has been closed.")

if __name__ == "__main__":
    run_secure_client()