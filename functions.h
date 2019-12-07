

struct Teilnehmer{
    char Vorname[81];
    char Nachname[81];
    char Berufsbezeichnung[81];
    int Tischnummer;
};    


void init(struct Teilnehmer * Informationen);
void update(struct Teilnehmer * Informationen);
void ausgabeUnsortiert(struct Teilnehmer * Informationen);
void ausgabeSortiert(struct Teilnehmer * Informationen);
void neuerTeilnehmer(struct Teilnehmer * Informationen);
void menu(struct Teilnehmer * Informationen);