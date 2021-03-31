#ifndef _KINUX_PORTS_H
#define _KINUX_PORTS_H

/* include/kinux/ports.h
 * Author - @jaychandra6
 */

// Reads a byte from a port
unsigned char byte_in(unsigned short port);

// Writes a byte to a port
void byte_out(unsigned short port, unsigned char data);

#endif //_KINUX_PORTS_H
