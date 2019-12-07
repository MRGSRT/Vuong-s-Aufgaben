#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"
 
int main(){
    printf("Hallo Benutzer, Ich verwalte Ihre Teilnehmerliste.\n\n");
    struct Teilnehmer Informationen [100] = {
            {"Horst", "Hode", "Schneidermeister", 0},
            {"Roman", "Rohrfrei", "Wasserinstallateur", 0},
            {"Paula", "Planlos", "Architektin", 0},
            {"Armin", "Gips", "Stuntman", 0},
            {"Nora", "Notfall", "Nachtschwester", 0},
            {"Stella", "Standup", "Fitnesstrainerin", 0}
    };

    init(Informationen);
    menu(Informationen);
      
    return 0;
}
