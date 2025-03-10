#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

int benv = 0;

int main() {
    int tent = 0, N_utente = 0, N_codice, MAX;
    int MIN = 1;
    char verifica[99], riavvio[99];

    if (benv == 0) {
        printf("Benvenuti a The Number Decider!\n");
        Sleep(1011);
    }

    printf("Per cominciare scrivere il range di numeri in cui si trova il numero scelto da voi, da 1 a? ");
    scanf("%d", &MAX);
    Sleep(1000);
    printf("In base ai tentativi, rispondere adeguatamente con maggiore, minore o giusto.");
    Sleep(1500);
    printf("Tutto pronto per l'inizio!\n");
    Sleep (900);
    srand(time(0));

    do {
        tent++;
        N_codice = rand() % (MAX - MIN + 1) + MIN;
        printf("Tentativo numero %d, il numero che rapporto ha con %d? ", tent, N_codice);
        scanf("%s", verifica);

        if (strcmp(verifica, "Maggiore") == 0 || strcmp(verifica, "maggiore") == 0) {
            printf("\nCavolo, quindi il numero e' maggiore, riprovo!\n");
            MIN = N_codice + 1;
        } else if (strcmp(verifica, "Minore") == 0 || strcmp(verifica, "minore") == 0) {
            printf("\nCavolo, quindi il numero e' minore, riprovo!\n");
            MAX = N_codice - 1;
        } else if (strcmp(verifica, "Giusto") == 0 || strcmp(verifica, "giusto") == 0) {
            printf("\nBene, ho indovinato in %d tentativi!\n\n", tent);
            N_utente = 1;
        }
    } while (N_utente != 1);

    printf("Il gioco e' finito, lo volete riavviare? ");
    scanf("%s", riavvio);

    if (strcmp(riavvio, "Si") == 0 || strcmp(riavvio, "si") == 0) {
        benv = 1;
        system("cls");
        main();
    } else {
        printf("Grazie di aver giocato!");
        Sleep(4000);
    }

    return 0;
}
