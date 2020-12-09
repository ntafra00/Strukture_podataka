#include "funkcije10.h"

tree_ptr readAndStore(char *name, node_ptr head_ref, tree_ptr root)
{

    FILE *fptr = NULL;
    tree_ptr first = NULL;
    tree_ptr second = NULL;
    char key[5];

    fptr = fopen(name, "r");

    if (fptr == NULL)
    {
        printf("File not opened.");
        return 0;
    }

    while (!feof(fptr))
    {
        fscanf(fptr, "%s ", key);

        if ((strcmp(key, "+") != 0) && (strcmp(key, "-") != 0) && (strcmp(key, "*") != 0) && (strcmp(key, "/") != 0))
        {

            push(head_ref, key);
        }
        else
        {
            root = createTree(key);
            first = pop(head_ref);
            second = pop(head_ref);
            root = updateTree(root, first, second);

            pushTree(head_ref, root);
        }
    }

    root = head_ref->next->tree_next;

    fclose(fptr);

    return root;
}

int push(node_ptr head_ref, char *value)
{
    node_ptr new;

    new = createNode(value);

    if (new == NULL)
    {
        printf("Error.");
    }

    new->next = head_ref->next;
    head_ref->next = new;

    return 0;
}

node_ptr createNode(char *value)
{
    node_ptr newNode;

    newNode = (node_ptr)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory not allocated!\n");
        return NULL;
    }

    newNode->next = NULL;
    newNode->tree_next = createTree(value);

    return newNode;
}

tree_ptr createTree(char *value)
{
    tree_ptr newNode;

    newNode = (tree_ptr)malloc(sizeof(struct tree_node));

    if (newNode == NULL)
    {
        printf("Memory not allocated!\n");
        return NULL;
    }

    strcpy(newNode->content, value);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

tree_ptr updateTree(tree_ptr root, tree_ptr first, tree_ptr second)
{
    root->right = first;
    root->left = second;

    return root;
}

tree_ptr pop(node_ptr head_ref)
{

    node_ptr nodeToDelete = head_ref->next;
    tree_ptr rootForReturn;

    head_ref->next = nodeToDelete->next;

    rootForReturn = nodeToDelete->tree_next;

    free(nodeToDelete);

    return rootForReturn;
}

int printLinkedList(node_ptr head_ref)
{
    while (head_ref != NULL)
    {
        printf("%s ", head_ref->tree_next->content);

        head_ref = head_ref->next;
    }

    return 0;
}

int inorder(tree_ptr root)
{

    if (root != NULL)
    {

        inorder(root->left);
        printf("%s ", root->content);
        inorder(root->right);
    }

    return 0;
}

int pushTree(node_ptr head_ref, tree_ptr root_ref)
{
    node_ptr nodeToAdd;

    nodeToAdd = (node_ptr)malloc(sizeof(struct node));

    if (nodeToAdd == NULL)
    {
        printf("Problem with memmory allocation!\n");
        return -1;
    }

    nodeToAdd->next = head_ref->next;
    head_ref->next = nodeToAdd;
    nodeToAdd->tree_next = root_ref;
}

tree_ptr deleteTree(tree_ptr root)
{
    if (root != NULL)
    {
        root->left = deleteTree(root->left);
        root->right = deleteTree(root->right);
        free(root);
    }

    return NULL;
}

int deleteHead(node_ptr head)
{

    while (head != NULL)
    {
        node_ptr temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

int writeInFile(char *nameOfFile, tree_ptr root)
{
    FILE *fptr;
    fptr = fopen(nameOfFile, "w");

    if (fptr == NULL)
    {
        printf("File not opened!\n");
        return -1;
    }

    return 0;
}