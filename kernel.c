#include "all.h"
#include "kernel_strinzadas.h"
//display /20i ($cs*16)+$pc
//print ($cs<<4)+$eip
//https://jbwyatt.com/253/emu/8086_bios_and_dos_interrupts.html#int10h_07h
//http://www.ee.hacettepe.edu.tr/~alkar/ELE336/w5-hacettepe[2016].pdf
//https://gist.github.com/MatanShahar/1441433e19637cf1bb46b1aa38a90815
//http://3zanders.co.uk/2017/10/16/writing-a-bootloader2/

void main();
void entrypoint() {
  main();
}

void main() {
  
  
  clearBootloader();
  

  cls();
  SkullBanner();
  delay();
  delay();
  delay();
  delay();

  cls();
  rootLogin();

  
  //progess bar
  cls();

  printProgress();

    while (1) {
        cls();
        mainmenu();
    }

}



