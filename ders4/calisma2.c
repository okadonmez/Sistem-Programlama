#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
//#include <io.h>
//#include <unistd.h>

#include <stdio.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define OKUNACAK_BYTE_SAYISI 1000

int main(int argc, char *argv[]){

    if(argc != 2){

        printf("Sadece 1 tane dosya ismi yazmalisiniz!");

        exit(-1);
    }

    int mevcut_dosya_belirteci = _open(argv[1], O_RDONLY, FILE_MODE);

    if(mevcut_dosya_belirteci < 0)
	{
		printf("Boyle bir dosya bulunmuyor!");

		exit(-2);
	}

    int text_dosya_belirteci = _open("metin_sesli_harfsiz.txt", O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);

    char yazilacak_veriler[OKUNACAK_BYTE_SAYISI];

    int bayt_sayisi;

    if((bayt_sayisi = _read(mevcut_dosya_belirteci, yazilacak_veriler, OKUNACAK_BYTE_SAYISI)) > 0)
	{
        for (int i = 0 ; i < bayt_sayisi; i++)
        {
            if(yazilacak_veriler[i] != 'a' && yazilacak_veriler[i] != 'A' &&
               yazilacak_veriler[i] != 'i' && yazilacak_veriler[i] != 'I' &&
               yazilacak_veriler[i] != 'o' && yazilacak_veriler[i] != 'O' &&
               yazilacak_veriler[i] != 'e' && yazilacak_veriler[i] != 'E' &&
               yazilacak_veriler[i] != 'u' && yazilacak_veriler[i] != 'U')
            {
               _write(text_dosya_belirteci, &yazilacak_veriler[i], 1);
            }
        }
	}

    _close(text_dosya_belirteci);
    _close(mevcut_dosya_belirteci);

    return 0;
}
