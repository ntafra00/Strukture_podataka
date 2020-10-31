#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funkcije.h"
#define MAX 256

struct osoba
{
    char ime[MAX];
    char prezime[MAX];
    int godRodenja;
    position next;
};

int unesiPodatke(position ptr)
{
    printf("Unesite ime osobe: ");
    scanf(" %s", ptr->ime);

    printf("\nUnesite prezime osobe: ");
    scanf(" %s", ptr->prezime);

    printf("\nUnesite godinu rodenja osobe: ");
    scanf(" %d", &ptr->godRodenja);

    return 0;
}

int addOnTheEnd(position head_ref)
{
    position ptr = head_ref;
    position temp = NULL;

    temp = (position)malloc(sizeof(struct osoba));

    if (temp == NULL)
    {
        printf("Error! Problem with memory allocation.");
        return -1;
    }

    printf("DODAVANJE ELEMENTA NA KRAJ LISTE: \n");

    unesiPodatke(temp);

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;

    return 0;
}

int addOnBeggining(position *head_ref)
{
    position ptr = NULL;

    ptr = (position)malloc(sizeof(struct osoba));

    if (ptr == NULL)
    {
        printf("Error! Problem with memory allocation");
        return -1;
    }

    printf("DODAVANJE ELEMENTA NA POCETAK LISTE: \n");
    unesiPodatke(ptr);

    ptr->next = *head_ref;
    *head_ref = ptr;

    return 0;
}

int printList(position head_ref)
{
    if (head_ref == NULL)
    {
        printf("Linked list is empty!");
    }

    position ptr = head_ref;
    while (ptr != NULL)
    {
        printf("%s %s %d\n", ptr->ime, ptr->prezime, ptr->godRodenja);
        ptr = ptr->next;
    }

    return 0;
}

int deleteNodeFromList(position *head_ref)
{
    position ptr = *head_ref;

    char niz[40];

    printf("Unesite prezime koje zelite izbrisati: ");
    scanf(" %s", niz);

    if (strcmp(ptr->prezime, niz) == 0)
    {
        deleteFirstNode(head_ref);
    }
    else
    {
        position previous = findPreviousElement(*head_ref, niz);

        if (previous == NULL)
        {
            return -1;
        }
        else
        {
            position current = previous->next;
            previous->next = current->next;

            free(current);
        }
    }

    return 0;
}

position findPreviousElement(position head_ref, char prezime[40])
{
    position ptr = head_ref;

    while (ptr->next != NULL)
    {
        if (strcmp(ptr->next->prezime, prezime) == 0)
        {
            break;
        }

        ptr = ptr->next;
    }

    if (ptr->next == NULL)
    {
        printf("Ne postoji element s takvim prezimenon\n");
        return NULL;
    }
    else
    {
        return ptr;
    }
}

position findElement(position head_ref, char prezime[20])
{
    position ptr = head_ref;

    while (ptr != NULL)
    {
        if (strcmp(ptr->prezime, prezime) == 0)
        {
            break;
        }

        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Ne postoji element s takvim prezimenon\n");
        return NULL;
    }
    else
    {
        return ptr;
    }
}

position deleteEntireList(position head_ref)
{
    position temp = head_ref;

    while (temp != NULL)
    {
        temp = temp->next;
        free(head_ref);
        head_ref = temp;
    }

    free(temp);

    return head_ref;
}

int deleteFirstNode(position *head_ref)
{
    position ptr = *head_ref;

    *head_ref = ptr->next;

    free(ptr);

    return 0;
}
