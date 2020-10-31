#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DONJA_GRANICA 10
#define GORNJA_GRANICA 100

typedef struct node *position;

struct node
{
    int number;
    position next;
};

int Push(position *);          // funkcija koja ubacuje element na pocetak vezane liste
int Pop(position *);           // funckija koja izbacuje element sa pocetka vezane liste
int printList(position);       // funkcija koja ispisuje sadrzaj liste
int deleteList(position *);    // funckija koja brise cijelu listu
int PopFromTheEnd(position *); // funkcija koja izbacuje zadnji element iz liste
int stack(position *);
int queue(position *);

int main()
{
    srand(time(NULL));

    position head = NULL;

    stack(&head);

    queue(&head);

    return 0;
}

int stack(position *head_ref)
{
    int flag = 0;
    char choice;

    printf("SIMULIRANI RAD STOGA:\n\n");

    while (flag == 0)
    {
        printf("\nu - novi element, p - izbacivanje elementa, k - kraj: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'u':
            Push(head_ref);
            printList(*head_ref);
            break;
        case 'p':

            if (*head_ref == NULL)
            {
                printf("Lista je prazna! Unesite u za novi element ili k za kraj");
                break;
            }

            Pop(head_ref);

            printList(*head_ref);

            break;
        case 'k':
            flag = 1;
            break;
        default:
            printf("Greska pri unosu!");
            break;
        }
    }

    deleteList(head_ref);

    return 0;
}

int queue(position *head_ref)
{
    char choice;
    int flag = 0;

    printf("\nSIMULIRANI RAD REDA:\n");

    while (flag == 0)
    {
        printf("\nu - novi element, p - izbacivanje elementa, k - kraj: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'u':
            Push(head_ref);
            printList(*head_ref);
            break;
        case 'p':

            if (*head_ref == NULL)
            {
                printf("Lista je prazna! Unesite u za novi element ili k za kraj");
                break;
            }

            PopFromTheEnd(head_ref);

            printList(*head_ref);

            break;
        case 'k':
            flag = 1;
            break;
        default:
            printf("Greska pri unosu!");
            break;
        }
    }

    deleteList(head_ref);

    return 0;
}

int Push(position *head_ref)
{
    position temp = NULL;

    temp = (position)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Problem with memory allocation");
        exit(1);
    }

    temp->number = (DONJA_GRANICA + rand() % (GORNJA_GRANICA - DONJA_GRANICA));

    temp->next = *(head_ref);
    *head_ref = temp;

    return 0;
}

int printList(position head_ref)
{
    position ptr = head_ref;

    while (ptr != NULL)
    {
        printf("%d\t", ptr->number);
        ptr = ptr->next;
    }

    return 0;
}

int Pop(position *head_ref)
{
    position current = *head_ref;

    *head_ref = current->next;

    free(current);

    return 0;
}

int deleteList(position *head_ref)
{
    position current = *head_ref;

    while (current != NULL)
    {
        current = current->next;
        free(*head_ref);
        *head_ref = current;
    }

    return 0;
}

int PopFromTheEnd(position *head_ref)
{
    position previous = *head_ref;
    position current = *head_ref;

    if (current->next == NULL)
    {
        Pop(head_ref);
    }

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;

    free(current);

    return 0;
}
