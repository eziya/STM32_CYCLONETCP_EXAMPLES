RESULT ?= ftp_server_demo

DEFINES = \
	-DSTM32H573xx \
	-DUSE_HAL_DRIVER \
	-DUSE_STM32H573I_DK \
	-D__USE_C99_MATH \
	-D_WINSOCK_H \
	-D__error_t_defined

INCLUDES = \
	-I../src \
	-I../../../../../third_party/cmsis/core/include \
	-I../../../../../third_party/st/devices/stm32h5xx \
	-I../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc \
	-I../../../../../third_party/st/boards2/stm32h573i_discovery \
	-I../../../../../third_party/st/boards2/components/common \
	-I../../../../../third_party/st/boards2/utilities/lcd \
	-I../../../../../third_party/freertos/include \
	-I../../../../../third_party/freertos/portable/gcc/arm_cm33_ntz/non_secure \
	-I../../../../../third_party/fatfs \
	-I../../../../../common \
	-I../../../../../cyclone_tcp

ASM_SOURCES = \
	./startup_stm32h573xx.S

C_SOURCES = \
	../src/system_stm32h5xx.c \
	../src/stm32h5xx_it.c \
	../src/stm32h5xx_hal_timebase_tim.c \
	./syscalls.c \
	../src/main.c \
	../src/diskio.c \
	../src/debug.c \
	../../../../../common/cpu_endian.c \
	../../../../../common/os_port_freertos.c \
	../../../../../common/fs_port_fatfs.c \
	../../../../../common/date_time.c \
	../../../../../common/str.c \
	../../../../../common/path.c \
	../../../../../cyclone_tcp/core/net.c \
	../../../../../cyclone_tcp/core/net_mem.c \
	../../../../../cyclone_tcp/core/net_misc.c \
	../../../../../cyclone_tcp/drivers/mac/stm32h5xx_eth_driver.c \
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
	../../../../../cyclone_tcp/ftp/ftp_server.c \
	../../../../../cyclone_tcp/ftp/ftp_server_commands.c \
	../../../../../cyclone_tcp/ftp/ftp_server_control.c \
	../../../../../cyclone_tcp/ftp/ftp_server_data.c \
	../../../../../cyclone_tcp/ftp/ftp_server_transport.c \
	../../../../../cyclone_tcp/ftp/ftp_server_misc.c \
	../../../../../third_party/freertos/portable/gcc/arm_cm33_ntz/non_secure/port.c \
	../../../../../third_party/freertos/portable/gcc/arm_cm33_ntz/non_secure/portasm.c \
	../../../../../third_party/freertos/croutine.c \
	../../../../../third_party/freertos/list.c \
	../../../../../third_party/freertos/queue.c \
	../../../../../third_party/freertos/tasks.c \
	../../../../../third_party/freertos/timers.c \
	../../../../../third_party/freertos/portable/memmang/heap_3.c \
	../../../../../third_party/fatfs/ff.c \
	../../../../../third_party/fatfs/option/unicode.c \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery.c \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery_audio.c \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery_bus.c \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery_lcd.c \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery_sd.c \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery_ts.c \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery_usbpd_pwr.c \
	../../../../../third_party/st/boards2/components/cs42l51/cs42l51.c \
	../../../../../third_party/st/boards2/components/cs42l51/cs42l51_reg.c \
	../../../../../third_party/st/boards2/components/ft6x06/ft6x06.c \
	../../../../../third_party/st/boards2/components/ft6x06/ft6x06_reg.c \
	../../../../../third_party/st/boards2/components/st7789h2/st7789h2.c \
	../../../../../third_party/st/boards2/components/st7789h2/st7789h2_reg.c \
	../../../../../third_party/st/boards2/components/tcpp0203/tcpp0203.c \
	../../../../../third_party/st/boards2/components/tcpp0203/tcpp0203_reg.c \
	../../../../../third_party/st/boards2/utilities/lcd/stm32_lcd.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_adc.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_adc_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_cec.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_comp.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_cordic.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_cortex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_crc.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_crc_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_cryp.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_cryp_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_dac.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_dac_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_dcache.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_dcmi.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_dma.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_dma_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_dts.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_eth.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_eth_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_exti.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_fdcan.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_flash.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_flash_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_fmac.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_gpio.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_gtzc.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_hash.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_hcd.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_i2c.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_i2c_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_i2s.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_i2s_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_i3c.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_icache.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_irda.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_iwdg.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_lptim.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_mmc.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_mmc_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_nand.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_nor.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_opamp.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_opamp_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_otfdec.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_pcd.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_pcd_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_pka.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_pssi.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_pwr.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_pwr_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_ramcfg.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_rcc.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_rcc_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_rng.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_rng_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_rtc.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_rtc_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_sai.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_sai_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_sd.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_sdram.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_sd_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_smartcard.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_smartcard_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_smbus.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_smbus_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_spi.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_spi_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_sram.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_tim.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_tim_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_uart.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_uart_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_usart.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_usart_ex.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_wwdg.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_hal_xspi.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_adc.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_comp.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_cordic.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_crc.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_crs.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_dac.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_dlyb.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_dma.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_exti.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_fmac.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_fmc.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_gpio.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_i2c.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_i3c.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_icache.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_lptim.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_lpuart.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_opamp.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_pka.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_pwr.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_rcc.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_rng.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_rtc.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_sdmmc.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_spi.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_tim.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_ucpd.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_usart.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_usb.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_ll_utils.c \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/src/stm32h5xx_util_i3c.c

