#include "user_code.h"

#include "main.h"

#include <stdbool.h>

/* PRIVATE DEFINES */

/**
 * This is how long to wait before reading the value of the button press.
 * I didn't use an oscilloscope to check this value but the button feels quite
 * crisp so I thought 50ms wasn't too small.
 * */
#define DEBOUNCE_VALUE_MS 50

/* PRIVATE VARIABLES */

/** This flag is used to turn the LED blink on or off. */
bool blink = false;

/** This timestamp is used to debounce the button press. */
uint32_t last_isr_trigger_time = 0;



/* PUBLIC FUNCTION DEFINITIONS */

void user_main(void)
{
  while(1)
  {
    if(blink)
    {
      HAL_GPIO_TogglePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin);
      HAL_Delay(100);
    }
    else
    {
      HAL_GPIO_WritePin(GREEN_LED_GPIO_Port,GREEN_LED_Pin, GPIO_PIN_RESET);
    }
  }
}


void user_button_isr()
{
  if((HAL_GetTick() - last_isr_trigger_time) < DEBOUNCE_VALUE_MS)
  {
    // Do nothing because the button hasn't had enough time to stop bouncing so it might not
    // be a new press.
     __NOP();
  }
  else
  {
    // This line of code gets the cortex systick value. It's in milliseconds since the program started.
    last_isr_trigger_time = HAL_GetTick();
    // Toggle the led behaviour.
    blink = !blink;
  }

}

