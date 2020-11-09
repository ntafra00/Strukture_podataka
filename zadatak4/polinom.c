#include "polinom.h"

int readFromFile(char fileName[], position *head_ref)
{
    FILE *fptr = NULL;

    fptr = fopen(fileName, "r");

    if (fptr == NULL)
    {
        printf("Error! File not opened!");
        return -1;
    }

    while (!feof(fptr))
    {
        position temp = NULL;
        position ptr = *head_ref;

        temp = (position)malloc(sizeof(struct polinom));

        if (temp == NULL)
        {
            printf("Problem with allocated memory");
            return -1;
        }

        fscanf(fptr, "%d %d", &temp->koef, &temp->eksponent);

        if ((ptr == NULL) || (temp->eksponent < ptr->eksponent))
        {
            temp->next = *head_ref;
            *head_ref = temp;
        }
        else
        {
            while ((ptr->next != NULL) && (temp->eksponent > ptr->next->eksponent))
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

int deleteEntireList(position *head_ref)
{
    position temp = *head_ref;

    if (temp == NULL)
    {
        printf("List is already empty");
        return -1;
    }

    while (temp != NULL)
    {
        temp = temp->next;
        free(*head_ref);
        *head_ref = temp;
    }

    return 0;
}

int addPoly(position poly1, position poly2)
{
    position poly3 = NULL;

    position prvi = poly1;
    position drugi = poly2;

    while ((prvi != NULL) && (drugi != NULL))
    {
        if (prvi->eksponent > drugi->eksponent)
        {
            if (List(poly3))
            {
                addOnTheBeggining(&poly3, drugi->koef, drugi->eksponent);
                drugi = drugi->next;
            }
            else
            {
                add(poly3, drugi->koef, drugi->eksponent);
                drugi = drugi->next;
            }
        }
        else if (prvi->eksponent == drugi->eksponent)
        {
            int zbrojKoef = prvi->koef + drugi->koef;

            if (List(poly3))
            {
                addOnTheBeggining(&poly3, zbrojKoef, prvi->eksponent);
                prvi = prvi->next;
                drugi = drugi->next;
            }
            else
            {
                add(poly3, zbrojKoef, drugi->eksponent);
                prvi = prvi->next;
                drugi = drugi->next;
            }
        }
        else
        {
            if (List(poly3))
            {
                addOnTheBeggining(&poly3, prvi->koef, prvi->eksponent);
                prvi = prvi->next;
            }
            else
            {
                add(poly3, prvi->koef, prvi->eksponent);
                prvi = prvi->next;
            }
        }
    }

    if (prvi == NULL)
    {
        while (drugi != NULL)
        {
            if (List(poly3))
            {
                addOnTheBeggining(&poly3, drugi->koef, drugi->eksponent);
                drugi = drugi->next;
            }
            else
            {
                add(poly3, drugi->koef, drugi->eksponent);
                drugi = drugi->next;
            }
        }
    }

    if (drugi == NULL)
    {
        while (prvi != NULL)
        {
            if (List(poly3))
            {
                addOnTheBeggining(&poly3, prvi->koef, prvi->eksponent);
                prvi = prvi->next;
            }
            else
            {
                add(poly3, prvi->koef, prvi->eksponent);
                prvi = prvi->next;
            }
        }
    }

    printf("Zbrojeni polinom:\n");

    printList(poly3);

    deleteEntireList(&poly3);

    return 0;
}

int multiplyPoly(position head_ref1, position head_ref2)
{
    position prvi = head_ref1;
    position drugi = head_ref2;
    position beggining = head_ref2;
    position poly3 = NULL;
    int sum;
    int multiply;

    while (prvi != NULL)
    {
        while (drugi != NULL)
        {

            if (List(poly3))
            {
                multiply = (prvi->koef) * (drugi->koef);
                sum = (prvi->eksponent) + (drugi->eksponent);

                addOnTheBeggining(&poly3, multiply, sum);
            }
            else
            {
                multiply = (prvi->koef) * (drugi->koef);
                sum = (prvi->eksponent) + (drugi->eksponent);

                add(poly3, multiply, sum);
                drugi = drugi->next;
            }
        }

        prvi = prvi->next;
        drugi = beggining;
    }

    printf("Polinom kao rezultat mnozenja:\n");
    printList(poly3);

    deleteEntireList(&poly3);

    return 0;
}

int addOnTheBeggining(position *head_ref, int koef, int eksp)
{
    position temp = NULL;

    temp = (position)malloc(sizeof(struct polinom));

    if (temp == NULL)
    {
        printf("Problem with allocated memory");
        return -1;
    }

    temp->koef = koef;
    temp->eksponent = eksp;

    temp->next = *head_ref;
    *head_ref = temp;

    return 0;
}

int add(position head_ref, int koef, int eksp)
{
    position ptr = head_ref;
    position temp = NULL;
    int suma;

    temp = (position)malloc(sizeof(struct polinom));

    if (temp == NULL)
    {
        printf("Problem with allocated memory");
        return -1;
    }

    while (ptr != NULL)
    {
        if (ptr->eksponent == eksp)
        {
            ptr->koef = ptr->koef + koef;
            return 0;
        }

        ptr = ptr->next;
    }

    ptr = head_ref;

    while (ptr->next != NULL && eksp > ptr->next->eksponent)
    {
        ptr = ptr->next;
    }

    temp->koef = koef;
    temp->eksponent = eksp;

    temp->next = ptr->next;
    ptr->next = temp;

    return 0;
}

int printList(position head_ref)
{
    position ptr = head_ref;

    while (ptr != NULL)
    {
        printf("%d\t%d\n", ptr->koef, ptr->eksponent);
        ptr = ptr->next;
    }

    printf("\n");

    return 0;
}

bool List(position head_ref)
{
    if (head_ref == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
