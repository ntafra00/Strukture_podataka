#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *position;

struct node
{
    int number;
    position next;
};

int Push(position *, int);
int Pop(position *);
int printList(position);
int readFromFile(char[], position *);

int main()
{

    position head = NULL;

    readFromFile("postfix.txt", &head);

    printList(head);

    return 0;
}

int Push(position *head_ref, int value)
{
    position ptr = *head_ref;

    ptr = (position)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("Problem with memory allocation.");
        return -1;
    }

    ptr->number = value;

    ptr->next = *(head_ref);
    *(head_ref) = ptr;

    return 0;
}

int printList(position head)
{
    printf("%d", head->number);

    return 0;
}

int readFromFile(char fileName[], position *head_ref)
{
    FILE *fptr = NULL;
    int num;
    int num1, num2;
    int result;
    char operation[10];

    fptr = fopen(fileName, "r");

    if (fptr == NULL)
    {
        printf("File not opened");
        return -1;
    }

    while (!feof(fptr))
    {

        fscanf(fptr, "%s ", operation);

        if (strcmp(operation, "+") == 0)
        {
            num1 = Pop(head_ref);
            num2 = Pop(head_ref);

            result = num2 + num1;

            Push(head_ref, result);
        }
        else if (strcmp(operation, "-") == 0)
        {
            num1 = Pop(head_ref);
            num2 = Pop(head_ref);

            result = num2 - num1;

            Push(head_ref, result);
        }
        else if (strcmp(operation, "*") == 0)
        {
            num1 = Pop(head_ref);
            num2 = Pop(head_ref);

            result = num2 * num1;

            Push(head_ref, result);
        }
        else if (strcmp(operation, "/") == 0)
        {
            num1 = Pop(head_ref);
            num2 = Pop(head_ref);

            result = num2 / num1;

            Push(head_ref, result);
        }
        else
        {
            num = atoi(operation);

            Push(head_ref, num);
        }
    }

    fclose(fptr);

    return 0;
}

int Pop(position *head_ref)
{
    position ptr = *head_ref;
    int value;

    *head_ref = ptr->next;
    value = ptr->number;

    free(ptr);

    return value;
}