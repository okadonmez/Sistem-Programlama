#include <stdio.h>

int main(int argc, char *argv[])
{
    //Sorular => sayi_1 islem sayi_2 kalibina uygun olarak yazilmalidir!

    if(argc != 2)
    {
        printf("Sadece 1 dosya ismi girmelisiniz!");

        exit(-1);
    }

    FILE *soru_dosyasi = fopen(argv[1], "r");

	if(soru_dosyasi == NULL)
	{
		printf("Dosya acilamadi!\n");

        exit(-2);
	}

	FILE *cevap_dosyasi = fopen("cevaplar.txt", "w");

	if(cevap_dosyasi == NULL)
	{
		printf("Dosya acilamadi!\n");

        exit(-3);
	}

    char dosya_satir_uzunlugu[100];
    char isaret;

    int sayi_1 = 0;
    int sayi_2 = 0;
    int sonuc = 0;

	while (fgets(dosya_satir_uzunlugu, sizeof(dosya_satir_uzunlugu), soru_dosyasi) != NULL)
    {
        if (sscanf(dosya_satir_uzunlugu, "%d %c %d", &sayi_1, &isaret, &sayi_2) == 3)
        {
            if(isaret == '+')
            {
                sonuc = sayi_1 + sayi_2;

                fprintf(cevap_dosyasi, "%d\n", sonuc);
            }
            else if(isaret == '-')
            {
                sonuc = sayi_1 - sayi_2;

                fprintf(cevap_dosyasi, "%d\n", sonuc);
            }
            else if(isaret == '*')
            {
                sonuc = sayi_1 * sayi_2;

                fprintf(cevap_dosyasi, "%d\n", sonuc);
            }
            else if(isaret == '/')
            {
                sonuc = sayi_1 / sayi_2;

                fprintf(cevap_dosyasi, "%d\n", sonuc);
            }
        }
    }

	fclose(soru_dosyasi);
	fclose(cevap_dosyasi);

	exit(0);
}
