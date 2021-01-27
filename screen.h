/*! \file screen.h
  \author Travis Goodspeed
  \brief Functions for writing to the screen.
*/

//! Print a character.
void printch();
//! Print a nybble.
void printnybble();
//! Print a 16-bit word of hex.
void printhex();
//! Print a null-terminated string.
void print();

//! Clear the screen.
void cls();


int getCursorPosition();
void setCursorPosition();
static asm_colour();
static asm_putc();
void printchclr();
void printclr();
void printObsf();
void printclrteletype();
void resetCursor();
void watermark();
