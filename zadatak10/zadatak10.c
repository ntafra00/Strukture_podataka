#include "funkcije10.h"
// iz infix izraza stvoriti stablo proracuna
// te u konacnici ispisati postfix izraz

int main()
{
    char nameOfFile[20];

    printf("Unesite ime file-a: ");
    scanf(" %s", nameOfFile);

    // head stoga
    node_ptr head;
    head = (node_ptr)malloc(sizeof(struct node));
    head->next = NULL;

    //root stabla
    tree_ptr root = NULL;

    root = readAndStore(nameOfFile, head, root);

    inorder(root);

    root = deleteTree(root);
    deleteHead(head);

    return 0;
}
