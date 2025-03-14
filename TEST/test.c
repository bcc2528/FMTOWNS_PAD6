#include <stdio.h>
#include <stdlib.h>
#include <EGB.h>

#include "PAD6.h"

void main(void)
{
	char *ework;
	unsigned int pad6_key;
	char para[64];

	ework = (char *)malloc(sizeof(char) * 1536);
	EGB_init(ework, 1536);
	EGB_resolution(ework, 1, 5);
	EGB_resolution(ework, 0, 5);
	EGB_writePage(ework, 1);
	EGB_displayStart(ework, 0, 64, 0);
	EGB_displayStart(ework, 2, 2, 2);
	EGB_displayStart(ework, 3, 256, 240);
	EGB_writePage(ework, 0);
	EGB_displayStart(ework, 0, 64, 0);
	EGB_displayStart(ework, 2, 2, 2);
	EGB_displayStart(ework, 3, 256, 240);
	EGB_color(ework, 0, 0x7fff);
	EGB_displayPage(ework, 0, 3);

	sprintf(para, "      6 Buttons PAD TEST");
	WORD(para+0) = 48;
	WORD(para+2) = 56;
	WORD(para+4) = 18;
	EGB_sjisString(ework, para);

	while(1)
	{
		pad6_key = PAD6_in(0);


		if((pad6_key & PAD6_UP) == 0)
		{
			EGB_color(ework, 0, 0x7fff);
		}
		else
		{
			EGB_color(ework, 0, 0);
		}
		sprintf(para, "      Up");
		WORD(para+0) = 56;
		WORD(para+2) = 96;
		WORD(para+4) = 2;
		EGB_sjisString(ework, para);


		if((pad6_key & PAD6_DOWN) == 0)
		{
			EGB_color(ework, 0, 0x7fff);
		}
		else
		{
			EGB_color(ework, 0, 0);
		}
		sprintf(para, "      Down");
		WORD(para+0) = 48;
		WORD(para+2) = 144;
		WORD(para+4) = 4;
		EGB_sjisString(ework, para);


		if((pad6_key & PAD6_LEFT) == 0)
		{
			EGB_color(ework, 0, 0x7fff);
		}
		else
		{
			EGB_color(ework, 0, 0);
		}
		sprintf(para, "      Left");
		WORD(para+0) = 8;
		WORD(para+2) = 120;
		WORD(para+4) = 4;
		EGB_sjisString(ework, para);


		if((pad6_key & PAD6_RIGHT) == 0)
		{
			EGB_color(ework, 0, 0x7fff);
		}
		else
		{
			EGB_color(ework, 0, 0);
		}
		sprintf(para, "      Right");
		WORD(para+0) = 88;
		WORD(para+2) = 120;
		WORD(para+4) = 5;
		EGB_sjisString(ework, para);


		if((pad6_key & PAD6_A) == 0)
		{
			EGB_color(ework, 0, 0x7fff);
		}
		else
		{
			EGB_color(ework, 0, 0);
		}
		sprintf(para, "      A");
		WORD(para+0) = 176;
		WORD(para+2) = 152;
		WORD(para+4) = 1;
		EGB_sjisString(ework, para);


		if((pad6_key & PAD6_B) == 0)
		{
			EGB_color(ework, 0, 0x7fff);
		}
		else
		{
			EGB_color(ework, 0, 0);
		}
		sprintf(para, "      B");
		WORD(para+0) = 196;
		WORD(para+2) = 136;
		WORD(para+4) = 1;
		EGB_sjisString(ework, para);


		if((pad6_key & PAD6_RUN) == 0)
		{
			if((pad6_key & PAD6_SELECT) == 0)
			{
				break;
			}

			EGB_color(ework, 0, 0x7fff);
		}
		else
		{
			EGB_color(ework, 0, 0);
		}
		sprintf(para, "      RUN");
		WORD(para+0) = 160;
		WORD(para+2) = 192;
		WORD(para+4) = 3;
		EGB_sjisString(ework, para);


		if((pad6_key & PAD6_SELECT) == 0)
		{
			EGB_color(ework, 0, 0x7fff);
		}
		else
		{
			EGB_color(ework, 0, 0);
		}
		sprintf(para, "      SELECT");
		WORD(para+0) = 40;
		WORD(para+2) = 192;
		WORD(para+4) = 6;
		EGB_sjisString(ework, para);


		if((pad6_key & PAD6_Z) == 0)
		{
			EGB_color(ework, 0, 0x7fff);
		}
		else
		{
			EGB_color(ework, 0, 0);
		}
		sprintf(para, "      Z");
		WORD(para+0) = 208;
		WORD(para+2) = 88;
		WORD(para+4) = 1;
		EGB_sjisString(ework, para);


		if((pad6_key & PAD6_Y) == 0)
		{
			EGB_color(ework, 0, 0x7fff);
		}
		else
		{
			EGB_color(ework, 0, 0);
		}
		sprintf(para, "      Y");
		WORD(para+0) = 188;
		WORD(para+2) = 104;
		WORD(para+4) = 1;
		EGB_sjisString(ework, para);


		if((pad6_key & PAD6_X) == 0)
		{
			EGB_color(ework, 0, 0x7fff);
		}
		else
		{
			EGB_color(ework, 0, 0);
		}
		sprintf(para, "      X");
		WORD(para+0) = 168;
		WORD(para+2) = 120;
		WORD(para+4) = 1;
		EGB_sjisString(ework, para);


		if((pad6_key & PAD6_C) == 0)
		{
			EGB_color(ework, 0, 0x7fff);
		}
		else
		{
			EGB_color(ework, 0, 0);
		}
		sprintf(para, "      C");
		WORD(para+0) = 216;
		WORD(para+2) = 120;
		WORD(para+4) = 1;
		EGB_sjisString(ework, para);

		Vsync_wait();
	}

	EGB_init(ework, 1536);
	free(ework);
}