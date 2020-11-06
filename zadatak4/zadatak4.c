#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "polinom.h"

int main()
{
    position head1 = NULL;
    position head2 = NULL;

    readFromFile("poli1.txt", &head1);
    readFromFile("poli2.txt", &head2);

    printf("Prvi polinom:\n");
    printList(head1);

    printf("Drugi polinom:\n");
    printList(head2);

    addPoly(head1, head2);
    multiplyPoly(head1, head2);

    deleteEntireList(&head1);
    deleteEntireList(&head2);

    return 0;
}
