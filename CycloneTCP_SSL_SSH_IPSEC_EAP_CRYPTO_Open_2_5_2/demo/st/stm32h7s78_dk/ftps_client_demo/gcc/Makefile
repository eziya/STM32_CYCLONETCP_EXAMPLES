RESULT ?= ftps_client_demo

DEFINES = \
	-DSTM32H7S7xx \
	-DUSE_HAL_DRIVER \
	-DUSE_STM32H7S78_DK \
	-D_WINSOCK_H \
	-D__error_t_defined

INCLUDES = \
	-I../src \
	-I../../../../../third_party/cmsis/core/include \
	-I../../../../../third_party/st/devices/stm32h7rsxx \
	-I../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc \
	-I../../../../../third_party/st/boards2/stm32h7s78_discovery \
	-I../../../../../third_party/st/boards2/components/common \
	-I../../../../../third_party/st/boards2/utilities/lcd \
	-I../../../../../third_party/freertos/include \
	-I../../../../../third_party/freertos/portable/gcc/arm_cm7/r0p1 \
	-I../../../../../common \
	-I../../../../../cyclone_tcp \
	-I../../../../../cyclone_ssl \
	-I../../../../../cyclone_crypto

ASM_SOURCES = \
	./startup_stm32h7s7xx.S

C_SOURCES = \
	../src/system_stm32h7rsxx.c \
	../src/stm32h7rsxx_it.c \
	./syscalls.c \
	../src/main.c \
	../src/smi_driver.c \
	../src/debug.c \
	../../../../../common/cpu_endian.c \
	../../../../../common/os_port_freertos.c \
	../../../../../common/date_time.c \
	../../../../../common/str.c \
	../../../../../cyclone_tcp/core/net.c \
	../../../../../cyclone_tcp/core/net_mem.c \
	../../../../../cyclone_tcp/core/net_misc.c \
	../../../../../cyclone_tcp/drivers/mac/stm32h7rsxx_eth_driver.c \
	../../../../../cyclone_tcp/drivers/phy/lan8742_driver.c \
	../../../../../cyclone_tcp/core/nic.c \
	../../../../../cyclone_tcp/core/ethernet.c \
	../../../../../cyclone_tcp/core/ethernet_misc.c \
	../../../../../cyclone_tcp/ipv4/arp.c \
	../../../../../cyclone_tcp/ipv4/arp_cache.c \
	../../../../../cyclone_tcp/ipv4/ipv4.c \
	../../../../../cyclone_tcp/ipv4/ipv4_frag.c \
	../../../../../cyclone_tcp/ipv4/ipv4_multicast.c \
	../../../../../cyclone_tcp/ipv4/ipv4_misc.c \
	../../../../../cyclone_tcp/ipv4/icmp.c \
	../../../../../cyclone_tcp/igmp/igmp_host.c \
	../../../../../cyclone_tcp/igmp/igmp_host_misc.c \
	../../../../../cyclone_tcp/igmp/igmp_common.c \
	../../../../../cyclone_tcp/igmp/igmp_debug.c \
	../../../../../cyclone_tcp/ipv6/ipv6.c \
	../../../../../cyclone_tcp/ipv6/ipv6_frag.c \
	../../../../../cyclone_tcp/ipv6/ipv6_multicast.c \
	../../../../../cyclone_tcp/ipv6/ipv6_pmtu.c \
	../../../../../cyclone_tcp/ipv6/ipv6_misc.c \
	../../../../../cyclone_tcp/ipv6/icmpv6.c \
	../../../../../cyclone_tcp/ipv6/ndp.c \
	../../../../../cyclone_tcp/ipv6/ndp_cache.c \
	../../../../../cyclone_tcp/ipv6/ndp_misc.c \
	../../../../../cyclone_tcp/ipv6/slaac.c \
	../../../../../cyclone_tcp/ipv6/slaac_misc.c \
	../../../../../cyclone_tcp/mld/mld_node.c \
	../../../../../cyclone_tcp/mld/mld_node_misc.c \
	../../../../../cyclone_tcp/mld/mld_common.c \
	../../../../../cyclone_tcp/mld/mld_debug.c \
	../../../../../cyclone_tcp/core/ip.c \
	../../../../../cyclone_tcp/core/tcp.c \
	../../../../../cyclone_tcp/core/tcp_fsm.c \
	../../../../../cyclone_tcp/core/tcp_misc.c \
	../../../../../cyclone_tcp/core/tcp_timer.c \
	../../../../../cyclone_tcp/core/udp.c \
	../../../../../cyclone_tcp/core/socket.c \
	../../../../../cyclone_tcp/core/socket_misc.c \
	../../../../../cyclone_tcp/core/bsd_socket.c \
	../../../../../cyclone_tcp/core/bsd_socket_options.c \
	../../../../../cyclone_tcp/core/bsd_socket_misc.c \
	../../../../../cyclone_tcp/core/raw_socket.c \
	../../../../../cyclone_tcp/dns/dns_cache.c \
	../../../../../cyclone_tcp/dns/dns_client.c \
	../../../../../cyclone_tcp/dns/dns_common.c \
	../../../../../cyclone_tcp/dns/dns_debug.c \
	../../../../../cyclone_tcp/mdns/mdns_client.c \
	../../../../../cyclone_tcp/mdns/mdns_responder.c \
	../../../../../cyclone_tcp/mdns/mdns_responder_misc.c \
	../../../../../cyclone_tcp/mdns/mdns_common.c \
	../../../../../cyclone_tcp/netbios/nbns_client.c \
	../../../../../cyclone_tcp/netbios/nbns_responder.c \
	../../../../../cyclone_tcp/netbios/nbns_common.c \
	../../../../../cyclone_tcp/llmnr/llmnr_client.c \
	../../../../../cyclone_tcp/llmnr/llmnr_responder.c \
	../../../../../cyclone_tcp/llmnr/llmnr_common.c \
	../../../../../cyclone_tcp/dhcp/dhcp_client.c \
	../../../../../cyclone_tcp/dhcp/dhcp_client_fsm.c \
	../../../../../cyclone_tcp/dhcp/dhcp_client_misc.c \
	../../../../../cyclone_tcp/dhcp/dhcp_common.c \
	../../../../../cyclone_tcp/dhcp/dhcp_debug.c \
	../../../../../cyclone_tcp/ftp/ftp_client.c \
	../../../../../cyclone_tcp/ftp/ftp_client_transport.c \
	../../../../../cyclone_tcp/ftp/ftp_client_misc.c \
	../../../../../cyclone_ssl/tls.c \
	../../../../../cyclone_ssl/tls_cipher_suites.c \
	../../../../../cyclone_ssl/tls_handshake.c \
	../../../../../cyclone_ssl/tls_client.c \
	../../../../../cyclone_ssl/tls_client_fsm.c \
	../../../../../cyclone_ssl/tls_client_extensions.c \
	../../../../../cyclone_ssl/tls_client_misc.c \
	../../../../../cyclone_ssl/tls_server.c \
	../../../../../cyclone_ssl/tls_server_fsm.c \
	../../../../../cyclone_ssl/tls_server_extensions.c \
	../../../../../cyclone_ssl/tls_server_misc.c \
	../../../../../cyclone_ssl/tls_common.c \
	../../../../../cyclone_ssl/tls_extensions.c \
	../../../../../cyclone_ssl/tls_certificate.c \
	../../../../../cyclone_ssl/tls_sign_generate.c \
	../../../../../cyclone_ssl/tls_sign_verify.c \
	../../../../../cyclone_ssl/tls_sign_misc.c \
	../../../../../cyclone_ssl/tls_key_material.c \
	../../../../../cyclone_ssl/tls_transcript_hash.c \
	../../../../../cyclone_ssl/tls_cache.c \
	../../../../../cyclone_ssl/tls_ticket.c \
	../../../../../cyclone_ssl/tls_ffdhe.c \
	../../../../../cyclone_ssl/tls_record.c \
	../../../../../cyclone_ssl/tls_record_encryption.c \
	../../../../../cyclone_ssl/tls_record_decryption.c \
	../../../../../cyclone_ssl/tls_misc.c \
	../../../../../cyclone_ssl/tls13_client.c \
	../../../../../cyclone_ssl/tls13_client_extensions.c \
	../../../../../cyclone_ssl/tls13_client_misc.c \
	../../../../../cyclone_ssl/tls13_server.c \
	../../../../../cyclone_ssl/tls13_server_extensions.c \
	../../../../../cyclone_ssl/tls13_server_misc.c \
	../../../../../cyclone_ssl/tls13_common.c \
	../../../../../cyclone_ssl/tls13_sign_generate.c \
	../../../../../cyclone_ssl/tls13_sign_verify.c \
	../../../../../cyclone_ssl/tls13_key_material.c \
	../../../../../cyclone_ssl/tls13_ticket.c \
	../../../../../cyclone_ssl/tls13_misc.c \
	../../../../../cyclone_crypto/hardware/stm32h7rsxx/stm32h7rsxx_crypto.c \
	../../../../../cyclone_crypto/hardware/stm32h7rsxx/stm32h7rsxx_crypto_trng.c \
	../../../../../cyclone_crypto/hardware/stm32h7rsxx/stm32h7rsxx_crypto_hash.c \
	../../../../../cyclone_crypto/hardware/stm32h7rsxx/stm32h7rsxx_crypto_cipher.c \
	../../../../../cyclone_crypto/hardware/stm32h7rsxx/stm32h7rsxx_crypto_pkc.c \
	../../../../../cyclone_crypto/hash/md5.c \
	../../../../../cyclone_crypto/hash/sha1.c \
	../../../../../cyclone_crypto/hash/sha224.c \
	../../../../../cyclone_crypto/hash/sha256.c \
	../../../../../cyclone_crypto/hash/sha384.c \
	../../../../../cyclone_crypto/hash/sha512.c \
	../../../../../cyclone_crypto/mac/hmac.c \
	../../../../../cyclone_crypto/cipher/rc4.c \
	../../../../../cyclone_crypto/cipher/idea.c \
	../../../../../cyclone_crypto/cipher/des.c \
	../../../../../cyclone_crypto/cipher/des3.c \
	../../../../../cyclone_crypto/cipher/aes.c \
	../../../../../cyclone_crypto/cipher/camellia.c \
	../../../../../cyclone_crypto/cipher/seed.c \
	../../../../../cyclone_crypto/cipher/aria.c \
	../../../../../cyclone_crypto/cipher_modes/cbc.c \
	../../../../../cyclone_crypto/aead/ccm.c \
	../../../../../cyclone_crypto/aead/gcm.c \
	../../../../../cyclone_crypto/cipher/chacha.c \
	../../../../../cyclone_crypto/mac/poly1305.c \
	../../../../../cyclone_crypto/aead/chacha20_poly1305.c \
	../../../../../cyclone_crypto/pkc/dh.c \
	../../../../../cyclone_crypto/pkc/rsa.c \
	../../../../../cyclone_crypto/pkc/rsa_misc.c \
	../../../../../cyclone_crypto/pkc/dsa.c \
	../../../../../cyclone_crypto/ecc/ec.c \
	../../../../../cyclone_crypto/ecc/ec_curves.c \
	../../../../../cyclone_crypto/ecc/ec_misc.c \
	../../../../../cyclone_crypto/ecc/ecdh.c \
	../../../../../cyclone_crypto/ecc/ecdsa.c \
	../../../../../cyclone_crypto/ecc/eddsa.c \
	../../../../../cyclone_crypto/ecc/curve25519.c \
	../../../../../cyclone_crypto/ecc/curve448.c \
	../../../../../cyclone_crypto/ecc/x25519.c \
	../../../../../cyclone_crypto/ecc/x448.c \
	../../../../../cyclone_crypto/ecc/ed25519.c \
	../../../../../cyclone_crypto/ecc/ed448.c \
	../../../../../cyclone_crypto/mpi/mpi.c \
	../../../../../cyclone_crypto/encoding/base64.c \
	../../../../../cyclone_crypto/encoding/asn1.c \
	../../../../../cyclone_crypto/encoding/oid.c \
	../../../../../cyclone_crypto/pkix/pem_import.c \
	../../../../../cyclone_crypto/pkix/pem_key_import.c \
	../../../../../cyclone_crypto/pkix/pem_decrypt.c \
	../../../../../cyclone_crypto/pkix/pem_common.c \
	../../../../../cyclone_crypto/pkix/pkcs5_decrypt.c \
	../../../../../cyclone_crypto/pkix/pkcs5_common.c \
	../../../../../cyclone_crypto/pkix/pkcs8_key_parse.c \
	../../../../../cyclone_crypto/pkix/x509_key_parse.c \
	../../../../../cyclone_crypto/pkix/x509_cert_parse.c \
	../../../../../cyclone_crypto/pkix/x509_cert_ext_parse.c \
	../../../../../cyclone_crypto/pkix/x509_cert_validate.c \
	../../../../../cyclone_crypto/pkix/x509_crl_parse.c \
	../../../../../cyclone_crypto/pkix/x509_crl_ext_parse.c \
	../../../../../cyclone_crypto/pkix/x509_crl_validate.c \
	../../../../../cyclone_crypto/pkix/x509_sign_parse.c \
	../../../../../cyclone_crypto/pkix/x509_sign_verify.c \
	../../../../../cyclone_crypto/pkix/x509_common.c \
	../../../../../cyclone_crypto/kdf/hkdf.c \
	../../../../../cyclone_crypto/kdf/pbkdf.c \
	../../../../../cyclone_crypto/xof/keccak.c \
	../../../../../cyclone_crypto/xof/shake.c \
	../../../../../cyclone_crypto/rng/hmac_drbg.c \
	../../../../../third_party/freertos/portable/gcc/arm_cm7/r0p1/port.c \
	../../../../../third_party/freertos/croutine.c \
	../../../../../third_party/freertos/list.c \
	../../../../../third_party/freertos/queue.c \
	../../../../../third_party/freertos/tasks.c \
	../../../../../third_party/freertos/timers.c \
	../../../../../third_party/freertos/portable/memmang/heap_3.c \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery.c \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_audio.c \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_bus.c \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_lcd.c \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_sd.c \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_ts.c \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_usbpd_pwr.c \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_xspi.c \
	../../../../../third_party/st/boards2/components/aps256xx/aps256xx.c \
	../../../../../third_party/st/boards2/components/gt911/gt911.c \
	../../../../../third_party/st/boards2/components/gt911/gt911_reg.c \
	../../../../../third_party/st/boards2/components/mx66uw1g45g/mx66uw1g45g.c \
	../../../../../third_party/st/boards2/components/tcpp0203/tcpp0203.c \
	../../../../../third_party/st/boards2/components/tcpp0203/tcpp0203_reg.c \
	../../../../../third_party/st/boards2/components/wm8904/wm8904.c \
	../../../../../third_party/st/boards2/components/wm8904/wm8904_reg.c \
	../../../../../third_party/st/boards2/utilities/lcd/stm32_lcd.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_adc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_adc_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_cec.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_cordic.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_cortex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_crc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_crc_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_cryp.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_cryp_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_dcmipp.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_dma.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_dma2d.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_dma_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_dts.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_eth.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_eth_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_exti.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_fdcan.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_flash.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_flash_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_gfxmmu.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_gfxtim.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_gpio.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_gpu2d.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_hash.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_hcd.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_i2c.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_i2c_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_i2s.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_i2s_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_i3c.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_icache.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_irda.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_iwdg.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_jpeg.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_lptim.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_ltdc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_ltdc_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_mce.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_mdf.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_mdios.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_mmc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_mmc_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_nand.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_nor.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_pcd.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_pcd_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_pka.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_pssi.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_pwr.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_pwr_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_ramecc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_rcc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_rcc_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_rng.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_rng_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_rtc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_rtc_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_sai.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_sai_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_sd.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_sdram.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_sd_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_smartcard.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_smartcard_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_smbus.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_smbus_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_spdifrx.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_spi.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_spi_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_sram.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_tim.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_tim_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_uart.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_uart_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_usart.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_usart_ex.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_wwdg.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_hal_xspi.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_adc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_cordic.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_crc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_crs.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_dlyb.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_dma.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_dma2d.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_exti.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_fmc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_gpio.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_i2c.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_i3c.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_lptim.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_lpuart.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_pka.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_pwr.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_rcc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_rng.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_rtc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_sdmmc.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_spi.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_tim.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_ucpd.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_usart.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_ll_usb.c \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/src/stm32h7rsxx_util_i3c.c

