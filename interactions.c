#include "stringzadas_interactions.h"
#include "all.h"
char *bufferino;


char username[20];
char password[20];
char key;
int induserpas;
int cursPos;
void rootLogin() {
    while (strcmp(rootUsername, username) != 0 || strcmp(rootPassword, password) != 0) {
        cls();
        setCursorPosition(0, 0);
        printclr(separador0, 2);
        setCursorPosition(1, 20);
        printchclr(pipe, 2);
        setCursorPosition(1, 30);
        printclr(rootkitAdmin, 2);
        setCursorPosition(1, 60);
        printchclr(pipe, 2);
        setCursorPosition(2, 0);

        printclr(separador0, 2);

        setCursorPosition(3, 20);
        printchclr(pipe, 2);
        setCursorPosition(3, 27);
        printclr(userTxt, 2);
        setCursorPosition(3, 60);
        printchclr(pipe, 2);
        setCursorPosition(4, 0);

        printclr(separador0, 2);

        setCursorPosition(5, 20);
        printchclr(pipe, 2);
        setCursorPosition(5, 23);
        printclr(passwordTxt, 2);
        setCursorPosition(5, 60);
        printchclr(pipe, 2);
        setCursorPosition(6, 0);

        printclr(separador0, 2);

        setCursorPosition(3, 33);

        //ask for username
        key = getKey();
        induserpas = 0;
        while (key != 0x09 && key != 0x0d) {
            if (key == 0x08) {
                if (induserpas > 0) {
                    induserpas--;
                    cursPos = getCursorPosition();
                    setCursorPosition((cursPos >> 8), (cursPos & 0x00ff) - 1);
                }
            } else {
                printchclr(key, 4);
                username[induserpas] = key;
                induserpas++;
            }
            key = getKey();
        }
        username[induserpas] = 0x0;
        //print (username);

        //ask for passwords
        setCursorPosition(5, 33);
        key = getKey();
        induserpas = 0;
        while (key != 0x09 && key != 0x0d) {
            if (key == 0x08) {
                if (induserpas > 0) {
                    induserpas--;
                    cursPos = getCursorPosition();
                    setCursorPosition((cursPos >> 8), (cursPos & 0x00ff) - 1);
                }
            } else {
                printchclr(key, 4);
                password[induserpas] = key;
                induserpas++;
            }
            key = getKey();
        }
        password[induserpas] = 0x0;
        //print (password);
    }
}


void SkullBanner() {
    printclr(caveira0, 2);
    printclr(caveira1, 2);
    printclr(caveira2, 2);
    printclr(caveira3, 2);
    printclr(caveira4, 2);
    printclr(caveira5, 2);
    printclr(caveira6, 2);
    printclr(caveira7, 4);
    printclr(caveira8, 2);
    printclr(caveira9, 4);
    printclr(caveira10, 2);
    printclr(caveira11, 4);
    printclr(caveira12, 2);
    printclr(caveira13, 2);
    printclr(caveira14, 4);
    printclr(caveira15, 2);
    printclr(caveira16, 4);
    printclr(caveira17, 2);
    printclr(caveira18, 2);
    printclr(caveira19, 2);
    printclr(caveira20, 2);
    printclr(caveira21, 2);
    printclr(caveira22, 2);
    printclr(caveira23, 2);
    printclr(caveira24, 2);
    printclr(caveira25, 2);
}

void printOpoterm() {
    printclr(opoterm0, 0xc);
    printclr(opoterm1, 0xc);
    printclr(opoterm2, 0xc);
    printclr(opoterm3, 0xc);
    printclr(opoterm4, 0xc);
    printclr(opoterm5, 0xc);
    printclr(opoterm6, 0xc);
    printclr(opoterm7, 0xc);

}

