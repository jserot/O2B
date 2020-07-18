/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu' in SOPC Builder design 'nios_128k_extended'
 * SOPC Builder design path: ../qsys/nios_128k_extended.sopcinfo
 *
 * Generated: Sat Jul 18 10:06:13 CEST 2020
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00020820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x12
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00000020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x12
#define ALT_CPU_NAME "cpu"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00020820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x12
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00000020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x12
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00000000


/*
 * Custom instruction macros
 *
 */

#define ALT_CI_GCD(A,B) __builtin_custom_inii(ALT_CI_GCD_N,(A),(B))
#define ALT_CI_GCD_N 0x0


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2
#define __GCD


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "MAX 10"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x21090
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x21090
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x21090
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_128k_extended"


/*
 * button configuration
 *
 */

#define ALT_MODULE_CLASS_button altera_avalon_pio
#define BUTTON_BASE 0x21080
#define BUTTON_BIT_CLEARING_EDGE_REGISTER 0
#define BUTTON_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BUTTON_CAPTURE 0
#define BUTTON_DATA_WIDTH 4
#define BUTTON_DO_TEST_BENCH_WIRING 0
#define BUTTON_DRIVEN_SIM_VALUE 0
#define BUTTON_EDGE_TYPE "NONE"
#define BUTTON_FREQ 50000000
#define BUTTON_HAS_IN 1
#define BUTTON_HAS_OUT 0
#define BUTTON_HAS_TRI 0
#define BUTTON_IRQ -1
#define BUTTON_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BUTTON_IRQ_TYPE "NONE"
#define BUTTON_NAME "/dev/button"
#define BUTTON_RESET_VALUE 0
#define BUTTON_SPAN 16
#define BUTTON_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK TIMER


/*
 * hex0 configuration
 *
 */

#define ALT_MODULE_CLASS_hex0 altera_avalon_pio
#define HEX0_BASE 0x21050
#define HEX0_BIT_CLEARING_EDGE_REGISTER 0
#define HEX0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX0_CAPTURE 0
#define HEX0_DATA_WIDTH 7
#define HEX0_DO_TEST_BENCH_WIRING 0
#define HEX0_DRIVEN_SIM_VALUE 0
#define HEX0_EDGE_TYPE "NONE"
#define HEX0_FREQ 50000000
#define HEX0_HAS_IN 0
#define HEX0_HAS_OUT 1
#define HEX0_HAS_TRI 0
#define HEX0_IRQ -1
#define HEX0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX0_IRQ_TYPE "NONE"
#define HEX0_NAME "/dev/hex0"
#define HEX0_RESET_VALUE 0
#define HEX0_SPAN 16
#define HEX0_TYPE "altera_avalon_pio"


/*
 * hex1 configuration
 *
 */

#define ALT_MODULE_CLASS_hex1 altera_avalon_pio
#define HEX1_BASE 0x21040
#define HEX1_BIT_CLEARING_EDGE_REGISTER 0
#define HEX1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX1_CAPTURE 0
#define HEX1_DATA_WIDTH 7
#define HEX1_DO_TEST_BENCH_WIRING 0
#define HEX1_DRIVEN_SIM_VALUE 0
#define HEX1_EDGE_TYPE "NONE"
#define HEX1_FREQ 50000000
#define HEX1_HAS_IN 0
#define HEX1_HAS_OUT 1
#define HEX1_HAS_TRI 0
#define HEX1_IRQ -1
#define HEX1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX1_IRQ_TYPE "NONE"
#define HEX1_NAME "/dev/hex1"
#define HEX1_RESET_VALUE 0
#define HEX1_SPAN 16
#define HEX1_TYPE "altera_avalon_pio"


/*
 * hex2 configuration
 *
 */

#define ALT_MODULE_CLASS_hex2 altera_avalon_pio
#define HEX2_BASE 0x21030
#define HEX2_BIT_CLEARING_EDGE_REGISTER 0
#define HEX2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX2_CAPTURE 0
#define HEX2_DATA_WIDTH 7
#define HEX2_DO_TEST_BENCH_WIRING 0
#define HEX2_DRIVEN_SIM_VALUE 0
#define HEX2_EDGE_TYPE "NONE"
#define HEX2_FREQ 50000000
#define HEX2_HAS_IN 0
#define HEX2_HAS_OUT 1
#define HEX2_HAS_TRI 0
#define HEX2_IRQ -1
#define HEX2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX2_IRQ_TYPE "NONE"
#define HEX2_NAME "/dev/hex2"
#define HEX2_RESET_VALUE 0
#define HEX2_SPAN 16
#define HEX2_TYPE "altera_avalon_pio"


/*
 * hex3 configuration
 *
 */

#define ALT_MODULE_CLASS_hex3 altera_avalon_pio
#define HEX3_BASE 0x21020
#define HEX3_BIT_CLEARING_EDGE_REGISTER 0
#define HEX3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX3_CAPTURE 0
#define HEX3_DATA_WIDTH 7
#define HEX3_DO_TEST_BENCH_WIRING 0
#define HEX3_DRIVEN_SIM_VALUE 0
#define HEX3_EDGE_TYPE "NONE"
#define HEX3_FREQ 50000000
#define HEX3_HAS_IN 0
#define HEX3_HAS_OUT 1
#define HEX3_HAS_TRI 0
#define HEX3_IRQ -1
#define HEX3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX3_IRQ_TYPE "NONE"
#define HEX3_NAME "/dev/hex3"
#define HEX3_RESET_VALUE 0
#define HEX3_SPAN 16
#define HEX3_TYPE "altera_avalon_pio"


