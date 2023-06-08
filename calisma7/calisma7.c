#include<stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){

    //"C:\Users\OGUZ\Desktop\Odevlerim\3.Sinif\Sistem_Programlama\ders11"

    if (argc != 2)
    {
        printf("Sadece 1 tane dosya yolu girilmelidir!\n");

        exit(-1);
    }

    struct stat filestat;

    DIR *dp;

    if ((dp = opendir(argv[1])) == NULL)
    {
        printf("Dosya yolu bulunamadi!\n");

        exit(-2);
    }

    struct dirent *dirp;

    int klasor_sayaci = 0;
    int dosya_sayaci = 0;

    while((dirp = readdir(dp)) != NULL)
    {
        if (stat(dirp -> d_name, &filestat) < 0)
        {
            printf("%s adinda bir dosya veya klasor bulunamadi!\n", dirp -> d_name);

            exit(-3);
        }

        if (S_ISREG(filestat.st_mode))
        {
            dosya_sayaci++;
        }
        else if (S_ISDIR(filestat.st_mode))
        {
            klasor_sayaci++;
        }
        else
        {
            dosya_sayaci++;
        }
    }

    printf("Incelenen klasor: %s\n", argv[1]);
    printf("Bu klasorde toplam %d normal dosya, %d klasor mevcut.\n", dosya_sayaci, klasor_sayaci - 2);

    closedir(dp);
}
