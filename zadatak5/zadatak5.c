#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *position;

struct node
{
    int value;
    position next;
};

int addOnTheBeggining(position *, int); // dodavanje elementa na pocetak liste
int add(position *, int);               // dodavanje elementa
int printList(position);                // ispis liste
int unija(position, position);          // funkcija koja trazi uniju dviju lista
int presjek(position, position);        // funkcija koja trazi presjek dviju lista
position deleteEntireList(position);    // funckija koja kompletno brise listu
int insertElements(position *);         // funkcija za unos elemenata u listu

int main()
{
    position head1 = NULL;
    position head2 = NULL;

    printf("PRVA LISTA:\n");

    insertElements(&head1);

    printf("DRUGA LISTA:\n");

    insertElements(&head2);

    unija(head1, head2);

    presjek(head1, head2);

    head1 = deleteEntireList(head1);
    head2 = deleteEntireList(head2);

    return 0;
}

int insertElements(position *head_ref)
{
    char choice;
    int flag = 0;
    int broj;

    while (flag == 0)
    {
        printf("n - novi element, k - kraj unosa: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'n':
            printf("\nUpisite broj: ");
            scanf(" %d", &broj);
            add(head_ref, broj);
            break;
        case 'k':
            flag = 1;
            break;
        default:
            printf("\nGreska pri unosu! \n");
            break;
        }
    }
}

int addOnTheBeggining(position *head_ref, int broj)
{
    position ptr = NULL;

    ptr = (position)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("Problem with allocated memory!");
        return -1;
    }

    ptr->value = broj;

    ptr->next = *head_ref;
    *head_ref = ptr;

    return 0;
}

int add(position *head_ref, int broj)
{
    position temp = NULL;
    position ptr = *head_ref;

    temp = (position)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Problem with allocated memory!");
        return -1;
    }

    if ((ptr == NULL) || (broj < ptr->value))
    {
        addOnTheBeggining(head_ref, broj);
    }
    else
    {
        while (ptr->next != NULL && ptr->next->value < broj)
        {
            ptr = ptr->next;
        }

        temp->value = broj;
        temp->next = ptr->next;
        ptr->next = temp;
    }

    return 0;
}

int printList(position head_ref)
{
    while (head_ref != NULL)
    {
        printf("%d\t", head_ref->value);
        head_ref = head_ref->next;
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

    return head_ref;
}

int unija(position list1, position list2)
{
    position unija = NULL;
    position ptr1 = list1;
    position ptr2 = list2;

    while ((ptr1 != NULL) && (ptr2 != NULL))
    {
        if (ptr1->value < ptr2->value)
        {
            add(&unija, ptr1->value);
            ptr1 = ptr1->next;
        }
        else if (ptr2->value < ptr1->value)
        {
            add(&unija, ptr2->value);
            ptr2 = ptr2->next;
        }

        else
        {
            add(&unija, ptr1->value);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            add(&unija, ptr2->value);
            ptr2 = ptr2->next;
        }
    }

    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            add(&unija, ptr1->value);
            ptr1 = ptr1->next;
        }
    }

    printf("\nUNIJA: ");
    printList(unija);

    unija = deleteEntireList(unija);

    return 0;
}

int presjek(position list1, position list2)
{
    position presjek = NULL;
    position ptr1 = list1;
    position ptr2 = list2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->value < ptr2->value)
        {
            ptr1 = ptr1->next;
        }
        else if (ptr1->value == ptr2->value)
        {
            add(&presjek, ptr1->value);

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else
        {
            ptr2 = ptr2->next;
        }
    }

    printf("\nPRESJEK: ");
    printList(presjek);

    presjek = deleteEntireList(presjek);
}
