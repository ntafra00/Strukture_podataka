#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct polinom *position;

struct polinom
{
    int koef;
    int eksponent;
    position next;
};

int readFromFile(char[], position *);        // funckija koja cita podatke iz datoteke
int addPoly(position, position);             // funkcija koja zbraja polinome
int multiplyPoly(position, position);        // funkcija koja mnozi
int printList(position);                     // funkcija koja ispisuje sadrzaj liste
bool List(position);                         // funkcija koja provjerava je li lista prazna
int addOnTheBeggining(position *, int, int); // funkcija koja dodaje na pocetak liste
int add(position, int, int);                 // funkcija koja dodaje na odredeno mjesto
int deleteEntireList(position *);            // funkcija koja brise kompletan sadrzaj liste