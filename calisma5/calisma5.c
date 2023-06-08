#include <stdio.h>

int main(int argc, char *argv[])
{
    int c;
    int n;

    int sesli_harf_sayisi = 0;
    int sessiz_harf_sayisi = 0;
    int toplam_harf_sayisi = 0;
    int kelime_sayisi = 0;
    int cumle_sayisi = 0;

    if(argc != 2)
	{
		printf("Sadece 1 input girmelisiniz!\n");

		exit(-1);
	}

	FILE *okunandosya = fopen(argv[1], "r");

	if(okunandosya == NULL)
	{
		printf("Dosya acilamadi!\n");

		exit(-2);
	}

    char hedefdosya[50];

    if(n = sprintf(hedefdosya, "sonuçlar.txt") < 0)
    {
        printf("Write hatasi!\n");

        exit(-3);
    }

	FILE *outfile = fopen(hedefdosya, "w");

	if(outfile == NULL)
	{
		printf("Dosya acilamadi!\n");

		exit(-4);
	}

	while((c = getc(okunandosya)) != EOF)
	{
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O')
        {
            sesli_harf_sayisi++;
        }
        else if(c == '.' || c == '?' || c == '!')
        {
            cumle_sayisi++;
        }
        else if(c == ' ')
        {
            kelime_sayisi++;
        }
        else
        {
            sessiz_harf_sayisi++;
        }
	}

    if(ferror(okunandosya))
    {
        printf("Read hatasi!\n");

        exit(-5);
    }

	fclose(okunandosya);
	fclose(outfile);

	outfile = fopen(hedefdosya, "w");

    toplam_harf_sayisi = sesli_harf_sayisi + sessiz_harf_sayisi;
    kelime_sayisi++;

    if(n = fprintf(outfile, "Sesli harf sayisi: %d\nSessiz harf sayisi: %d\nToplam harf sayisi: %d\nKelime sayisi: %d\nCumle sayisi: %d\n", sesli_harf_sayisi, sessiz_harf_sayisi, toplam_harf_sayisi, kelime_sayisi, cumle_sayisi) < 0)
    {
        printf("Write hatasi\n");

        exit(-6);
    }

    fclose(outfile);

	exit(0);
}
