#include <atmel_start.h>

static void toogle_led(void){
  gpio_toggle_pin_level(LED1);
}

int main()
{
  atmel_start_init();
  
  ext_irq_register(PA00, toogle_led);
  
  while (1) {
    gpio_set_pin_level(LED0,true);
    delay_ms(100);
    gpio_set_pin_level(LED0,false);
    delay_ms(100);
  }
}
