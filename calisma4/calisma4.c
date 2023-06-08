#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char *argv[]){

    if(argc != 2)
    {
        printf("Sadece 1 dosya ismi girmelisiniz!");

        exit(-1);
    }

    int dosya = _open(argv[1], O_RDONLY, FILE_MODE);

    if(dosya < 0)
    {
        printf("Dosya acilamadi, dosyanin mevcut oldugundan emin olunuz!\n");

        exit(-2);
    }

    char buffer[1024];

    int byte_sayisi;
    int kelime_sayisi = 0;
    int cumle_sayisi = 0;
    int char_sayisi = 0;

    int okumaya_basla = 0;

    if((byte_sayisi = _read(dosya, buffer, sizeof(buffer))) > 0)
	{
        for (int i = 0 ; i < byte_sayisi; i++)
        {
            //Eger metinde paragraf varsa ilk bosluklari kelime olarak sayar.
            //Engel olmak icin izin verilmeli ve ilk char gordugunde okumaya baslamali.
            if(buffer[i] != ' ')
            {
                okumaya_basla = 1;
            }

            //Eger yanyana birden fazla bosluk varsa veya bosluktan sonra
            //noktalama isareti konulmussa bunu duzelterek kelime sayisini sayar
            if(buffer[i] == ' ' && buffer[i+1] != ' ' && buffer[i+1] != '.' &&
               buffer[i+1] != '!' && buffer[i+1] != '?')
            {
                if(okumaya_basla == 1)
                {
                    kelime_sayisi++;
                }
            }

            //Cumleleri sayar. Virgul ile ayrilmis sirali cumleleri ihmal eder
            if(buffer[i] == '.' || buffer[i] == '!' || buffer[i] == '?')
            {
                cumle_sayisi++;
            }

            //Noktalama isaretlerini ve bosluklari ihmal ederek char sayisini dondurur
            if(buffer[i] != ' ' && buffer[i] != '.' && buffer[i] != ',' && buffer[i] != '!' && buffer[i] != '?')
            {
                char_sayisi++;
            }
        }

        printf("Dosya toplam %d bayttir.\n", byte_sayisi);
        printf("Dosyada toplam %d kelime bulunmaktadir.\n", kelime_sayisi + 1);
        printf("Dosyada toplam %d cumle bulunmaktadir.\n", cumle_sayisi);
        printf("Dosyada toplam %d tane karekter bulunmaktadir. (Noktalama isaretleri ve bosluklar dahil degildir)\n", char_sayisi);
	}
	else
    {
        printf("Hata, dosya okunamadi!\n");

        exit(-3);
	}

    _close(dosya);

    return 0;
}
