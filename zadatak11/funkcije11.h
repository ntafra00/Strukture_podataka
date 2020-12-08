#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TABLE 11
#define MAX 100

typedef struct struktura *hash_ptr;

struct struktura
{
    char ime[MAX];
    char prezime[MAX];
    int mat_broj;
    hash_ptr next;
};

int hashFunction(char *);           // hash funkcija
int hashTable(hash_ptr *);          // funkcija koja ispisuje hash tablicu
hash_ptr insert();                  // funkcija koja prima podatke o studentu
int putAtNull(hash_ptr *);          // funckija koja postavlja sve head elemente na nulu
int updateHead(hash_ptr, hash_ptr); // funckija za koju jos nisam definira sta radi
int freeHead(hash_ptr *);           // funkcija koja oslobada memoriju