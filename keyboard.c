#include "all.h"
#include "stringzadas_keyboard.h"

char getKey(){ //getRegularKey
#asm
  xor ax,ax
  int 0x16
#endasm
}

char getExtendedKey(){ //getExtendedKey
#asm
  xor ax,ax
  mov ah,#0x10
  int 0x16
  mov al,ah
#endasm
}

char keyPressed;
char isThereKey(){
  keyPressed=isThereExtendedKey();
  if (keyPressed==0xe0){
    return getExtendedKey()+128;
  }
  else if(keyPressed!=0){
    return getKey();
  }
  else{
    
  }
  return 0x00;
}

char isThereRegularKey(){
#asm
  mov	ah,#0x01
  int	$16
  jz	nokey
  cmp	ax,#0
  jnz	dort
  mov	ax,#3
dort:
  ret
nokey:
  xor	ax,ax
#endasm
}

char isThereExtendedKey(){
#asm
  mov	ah,#0x11
  int	$16
  jz	nokeyex
  cmp	ax,#0
  jnz	dortex
  mov	ax,#3
dortex:
  //mov al,ah
  ret
nokeyex:
  xor	ax,ax
#endasm
}

void clearBufferedkey(){
#asm
  mov ah, #0x4
  int 0x16
#endasm
}

void anyKey(){
  print(pressAnyKey);
  getKey();
  print(crlf);
}
