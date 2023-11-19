/**
 * @file user_code.h
 *
 *  Created on: Oct 16, 2023
 *      Author: Tom
 */

#ifndef USER_CODE_H
#define USER_CODE_H

#include "main.h"

/* PUBLIC FUNCTION DECLARATIONS */

/**
 * @brief This is the main super loop of my program.
 */
void user_main(void);

/**
 * @brief This function is called when the user button is pressed. It debounces the
 * button press and toggles the LED blink on or off.
 */
void user_button_isr();

#endif