int completion;
int j = 0;
char charBreak;
int polymorphCount;
void printProgress() {
    polymorphCount=0;
    printclr(bootkit0, 2);
    j = 0;
    for (; j < 50; j++) {
        if ((charBreak=isThereKey())) {
            //charBreak = getKey();
            if (charBreak==0x03){
              polymorphCount=polymorph();
              if (polymorphCount!=0){
                printclr(crlfInteractions, 4);
                printclr(crlfInteractions, 4);
                print (itoa(polymorphCount));
                print (polymorhFailedAttempts);
                print(polymorphMayBreak);
                getKey();  
              }
              return;
            }
        }
        smallSmallDelay();
        smallSmallDelay();
        smallSmallDelay();
        setCursorPosition(2, 51);
        printchclr(pipe, 4);
        printchclr(space, 4);
        completion = (j * 100) / 50;
        //printclr(completion,4);
        printclr(itoa(completion), 4);
        printchclr(percentage, 4);
        setCursorPosition(2, j);
        printclr(hash, 4);
    }
}

void opoleaks() {
    cls();
    printclrteletype(manifesto0, 11);
    smallDelay();
    //printclrteletype(manifesto1, 11);
    //smallDelay();
    //printclrteletype(manifesto2, 11);
    //printclr(crlfInteractions,11);
    anyKey();

}


void xmas() {
    char charpwd;
    charpwd = 0;
    
    cls();
    printOpoterm();

    print(tree0);
    print(tree1);
    print(tree2);
    print(tree3);
    print(tree4);
    print(tree5);
    print(tree6);
    print(tree7);
    print(tree8);
    print(tree9);
    print(tree10);
    print(tree11);
    print(tree12);
    print(tree13);
    print(tree14);
    print(tree15);
    //printclr(treeFlag,0x9);

    bufferino = 0x7c00;
    free(bufferino,obfStrSize(treeFlag));
    
    while (charpwd != 0x3) {

        //printch('x');
        if ((charpwd=isThereKey())) {
            //charpwd = getKey();
            break;
        }
        //else{continue;}


        setCursorPosition(12, 6);
        printchclr(bigI, 0xa);

        setCursorPosition(12, 12);
        printchclr(bigI, 0xa);

        setCursorPosition(15, 4);
        printchclr(bigI, 0xa);
        setCursorPosition(15, 14);
        printchclr(bigI, 0xa);

        setCursorPosition(18, 2);
        printchclr(bigI, 0xa);
        setCursorPosition(18, 16);
        printchclr(bigI, 0xa);

        setCursorPosition(21, 0);
        printchclr(bigI, 0xa);
        setCursorPosition(21, 18);
        printchclr(bigI, 0xa);


        //middles
        setCursorPosition(14, 9);
        printchclr(bigI, 0xa);
        setCursorPosition(18, 9);
        printchclr(bigI, 0xa);
        setCursorPosition(20, 9);
        printchclr(bigI, 0xa);

        //Os
        setCursorPosition(12, 9);
        printchclr(bigO, 0xc);
        setCursorPosition(15, 7);
        printchclr(bigO, 0xc);
        setCursorPosition(15, 11);
        printchclr(bigO, 0xc);
        setCursorPosition(18, 5);
        printchclr(bigO, 0xc);
        setCursorPosition(18, 13);
        printchclr(bigO, 0xc);
        setCursorPosition(20, 5);
        printchclr(bigO, 0xc);
        setCursorPosition(20, 13);
        printchclr(bigO, 0xc);
        setCursorPosition(21, 7);
        printchclr(bigO, 0xc);
        setCursorPosition(21, 11);
        printchclr(bigO, 0xc);
        setCursorPosition(24, 0);
        
        
        //print(deobfStr(xxx,obfKeyValue(xxx)));
        getFlag(treeFlag,bufferino);
        printclr(bufferino, 0x9);

        delay();

        if ((charpwd=isThereKey())) {
            //charpwd = getKey();
            break;
        }
        setCursorPosition(12, 6);
        printchclr(bigI, 0xc);
        setCursorPosition(12, 12);
        printchclr(bigI, 0xc);

        setCursorPosition(15, 4);
        printchclr(bigI, 0xc);
        setCursorPosition(15, 14);
        printchclr(bigI, 0xc);

        setCursorPosition(18, 2);
        printchclr(bigI, 0xc);
        setCursorPosition(18, 16);
        printchclr(bigI, 0xc);

        setCursorPosition(21, 0);
        printchclr(bigI, 0xc);
        setCursorPosition(21, 18);
        printchclr(bigI, 0xc);


        //middles
        setCursorPosition(14, 9);
        printchclr(bigI, 0xc);
        setCursorPosition(18, 9);
        printchclr(bigI, 0xc);
        setCursorPosition(20, 9);
        printchclr(bigI, 0xc);

        //Os
        //Os
        setCursorPosition(12, 9);
        printchclr(bigO, 0xa);
        setCursorPosition(15, 7);
        printchclr(bigO, 0xa);
        setCursorPosition(15, 11);
        printchclr(bigO, 0xa);
        setCursorPosition(18, 5);
        printchclr(bigO, 0xa);
        setCursorPosition(18, 13);
        printchclr(bigO, 0xa);
        setCursorPosition(20, 5);
        printchclr(bigO, 0xa);
        setCursorPosition(20, 13);
        printchclr(bigO, 0xa);
        setCursorPosition(21, 7);
        printchclr(bigO, 0xa);
        setCursorPosition(21, 11);
        printchclr(bigO, 0xa);

        setCursorPosition(24, 0);
        printclr(bufferino, 0xb);
        delay();

    }
    
    free(bufferino,obfStrSize(treeFlag));
}