HEADERS = \
	../src/os_port_config.h \
	../src/net_config.h \
	../src/tls_config.h \
	../src/crypto_config.h \
	../src/FreeRTOSConfig.h \
	../src/stm32h7rsxx_hal_conf.h \
	../src/stm32h7s78_discovery_conf.h \
	../src/aps256xx_conf.h \
	../src/gt911_conf.h \
	../src/mx66uw1g45g_conf.h \
	../src/stm32h7rsxx_it.h \
	../src/smi_driver.h \
	../../../../../common/cpu_endian.h \
	../../../../../common/os_port.h \
	../../../../../common/os_port_freertos.h \
	../../../../../common/date_time.h \
	../../../../../common/str.h \
	../../../../../common/error.h \
	../../../../../common/debug.h \
	../../../../../cyclone_tcp/core/net.h \
	../../../../../cyclone_tcp/core/net_mem.h \
	../../../../../cyclone_tcp/core/net_misc.h \
	../../../../../cyclone_tcp/drivers/mac/stm32h7rsxx_eth_driver.h \
	../../../../../cyclone_tcp/drivers/phy/lan8742_driver.h \
	../../../../../cyclone_tcp/core/nic.h \
	../../../../../cyclone_tcp/core/ethernet.h \
	../../../../../cyclone_tcp/core/ethernet_misc.h \
	../../../../../cyclone_tcp/ipv4/arp.h \
	../../../../../cyclone_tcp/ipv4/arp_cache.h \
	../../../../../cyclone_tcp/ipv4/ipv4.h \
	../../../../../cyclone_tcp/ipv4/ipv4_frag.h \
	../../../../../cyclone_tcp/ipv4/ipv4_multicast.h \
	../../../../../cyclone_tcp/ipv4/ipv4_misc.h \
	../../../../../cyclone_tcp/ipv4/icmp.h \
	../../../../../cyclone_tcp/igmp/igmp_host.h \
	../../../../../cyclone_tcp/igmp/igmp_host_misc.h \
	../../../../../cyclone_tcp/igmp/igmp_common.h \
	../../../../../cyclone_tcp/igmp/igmp_debug.h \
	../../../../../cyclone_tcp/ipv6/ipv6.h \
	../../../../../cyclone_tcp/ipv6/ipv6_frag.h \
	../../../../../cyclone_tcp/ipv6/ipv6_multicast.h \
	../../../../../cyclone_tcp/ipv6/ipv6_pmtu.h \
	../../../../../cyclone_tcp/ipv6/ipv6_misc.h \
	../../../../../cyclone_tcp/ipv6/icmpv6.h \
	../../../../../cyclone_tcp/ipv6/ndp.h \
	../../../../../cyclone_tcp/ipv6/ndp_cache.h \
	../../../../../cyclone_tcp/ipv6/ndp_misc.h \
	../../../../../cyclone_tcp/ipv6/slaac.h \
	../../../../../cyclone_tcp/ipv6/slaac_misc.h \
	../../../../../cyclone_tcp/mld/mld_node.h \
	../../../../../cyclone_tcp/mld/mld_node_misc.h \
	../../../../../cyclone_tcp/mld/mld_common.h \
	../../../../../cyclone_tcp/mld/mld_debug.h \
	../../../../../cyclone_tcp/core/ip.h \
	../../../../../cyclone_tcp/core/tcp.h \
	../../../../../cyclone_tcp/core/tcp_fsm.h \
	../../../../../cyclone_tcp/core/tcp_misc.h \
	../../../../../cyclone_tcp/core/tcp_timer.h \
	../../../../../cyclone_tcp/core/udp.h \
	../../../../../cyclone_tcp/core/socket.h \
	../../../../../cyclone_tcp/core/socket_misc.h \
	../../../../../cyclone_tcp/core/bsd_socket.h \
	../../../../../cyclone_tcp/core/bsd_socket_options.h \
	../../../../../cyclone_tcp/core/bsd_socket_misc.h \
	../../../../../cyclone_tcp/core/raw_socket.h \
	../../../../../cyclone_tcp/dns/dns_cache.h \
	../../../../../cyclone_tcp/dns/dns_client.h \
	../../../../../cyclone_tcp/dns/dns_common.h \
	../../../../../cyclone_tcp/dns/dns_debug.h \
	../../../../../cyclone_tcp/mdns/mdns_client.h \
	../../../../../cyclone_tcp/mdns/mdns_responder.h \
	../../../../../cyclone_tcp/mdns/mdns_responder_misc.h \
	../../../../../cyclone_tcp/mdns/mdns_common.h \
	../../../../../cyclone_tcp/netbios/nbns_client.h \
	../../../../../cyclone_tcp/netbios/nbns_responder.h \
	../../../../../cyclone_tcp/netbios/nbns_common.h \
	../../../../../cyclone_tcp/llmnr/llmnr_client.h \
	../../../../../cyclone_tcp/llmnr/llmnr_responder.h \
	../../../../../cyclone_tcp/llmnr/llmnr_common.h \
	../../../../../cyclone_tcp/dhcp/dhcp_client.h \
	../../../../../cyclone_tcp/dhcp/dhcp_client_fsm.h \
	../../../../../cyclone_tcp/dhcp/dhcp_client_misc.h \
	../../../../../cyclone_tcp/dhcp/dhcp_common.h \
	../../../../../cyclone_tcp/dhcp/dhcp_debug.h \
	../../../../../cyclone_tcp/ftp/ftp_client.h \
	../../../../../cyclone_tcp/ftp/ftp_client_transport.h \
	../../../../../cyclone_tcp/ftp/ftp_client_misc.h \
	../../../../../cyclone_ssl/tls.h \
	../../../../../cyclone_ssl/tls_cipher_suites.h \
	../../../../../cyclone_ssl/tls_handshake.h \
	../../../../../cyclone_ssl/tls_client.h \
	../../../../../cyclone_ssl/tls_client_fsm.h \
	../../../../../cyclone_ssl/tls_client_extensions.h \
	../../../../../cyclone_ssl/tls_client_misc.h \
	../../../../../cyclone_ssl/tls_server.h \
	../../../../../cyclone_ssl/tls_server_fsm.h \
	../../../../../cyclone_ssl/tls_server_extensions.h \
	../../../../../cyclone_ssl/tls_server_misc.h \
	../../../../../cyclone_ssl/tls_common.h \
	../../../../../cyclone_ssl/tls_extensions.h \
	../../../../../cyclone_ssl/tls_certificate.h \
	../../../../../cyclone_ssl/tls_sign_generate.h \
	../../../../../cyclone_ssl/tls_sign_verify.h \
	../../../../../cyclone_ssl/tls_sign_misc.h \
	../../../../../cyclone_ssl/tls_key_material.h \
	../../../../../cyclone_ssl/tls_transcript_hash.h \
	../../../../../cyclone_ssl/tls_cache.h \
	../../../../../cyclone_ssl/tls_ticket.h \
	../../../../../cyclone_ssl/tls_ffdhe.h \
	../../../../../cyclone_ssl/tls_record.h \
	../../../../../cyclone_ssl/tls_record_encryption.h \
	../../../../../cyclone_ssl/tls_record_decryption.h \
	../../../../../cyclone_ssl/tls_misc.h \
	../../../../../cyclone_ssl/tls13_client.h \
	../../../../../cyclone_ssl/tls13_client_extensions.h \
	../../../../../cyclone_ssl/tls13_client_misc.h \
	../../../../../cyclone_ssl/tls13_server.h \
	../../../../../cyclone_ssl/tls13_server_extensions.h \
	../../../../../cyclone_ssl/tls13_server_misc.h \
	../../../../../cyclone_ssl/tls13_common.h \
	../../../../../cyclone_ssl/tls13_sign_generate.h \
	../../../../../cyclone_ssl/tls13_sign_verify.h \
	../../../../../cyclone_ssl/tls13_key_material.h \
	../../../../../cyclone_ssl/tls13_ticket.h \
	../../../../../cyclone_ssl/tls13_misc.h \
	../../../../../cyclone_crypto/core/crypto.h \
	../../../../../cyclone_crypto/hardware/stm32h7rsxx/stm32h7rsxx_crypto.h \
	../../../../../cyclone_crypto/hardware/stm32h7rsxx/stm32h7rsxx_crypto_trng.h \
	../../../../../cyclone_crypto/hardware/stm32h7rsxx/stm32h7rsxx_crypto_hash.h \
	../../../../../cyclone_crypto/hardware/stm32h7rsxx/stm32h7rsxx_crypto_cipher.h \
	../../../../../cyclone_crypto/hardware/stm32h7rsxx/stm32h7rsxx_crypto_pkc.h \
	../../../../../cyclone_crypto/hash/md5.h \
	../../../../../cyclone_crypto/hash/sha1.h \
	../../../../../cyclone_crypto/hash/sha224.h \
	../../../../../cyclone_crypto/hash/sha256.h \
	../../../../../cyclone_crypto/hash/sha384.h \
	../../../../../cyclone_crypto/hash/sha512.h \
	../../../../../cyclone_crypto/mac/hmac.h \
	../../../../../cyclone_crypto/cipher/rc4.h \
	../../../../../cyclone_crypto/cipher/idea.h \
	../../../../../cyclone_crypto/cipher/des.h \
	../../../../../cyclone_crypto/cipher/des3.h \
	../../../../../cyclone_crypto/cipher/aes.h \
	../../../../../cyclone_crypto/cipher/camellia.h \
	../../../../../cyclone_crypto/cipher/seed.h \
	../../../../../cyclone_crypto/cipher/aria.h \
	../../../../../cyclone_crypto/cipher_modes/cbc.h \
	../../../../../cyclone_crypto/aead/ccm.h \
	../../../../../cyclone_crypto/aead/gcm.h \
	../../../../../cyclone_crypto/cipher/chacha.h \
	../../../../../cyclone_crypto/mac/poly1305.h \
	../../../../../cyclone_crypto/aead/chacha20_poly1305.h \
	../../../../../cyclone_crypto/pkc/dh.h \
	../../../../../cyclone_crypto/pkc/rsa.h \
	../../../../../cyclone_crypto/pkc/rsa_misc.h \
	../../../../../cyclone_crypto/pkc/dsa.h \
	../../../../../cyclone_crypto/ecc/ec.h \
	../../../../../cyclone_crypto/ecc/ec_curves.h \
	../../../../../cyclone_crypto/ecc/ec_misc.h \
	../../../../../cyclone_crypto/ecc/ecdh.h \
	../../../../../cyclone_crypto/ecc/ecdsa.h \
	../../../../../cyclone_crypto/ecc/eddsa.h \
	../../../../../cyclone_crypto/ecc/curve25519.h \
	../../../../../cyclone_crypto/ecc/curve448.h \
	../../../../../cyclone_crypto/ecc/x25519.h \
	../../../../../cyclone_crypto/ecc/x448.h \
	../../../../../cyclone_crypto/ecc/ed25519.h \
	../../../../../cyclone_crypto/ecc/ed448.h \
	../../../../../cyclone_crypto/mpi/mpi.h \
	../../../../../cyclone_crypto/encoding/base64.h \
	../../../../../cyclone_crypto/encoding/asn1.h \
	../../../../../cyclone_crypto/encoding/oid.h \
	../../../../../cyclone_crypto/pkix/pem_import.h \
	../../../../../cyclone_crypto/pkix/pem_key_import.h \
	../../../../../cyclone_crypto/pkix/pem_decrypt.h \
	../../../../../cyclone_crypto/pkix/pem_common.h \
	../../../../../cyclone_crypto/pkix/pkcs5_decrypt.h \
	../../../../../cyclone_crypto/pkix/pkcs5_common.h \
	../../../../../cyclone_crypto/pkix/pkcs8_key_parse.h \
	../../../../../cyclone_crypto/pkix/x509_key_parse.h \
	../../../../../cyclone_crypto/pkix/x509_cert_parse.h \
	../../../../../cyclone_crypto/pkix/x509_cert_ext_parse.h \
	../../../../../cyclone_crypto/pkix/x509_cert_validate.h \
	../../../../../cyclone_crypto/pkix/x509_crl_parse.h \
	../../../../../cyclone_crypto/pkix/x509_crl_ext_parse.h \
	../../../../../cyclone_crypto/pkix/x509_crl_validate.h \
	../../../../../cyclone_crypto/pkix/x509_sign_parse.h \
	../../../../../cyclone_crypto/pkix/x509_sign_verify.h \
	../../../../../cyclone_crypto/pkix/x509_common.h \
	../../../../../cyclone_crypto/kdf/hkdf.h \
	../../../../../cyclone_crypto/kdf/pbkdf.h \
	../../../../../cyclone_crypto/xof/keccak.h \
	../../../../../cyclone_crypto/xof/shake.h \
	../../../../../cyclone_crypto/rng/hmac_drbg.h \
	../../../../../third_party/freertos/portable/gcc/arm_cm7/r0p1/portmacro.h \
	../../../../../third_party/freertos/include/croutine.h \
	../../../../../third_party/freertos/include/FreeRTOS.h \
	../../../../../third_party/freertos/include/list.h \
	../../../../../third_party/freertos/include/mpu_wrappers.h \
	../../../../../third_party/freertos/include/portable.h \
	../../../../../third_party/freertos/include/projdefs.h \
	../../../../../third_party/freertos/include/queue.h \
	../../../../../third_party/freertos/include/semphr.h \
	../../../../../third_party/freertos/include/stack_macros.h \
	../../../../../third_party/freertos/include/task.h \
	../../../../../third_party/freertos/include/timers.h \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery.h \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_audio.h \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_bus.h \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_errno.h \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_lcd.h \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_sd.h \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_ts.h \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_usbpd_pwr.h \
	../../../../../third_party/st/boards2/stm32h7s78_discovery/stm32h7s78_discovery_xspi.h \
	../../../../../third_party/st/boards2/components/aps256xx/aps256xx.h \
	../../../../../third_party/st/boards2/components/gt911/gt911.h \
	../../../../../third_party/st/boards2/components/gt911/gt911_reg.h \
	../../../../../third_party/st/boards2/components/mx66uw1g45g/mx66uw1g45g.h \
	../../../../../third_party/st/boards2/components/rk050hr18/rk050hr18.h \
	../../../../../third_party/st/boards2/components/tcpp0203/tcpp0203.h \
	../../../../../third_party/st/boards2/components/tcpp0203/tcpp0203_reg.h \
	../../../../../third_party/st/boards2/components/wm8904/wm8904.h \
	../../../../../third_party/st/boards2/components/wm8904/wm8904_reg.h \
	../../../../../third_party/st/boards2/utilities/lcd/stm32_lcd.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_adc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_adc_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_cec.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_cordic.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_cortex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_crc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_crc_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_cryp.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_cryp_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_dcmipp.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_def.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_dma.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_dma2d.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_dma_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_dts.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_eth.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_eth_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_exti.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_fdcan.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_flash.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_flash_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_gfxmmu.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_gfxtim.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_gpio.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_gpio_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_gpu2d.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_hash.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_hcd.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_i2c.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_i2c_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_i2s.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_i2s_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_i3c.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_icache.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_irda.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_irda_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_iwdg.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_jpeg.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_lptim.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_ltdc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_ltdc_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_mce.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_mdf.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_mdios.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_mmc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_mmc_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_nand.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_nor.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_pcd.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_pcd_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_pka.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_pssi.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_pwr.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_pwr_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_ramecc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_rcc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_rcc_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_rng.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_rng_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_rtc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_rtc_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_sai.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_sai_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_sd.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_sdram.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_sd_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_smartcard.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_smartcard_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_smbus.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_smbus_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_spdifrx.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_spi.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_spi_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_sram.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_tim.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_tim_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_uart.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_uart_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_usart.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_usart_ex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_wwdg.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_hal_xspi.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_adc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_bus.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_cordic.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_cortex.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_crc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_crs.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_dlyb.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_dma.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_dma2d.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_exti.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_fmc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_gpio.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_i2c.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_i3c.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_icache.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_iwdg.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_lptim.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_lpuart.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_pka.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_pwr.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_rcc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_rng.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_rtc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_sdmmc.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_spi.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_system.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_tim.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_ucpd.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_usart.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_usb.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_utils.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_ll_wwdg.h \
	../../../../../third_party/st/drivers/stm32h7rsxx_hal_driver/inc/stm32h7rsxx_util_i3c.h

