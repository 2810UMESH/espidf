//Driving Seven Segment Display using esp32
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define a GPIO_NUM_12          
#define b GPIO_NUM_14        
#define c GPIO_NUM_25        
#define d GPIO_NUM_33        
#define e GPIO_NUM_26
#define f GPIO_NUM_32
#define g GPIO_NUM_27


extern "C" void app_main() 
{
  gpio_pad_select_gpio(a);
  gpio_pad_select_gpio(b);
  gpio_pad_select_gpio(c);
  gpio_pad_select_gpio(d);
  gpio_pad_select_gpio(e);
  gpio_pad_select_gpio(f);
  gpio_pad_select_gpio(g);

gpio_set_direction(a, GPIO_MODE_OUTPUT);
 gpio_set_direction(b, GPIO_MODE_OUTPUT);
 gpio_set_direction(c, GPIO_MODE_OUTPUT);
 gpio_set_direction(d, GPIO_MODE_OUTPUT);
 gpio_set_direction(e, GPIO_MODE_OUTPUT);
 gpio_set_direction(f, GPIO_MODE_OUTPUT);
 gpio_set_direction(g, GPIO_MODE_OUTPUT);

 while(1)
 {
    //for displaying output
    //9 will be display
          gpio_set_level(a,0);
         gpio_set_level(b,0); 
         gpio_set_level(c,0);
         gpio_set_level(d,1);
         gpio_set_level(e,1);
         gpio_set_level(f,0);
         gpio_set_level(g,0);
vTaskDelay(1111 / portTICK_PERIOD_MS);

 }
}