char charpwd;
int indexzadas;
char *bufferino2;
void vault() {
    int curX, curY, cursPos;
    cls();
    charpwd = null;
    print(enterPasswordVault);
    indexzadas = 0;
    while (charpwd != 0x3) {
        //printch('x');
        if ((charpwd=isThereKey())) {
            //charpwd = getKey();
            //printhex (charpwd);
          bufferino = 0x7c00;
          free(bufferino,obfStrSize(vaultPwd));
        
          getFlag(vaultPwd,bufferino);
        } else { continue; }
        
        
        
        
        //deobfStr(vaultPwd+2+obfKeySize(vaultPwd), indexzadas+1, obfKeyValue(vaultPwd), obfKeySize(vaultPwd),bufferino);
        //printhex(bufferino[indexzadas]);
        
        if (charpwd == bufferino[indexzadas]) {
            indexzadas++;
            printchclr(charpwd, 4);
        }
        else {
            /*if (charpwd==vaultPwd[0]){
              indexzadas=1;printchclr(charpwd,4);
            }*/
            //else{
            //indexzadas=0;
            cursPos = getCursorPosition();
            curX = cursPos >> 8;
            curY = (cursPos & 0x00ff);
            for (; indexzadas > 0; indexzadas--) {
                setCursorPosition(curX, --curY);
                printch(null);
            }
            setCursorPosition(curX, curY);

            //}
        }
        
        
        if (indexzadas == strlen(bufferino)) {
            charpwd = 0x3;
            printclr(crlfInteractions,4);
            print(heresVaultFlag);
            
            bufferino2= 0x7d00;
            free(bufferino2,obfStrSize(vaultFlag));
            
            deobfStr(vaultFlag+2+(strlen(bufferino)*2),obfStrSize(vaultFlag),bufferino,strlen(bufferino)*2,bufferino2);
            //printhex(bufferino2[2]);
            print(bufferino2);
            
            free(bufferino,obfStrSize(vaultPwd));
            free(bufferino2,obfStrSize(vaultFlag));
                        
            print(crlfInteractions);
            print(crlfInteractions);
            anyKey();
        }
        
        free(bufferino,obfStrSize(vaultPwd));
        
    }
}

