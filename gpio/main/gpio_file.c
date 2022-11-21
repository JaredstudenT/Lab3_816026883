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
        return FALSE;
    }
    return TRUE;
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
    vTaskDelay(100 / portTICK_RATE_MS);
}

const char* blink_message(int blink_count)
{
    if (blink_count ==0)
    {
        return " The LED is going to Blink zero times \n";
    }
    else if (blink_count ==1)
    {
        return " The LED is going to Blink one time \n";
    }
    else if (blink_count ==2)
    {
        return " The LED is going to Blink two times \n";
    }
    else if (blink_count ==3)
    {
        return " The LED is going to Blink three times \n";
    }
    else if (blink_count ==4)
    {
        return " The LED is going to Blink four times \n";
    }
    else if (blink_count ==5)
    {
        return " The LED is going to Blink five times \n";
    }
    else if (blink_count ==6)
    {
        return " The LED is going to Blink six times \n";
    }
    else if (blink_count ==7)
    {
        return " The LED is going to Blink seven times \n";
    }
    else if (blink_count ==8)
    {
        return " The LED is going to Blink eight times \n";
    }
    else if (blink_count ==9)
    {
        return " The LED is going to Blink nine times \n";
    }
    else if (blink_count ==10)
    {
        return " The LED is going to Blink ten times \n";
    }


    return  " ERROR \n" ;
}

void blink_LED(int blink_count)
{
    
    printf("LED is going to blink %d times ", blink_count);
    const char* status_message = blink_message(blink_count);
    printf(status_message);
    for(int i=0;i<blink_count;i++)
    {

        turn_LED_off();
        active_delay();
        turn_LED_on();
        active_delay();

    }
    vTaskDelay(2000 / portTICK_RATE_MS);
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

    int blink_count ;
    int click_count=6;

    int test_parameter=16;
    int test_result =0;

    //////////////////////UNIT TEST 1.1////////////////////////
    //testing the function ret_les_ten

    test_result = ret_les_ten(test_parameter);
    if(test_result==6)
    {
        printf("Expected 6, got %d. TEST PASSED\n", test_result);
    }
    else
    {
        printf("Expected 6, got %d. TEST FAILED\n", test_result);
    }
    //////////////////////UNIT TEST 1.1////////////////////////


    //////////////////////UNIT TEST 1.2////////////////////////
    //testing the function ret_les_ten  
    test_parameter=4;

    test_result = ret_les_ten(test_parameter);
    if(test_result==4)
    {
        printf("Expected 4, got %d. TEST PASSED\n", test_result);
    }
    else
    {
        printf("Expected 4, got %d. TEST FAILED\n", test_result);
    }
    //////////////////////UNIT TEST 1.2////////////////////////


    //////////////////////UNIT TEST 2.1////////////////////////
    //testing function blink_message
    const char* test_message;
    char answer_message[] = " ERROR \n";
    test_parameter=21;
    test_message = blink_message(test_parameter);
   
    if( strcmp(answer_message, test_message) == 0)
    {
        printf("Expected ' ERROR \n', got %d. TEST PASSED \n", test_message);
    }
    else
    {
        printf("Expected ' ERROR \n', got %d. TEST FAILED \n", test_message);
    }
    //////////////////////UNIT TEST 2.1////////////////////////


    //////////////////////UNIT TEST 2.2////////////////////////
    //testing function blink_message
    test_parameter  = 7;
    answer_message[] = " The LED is going to Blink seven times \n";
    test_message = blink_message(test_parameter);
    
    if( strcmp(answer_message, test_message) == 0)
    {
        printf("Expected ' The LED is going to Blink seven times \n', got %d. TEST PASSED \n", test_message);
    }
    else
    {
        printf("Expected ' The LED is going to Blink seven times \n', got %d. TEST FAILED \n", test_message);
    }
    //////////////////////UNIT TEST 2.2////////////////////////
}
