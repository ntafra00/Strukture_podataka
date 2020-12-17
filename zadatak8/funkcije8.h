#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct tree *tree_ptr;
typedef struct stack *position;

struct tree
{
    char dir[MAX];
    tree_ptr firstChild;
    tree_ptr nextSibling;
};

struct stack
{
    tree_ptr content;
    position next;
};

tree_ptr makeDirectory(tree_ptr, char *);    // funkcija koja kreira novi direktorij
tree_ptr goBack(position);                   // funkcija koja djeluje jednako kao i pop funckija na stogu
tree_ptr makeBeginning();                    // funkcija koja kreira pocetni direktorij
int push(position, tree_ptr);                // funkcija koja ubacuje element na stog
int directorySimulation(position, tree_ptr); // funkcija kojom simuliramo rad direktorija
int printStack(position);                    // funkcija koja ispisuje sadrzaj stoga
int contentOfDirectory(tree_ptr);            // funkcija koja ispisuje kompletan sadrzaj trenutnog direktorija
tree_ptr isFound(tree_ptr, char *);          // funkcija koja pronalazi postoji li trazeni direktorij
