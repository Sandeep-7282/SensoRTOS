
#include "cmsis_os.h"
#include "systemclock_config.h"
#include "task_uart.h"
#include "uart-driver.h"
#include "task_dht22.h"
#include "task_hcsr04.h"
#include "task_display.h"

// ⛳ Correct place to define the task (GLOBAL, not inside any function)
osThreadDef(UART_Task, UART_Task, osPriorityNormal, 1, 512);  // 512 words = 2KB stack

osThreadId uartTaskHandle;

int main(void)
{
	UART1_Init();
   // HAL_Init();
    SystemClock_Config();
    // CMSIS v1 initialization
    UART1_SendString("Initialized\r\n");
    osThreadDef(UART_Task, UART_Task, osPriorityNormal, 1, 512);
    uartTaskHandle = osThreadCreate(osThread(UART_Task), NULL);

    // Inside main() after kernel init
    osThreadDef(DHT22_Task, DHT22_Task, osPriorityNormal, 1, 512);
    dht22TaskHandle = osThreadCreate(osThread(DHT22_Task), NULL);

    // Inside main() after kernel init
    osThreadDef(HCSR04_Task, HCSR04_Task, osPriorityNormal, 1, 512);
    hcsr04TaskHandle = osThreadCreate(osThread(HCSR04_Task), NULL);

    // Inside main() after FreeRTOS kernel init and other tasks
    osThreadDef(Display_Task, Display_Task, osPriorityNormal, 1, 512);
    displayTaskHandle = osThreadCreate(osThread(Display_Task), NULL);

    osKernelStart();  // Only this is needed to start scheduler

    while (1);
}
