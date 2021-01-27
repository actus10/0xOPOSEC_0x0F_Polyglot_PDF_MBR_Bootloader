void slowInt(multiplier,time)int multiplier;int time;{
#asm
#if !__FIRST_ARG_IN_AX__
  mov	bx,sp
  mov	cx,[bx+2]
  mov	dx,[bx+4]
#endif
  xor ax,ax
  //MOV     CX, #0x0F    // CX:DX      Number of microseconds to elapse
  //MOV     DX, #0x4240
  MOV     AH, #0x86 //code for wait
  INT     0x15      //int for wait
#endasm
}

void delay(){
    slowInt(0xf,0x4240); //1second
}

void smallDelay(){
  slowInt(0x8,0x4240);
}

void smallSmallDelay(){
  slowInt(0x0,0xaaaa);
}

////////////////////////////////


char obfStrSize(c) char *c;{
  return c[0];
}

#define dispersion 2
char obfKeySize(c) char *c;{
  return c[1];
}

char key[20];// key need to be on the heap or else memory address will be lost when parsing as args
char* obfKeyValue(c) char *c;{
  int i;
  for (i=0;i<obfKeySize(c);i+=2){
    key[i/2]=c[i+2]; //+1 skip char size +1 skip char key size
  }
  return key;
}

//char* plainStr;
void deobfStr(c,cs,k,ks,r) char *c; int cs;char *k;int ks; char *r;{
  #ifdef OBFUSCATE
    int j;
    //int totalSize;
    //plainStr=0x7c00;
    for (j=cs-1;j>=0;j--){
      r[j]=c[j] ^ k[imod(cs-1-j,ks/dispersion)] ^ (cs-1-j); 
      //printhex(k[imod(cs-1-j,ks/dispersion)]);
      //printhex(r[j]);
    }
    r[cs]='\0';
  #else
    strcpy(r,c-2-ks);
  #endif
  
  //while(1);
  //return r;
}

void getFlag(c,r) char *c; char *r;{
  #ifdef OBFUSCATE
    //return 
    deobfStr(c+2+obfKeySize(c), obfStrSize(c), obfKeyValue(c), obfKeySize(c),r);
  #else
    strcpy(r,c);
    //return c;
  #endif
}

void free(c,s) char *c;int s;{
  int f;
  for (f=0;f<s;f++){
    c[f]='\0';
  }
}


