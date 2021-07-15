#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct
{
    int j;
    int m;
    int a;
}date;

typedef struct
{
    char rue[20];
    char ville[20];
    char codep[10];
}adr;

typedef struct
{
    char numtel[10];
    char nom[21];
    char prenom[21];
    date dn;
    adr adresse;
    char email[30];
}repertoire;

struct cellule1
{
    repertoire info;
    struct cellule1* suiv;
};
typedef struct cellule1* liste;


#endif // STRUCTURE_H_INCLUDED
