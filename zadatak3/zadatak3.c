#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funkcije.h"
#define MAX 256

typedef struct osoba *position;

struct osoba
{
    char ime[MAX];
    char prezime[MAX];
    int godRodenja;
    position next;
};

// --------- FUNKCIJE ZA TRECI ZADATAK ---------

int addBefore(position *);                // funkcija koja dodaje element prije odgovarajuceg elementa
int addAfter(position);                   // funckija koja dodaje element iza odgovarajuceg elementa
int sortElements(position *);             // funkcija koja sortira listu po prezimenu
int printListInFile(position, char[]);    // funckija koja ispisuje listu u datoteku
int readListFromFile(char[], position *); // funkcija koja ucitava listu iz datoteke
int choose(position *);

int main()
{
    position head = NULL;

    readListFromFile("ulaz.txt", &head);

    printList(head);

    printf("\n");

    choose(&head);

    printListInFile(head, "izlaz.txt");

    head = deleteEntireList(head);

    return 0;
}

int choose(position *head_ref)
{
    char choice;
    int flag;

    while (flag != 1)
    {
        printf("n - umetanje elementa nakon, p - umetanje elementa prije, s - sortiranje liste, k - kraj:");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'p':
            addBefore(head_ref);
            break;
        case 'n':
            addAfter(*head_ref);
            break;
        case 's':
            sortElements(head_ref);
            printf("Lista je sortirana!\n");
            break;
        case 'k':
            flag = 1;
            break;
        default:
            printf("Greska pri unosu.\n");
            break;
        }
    }

    return 0;
}

int printListInFile(position head_ref, char fileName[])
{
    FILE *fptr = NULL;
    position ptr = head_ref;

    fptr = fopen(fileName, "w");

    if (fptr == NULL)
    {
        printf("Error! File not opened");
        return -1;
    }

    while (ptr != NULL)
    {
        fprintf(fptr, "%-15s\t%-15s\t%-5d\n", ptr->ime, ptr->prezime, ptr->godRodenja);
        ptr = ptr->next;
    }

    fclose(fptr);
    free(ptr);

    return 0;
}

int addBefore(position *head_ref)
{
    position ptr = *head_ref;
    position temp = NULL;

    char niz[30];

    printf("Unesite prezime elementa prije kojeg zelite ubaciti novi element: ");
    scanf(" %s", niz);

    if (strcmp(ptr->prezime, niz) == 0)
    {
        addOnBeggining(head_ref);
    }
    else
    {
        ptr = findPreviousElement(*head_ref, niz);

        if (ptr == NULL)
        {
            return -1;
        }

        temp = (position)malloc(sizeof(struct osoba));

        if (temp == NULL)
        {
            return -1;
        }

        unesiPodatke(temp);

        temp->next = ptr->next;

        ptr->next = temp;
    }

    return 0;
}

int addAfter(position head_ref)
{
    position temp = NULL;
    position ptr = NULL;

    char niz[30];

    printf("Unesite prezime elementa nakon kojeg zelite ubaciti novi element: ");
    scanf(" %s", niz);

    ptr = findElement(head_ref, niz);

    if (ptr == NULL)
    {
        return -1;
    }

    temp = (position)malloc(sizeof(struct osoba));

    if (temp == NULL)
    {
        printf("Error!");
        return -1;
    }

    unesiPodatke(temp);

    temp->next = ptr->next;
    ptr->next = temp;

    return 0;
}

int sortElements(position *head_ref)
{
    position curr;

    curr = (position)malloc(sizeof(struct osoba));

    curr->next = *head_ref;
    *head_ref = curr;

    position pointer = *head_ref;

    position ptr, prev_ptr, temp, end;

    end = NULL;

    while (pointer->next != end)
    {
        prev_ptr = pointer;
        ptr = pointer->next;
        while (ptr->next != end)
        {
            if (strcmp(ptr->prezime, ptr->next->prezime) > 0)
            {
                temp = ptr->next;
                prev_ptr->next = temp;
                ptr->next = temp->next;
                temp->next = ptr;

                ptr = temp;
            }

            prev_ptr = ptr;
            ptr = ptr->next;
        }
        end = ptr;
    }

    deleteFirstNode(head_ref);
}
int readListFromFile(char fileName[], position *head_ref)
{
    FILE *fptr = NULL;

    fptr = fopen(fileName, "r");

    if (fptr == NULL)
    {
        printf("Error!");
        return -1;
    }

    while (!feof(fptr))
    {
        if (*head_ref == NULL)
        {

            position ptr = NULL;
            ptr = (position)malloc(sizeof(struct osoba));
            if (ptr == NULL)
            {
                perror("Problem with allocated memory!");
                return -1;
            }

            fscanf(fptr, "%s %s %d", ptr->ime, ptr->prezime, &ptr->godRodenja);

            ptr->next = *head_ref;
            *head_ref = ptr;
        }
        else
        {
            position ptr = *head_ref;
            position temp = NULL;

            temp = (position)malloc(sizeof(struct osoba));
            fscanf(fptr, "%s %s %d", temp->ime, temp->prezime, &temp->godRodenja);

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            temp->next = ptr->next;
            ptr->next = temp;
        }
    }

    fclose(fptr);

    return 0;
}
