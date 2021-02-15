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
    int c;

    kprintf("===TEST BEGIN===\r\n");

    c = kgetc();
    switch (c)
    {
        case '0': case '1': case '2': case '3': case '4': case '5':kprintf("The numbers that were entered: %c \r\n",c); break;
        default: kprintf("Please type an integer, the character typed was: %c\r\n",c); break;

    }

        kungetc(c);
        kprintf("The last input: %c\r\n",  kgetc());
    kprintf("\r\n===TEST END===\r\n");
 return;
}
/* --------- OLD CODE ----------
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
void testcases(void)
{
    int c;

    kprintf("===TEST BEGIN===\r\n");

    c = kgetc();
    switch (c)
    {

        // TODO: Test your operating system!

    default:
        kprintf("Hello Xinu World!\r\n");
    }


    kprintf("\r\n===TEST END===\r\n");
    return;
}
*/
