/**
* COSC 3250 - Project 3
* Systems for reading and writing to the UART and buffer 
* @authors [Nick Schaller Anya Maradiaga]
* Instructor [Sabirat]
* TA-BOT:MAILTO [nicholas.schaller@marquette.edu anya.maradiaga@marquette.edu]
*/

/**
 * @file kprintf.c
 */

/* Embedded Xinu, Copyright (C) 2009, 2013.  All rights reserved. */

#include <xinu.h>

#define UNGETMAX 10             /* Can un-get at most 10 characters. */

static unsigned char ungetArray[UNGETMAX];
int buf=0;
int inc=1;
/**
 * Synchronously read a character from a UART.  This blocks until a character is
 * available.  The interrupt handler is not used.
 *
 * @return
 *      The character read from the UART as an <code>unsigned char</code> cast
 *      to an <code>int</code>.
 */
syscall kgetc(void)
{
    volatile struct pl011_uart_csreg *regptr;

    /* Pointer to the UART control and status registers.  */
    regptr = (struct pl011_uart_csreg *)0x3F201000;

    // TODO: First, check the unget buffer for a character.
    //       Otherwise, check UART flags register, and
    //       once the receiver is not empty, get character c.
        int c;
        while(!kcheckc());
        if(buf == inc && buf<UNGETMAX)
{
        c= ungetArray[--buf];
        buf++;
        inc++;
}
        else
{
        c = regptr->dr;
}

      return c;
   // return SYSERR;
}

/**
 * kcheckc - check to see if a character is available.
 * @return true if a character is available, false otherwise.
 */
syscall kcheckc(void)
{
    volatile struct pl011_uart_csreg *regptr;
    regptr = (struct pl011_uart_csreg *)0x3F201000;

    // TODO: Check the unget buffer and the UART for characters.
        for(int i=0; i<UNGETMAX; i++)
{
        if(ungetArray[i] != NULL) //check if theres something on the unget array
{
        return 1;
}
}
        if(!(regptr->fr & PL011_FR_RXFE)) //check if its not empty, else return
{
        return 1;
}
        return 0;
    //return SYSERR;
}

/**
 * kungetc - put a serial character "back" into a local buffer.
 * @param c character to unget.
 * @return c on success, SYSERR on failure.
 */
syscall kungetc(unsigned char c)
{
    // TODO: Check for room in unget buffer, put the character in or discard.
        if(buf<=UNGETMAX) //checking if the FIFO is not full
{

        ungetArray[buf++] = c;
}
        return c; //sending character c

    //return SYSERR;
}


/**
 * Synchronously write a character to a UART.  This blocks until the character
 * has been written to the hardware.  The interrupt handler is not used.
 *
 * @param c
 *      The character to write.
 *
 * @return
 *      The character written to the UART as an <code>unsigned char</code> cast
 *      to an <code>int</code>.
 */
syscall kputc(uchar c)
{
    volatile struct pl011_uart_csreg *regptr;

    /* Pointer to the UART control and status registers.  */
    regptr = (struct pl011_uart_csreg *)0x3F201000;

    // TODO: Check UART flags register.
    //       Once the Transmitter FIFO is not full, send character c.
        while(regptr->fr & PL011_FR_TXFF); //checking if there's an input
        regptr->dr = (int)(c);
        return(int)c; //return c
    //return SYSERR;
}

/**
 * kernel printf: formatted, synchronous output to SERIAL0.
 *
 * @param format
 *      The format string.  Not all standard format specifiers are supported by
 *      this implementation.  See _doprnt() for a description of supported
 *      conversion specifications.
 *      Arguments matching those in the format string.
 *
 * @return
 *      The number of characters written.
 */
syscall kprintf(const char *format, ...)
{
    int retval;
    va_list ap;

    va_start(ap, format);
    retval = _doprnt(format, ap, (int (*)(int, int))kputc, 0);
    va_end(ap);
    return retval;
}