#define codesegment 0x7e00
#define numSectores 23
#define destAddr    (numSectores*512)+0x7e00
#define callOffset  numSectores*512
char charShellCode;
char charOrigShellCode;
char charindex;
char *destino;
int cursPos;
int readShellCode(){
  charindex=0;
  charShellCode=0;
  destino=destAddr;//+(512*numSectores);
 
  while((charShellCode=getKey())!=3 && charShellCode!=0x0d){
    //printchclr(charShellCode,4);
    charOrigShellCode=charShellCode;
    if (charShellCode>=0x41 && charShellCode<=0x46){
      charShellCode=charShellCode-0x37;
      //printhex(charShellCode);
    }
    else if(charShellCode>=0x61 && charShellCode<=0x66) {
      charShellCode=charShellCode-0x57;
      charOrigShellCode-=0x20;// print small letters as capital;
      //printhex(charShellCode);
    }
    else if (charShellCode>=0x30 && charShellCode<=0x39){
      charShellCode=charShellCode-0x30;
      //printhex(charShellCode);
    }
    else if (charShellCode==0x08){
      
      //printch(eof);
      //setCursorPosition((cursPos >> 8), (cursPos & 0x00ff)-1);
      if(charindex==0){
        if(destino>destAddr){
        destino--;
        *destino=*destino&0xf0;
        charindex=1;
        }
        else{
          continue;
        }
      }
      else{
        charindex=0;
        *destino=0x0;
      }
      cursPos = getCursorPosition();
      setCursorPosition((cursPos >> 8), (cursPos & 0x00ff)-1);
      continue;
    }
    else{
      continue;
    }
    printchclr(charOrigShellCode,4);
    
    if(charindex==0){
      charindex=1;
      *destino=0x0;
      charShellCode=charShellCode<<4;
      *destino=charShellCode;
    }
    else if (charindex==1){
      charindex=0;
      *destino=*destino^charShellCode;
      //print("\r\n");
      //printhex(*destino);
      destino++;
    }
    else{
      return 0;
    }
  }
  
  if(charShellCode==0x0d){
    //*destino++=0x66;  //ret
    *destino++=0xc3;  //...
  }
  else if(charShellCode==0x03){
    //print ("cancelamos");
    return 0;
  }
  else{return 0;}
  return 1;
}

void polymorphPrint(){
  print(SystemUnstablePolymorphFlag,4);
  print(crlfInteractions,4);
  bufferino = 0x7c00;
  free(bufferino,obfStrSize(polymorphFlag));
  getFlag(polymorphFlag,bufferino);
  print(bufferino,4);
  free(bufferino,obfStrSize(polymorphFlag));
  print(crlfInteractions,4);
}


int retShellCode;
//char *leetAddr;
void shellCodeGlitch(){
  cls();
  print(glitchMsg);
  printclr(leet,2);
  print(exfil);
  printclr(shellcodeexample,4);
  print(endGlitchMsg);
  
  
  retShellCode=readShellCode();
  
  //if the user didn't ctrl+c then execute shellcode
  if (retShellCode){
    printclr(crlfInteractions,4);
    print(outputShellCode);
    //print(crlfInteractions);
    //*leetAddr="atuamae";
    
    
    //leetAddr=0x1337;
    bufferino = 0x1337;
    free(bufferino,obfStrSize(flagShellCode));
    getFlag(flagShellCode,bufferino);
    //strcpy(leetAddr,flagShellCode);
    
    
    //#https://c9x.me/x86/html/file_module_x86_id_280.html
    //this is tightly connected to the addresses in memory// since bootloader reads 16 sectors, thins funcrion will write on 20th sector, which is free, along with sector 17,18,19
    //read funcion has static addresses on the code
    //jmp and push addresses are relative to CS
    #asm
    push    bp
    mov     bp, sp
    push    di
    push    si
    #endasm
      
   #asm
    //mov ax,#skip
    //sub ax,#0x7e00
    //push ax
    mov ax,#callOffset
    call ax
    skip:
    nop
    #endasm
      
    #asm
    pop     si
    pop     di
    pop     bp
    #endasm
  free(bufferino,obfStrSize(flagShellCode));
  }
  else{ //user ctrl+c; exit
    return;
  }
    //wait for the user to see the outputShellCode
    print(crlfInteractions);
    anyKey();
}

void contactHackingTeam(){
  cls();
  printclr(contactRui,4);
  printclr(crlfInteractions,4);
  anyKey();
}

void printKonami(){
  bufferino = 0x7c00;
  free(bufferino,obfStrSize(flagKONAMI));
  
  deobfStr(flagKONAMI+2+(strlen(codeKONAMI)*2),obfStrSize(flagKONAMI),codeKONAMI,strlen(codeKONAMI)*2,bufferino);
  
  //getFlag(flagKONAMI,bufferino);
  print(bufferino);
  
  free(bufferino,obfStrSize(flagKONAMI));
  print(crlfInteractions);
  anyKey();
}

void getCodeKonami(c)char *c;{
  strcpy(c,codeKONAMI);
}
