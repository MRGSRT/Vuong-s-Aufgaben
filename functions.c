#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"

void init(struct Teilnehmer * Informationen){
    srand(time(NULL));
    for(int i = 0; i < 6; i++){                          
        Informationen[i].Tischnummer = rand() % 4 + 1;
    }               
}

void update(struct Teilnehmer * Informationen) {
    for(int i = 0; i < 100; i++) {
        if(Informationen[i].Tischnummer == 0) {
            Informationen[i].Tischnummer = rand() % 4 + 1;
            printf("\n");
            printf("Vorname: %s\tNachname: %s\t\tBerufsbezeichnung: %s\tTischnummer: %i\n", Informationen[i].Vorname, Informationen[i].Nachname, Informationen[i].Berufsbezeichnung, Informationen[i].Tischnummer);
            printf("\n");
            return;
        }
    }
}

void ausgabeUnsortiert(struct Teilnehmer * Informationen){
    printf("\n");
    for(int i = 0; i < 100; i++){
        if(Informationen[i].Tischnummer != 0) {
            printf("Vorname: %s\tNachname: %s\t\tBerufsbezeichnung: %s\tTischnummer: %i\n", Informationen[i].Vorname, Informationen[i].Nachname, Informationen[i].Berufsbezeichnung, Informationen[i].Tischnummer);
        }
    }
    printf("\n");
}

void ausgabeSortiert(struct Teilnehmer * Informationen){
    printf("\n");
    for(int q = 1; q < 5; q++) {
        for(int w = 0; w < 100; w++) {
            if( (Informationen[w].Tischnummer == q) && ( Informationen[w].Tischnummer != 0) ) printf("Vorname: %s\tNachname: %s\t\tBerufsbezeichnung: %s\tTischnummer: %i\n", Informationen[w].Vorname, Informationen[w].Nachname, Informationen[w].Berufsbezeichnung, Informationen[w].Tischnummer);
        }
    }
    printf("\n");
}


void neuerTeilnehmer(struct Teilnehmer * Informationen){
    int i;
    for(i = 0; i < 100; i++) {
        if(Informationen[i].Tischnummer == 0) {
            break;
        }
    }
    if(i == 100) {
        fprintf(stderr, "Teilnehmerliste ist voll\n");
        return;
    }
    printf("Geben Sie den Vornamen des neuen Teilnehmers an: ");
    scanf(" %s", Informationen[i].Vorname);
    printf("Geben Sie den Nachnamen des neuen Teilnehmers an: ");
    scanf(" %s", Informationen[i].Nachname);
    printf("Geben Sie die Berufsbezeichnung des neuen Teilnehmers an: ");
    scanf(" %s", Informationen[i].Berufsbezeichnung);
    printf("Ihre Eingaben wurden aktualisiert.\n");
    update(Informationen);
    ausgabeSortiert(Informationen);
}

void menu(struct Teilnehmer * Informationen){
    int Option;

    printf("\nWählen Sie einer der folgenden Option aus und geben Sie die dazugehörige Zahl an, um mit dieser Option fortzufahren.\n");
        printf("Teilnehmer unsortiert anzeigen [1]\nTeilnehmerliste nach Tischen sortiert [2]\nneuen Teilnehmer erfassen [3]\nProgramm beenden [4].\n");
        printf("Geben Sie nun ihre Option (Zahl) ein mit der Sie fortfahren möchten.\n\n\n");
        
        scanf("%d", &Option);
        if(Option == 1){
            ausgabeUnsortiert(Informationen);
            //menu(Informationen);
        }
        else if(Option == 2){
            ausgabeSortiert(Informationen);
            //menu(Informationen);
        }
        else if(Option == 3){
            neuerTeilnehmer(Informationen);
            //menu(Informationen);
        }
        else if(Option == 4){
            printf("Das Programm wird beendet.\n");
            exit(0);
        } else {
            printf("Ihre Eingabe war ungültig, bitte versuchen Sie es erneut.\n");
            //menu(Informationen);
        }
}