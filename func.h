#pragma once
#include <stdio.h>

/*Datentyp struktur eines mitgliedes*/
typedef struct{
	int rank;
	char *name;
	char *role;
	int donate;
	int received;
	int aktiv_rank;
}member_t;


/*liest alle mitglieder der csv datei
 * die Datei muss als komandozeilenparameter übergeben werden*/
void members_read(FILE *infile, member_t mitglied[], int *i);

/*fuegt dem mitgliederarray ein mitglied hinzu*/
void member_add(char linebuf[], member_t mitglied[], int *i);

/*gibt die mitgliederliste aus*/
void member_list_print(member_t mitglied[],const int i);

/*gibt ein mitglied der liste aus*/
void member_print(const member_t *m);

/*zeigt alle mitglieder die weniger als 100 spenden haben
 * und liefert die anzahl von denen zurück*/
int no_donate(member_t mitglied[], const int i);
