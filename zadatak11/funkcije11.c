#include "funkcije11.h"

int hashFunction(char *array)
{
    int sum = 0;

    for (int i = 0; array[i] != '\0' && i < 5; i++)
    {
        sum += array[i];
    }
    sum = sum % MAX_TABLE;

    return sum;
}

hash_ptr insert()
{

    hash_ptr new;

    new = (hash_ptr)malloc(sizeof(struct struktura));

    if (new == NULL)
    {
        printf("Problem with allocated memory.");
        exit(1);
    }

    printf("Unesite ime studenta: ");
    scanf(" %s", new->ime);

    printf("Unesite prezime studenta: ");
    scanf(" %s", new->prezime);

    printf("Unesite maticni broj studenta: ");
    scanf("%d", &new->mat_broj);

    new->next = NULL;

    return new;
}

int putAtNull(hash_ptr *head_ref)
{

    for (int i = 0; i < MAX_TABLE; i++)
    {
        head_ref[i] = (hash_ptr)malloc(sizeof(struct struktura));

        if (head_ref[i] == NULL)
        {
            printf("Problem with allocated memory.");
        }

        head_ref[i]->next = NULL;
    }

    return 0;
}

int hashTable(hash_ptr *head)
{
    int choice = 0;
    int i;
    char answer;
    char stringName[MAX], stringSurname[MAX];

    for (i = 0; i < MAX_TABLE; i++)
    {
        if (head[i]->next == NULL)
        {
            printf("%d\t", i);
            printf("~~");
        }
        else if (head[i]->next != NULL)
        {
            hash_ptr ptr = head[i]->next;

            printf("%d\t", i);

            while (ptr != NULL)
            {
                printf("%s %s\t", ptr->ime, ptr->prezime);
                ptr = ptr->next;
            }
        }
        else
        {
            printf("%d\t", i);
            printf("%s %s", head[i]->next->ime, head[i]->next->prezime);
        }

        printf("\n");
    }

    while (choice == 0)
    {
        printf("Zelite li ispisati maticni broj nekog od studenata? (unesite y ako zelite te n ako ne zelite)\n");
        scanf(" %c", &answer);

        if (answer != 'n')
        {
            printf("Unesite ime i prezime studenta ciji maticni broj zelite dobiti: ");
            scanf(" %s %s", stringName, stringSurname);

            i = 0;

            while (i < MAX_TABLE)
            {
                if (head[i]->next == NULL)
                {
                    ++i;
                }
                else
                {
                    hash_ptr ptr = head[i]->next;

                    while (ptr != NULL)
                    {
                        if (strcmp(ptr->prezime, stringSurname) == 0 && strcmp(ptr->ime, stringName) == 0)
                        {
                            printf("Student/ica %s %s ima maticni broj %d\n\n", stringName, stringSurname, ptr->mat_broj);
                            break;
                        }
                        ptr = ptr->next;
                    }

                    if (ptr == NULL)
                    {
                        ++i;
                    }
                    else
                    {
                        break;
                    }
                }

                if (i == MAX_TABLE)
                {
                    printf("Student nije pronaden.\n\n");
                }
            }
        }
        else
        {
            choice = 1;
        }
    }

    return 0;
}
int updateHead(hash_ptr head_ref, hash_ptr value)
{
    hash_ptr previous = head_ref;
    hash_ptr current = head_ref->next;

    if (current == NULL)
    {
        value->next = previous->next;
        previous->next = value;
    }

    else
    {

        if (strcmp(current->prezime, value->prezime) > 0 || (strcmp(current->prezime, value->prezime) == 0 && strcmp(current->ime, value->ime) > 0))
        {
            previous->next = value;
            value->next = current;
            return 0;
        }

        while (current != NULL)
        {
            if (strcmp(current->prezime, value->prezime) < 0 || (strcmp(current->prezime, value->prezime) == 0 && strcmp(current->ime, previous->ime) < 0))
            {
                if (strcmp(current->prezime, value->prezime) < 0)
                {
                    if (strcmp(current->next->prezime, value->prezime) > 0)
                    {
                        value->next = current->next;
                        current->next = value;
                        return 0;
                    }
                    else
                    {
                        previous = current;
                        current = current->next;
                    }
                }
                else if (strcmp(current->prezime, value->prezime) == 0 && strcmp(current->ime, previous->ime))
                {
                    if (strcmp(current->next->ime, value->ime) > 0)
                    {
                        value->next = current->next;
                        current->next = value;
                        return 0;
                    }
                    else
                    {
                        previous = current;
                        current = current->next;
                    }
                }
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }

        if (current == NULL)
        {
            previous->next = value;
            value->next = NULL;
        }
    }

    return 0;
}

int freeHead(hash_ptr *head_ref)
{
    int i = 0;

    while (i < MAX_TABLE)
    {
        if (head_ref[i] == NULL)
        {
            ++i;
        }
        else
        {
            hash_ptr temp = head_ref[i]->next;

            while (head_ref[i] != NULL)
            {
                temp = head_ref[i];
                head_ref[i] = head_ref[i]->next;
                free(temp);
            }

            ++i;
        }
    }

    return 0;
}