#include "all.h"
#include "stringzadas_screen.h"


/*   CURSOR   */

/*void resetCursor(){
#asm
  mov ah, #0x02
  mov bh, #0x0
  mov dh, #0x0
  //asm "mov dl #0x0";
  int 0x10
#endasm
}*/

int getCursorPosition(){
#asm
  mov ah, #0x3
  mov bh, #0x0
  int 0x10
  mov ax,dx
#endasm
}

void setCursorPosition(c,d)char c;char d;{
#asm
  push    bp
  mov     bp, sp
  push    di
  push    si
  mov     al, [bp+4]
  mov     dh, al
  mov     al, [bp+6]
  mov     dl, al

  //mov dh,#10 //row
  //mov dl,#20 //column
  mov bh,#0  //page num
  mov ah,#2
  int 0x10

  pop     si
  pop     di
  pop     bp
#endasm
}

void cls(){
  int i=0;
  while(i++<64) print(crlfScreen);
  watermark();
  setCursorPosition(0,0);
  /*
  asm("mov ax, #0x0600");
  asm("mov bx, #0x4300");
  asm("mov cx, #0x5050");
  asm("mov dx, #0x0000");

  asm("int #0x10");
  */
}

void watermark(){
  int assinaturaSize;
  assinaturaSize=strlen(assinatura);
  setCursorPosition(24,79-assinaturaSize);
  printclr(assinatura,10);
}


/*   PRINTS   */

void printclr(c,d) char *c; int d;{
  while(*c){
    printchclr(*c++,d);
    //asm_colour(d);
    //asm_putc();
  }
    //printchclr(*c++);
}

void printchclr(c,d) char c;int d;{
  asm_colour(d);
  asm_putc(c);
}

void print(c) char *c; {
  while(*c){
    printch(*c++);
    //asm_colour(15);
    //asm_putc(*c++);
  }
  //printch(*c++);
}

void printch(c) char c;{
/*#asm
  mov ah, #0x0E
  int 0x10
#endasm*/
  printchclr(c,0x7);
}


void printclrteletype(c,d) char *c; int d;{
  int skip;
  char charpwd;
  skip=0;
  charpwd=0;
  while(*c){
    //asm_colour(d);
    if((charpwd=isThereKey())){
      //charpwd=getKey();
      if (charpwd==0x3){
        skip=1;
      }
    }

    if(skip==0)
    smallSmallDelay();
    printchclr(*c++,d);
    //asm_putc(*c++);
  }
  //printchclr(*c++);
}

static asm_colour(c){
#asm
#if __FIRST_ARG_IN_AX__
  mov	bx,ax
#else
  mov	bx,sp
  mov	bx,[bx+2]
#endif
  mov	ah,#$08
  int	$10
  mov	ah,#$09
  mov	cx,#1
  int	$10
#endasm
}


static asm_putc(c){
#asm
#if !__FIRST_ARG_IN_AX__
  mov	bx,sp
  mov	ax,[bx+2]
#endif
  cmp	al,#$0A
  jne	not_nl
  mov	ax,#$0E0D
  mov	bx,#7
  int	$10
  mov	al,#$0A
not_nl:
  mov	ah,#$0E
  mov	bx,#7
  int	$10
#endasm
}

char nybbles[]="0123456789abcdef";
void printnybble(c) int c;{
  printch(nybbles[c&0xF]);
}

void printhex(c) int c;{
  printnybble(c>>12);
  printnybble(c>>8);
  printnybble(c>>4);
  printnybble(c);
  //printch(' ');
}



/*
 * Dec 	Hex 	Binary 	Color
0 	0 	0000 	Black 	
1 	1 	0001 	Blue 	
2 	2 	0010 	Green 	
3 	3 	0011 	Cyan 	
4 	4 	0100 	Red 	
5 	5 	0101 	Magenta 	
6 	6 	0110 	Brown 	
7 	7 	0111 	Light Gray 	
8 	8 	1000 	Dark Gray 	
9 	9 	1001 	Light Blue 	
10 	A 	1010 	Light Green 	
11 	B 	1011 	Light Cyan 	
12 	C 	1100 	Light Red 	
13 	D 	1101 	Light Magenta 	
14 	E 	1110 	Yellow 	
15 	F 	1111 	White 	
*/
