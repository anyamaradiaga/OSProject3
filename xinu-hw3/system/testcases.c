/**
* COSC 3250 - Project 3
* Test cases for kprintf.c changes as part of p3
* @authors [Nick Schaller Anya Maradiaga]
* Instructor [Sabirat]
* TA-BOT:MAILTO [nicholas.schaller@marquette.edu anya.maradiaga@marquette.edu]
*/

/**
 * @file testcases.c
 * @provides testcases
 *
 * $Id: testcases.c 175 2008-01-30 01:18:27Z brylow $
 *
 * Modified by:
 *
 * and
 *
 */
/* Embedded XINU, Copyright (C) 2007.  All rights reserved. */

#include <xinu.h>

devcall putc(int dev, char c)
{
    return 0;
}


/**
 * testcases - called after initialization completes to test things.
 */

        // TODO: Test your operating system!
void testcases(void)
{
    int c,d;

    kprintf("===TEST BEGIN===\r\n");
	kprintf("Please type an integer, (0 - kputc, 1 - kgetc, 2 - kungetc, 3 - kcheckc) \r\n");
    c = kgetc();
	
	
	kprintf("the character typed was: %c\r\n",c);
    switch (c)
    {
		
        case '0':
			
			kprintf("Testing the kputc() function via character input \r\n");
			kprintf("Please type a character \r\n");
			d = kgetc();
			kprintf("The character that was entered: %c \r\n",d);
			kputc(d);
			break;
			
		
		case '1':
			kprintf("Testing the kgetc() function via character input \r\n");
			kprintf("Please type a character \r\n");
			d = kgetc();
			kprintf("The character that was entered: %c \r\n",d);
			kputc(d);
			kgetc();
			break;
			
		
		case '2':
			kprintf("Testing the kungetc() function via character input \r\n");
			kprintf("Please type a character \r\n");
			d = kgetc();
			kprintf("The character that was entered: %c \r\n",d);
			kungetc(d);
			break;
			
		
		case '3':
			kprintf("Testing the kcheckc() function \r\n");
			kcheckc();
			break;
			
		
		
		
        default: kprintf("Please type an integer, the character typed was: %c\r\n",c);

    }
		kprintf("The number that was entered: %c \r\n",c);
        kungetc(c);
        kprintf("The last input: %c\r\n",  kgetc());
    kprintf("\r\n===TEST END===\r\n");
 return;
}

