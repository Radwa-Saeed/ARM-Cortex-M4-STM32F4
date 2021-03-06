/*
 * Author : Radwa_Saeed
 * Date   : 8/12/2021
 * Version: 1.0.0
 */

#ifndef KEYPAD_H
#define KEYPAD_H

void KeyPad_INIT(void);
void KeyPad_Manage(void);
void KeyPad_Callouts_KeyPressNotificaton(void);
unsigned char KeyPad_Getkey(void);

#define PRESSED ((unsigned char)0)
#define RELEASED ((unsigned char)1)

#endif /* KEYPAD_H */
