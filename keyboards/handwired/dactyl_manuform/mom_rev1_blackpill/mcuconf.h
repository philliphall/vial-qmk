// This file seems to be needed to initialize the very 
// flexible STM32 units, telling it which pins are being 
// used for which function. 
#pragma once

#include_next <mcuconf.h>

#undef STM32_SERIAL_USE_USART2
#define STM32_SERIAL_USE_USART2 TRUE

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE

#undef STM32_I2C_I2C1_TX_DMA_STREAM
#define STM32_I2C_I2C1_TX_DMA_STREAM STM32_DMA_STREAM_ID(1, 1)

#undef STM32_SPI_USE_SPI1
#define STM32_SPI_USE_SPI1 TRUE