ASM_OBJECTS = $(patsubst %.S, %.o, $(ASM_SOURCES))

C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

OBJ_DIR = obj

LINKER_SCRIPT = stm32h7s7_flash.ld

CFLAGS += -fno-common -Wall -Os -g3
CFLAGS += -mcpu=cortex-m7 -mthumb -mfpu=fpv5-d16 -mfloat-abi=hard
CFLAGS += -ffunction-sections -fdata-sections -Wl,--gc-sections
CFLAGS += $(DEFINES)
CFLAGS += $(INCLUDES)

CROSS_COMPILE ?= arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJDUMP = $(CROSS_COMPILE)objdump
OBJCOPY = $(CROSS_COMPILE)objcopy
SIZE = $(CROSS_COMPILE)size

THIS_MAKEFILE := $(lastword $(MAKEFILE_LIST))

all: build size

install: build size program

build: $(RESULT).elf $(RESULT).lst $(RESULT).bin $(RESULT).hex
	
$(RESULT).elf: $(ASM_OBJECTS) $(C_OBJECTS) $(HEADERS) $(LINKER_SCRIPT) $(THIS_MAKEFILE)
	$(CC) -Wl,-M=$(RESULT).map -Wl,-T$(LINKER_SCRIPT) $(CFLAGS) $(addprefix $(OBJ_DIR)/, $(notdir $(ASM_OBJECTS))) $(addprefix $(OBJ_DIR)/, $(notdir $(C_OBJECTS))) -o $@

$(ASM_OBJECTS): | $(OBJ_DIR)

$(C_OBJECTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

%.o: %.c $(HEADERS) $(THIS_MAKEFILE)
	$(CC) $(CFLAGS) -c $< -o $(addprefix $(OBJ_DIR)/, $(notdir $@))

%.o: %.S $(HEADERS) $(THIS_MAKEFILE)
	$(CC) $(CFLAGS) -c $< -o $(addprefix $(OBJ_DIR)/, $(notdir $@))

%.lst: %.elf
	$(OBJDUMP) -x -S $(RESULT).elf > $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@

size: $(RESULT).elf
	$(SIZE) $(RESULT).elf

flash:
	openocd -f board/st_nucleo_h7s3l8.cfg -c "init; reset halt; flash write_image erase $(RESULT).bin 0x08000000; reset run; shutdown"

clean:
	rm -f $(RESULT).elf
	rm -f $(RESULT).bin
	rm -f $(RESULT).map
	rm -f $(RESULT).hex
	rm -f $(RESULT).lst
	rm -f $(OBJ_DIR)/*.o
