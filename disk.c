#include "disk.h"

char *counterValue;
int counterPolymorph;
void readSector(){
#asm
  mov ax, #0x7c0		;Load to 07E0:0000 -> 0x7E00

  mov es, ax			
  xor bx, bx

  mov ah, #0x02    ;Interrupt 13h,2 => Read disk sectors
  mov al, #0x01    ;how many sectors to read
  mov ch, #0       ;Cylinder 0
  mov cl, #1       ;Sector   2 (These begin at 1 not 0.)
  mov dh, #0       ;Head     0 (Top side of a floppy.)
  mov dl, #0       ;Lecteur de disquettes
  int 0x13
 
#endasm
}

void writeSector(){
#asm
  mov ax, #0x7c0		;Load to 07E0:0000 -> 0x7E00

  mov es, ax			
  xor bx, bx

  mov ah, #0x03    ;Interrupt 13h,2 => Read disk sectors
  mov al, #0x01    ;how many sectors to read
  mov ch, #0       ;Cylinder 0
  mov cl, #1       ;Sector   2 (These begin at 1 not 0.)
  mov dh, #0       ;Head     0 (Top side of a floppy.)
  mov dl, #0       ;Lecteur de disquettes
  int 0x13
 
#endasm
}

int polymorph(){
    readSector(); //read from disk to memory. can't use content in memory because disk is packed and content ir ram is unpacked
    counterValue = 0x7c00; //point char address to 0x7c00
    counterPolymorph=counterValue[0x5b]; //get value of counter reserved byte in disk
    counterPolymorph++; //increment counter
    counterValue[0x5b]=counterPolymorph; //increment counter
    writeSector(); //write changes to disk
    clearBootloader();
    //printhex(counterPolymorph);
    //print ("write done");
    if (counterPolymorph>7){
      cls();
      
      polymorphPrint();
      
      getKey();
      return 0;
    }
    return counterPolymorph;
}

void clearBootloader(){
  int i;
  char *addr;
  addr=0x7c00;
  for (i=0;i<0x1fe;i++){
    *addr++=0x0;  
  }
  addr=0x7c00;
}
