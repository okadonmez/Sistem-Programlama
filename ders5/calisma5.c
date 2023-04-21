#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char *argv[]){

    if(argc != 3){

        printf("Sadece 2 tane dosya ismi yazmalisiniz!");

        exit(-1);
    }

    char metin_1[40]= "Bu dosya hem okunabilir hem yazýlabilir.";
    char metin_2[34]= "Uyarý: Bu dosya sadece okunabilir.";

    int dosya_1 = _open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
    int dosya_2 = _open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);

    int n;

    if(dosya_1 < 0)
    {
        printf("1. Dosya olusturulamadi!\n");

        exit(-2);
    }

    if(dosya_2 < 0)
    {
        printf("2. Dosya olusturulamadi! (Salt okunur, ustune yazamazsin)\n");

        exit(-2);
    }

    _write(dosya_1,&metin_1,sizeof(metin_1));
    _write(dosya_2,&metin_2,sizeof(metin_2));

    if (chmod(argv[2],_S_IREAD) < 0)
    {
        printf("2. Dosyanin modu degistirilemedi!\n");

        exit(-3);
    }

    _close(dosya_1);
    _close(dosya_2);

    return 0;
}
