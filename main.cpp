#include <util/delay.h>
#include <stdio.h>

#include "SSD1306.h"

int main(void)
{
	
	OLED_Init();	//initialize the OLED
	OLED_Clear();	//clear the display (for good measure)

	OLED_SetCursor(0, 0);		//set the cursor position to (0, 0)
	OLED_Printf("Hi guys!");	//Print out some text
	_delay_ms(3000);

	double value = 0.0;
	OLED_Clear();
	while (true) {
		value += 0.1;
		char str[32] = { '\0', };
		snprintf(str, sizeof(str), "value = %5.2f%%", value);
		OLED_SetCursor(0, 0);
		OLED_Printf("%s", str);
		OLED_SetCursor(1, 0);
		OLED_Printf("Line %s", str);
		_delay_ms(500);
	}

	return 0;	// never reached
}
