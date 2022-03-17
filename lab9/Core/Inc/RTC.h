#ifndef RTC_H
#define RTC_H

void RTC_Init(void);

void RTC_GetTime(unsigned char *h, unsigned char *m, unsigned char *s);

void RTC_SetTime(unsigned char Buffer[]);

#endif /* RTC_H */
