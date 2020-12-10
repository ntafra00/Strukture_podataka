#include "funkcije10.h"
// iz infix izraza stvoriti stablo proracuna
// te u konacnici ispisati postfix izraz

int main()
{
    char ulaz[20];

    printf("Unesite ime file-a: ");
    scanf(" %s", ulaz);

    // head stoga
    node_ptr head;
    head = (node_ptr)malloc(sizeof(struct node));
    head->next = NULL;

    //root stabla
    tree_ptr root = NULL;

    root = readAndStore(ulaz, head, root);

    writeInFile(root);

    root = deleteTree(root);
    deleteHead(head);

    return 0;
}
