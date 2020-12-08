#include "funkcije11.h"

int main()
{
    hash_ptr head[MAX_TABLE];
    hash_ptr temp;
    int suma = 0;
    char choice;

    putAtNull(head);

    do
    {
        temp = NULL;
        temp = insert();
        suma = hashFunction(temp->prezime);

        updateHead(head[suma], temp);

        printf("Zelite li unijeti novoga studenta? (unesite n ako ne zelite, a y ako zelite)\n");
        scanf(" %c", &choice);
        system("cls");
    } while (choice != 'n');

    hashTable(head);

    freeHead(head);

    return 0;
}