#include "func.h"
#include <string.h>
#include <stdlib.h>

/*-------------------------------------------------------------*/
void members_read(FILE *infile, member_t mitglied[], int *i) {
    enum {MAXLL =240};
    char linebuf[MAXLL];

    fgets(linebuf, sizeof(linebuf),infile); /*Kopfzeile überlesen*/

    while (fgets(linebuf,sizeof(linebuf),infile)) {
        /*zeilenlaenge absichern */

        if(linebuf[strlen(linebuf)-1] != '\n') { //zeile zulang
            fprintf(stderr," *** Hinweis: Zeile zu lang\n");
            fprintf(stderr,"Zeile ignoriert:\n *** > %s...<\n",
                    linebuf);
        }
        /*mitglied dem array hinzufuegen*/
        member_add(linebuf,mitglied,i);
    }
}

/*-------------------------------------------------------------*/
void member_add(char linebuf[], member_t mitglied[],int *i) {

    const char *delim = ",\n"; /*trennzeichen + NL*/

    mitglied[*i].rank       = atoi(strdup(strtok(linebuf, delim)));
    mitglied[*i].name       = strdup(strtok(NULL,delim));
    mitglied[*i].role       = strdup(strtok(NULL,delim));
    mitglied[*i].donate	    = atoi(strdup(strtok(NULL,delim)));
    mitglied[*i].received   = atoi(strdup(strtok(NULL,delim)));
    mitglied[*i].aktiv_rank = atoi(strdup(strtok(NULL,delim)));
    (*i)++;

}

/*----------------------------------------------------------*/
void member_list_print(member_t mitglied[], const int i) {

    int n;

    printf("Rank: %-20s | Donations | Aktiv-Rank\n","Mitglied");
    printf("-------------------------------------------------\n");

    for(n = 0; n < i; n++) {
        member_print(&(mitglied[n]));

    }

}


/*----------------------------------------------------------*/
void member_print(const member_t *m) {

    printf("(%2d): %-20s | %5d | %3d\n",
           m->rank, m->name, m->donate, m->aktiv_rank);

}

/*----------------------------------------------------------*/
int no_donate(member_t mitglied[],const int i) {
    int anz=0;

    for(int n=0; n < i; n++) {
        if(mitglied[n].donate <= 100) {
            member_print(&(mitglied[n]));
            anz++;
        }

    }
    return anz;

}
/*----------------------------------------------------------*/
