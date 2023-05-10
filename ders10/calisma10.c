#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, j;
    int *bellek;
    int enbuyuk = 0, enkucuk = 0, toplam = 0;

    printf("Dizide kac eleman olacagini giriniz: ");

    scanf("%d", &i);

    bellek = (int*) malloc (i);

    if(bellek==NULL)
    {
        exit(1);
    }

    printf("\nDizinin elemanlarini giriniz (%d tane tam sayi girmelisiniz):\n", i);

    for(n=0; n<i; n++)
    {
        scanf("%d", &j);

        bellek[n] = j;
    }

    printf("\n");

    enbuyuk = bellek[0];
    enkucuk = bellek[0];

    for(n=0; n<i; n++)
    {
        printf("%d. sayi = %d\n", n+1, bellek[n]);

        toplam += bellek[n];

        if(enbuyuk < bellek[n])
        {
            enbuyuk = bellek[n];
        }

        if(enkucuk > bellek[n])
        {
            enkucuk = bellek[n];
        }
    }

    free(bellek);

    printf("\nGirilen sayilarin toplami: %d\n", toplam);
    printf("Girilen en buyuk sayi:  %d\n", enbuyuk);
    printf("Girilen en kucuk sayi: %d\n", enkucuk);

    return 0;
}