/*
 * hex4 configuration
 *
 */

#define ALT_MODULE_CLASS_hex4 altera_avalon_pio
#define HEX4_BASE 0x21010
#define HEX4_BIT_CLEARING_EDGE_REGISTER 0
#define HEX4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX4_CAPTURE 0
#define HEX4_DATA_WIDTH 7
#define HEX4_DO_TEST_BENCH_WIRING 0
#define HEX4_DRIVEN_SIM_VALUE 0
#define HEX4_EDGE_TYPE "NONE"
#define HEX4_FREQ 50000000
#define HEX4_HAS_IN 0
#define HEX4_HAS_OUT 1
#define HEX4_HAS_TRI 0
#define HEX4_IRQ -1
#define HEX4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX4_IRQ_TYPE "NONE"
#define HEX4_NAME "/dev/hex4"
#define HEX4_RESET_VALUE 0
#define HEX4_SPAN 16
#define HEX4_TYPE "altera_avalon_pio"


/*
 * hex5 configuration
 *
 */

#define ALT_MODULE_CLASS_hex5 altera_avalon_pio
#define HEX5_BASE 0x21000
#define HEX5_BIT_CLEARING_EDGE_REGISTER 0
#define HEX5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX5_CAPTURE 0
#define HEX5_DATA_WIDTH 7
#define HEX5_DO_TEST_BENCH_WIRING 0
#define HEX5_DRIVEN_SIM_VALUE 0
#define HEX5_EDGE_TYPE "NONE"
#define HEX5_FREQ 50000000
#define HEX5_HAS_IN 0
#define HEX5_HAS_OUT 1
#define HEX5_HAS_TRI 0
#define HEX5_IRQ -1
#define HEX5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX5_IRQ_TYPE "NONE"
#define HEX5_NAME "/dev/hex5"
#define HEX5_RESET_VALUE 0
#define HEX5_SPAN 16
#define HEX5_TYPE "altera_avalon_pio"


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x21090
#define JTAG_UART_IRQ 0
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * led configuration
 *
 */

#define ALT_MODULE_CLASS_led altera_avalon_pio
#define LED_BASE 0x21060
#define LED_BIT_CLEARING_EDGE_REGISTER 0
#define LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_CAPTURE 0
#define LED_DATA_WIDTH 10
#define LED_DO_TEST_BENCH_WIRING 0
#define LED_DRIVEN_SIM_VALUE 0
#define LED_EDGE_TYPE "NONE"
#define LED_FREQ 50000000
#define LED_HAS_IN 0
#define LED_HAS_OUT 1
#define LED_HAS_TRI 0
#define LED_IRQ -1
#define LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_IRQ_TYPE "NONE"
#define LED_NAME "/dev/led"
#define LED_RESET_VALUE 0
#define LED_SPAN 16
#define LED_TYPE "altera_avalon_pio"


/*
 * onchip_memory configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory altera_avalon_onchip_memory2
#define ONCHIP_MEMORY_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY_BASE 0x0
#define ONCHIP_MEMORY_CONTENTS_INFO ""
#define ONCHIP_MEMORY_DUAL_PORT 0
#define ONCHIP_MEMORY_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY_INIT_CONTENTS_FILE "nios_128k_extended_onchip_memory"
#define ONCHIP_MEMORY_INIT_MEM_CONTENT 0
#define ONCHIP_MEMORY_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY_IRQ -1
#define ONCHIP_MEMORY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY_NAME "/dev/onchip_memory"
#define ONCHIP_MEMORY_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY_SIZE_VALUE 131072
#define ONCHIP_MEMORY_SPAN 131072
#define ONCHIP_MEMORY_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY_WRITABLE 1


/*
 * switch configuration
 *
 */

#define ALT_MODULE_CLASS_switch altera_avalon_pio
#define SWITCH_BASE 0x21070
#define SWITCH_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCH_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH_CAPTURE 0
#define SWITCH_DATA_WIDTH 10
#define SWITCH_DO_TEST_BENCH_WIRING 0
#define SWITCH_DRIVEN_SIM_VALUE 0
#define SWITCH_EDGE_TYPE "NONE"
#define SWITCH_FREQ 50000000
#define SWITCH_HAS_IN 1
#define SWITCH_HAS_OUT 0
#define SWITCH_HAS_TRI 0
#define SWITCH_IRQ -1
#define SWITCH_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SWITCH_IRQ_TYPE "NONE"
#define SWITCH_NAME "/dev/switch"
#define SWITCH_RESET_VALUE 0
#define SWITCH_SPAN 16
#define SWITCH_TYPE "altera_avalon_pio"


/*
 * timer configuration
 *
 */

#define ALT_MODULE_CLASS_timer altera_avalon_timer
#define TIMER_ALWAYS_RUN 0
#define TIMER_BASE 0x20000
#define TIMER_COUNTER_SIZE 32
#define TIMER_FIXED_PERIOD 0
#define TIMER_FREQ 50000000
#define TIMER_IRQ 1
#define TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_LOAD_VALUE 49999
#define TIMER_MULT 0.001
#define TIMER_NAME "/dev/timer"
#define TIMER_PERIOD 1
#define TIMER_PERIOD_UNITS "ms"
#define TIMER_RESET_OUTPUT 0
#define TIMER_SNAPSHOT 1
#define TIMER_SPAN 32
#define TIMER_TICKS_PER_SEC 1000
#define TIMER_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
