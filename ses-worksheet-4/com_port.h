/*
	Copyright 2012, Michael Scott

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef COM_PORT_H_
#define COM_PORT_H_

/* Baud rate used by the comtest tasks. */
#define mainCOM_PORT_BAUD_RATE				( 9600 )

/*
 * Initialise the COM port (USART2) was 3 on Rev a 2 on rev b 
 */
void COMPortInit( void );

/*
 * Send a character to the COM port.
 */
extern int __io_putchar(int c);

/*
 * Receive a character from the COM port.
 */
extern int inbyte(void);

#endif /* COM_PORT_H_ */
