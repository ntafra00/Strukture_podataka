#include <stdlib.h>
#include <stdio.h>
#define MAX_BODOVI 60

struct osoba
{
    char ime[60];
    char prezime[60];
    int bodovi;
};

int countLines(char[]);                        // funkcija koja broji broj redaka u datoteci
int readFromFile(struct osoba *, int, char[]); // funkcija koja čita podatke iz datoteke
int printOutStudent(struct osoba *);           // funkcija koja ispisuje podatke pojedine osobe na ekran

int main()
{
    struct osoba *strukt = NULL;
    int n = 0;
    int i;

    n = countLines("studenti.txt");

    strukt = (struct osoba *)malloc(n * sizeof(struct osoba));

    if (strukt == NULL)
    {
        printf("Error! Problem with allocated memory");
        return -1;
    }

    readFromFile(strukt, n, "studenti.txt");

    for (i = 0; i < n; i++)
    {
        printOutStudent(strukt + i);
    }

    free(strukt);

    return 0;
}

int countLines(char nameOfFile[40])
{
    int counter = 0;
    FILE *fptr = NULL;

    fptr = fopen(nameOfFile, "r");

    if (fptr == NULL)
    {
        printf("Error! File not opened.");
        exit(1);
    }

    while (!feof(fptr))
    {
        fscanf(fptr, "%*[^\n]\n");
        counter++;
    }

    fclose(fptr);

    return counter;
}

int printOutStudent(struct osoba *ptr)
{
    double relBrojBodova = 0.0;

    relBrojBodova = (double)ptr->bodovi / MAX_BODOVI * 100;

    printf("%s\t%s\t%d\t%f\n", ptr->ime, ptr->prezime, ptr->bodovi, relBrojBodova);

    return 0;
}

int readFromFile(struct osoba *ptr, int number, char nameOfFile[40])
{
    FILE *fptr;

    fptr = fopen(nameOfFile, "r");

    if (fptr == NULL)
    {
        printf("Error! Problem with allocated memory");
        return -1;
    }

    for (int i = 0; i < number; i++)
    {
        fscanf(fptr, "%s %s %d", ptr[i].ime, ptr[i].prezime, &ptr[i].bodovi);
    }

    fclose(fptr);

    return 0;
}