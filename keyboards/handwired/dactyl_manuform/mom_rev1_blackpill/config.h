// This is how the MCU will know which hand it is. 
#define SPLIT_HAND_PIN B10 // high = left, low = right

// Split Communication
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN A2     // USART TX pin
#define SERIAL_USART_RX_PIN A3     // USART RX pin
#define SERIAL_USART_DRIVER SD2
#define SERIAL_USART_TX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_RX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_TIMEOUT     100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED       921600

// Split additional data sync
#define SPLIT_LAYER_STATE_ENABLE   // This enables syncing of the layer state between both halves of the split keyboard. The main purpose of this feature is to enable support for use of things like OLED display of the currently active layer
#define SPLIT_LED_STATE_ENABLE     // This enables syncing of the Host LED status (caps lock, num lock, etc) between both halves of the split keyboard. The main purpose of this feature is to enable support for use of things like OLED display of the Host LED status.

// LIGHTING
#define WS2812_DI_PIN A1
#define RGBLED_NUM 30
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 15, 15 }
#define RGBLIGHT_LIMIT_VAL 100
#define RGBLIGHT_SLEEP
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_MODE_SNAKE
#define RGBLIGHT_MODE_STATIC_GRADIENT
#define RGBLIGHT_MODE_TWINKLE
#define RGBLIGHT_DEFAULT_MODE 7

/* I2C config for oleds */
#define I2C_DRIVER        I2CD1 //  I2CDn must correspond with mcuconf.h STM32_I2C_USE_I2Cn
#define I2C1_SCL_PIN      B8
#define I2C1_SDA_PIN      B9
#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PAL_MODE 4
#define I2C1_CLOCK_SPEED  400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_16_9

/* OLED config */
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 5
#define OLED_BRIGHTNESS 128
#define OLED_UPDATE_INTERVAL 100

/* SPI config for trackball sensor */
#define SPI_DRIVER         SPID1
#define SPI_SCK_PIN        A5
#define SPI_SCK_PAL_MODE   5
#define SPI_MOSI_PIN       A7
#define SPI_MOSI_PAL_MODE  5
#define SPI_MISO_PIN       A6
#define SPI_MISO_PAL_MODE  5

/* Trackball sensor config  */
#define PMW33XX_CS_PIN     B0
#define PMW33XX_LIFTOFF_DISTANCE 0x03
#define MOUSE_EXTENDED_REPORT
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_TASK_THROTTLE_MS 1
#define POINTING_DEVICE_DEBUG

/* Custom Trackball Configs */
#define SCROLL_DIVISOR_H 15.0 // Modify these values to adjust the scrolling speed (horizontal). In windows, I recoomend also updating mouse settings to scroll only one line at a time (default is 3) for smoother scrolling performance. 
#define SCROLL_DIVISOR_V 30.0 // Modify these values to adjust the scrolling speed (vertical)
#define PRECISION_DIVISOR 10  // When in precision mode, how much slower to go
#define PMW33XX_CPI 12000     // Default 2000
#define DPI_INCREMENT 150     // Percent increase when increasing DPI
#define DPI_DECREMENT 66      // Percent to multiply by when decreasing DPI
#define SEN_INITIAL 150       // Initial Sensitivity (percent times 10 - so I can use an int)
#define SEN_INCREMENT 150     // Percent increase when increasing Sensitivity
#define SEN_DECREMENT 66      // Percent to multiply by when decreasing Sensitivity
#define DECEL_WIDTH 70        // Width of precision deceleration curve 1-255 (0 breaks the pointer)
#define DECEL_STRENGTH 23     // Deceleration factor (higher is more extreme) 0-255
#define SNIPING_DIVISOR 10    // When in sniping mode, how much slower should the cursor move?

/* Used for checksums of mouse report transactions across split */
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED
