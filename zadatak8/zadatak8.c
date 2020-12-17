#include "funkcije8.h"

int main()
{

    // pocetak stoga
    position head;
    head = (position)malloc(sizeof(struct stack));
    head->next = NULL;

    // polazni direktorij
    tree_ptr beginning;
    beginning = makeBeginning();
    push(head, beginning);

    directorySimulation(head, beginning);

    return 0;
}