HEADERS = \
	../src/os_port_config.h \
	../src/fs_port_config.h \
	../src/net_config.h \
	../src/FreeRTOSConfig.h \
	../src/ffconf.h \
	../src/stm32h5xx_hal_conf.h \
	../src/stm32h573i_discovery_conf.h \
	../src/stm32h5xx_it.h \
	../../../../../common/cpu_endian.h \
	../../../../../common/os_port.h \
	../../../../../common/os_port_freertos.h \
	../../../../../common/fs_port.h \
	../../../../../common/fs_port_fatfs.h \
	../../../../../common/date_time.h \
	../../../../../common/str.h \
	../../../../../common/path.h \
	../../../../../common/error.h \
	../../../../../common/debug.h \
	../../../../../cyclone_tcp/core/net.h \
	../../../../../cyclone_tcp/core/net_mem.h \
	../../../../../cyclone_tcp/core/net_misc.h \
	../../../../../cyclone_tcp/drivers/mac/stm32h5xx_eth_driver.h \
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
	../../../../../cyclone_tcp/ftp/ftp_server.h \
	../../../../../cyclone_tcp/ftp/ftp_server_commands.h \
	../../../../../cyclone_tcp/ftp/ftp_server_control.h \
	../../../../../cyclone_tcp/ftp/ftp_server_data.h \
	../../../../../cyclone_tcp/ftp/ftp_server_transport.h \
	../../../../../cyclone_tcp/ftp/ftp_server_misc.h \
	../../../../../third_party/freertos/portable/gcc/arm_cm33_ntz/non_secure/portmacro.h \
	../../../../../third_party/freertos/portable/gcc/arm_cm33_ntz/non_secure/portasm.h \
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
	../../../../../third_party/fatfs/diskio.h \
	../../../../../third_party/fatfs/ff.h \
	../../../../../third_party/fatfs/integer.h \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery.h \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery_audio.h \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery_bus.h \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery_lcd.h \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery_sd.h \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery_ts.h \
	../../../../../third_party/st/boards2/stm32h573i_discovery/stm32h573i_discovery_usbpd_pwr.h \
	../../../../../third_party/st/boards2/components/cs42l51/cs42l51.h \
	../../../../../third_party/st/boards2/components/cs42l51/cs42l51_reg.h \
	../../../../../third_party/st/boards2/components/ft6x06/ft6x06.h \
	../../../../../third_party/st/boards2/components/ft6x06/ft6x06_reg.h \
	../../../../../third_party/st/boards2/components/st7789h2/st7789h2.h \
	../../../../../third_party/st/boards2/components/st7789h2/st7789h2_reg.h \
	../../../../../third_party/st/boards2/components/tcpp0203/tcpp0203.h \
	../../../../../third_party/st/boards2/components/tcpp0203/tcpp0203_reg.h \
	../../../../../third_party/st/boards2/utilities/lcd/stm32_lcd.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_adc.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_adc_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_cec.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_comp.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_cordic.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_cortex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_crc.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_crc_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_cryp.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_cryp_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_dac.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_dac_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_dcache.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_dcmi.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_def.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_dma.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_dma_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_dts.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_eth.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_eth_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_exti.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_fdcan.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_flash.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_flash_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_fmac.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_gpio.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_gpio_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_gtzc.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_hash.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_hcd.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_i2c.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_i2c_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_i2s.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_i2s_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_i3c.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_icache.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_irda.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_irda_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_iwdg.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_lptim.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_mmc.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_mmc_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_nand.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_nor.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_opamp.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_opamp_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_otfdec.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_pcd.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_pcd_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_pka.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_pssi.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_pwr.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_pwr_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_ramcfg.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_rcc.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_rcc_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_rng.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_rng_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_rtc.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_rtc_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_sai.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_sai_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_sd.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_sdram.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_sd_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_smartcard.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_smartcard_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_smbus.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_smbus_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_spi.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_spi_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_sram.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_tim.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_tim_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_uart.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_uart_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_usart.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_usart_ex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_wwdg.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_hal_xspi.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_adc.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_bus.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_comp.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_cordic.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_cortex.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_crc.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_crs.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_dac.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_dcache.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_dlyb.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_dma.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_exti.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_fmac.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_fmc.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_gpio.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_i2c.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_i3c.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_icache.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_iwdg.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_lptim.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_lpuart.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_opamp.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_pka.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_pwr.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_rcc.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_rng.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_rtc.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_sdmmc.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_spi.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_system.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_tim.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_ucpd.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_usart.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_usb.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_utils.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_ll_wwdg.h \
	../../../../../third_party/st/drivers/stm32h5xx_hal_driver/inc/stm32h5xx_util_i3c.h

ASM_OBJECTS = $(patsubst %.S, %.o, $(ASM_SOURCES))

C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))

OBJ_DIR = obj

LINKER_SCRIPT = stm32h573_flash.ld

CFLAGS += -fno-common -Wall -Os -g3
CFLAGS += -mcpu=cortex-m33 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=softfp
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
	openocd -f board/st_nucleo_h5.cfg -c "init; reset halt; flash write_image erase $(RESULT).bin 0x08000000; reset run; shutdown"

clean:
	rm -f $(RESULT).elf
	rm -f $(RESULT).bin
	rm -f $(RESULT).map
	rm -f $(RESULT).hex
	rm -f $(RESULT).lst
	rm -f $(OBJ_DIR)/*.o
