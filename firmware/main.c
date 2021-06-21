#include <atmel_start.h>

static uint8_t src_data[128] = {0x44, 0x5A, 0x69, 0x6D, 0x61, 0x73, 0x69, 0x6B};
static uint8_t chk_data[128];

void FLASH_0_test(void){
	uint32_t page_size;
        uint8_t e;

	/* Init source data */
	page_size = flash_get_page_size(&FLASH_0);
        
        for (e = 0; e < 255; e++){
          /* Write data to flash */
          flash_write(&FLASH_0, 0x2300 + (page_size * e), src_data, page_size);

          /* Read data from flash */
          flash_read(&FLASH_0, 0x2300 + (page_size * e), chk_data, page_size);
        }
	
}

static void toogle_led(void){
  gpio_toggle_pin_level(LED_1);
}

int main(void){
  /* Initializes MCU, drivers and middleware */
  atmel_start_init();

  ext_irq_register(EXT_BUTTON, toogle_led);

  FLASH_0_test();
  
  /* Replace with your application code */
  while (1){
  }
}
