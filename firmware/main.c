#include <atmel_start.h>

static void toogle_led(void){
  gpio_toggle_pin_level(LED_1);
}

int main(void)
{
  /* Initializes MCU, drivers and middleware */
  atmel_start_init();

  ext_irq_register(EXT_BUTTON, toogle_led);

  /* Replace with your application code */
  while (1) {

  }
}