/* gpio example
   This example code is in the Public Domain (or CC0 licensed, at your option.)
   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "driver/gpio.h"

#include "esp_log.h"
#include "esp_system.h"

#define FALSE 0
#define TRUE 1

static const char *TAG = "main";

/**
 * Brief:
 * This test code shows how to configure gpio and how to use gpio interrupt.
 *
 * GPIO status:
 * GPIO0: output
 * GPIO2:  input, pulled up, interrupt from rising edge and falling edge
 *
 * Test:
 * Connect GPIO0 with GPIO2
 * Generate pulses on GPIO0, that triggers interrupt on GPIO2
 *
 */ 

#define GPIO_OUTPUT_IO_0    2
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<GPIO_OUTPUT_IO_0) 

#define GPIO_INPUT_IO_0     0
#define GPIO_INPUT_PIN_SEL  (1ULL<<GPIO_INPUT_IO_0) 




bool button_press()
{
    if (gpio_get_level(GPIO_INPUT_IO_0))
    {
        return TRUE;
    }
    return FALSE;
}

void turn_LED_on()
{
    gpio_set_level(GPIO_OUTPUT_IO_0, 1);
}

void turn_LED_off()
{
    gpio_set_level(GPIO_OUTPUT_IO_0, 0);
}



int ret_les_ten(int blink_count)
{
    blink_count = blink_count % 10;
    return blink_count;
}

void active_delay()
{
    printf("Waiting ! \n");
    for(int j=0;j<10000000;j++)
    {
        if(j%1000000==0)
        {
            printf(".");
        }
    }
}

void blink_LED(blink_count)
{
    blink_count = ret_les_ten(blink_count);
    printf("LED is going to blink \n");
    printf(blink_count);
    printf("   times.");
    for(int i=0;i<blink_count;i++)
    {
        turn_LED_off();
        active_delay();
        turn_LED_on();
        active_delay();

    }
}

void app_main(void)
{
    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;

    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);

    //interrupt of rising edge
    io_conf.intr_type = GPIO_INTR_DISABLE;

    io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
    //set as input mode
    io_conf.mode = GPIO_MODE_INPUT;
    //enable pull-up mode
    io_conf.pull_up_en = 1;
    gpio_config(&io_conf);

    int blink_count=0;

    while (1) 
    {
        if(button_press())
        {
            blink_count = blink_count+1;
        }
        active_delay();
        active_delay();
        active_delay();
        active_delay();
        active_delay();
        blink_LED(blink_count);

    }
}