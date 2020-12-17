#include "funkcije8.h"

tree_ptr makeDirectory(tree_ptr root, char *key)
{
    tree_ptr newDir;

    newDir = (tree_ptr)malloc(sizeof(struct tree));

    if (newDir == NULL)
    {
        printf("Problem with memory allocation!\n");
        exit(-1);
    }

    strcpy(newDir->dir, key);
    newDir->firstChild = NULL;
    newDir->nextSibling = NULL;

    if (root->firstChild == NULL)
    {
        root->firstChild = newDir;
    }
    else
    {
        tree_ptr temp = root->firstChild;

        while (temp->nextSibling != NULL)
        {
            temp = temp->nextSibling;
        }

        temp->nextSibling = newDir;
    }

    return root;
}

tree_ptr makeBeginning()
{
    char name[MAX] = "PS C:";
    tree_ptr root = (tree_ptr)malloc(sizeof(struct tree));

    if (root == NULL)
    {
        printf("Problem with memory allocation!\n");
        return NULL;
    }

    strcpy(root->dir, name);
    root->firstChild = root->nextSibling = NULL;

    return root;
}

int push(position head_ref, tree_ptr toBePushed)
{
    position new;
    new = (position)malloc(sizeof(struct stack));

    if (new == NULL)
    {
        printf("Problem with allocated memory.");
        return -1;
    }

    new->content = toBePushed;
    new->next = NULL;

    if (head_ref->next == NULL)
    {
        head_ref->next = new;
    }
    else
    {
        position temp = head_ref;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new;
    }
}

tree_ptr goBack(position head_ref)
{
    position temp = head_ref;

    while (temp->next != NULL)
    {
        head_ref = temp;
        temp = temp->next;
    }

    head_ref->next = temp->next;
    free(temp);

    return head_ref->content;
}

int printStack(position head_ref)
{
    char stringToPrint[MAX] = "";

    while (head_ref != NULL)
    {
        strcat(stringToPrint, head_ref->content->dir);
        strcat(stringToPrint, "\\");
        head_ref = head_ref->next;
    }

    //strcat(stringToPrint, ">");
    printf("%s ", stringToPrint);

    return 0;
}

int directorySimulation(position head, tree_ptr root)
{
    system("cls");
    tree_ptr current = root;
    printStack(head->next);
    int flag = 1;

    while (flag)
    {
        char users_input[MAX];
        char command[10] = "";
        char argument[10] = "";

        fgets(users_input, MAX, stdin);
        sscanf(users_input, "%s %s", command, argument);

        if (strcmp(command, "cd..") == 0)
        {
            if (current == root)
            {
                printf("\nNije moguce izvesti navedenu naredbu.\n\n");
                printStack(head->next);
            }
            else
            {
                current = goBack(head);
                printStack(head->next);
            }
        }
        else if (strcmp(command, "dir") == 0)
        {
            contentOfDirectory(current);
            printStack(head->next);
        }
        else if (strcmp(command, "cd") == 0 && strcmp(argument, "") != 0)
        {
            tree_ptr temp = current;
            current = isFound(current, argument);

            if (current == NULL)
            {
                printf("\nTrazeni direktorij nije pronaden\n\n");
                printStack(head->next);
                current = temp;
            }
            else
            {
                push(head, current);
                printStack(head->next);
            }
        }
        else if (strcmp(command, "md") == 0 && strcmp(argument, "") != 0)
        {
            current = makeDirectory(current, argument);
            printStack(head->next);
        }
        else if (strcmp(command, "exit") == 0)
        {
            flag = 0;
        }
        else
        {
            printf("Unesena je pogresna naredba...\n\n");
            printStack(head->next);
        }
    }
    return 0;
}

int contentOfDirectory(tree_ptr root)
{
    if (root->firstChild == NULL)
    {
        printf("\nDirektorij je prazan!\n\n");
    }
    else
    {
        printf("\nUnutar direktorija se nalazi: \n");
        root = root->firstChild;
        while (root != NULL)
        {
            printf("%s\n", root->dir);
            root = root->nextSibling;
        }
        printf("\n");
    }

    return 0;
}

tree_ptr isFound(tree_ptr root, char *key)
{
    root = root->firstChild;

    while (root != NULL)
    {
        if (strcmp(root->dir, key) == 0)
        {
            return root;
        }
        else
        {
            root = root->nextSibling;
        }
    }

    if (root == NULL)
    {

        return NULL;
    }
}

int freeStack(position head_ref)
{
    position temp = head_ref;

    while (head_ref != NULL)
    {
        temp = head_ref;
        head_ref = head_ref->next;
        free(temp);
    }
}