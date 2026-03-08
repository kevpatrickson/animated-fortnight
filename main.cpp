#include <stdio.h>

#include "pico/stdlib.h"



#include "FreeRTOS.h"
#include "task.h"


int i=0;

// Task 1: Toggles an LED
void vTask1(void *pvParameters) {
    for (;;) {
        // Code to turn LED ON
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 500ms
        // Code to turn LED OFF
        printf("Hello %d\n",i++);
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 500ms
    }
}

// Task 2: Prints status or performs a different action
void vTask2(void *pvParameters) {
    for (;;) {
        // Perform second action (e.g., read sensor)
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1000ms
    }
}

int main(void) {
        stdio_init_all();
    // Create Task 1
    xTaskCreate(vTask1, "LED Task", 1000, NULL, 1, NULL);
    
    // Create Task 2
    xTaskCreate(vTask2, "Sensor Task", 1000, NULL, 1, NULL);
    
    // Start the scheduler
    vTaskStartScheduler();
    
    for (;;); // Should never reach here
}




// int main()
// {

//     // Initialize TinyUSB stack
//     // board_init();
// while (1)
// {
//     stdio_init_all();
//     printf("Hello world\n");
//             sleep_ms(1000);

// }

// }