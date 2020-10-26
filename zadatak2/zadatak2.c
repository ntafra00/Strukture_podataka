#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 256

typedef struct osoba *position;

struct osoba
{
    char ime[MAX];
    char prezime[MAX];
    int godRodenja;
    position next;
};

position addOnBeggining(position);              // funkcija koja dodaje element na početak liste
int printList(position);                        // funkcija koja ispisuje listu
int addOnTheEnd(position);                      // funkcija koja upisuje element na kraj liste
position findElement(position, char[]);         // funkcija koja pronalazi element po prezimenu
position findPreviousElement(position, char[]); // funckija koja pronalazi prethodni element
int unesiPodatke(position);                     // funkcija za unos podataka za pojedinu osobu
int deleteNodeFromList(position *);             // funkcija koja brise element iz liste
position deleteEntireList(position);            // funckija koja brise kompletni sadrzaj liste
int deleteFirstNode(position *);                // funkcija koja brise prvi element

int main()
{
    position head = NULL;

    head = addOnBeggining(head);

    //addOnTheEnd(head);

    addOnTheEnd(head);

    addOnTheEnd(head);

    printf("\n");

    printList(head);

    deleteNodeFromList(&head);

    printf("\n");

    printList(head);

    head = deleteEntireList(head);

    free(head);

    return 0;
}
