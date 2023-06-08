#include <stdio.h>

#define PARAMETRE_SAYISI 5 //argc[0] + 4 tane girdi

int main(int argc, char *argv[]){

    int i = 1;

    if(argc < PARAMETRE_SAYISI){

        printf("Eksik parametre girildi! Girdiginiz parametre sayisi = %d\nKullanim Sekli: %s %d tane parametre\n", (argc - 1), argv[0], (PARAMETRE_SAYISI - 1));

        exit(-1);
    }
    else if(argc > PARAMETRE_SAYISI) {

        printf("Fazla parametre girildi! Girdiginiz parametre sayisi = %d\nKullanim Sekli: %s %d tane parametre\n", (argc - 1), argv[0], (PARAMETRE_SAYISI - 1));

        exit(-2);
    }
    else{

        printf("Calistirilan program: %s\n", argv[0]);

        while(i < PARAMETRE_SAYISI){

            printf("%d. parametre: %s\n", i, argv[i]);

            i++;
        }
    }

    printf("Program sorunsuz bir sekilde kapaniyor...");
    exit(0);
}
