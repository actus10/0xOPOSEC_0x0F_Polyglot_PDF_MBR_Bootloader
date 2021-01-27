#include "all.h"
#include "stringzadas_menu.h"

int mainmenulst[] = {
        'o', opoleaksTxt, opoleaks,
        'f', xmasFlagTxt, xmas,
        'v', vaultTxt, vault,
        'g', glitchTxt, shellCodeGlitch,
        'h', helpTxt, contactHackingTeam,
        0x0000
};


void printmenulst(list)
        int *list;
{
    int i = 0;
    while (list[i]) {
        printchclr((char) list[i++], 2);
        printclr(slashslash, 2);
        printclr(list[i++], 2);
        print(crlfMenu);
        i++; // Skip the pointer.
    }
    print(crlfMenu);
}


char charKONAMI;
int indexzadas;
void mainmenu() {
    printOpoterm();
    print(crlfMenu);
    print(crlfMenu);
    print(crlfMenu);
    print(crlfMenu);
    printmenulst(mainmenulst);
    
    charKONAMI=0;
    indexzadas=0;
    getCodeKonami(auxCodeKONAMI);
    while (1) {
        //printch('x');
        charKONAMI=isThereKey();
        if (!charKONAMI) { continue; }
        
        //printhex(charKONAMI);
        if (charKONAMI == auxCodeKONAMI[indexzadas]) {
          indexzadas++;      
        }
        else {
          
          break;
        }
        
        if (indexzadas == strlen(auxCodeKONAMI)) {
            printKonami();
            return;
        }
    }
    
    switch (charKONAMI) {
        case 'o':
            opoleaks();
            break;
        case 'f':
            xmas();
            break;
        case 'v':
            vault();
            break;
        case 'g':
            shellCodeGlitch();
            break;
        case 'h':
          contactHackingTeam();
          break;
        default:
            return;
            //print("Unsupported function.\r\n");
    }
}


