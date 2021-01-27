/*! \file keyboard.h
  \author Travis Goodspeed
  \brief Functions for reading the keyboard.
*/

//! Returns keypress, blocking.
char getKey();

//! Waits for the any key.
void anyKey();

char isThereKey();
char isThereRegularKey();
char isThereExtendedKey();
void clearBufferedkey();
