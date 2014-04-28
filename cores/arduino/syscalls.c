/*
  Copyright (c) 2014 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/**
  * Implementation of newlib syscall.
  *
  */

#include "syscalls.h"

#include <stdio.h>
#include <stdarg.h>
#include "sam.h"
#if defined (  __GNUC__  ) /* GCC CS3 */
  #include <sys/types.h>
  #include <sys/stat.h>
#endif

#undef errno
extern int errno ;
extern int __end__ ;
extern int __ram_end__ ;

extern caddr_t _sbrk( int incr )
{
	static unsigned char *heap = NULL ;
	unsigned char *prev_heap ;
	int ramend = (int)&__ram_end__ ;

	if ( heap == NULL )
	{
		heap = (unsigned char *)&__end__ ;
	}
	prev_heap = heap ;

	if ( ((int)prev_heap + incr) > ramend )
	{
		return (caddr_t) -1 ;
	}

	heap += incr ;

	return (caddr_t) prev_heap ;
}

extern int link( char *cOld, char *cNew )
{
    return -1 ;
}

extern int _close( int file )
{
    return -1 ;
}

extern int _fstat( int file, struct stat *st )
{
    st->st_mode = S_IFCHR ;

    return 0 ;
}

extern int _isatty( int file )
{
    return 1 ;
}

extern int _lseek( int file, int ptr, int dir )
{
    return 0 ;
}

extern int _read(int file, char *ptr, int len)
{
    return 0 ;
}

// todo
extern int _write( int file, char *ptr, int len )
{
    for ( ; len >= 0 ; len--, ptr++ )
    {
		// Check if the transmitter is ready
//		  while ((UART->UART_SR & UART_SR_TXRDY) != UART_SR_TXRDY)
			;

		  // Send character
//		  UART->UART_THR = *ptr;
    }

    return iIndex ;
}

extern void _exit( int status )
{
    printf( "Exiting with status %d.\n", status ) ;

    for ( ; ; ) ;
}

extern void _kill( int pid, int sig )
{
    return ;
}

extern int _getpid ( void )
{
    return -1 ;
}