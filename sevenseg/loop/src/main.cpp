
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
  bool a1,b1,c1,d1,e1,f1,g1,A=0,B=0,C=0,D=0,W,X,Y,Z;
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

  while(1) {
  //seven segment boolean expressions
  a1= ((B&&!C&&!D) || (!A&&!B&&!C&&D));
  b1= ((B&&!C&&D) || (B&&C&&!D));
  c1= (!B&&C&&!D);
  d1=((B&&!C&&!D) || (B&&C&&D) || (!A&&!B&&!C&&D));
  e1=((B&&!C) || (D));
  f1=((C&&D) || (!B&&C) || (!A&&!B&&D));
  g1=(!A&&!B&&!C) || (B&&C&&D);
//boolean expression for 
  W=A;
  X=B;
  Y=C;
  Z=D;

  //increment operation

  A=(W&&!Z) || (X&&Y&&Z);
  B=(X&&!Y) || (X&&!Z) || (!X&&Y&&Z);
  C=(Y&&!Z) || (!W&&!Y&&Z);
  D=(!Z);
 vTaskDelay(1111 / portTICK_PERIOD_MS); 
//output values
          gpio_set_level(a,a1);
	 gpio_set_level(b,b1);
	 gpio_set_level(c,c1);
	 gpio_set_level(d,d1);
	 gpio_set_level(e,e1);
	 gpio_set_level(f,f1);
	 gpio_set_level(g,g1);
       /* vTaskDelay(1111 / portTICK_PERIOD_MS);
        vTaskDelay(1111 / portTICK_PERIOD_MS);*/
    }
//return 1;
}
