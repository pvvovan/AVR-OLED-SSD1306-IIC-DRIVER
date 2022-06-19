#include "SSD1306.h"

int main(void)
{
	
	OLED_Init();	//initialize the OLED
	OLED_Clear();	//clear the display (for good measure)

	OLED_SetCursor(0, 0);		//set the cursor position to (0, 0)
	OLED_Printf("Hi guys!");	//Print out some text

	while (true) {
		;
	}

	return 0;	// never reached
}
