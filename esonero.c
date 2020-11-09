#include <stdio.h>
#include <string.h>
#include <stdlib.h> // includere per utillizzare rand() e srand()
#include <time.h> // includere per utilizzare time()

int main(void)
{
  char m[128], k[128], c[128], decrip[128];
  int scelta, i;
  time_t t;
  srand((unsigned) time(&t));
  printf("Dammi una stringa da cifrare: " );
  fgets(m,128, stdin); // controlla che la lunghezza max di m sia di 128 posizioni
  scelta=0;

    while(scelta!=1 && scelta!=2)
  {
   printf("Ora può scegliere tra 2 opzioni:\nDigitare 1 per inserire la chiave manualmente\nDigitare 2 per generare la chiave in modalità random\n");
   fflush(stdin); // pulisce cartatteri rimasti nel buffer
   scanf("%d", &scelta);
     if (scelta!=1 && scelta!=2) {printf("scelta errata, reinserire\n" );}

  }

  switch (scelta)
  {
    case 1: // inserisci la chiave manualmente
    printf("inserire la chiave: " );
    fgets(k,128, stdin);
    do
    {
      fgets(k,128, stdin);
      if (strlen (k) < strlen (m) ) {printf("la chiave è troppo corta\nreinserire la chiave: " );}

    } while(strlen (k) < strlen (m));

    case 2: // genera la chiave random
    printf("la chiave è: " );
    for (i= 0; i < strlen(m)-1; i++)
    {
      k[i]=rand() %128; //genera un numero random
      printf("%x",k[i] ); // stampa in esadecimale per evitare i caratteri "particolari"
    }
      printf("\n");

    printf("la stringa criptata è: " );
    for (i=0; i < strlen(m)-1; i++)
    {
      c[i]=m[i]^k[i];
      printf("%x", c[i] );
    }
    printf("\n" );

    printf("la stringa decriptata è: " );
    for (i = 0; i < strlen(m)-1; i++)
    {
      decrip[i]=c[i]^k[i];
      printf("%c",decrip[i] ); // stampa in formato char
    }
    printf("\n");
  }
}
