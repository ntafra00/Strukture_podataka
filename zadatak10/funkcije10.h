#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *node_ptr;
typedef struct tree_node *tree_ptr;

struct node
{
    node_ptr next;
    tree_ptr tree_next;
};

struct tree_node
{
    char content[5];
    tree_ptr left;
    tree_ptr right;
};

tree_ptr readAndStore(char *, node_ptr, tree_ptr); // funkcija koja cita sadrzaj iz datoteke
int push(node_ptr, char *);                        // funkcija koja salje element na stog
tree_ptr pop(node_ptr);                            // funkcija koja izbacuje element sa stoga i sprema ga kao dijete stabla
node_ptr createNode(char *);                       // funkcija koja kreira node za stog
tree_ptr createTree(char *);                       // funkcija koja kreira stablo
tree_ptr updateTree(tree_ptr, tree_ptr, tree_ptr); // funkcija koja azurira sadrzaj stabla
int pushTree(node_ptr, tree_ptr);                  // funkcija koja salje node sa stablom na stog
int inorder(tree_ptr);                             // inorder ispis stabla
tree_ptr deleteTree(tree_ptr);                     // funkcija koja brise stablo
int deleteHead(node_ptr);                          // funkcija koja brise vezanu listu
int writeInFile(tree_ptr);                         // funkcija koja ispisuje sadrzaj stabla u proizvoljan file