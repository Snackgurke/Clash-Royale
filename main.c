#include "func.h"
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char *argv[]) {
	system("clear");

    /*USAGE MELDUNG*/
    if (argc !=2) printf("***USAGE: ./prog members.txt");

    /*VARIABLEN*/
    member_t members[50];
    int counter = 0;
    int donator=0;

    /*DATEI ÖFFNEN & AUSLESEN*/
    FILE *infile;
    infile = fopen(argv[1],"r");
    if (infile == NULL) {
        fprintf(stderr,"ERROR: Datei %s geht nicht!\n",argv[1]);
        return EXIT_FAILURE;
    }
    members_read(infile,members,&counter);
    fclose(infile);

    /*KONTROLL MELDUNG*/
    printf("Aktuell sind %d Mitglieder in deinem Clan!\n",counter);

    /*ANZ. DER WENIGSPENDER + AUSGABE*/
    donator = no_donate(members,counter);
    printf("%d Mitglieder haben unter 100 Spenden!\n",donator);


    return 0;
}
