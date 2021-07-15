#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "fonctions.h"
#include "structure.h"


liste l=NULL;

//Fonction Taille
int taille_liste_rep(liste l)
{

    int n=0;
    while(l)
    {
        n++;
        l=l->suiv;
    }
    return n;
}

//FONCTION RECHERCHE PAR TELEPHONE
liste recherche_tel(liste l, char mat[])
{
    liste p=l;
    while(p)
    {
        if(strcmp(p->info.numtel,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

//FONCTION RECHERCHE PAR NOM
liste recherche_nom(liste l, char mat[])
{
    liste p=l;
    while(p)
    {
        if(strcmp(p->info.nom,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

//FONCTION RECHERCHE PAR PRENOM
liste recherche_prenom(liste l, char mat[])
{
    liste p=l;
    while(p)
    {
        if(strcmp(p->info.prenom,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}


//FONCTION RECHERCHE PAR VILLE
liste recherche_ville(liste l, char mat[])
{
    liste p=l;
    while(p)
    {
        if(strcmp(p->info.adresse.ville,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

//FONCTION RECHERCHE PAR INDICATIF
liste recherche_indicatif(liste l, char mat[])
{
    liste p=l;
    long int val,num;
    num=atol(mat);
    while(p)
    {
        val=atol(p->info.numtel);
        if(val/1000000==num)
            return p;
        p=p->suiv;
    }
    return NULL;
}

//FONCTION VALIDE DATE
int valide(date d)
{
   int jmax;
   switch(d.m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:jmax=31;
        case 4:
        case 6:
        case 9:
        case 11:jmax=30;
        case 2:if(d.m%4)
            jmax=28;
            else
                jmax=29;
    }
    return (jmax>=d.j&&d.m>=1&&d.m<=12&&d.a>=1900&&d.a<=2099&&d.j>=1);
}

//FONCTION VALIDE NUMERO
int valide_num (char num[])
{
    int i;
    for(i=0;i<strlen(num);i++)
    {
        if (isdigit(num[i])!=1)
            return 0;
    }
  return 1;
}

//FONCTION VALIDE CODE POSTAL
int valide_codep(adr a)
{
    int i;
    for(i=0;i<strlen(a.codep);i++)
    {
        if (isdigit(a.codep[i])!=1)
            return 0;
    }
    return 1;
}

//FONCTION VALIDE VILLE
int valide_ville(adr a)
{
    int j;
    for(j=0;j<strlen(a.ville);j++)
    {
        if (isdigit(a.ville[j])==1)
            return 0;
    }
    return 1;
}

//FONCTION VALIDE NOM
int valide_nom(char a[])
{
    int j;
    for(j=0;j<strlen(a);j++)
    {
        if (isdigit(a[j])==1)
            return 0;
    }
    return 1;
}

//FONCTION VALIDE PRENOM
int valide_prenom(char a[])
{
    int j;
    for(j=0;j<strlen(a);j++)
    {
        if (isdigit(a[j])==1)
            return 0;
    }
    return 1;
}

//FONCTION VALIDE EMAIL
int valide_email(char test[])
{
    int     i;
    char    *pos1, *pos2;
    char    *ch;

    while (1) {
           for (i = 0, ch = test; *ch; ch++) {
            if (*ch == '@') {
                pos1 = ch;
                i++;
            }
        }
        pos2 = ch;

        if (i == 1) {

            while (pos1 - test && ch - pos1 > 1) {

                if ((pos2 - ch) > 2 && *ch == '.') {

                    return 1;
                }
                ch--;
            }
        }
        textcolor(RED);
        puts("Email wrong! Enter again");
        textcolor(9);
        scanf("%39s", test);

    }

    return 1;
}


//FONCTION SAISIE DATE
date saisie_date()
{
    date d;
    do
    {
        printf("Donner la date sous la forme jj/mm/aaaa: ");
        fflush(stdin);
        scanf("%d/%d/%d",&d.j,&d.m,&d.a);
    }while(!valide(d));
    return d;
}

//FONCTION SAISIE REPERTOIRE
repertoire saisie_repertoire(liste l)
{
    repertoire e;
    do
    {
        puts("Donner le numero de telephone (8 chiffres): ");
        fflush(stdin);gets(e.numtel);
        if(recherche_tel(l,e.numtel)||strlen(e.numtel)!=8||valide_num(e.numtel)==0){
            printf("Saisie Invalid\n");
        }
    }while(recherche_tel(l,e.numtel)||strlen(e.numtel)!=8||valide_num(e.numtel)==0);
    do
    {
        printf("Donner le nom: ");
        fflush(stdin);gets(e.nom);
        if(!(valide_nom(e.nom)!=0)){
            printf("Saisie Invalid\n");
        }
    }while(!(valide_nom(e.nom)!=0));
    do
    {
        printf("Donner le prenom: ");
        fflush(stdin);
        gets(e.prenom);
        if(!(valide_nom(e.prenom)!=0)){
            printf("Saisie Invalid\n");
        }
    }while(!(valide_nom(e.prenom)!=0));
    e.dn=saisie_date();
    printf("Donner l'adresse: ");
    printf("\n\tRue: ");
    fflush(stdin);
    gets(e.adresse.rue);
    do
    {
        printf("\n\tVille: ");
        fflush(stdin);
        gets(e.adresse.ville);
        if(!(valide_ville(e.adresse)!=0)){
            printf("Saisie Invalid\n");
        }
    }while(!(valide_ville(e.adresse)!=0));
    do
    {
        printf("\n\tCode Postal: ");
        fflush(stdin);
        gets(e.adresse.codep);
        if(!(valide_codep(e.adresse)!=0)){
            printf("Saisie Invalid\n");
        }
    }while(!(valide_codep(e.adresse)!=0));
    do
    {
        printf("Donner l'adresse email: ");
        fflush(stdin);
        gets(e.email);
    }while(!(valide_email(e.email)==1));
    return e;
}

//FONCTION INSERSION TETE DU TELEPHONE
liste insere_tete_tel(liste l ,repertoire e)
{
    liste p;
    p=malloc(sizeof(struct cellule1));
    p->info=e;
    p->suiv=l;
    l=p;
    return l;
}

//FONCTION INSERSION QUEUE DU TELEPHONE
liste insere_queue_tel(liste l,repertoire e)
{
    liste p,q=l;
    if(l==NULL)
        l=insere_tete_tel(l,e);
    else
    {
        while(q->suiv)
            q=q->suiv;
        p=malloc(sizeof(struct cellule1));
        p->info=e;
        p->suiv=NULL;
        q->suiv=p;

    }
return l;
}

//FONCTION INSERSION D'UNE POSITION DONNEE
liste insere_pos_tel(liste l,repertoire e,int pos)
{
    int cp=1;
    liste p,q=l;
    while(cp<pos-1)
    {
        cp++;
        q=q->suiv;
    }
    p=malloc(sizeof(struct cellule1));
    p->info=e;
    p->suiv=q->suiv;
    q->suiv=p;
    return l;
}

//FONCTION SUPPRESSION TETE DU TELEPHONE
liste supprimer_tete_tel(liste l)
{liste p=l;

    if(l==NULL)
        printf("\n La liste est vide\n");
    else
    {
        l=l->suiv;
        free(p);
    }
    return l;
}

//FONCTION SUPPRESSION QUEUE DU TELEPHONE
liste supprimer_queue_tel(liste l)
{
    liste p1=l;
    if(!l)
        printf("\n La liste est vide\n");
    else
    if(l->suiv==NULL)
    {
        l=l->suiv;
        free(p1);
    }
    else
    {
        while((p1->suiv)->suiv){
             p1=p1->suiv;
            }
            free(p1->suiv);
            p1->suiv=NULL;
    }
    return l;
}

//FONCTION SUPPRESSION D'UNE POSITION DONNEE
liste suppression_pos_tel(liste l, int pos)
{
    liste p1,p2;
    int i;

    p1 = l;
    i = 0;
    while(p1->suiv && i < pos-1)
        {
            p1=p1->suiv ;
            i++;
        }
    if(i == pos-1)
        {
            p2=(p1->suiv)->suiv;
            free(p1->suiv);
            p1->suiv=p2;

            return l;
        }
    else
        {
            return 0;
        }

}


//FONCTION SUPPRESSION D'UN NUMERO DONNE
liste suppression_tel_donne(liste l,char num[])
{
    liste p1=l,p2;
    int ok=0;

    if(strcmp(p1->info.numtel,num)==0)
        l=supprimer_tete_tel(l);
    else
    {
        while(p1->suiv)
        {
            if(strcmp(p1->suiv->info.numtel,num)==0)
            {
                ok=1;
                break;
            }
            else
                p1=p1->suiv;
        }

        if(ok==1)
        {
            p2=p1->suiv;
            p1->suiv=p2->suiv;
            free(p2);
        }
    }
    return l;
}

//FONCTION SUPPRESSION D'UNE VILLE DONNEE
liste suppression_ville_donnee(liste l,char v[])
{
    liste p1=l,p2=l,p3=l;
    for (p3=l;p3;p3=p3->suiv)
    {
        if(strcmp(p1->info.adresse.ville,v)==0)
        {
            l=supprimer_tete_tel(l);
            p1=p1->suiv;
        }
        while(p1)
        {
            if(strcmp(p1->info.adresse.ville,v)==0)
            {
                while(p2->suiv!=p1){
                    p2=p2->suiv;}
                    p2->suiv=p1->suiv;
                    free(p1);
            }
            p1=p1->suiv;
        }
        p1=l;
    }
    return l;
}

//FONCTION SUPPRESSION D'UN INDICATIF DONNE
liste suppression_indicatif_donnee(liste l,char ind[])
{
    liste p1=l,p2=l,p3=l;
    long int val,val2,num;
    num=atol(ind);
    for (p3=l;p3;p3=p3->suiv)
    {
        val=atol(p1->info.numtel);
        if(val/1000000==num)
        {
            l=supprimer_tete_tel(l);
            p1=p1->suiv;
        }
        while(p1)
        {
            val2=atol(p1->info.numtel);
            if(val2/1000000==num)
            {
                while(p2->suiv!=p1)
                p2=p2->suiv;
                p2->suiv=p1->suiv;
                free(p1);
            }
            p1=p1->suiv;
        }
        p1=l;
    }
    return l;
}

//FONCTION MODIFICATION T E L E P H O N E :
void modification_tel(liste l)
{
    liste p1=l;
    int ok=0;
    char nomp[10],new[10];
    do
    {
        printf("Donner le nom contact que vous voulez modifier: ");
        fflush(stdin);gets(nomp);
        if(!(recherche_nom(l,nomp)&&valide_nom(nomp)!=0)){
            printf("Saisie Invalid\n");
        }
    }while(!(recherche_nom(l,nomp)&&valide_nom(nomp)!=0));
    do
    {
        printf("\nDonner un nouveau telephone: ");
        fflush(stdin);gets(new);
        if(strlen(new)!=8||valide_num(new)==0){
            printf("Saisie Invalid\n");
        }
    }while(strlen(new)!=8||valide_num(new)==0);
    while (p1&&ok==0)
    {
        if(strcmp(p1->info.nom,nomp)==0)
        {
            strcpy(p1->info.numtel,new);
            ok=1;
        }
        else
            p1=p1->suiv;
    }
}

//FONCTION MODIFICATION N O M :
void modification_nom(liste l)
{
    liste p1=l;
    int ok=0;
    char nomp[10],new[10];
    do
    {
        printf("Donner le nom contact que vous voulez modifier: ");
        fflush(stdin);gets(nomp);
        if(!(recherche_nom(l,nomp)&&valide_nom(nomp)!=0)){
           printf("Saisie Invalid\n");
                  }
    }while(!(recherche_nom(l,nomp)&&valide_nom(nomp)!=0));
    do
    {
        printf("\nDonner un nouveau nom: ");
        fflush(stdin);
        gets(new);
        if(recherche_nom(l,new)||valide_nom(new)==0){
            printf("Saisie Invalid\n");
        }
    }while(recherche_nom(l,new)||valide_nom(new)==0);
    while (p1&&ok==0)
    {
        if(strcmp(p1->info.nom,nomp)==0)
        {
            strcpy(p1->info.nom,new);
            ok=1;
        }
        else
            p1=p1->suiv;
    }
}

//FONCTION MODIFICATION P R E N O M :
void modification_prenom(liste l)
{
    liste p1=l;
    int ok=0;
    char nomp[10],new[10];
    do
    {
        printf("Donner le nom contact que vous voulez modifier: ");
        fflush(stdin);
        gets(nomp);
        if(!(recherche_nom(l,nomp)&&valide_nom(nomp)!=0)){
            printf("Saisie Invalid\n");
        }
    }while(!(recherche_nom(l,nomp)&&valide_nom(nomp)!=0));
    do
    {
        printf("\nDonner un nouveau prenom: ");
        fflush(stdin);gets(new);
    }while(valide_prenom(new)==0);
    while (p1&&ok==0)
    {
        if(strcmp(p1->info.nom,nomp)==0)
        {
            strcpy(p1->info.prenom,new);
            ok=1;
        }
        else
            p1=p1->suiv;
    }
}

//FONCTION MODIFICATION E M A I L :
void modification_email(liste l)
{
    liste p1=l;
    int ok=0;
    char nomp[10],new[10];
    do
    {
        printf("Donner le nom contact que vous voulez modifier: ");
        fflush(stdin);
        gets(nomp);
        if(!(recherche_nom(l,nomp)&&valide_nom(nomp)!=0)){
            printf("Saisie Invalid\n");
        }
    }while(!(recherche_nom(l,nomp)&&valide_nom(nomp)!=0));
    do
    {
        printf("\nDonner une nouvelle adresse email : ");
        fflush(stdin);
        gets(new);
    }while(valide_email(new)==0);
    while (p1&&ok==0)
    {
        if(strcmp(p1->info.nom,nomp)==0)
        {
            strcpy(p1->info.email,new);
            ok=1;
        }
        else
            p1=p1->suiv;
    }
}

//FONCTION MODIFICATION D A T E   N A I S S A N C E :
void modification_date(liste l)
{
    liste p1=l;
    int ok=0;
    date d;
    char nomp[10];
    do
    {
        printf("Donner le nom contact que vous voulez modifier : ");
        fflush(stdin);
        gets(nomp);
        if(!(recherche_nom(l,nomp)&&valide_nom(nomp)!=0)){
            printf("Saisie Invalid\n");
        }
    }while(!(recherche_nom(l,nomp)&&valide_nom(nomp)!=0));
     do
    {
        printf("Donner la date sous la forme jj/mm/aaaa: ");
        fflush(stdin);
        scanf("%d/%d/%d",&d.j,&d.m,&d.a);
    }while(!valide(d));
    while (p1&&ok==0)
    {
        if(strcmp(p1->info.nom,nomp)==0)
        {
           p1->info.dn.a=d.a;
           p1->info.dn.j=d.j;
           p1->info.dn.m=d.m;
            ok=1;

        }
        else
            p1=p1->suiv;
    }
}

//FONCTION MODIFICATION A D R E S S E :
void modification_adresse(liste l)
{
    liste p1=l;
    int ok=0;
    char nump[10];
    adr new;
    do
    {
        printf("Donner le nom du contact que vous voulez modifier: ");
        fflush(stdin);gets(nump);
    }while(!(recherche_nom(l,nump)&&valide_nom(nump)!=0));
    printf("\n\n\t\tSAISIE DE LA NOUVELLE ADRESSE\n");
    printf("\n\tRue: ");
    fflush(stdin);
    gets(new.rue);
    do
    {
        printf("\n\tVille: ");
        fflush(stdin);gets(new.ville);
    }while(!(valide_ville(new)!=0));
    do
    {
        printf("\n\tCode Postal: ");
        fflush(stdin);gets(new.codep);
    }while(!(valide_codep(new)!=0));

    while (p1&&ok==0)
    {
        if(strcmp(p1->info.nom,nump)==0)
        {
            strcpy(p1->info.adresse.rue,new.rue);
            strcpy(p1->info.adresse.codep,new.codep);
            strcpy(p1->info.adresse.ville,new.ville);
            ok=1;
        }
        else
            p1=p1->suiv;
    }
}

//FONCTION AFFICHE1
void affiche1(liste l,char x[])
{
    liste p=l;
    while(p)
    {
        if (strcmp(x,p->info.numtel)==0)
        {
            printf("%s\t%s\t\t%s\t\t%d/%d/%d\t\t%s %s %s\t\t%s\n",p->info.numtel,p->info.nom,p->info.prenom,p->info.dn.j,p->info.dn.m,p->info.dn.a,p->info.adresse.rue,p->info.adresse.ville,p->info.adresse.codep,p->info.email);
            break;
        }
        else
            p=p->suiv;
    }
}


//FONCTION AFFICHE D'UN TELEPHONE DONNE
void affiche_tel_donne(liste l)
{
    char nump[10];
    do
    {
        printf(" -----------------------------------------------------------------------\n");
        printf("|Donner le numero telephone du contact que vous voulez afficher: ");fflush(stdin);gets(nump);
        printf(" -----------------------------------------------------------------------\n");
    }while(!(recherche_tel(l,nump)&&strlen(nump)==8&&valide_num(nump)!=0));
    textcolor(12);
    printf("\nTel\t\t|nom\t\t|prenom\t\t|date naissance\t\t|adresse\t\t\t|mail\n\n");
    textcolor(0);
    affiche1(l,nump);
}

//FONCTION AFFICHE D'UN NOM DONNE
void affiche_nom_donne(liste l)
{
    liste p1=l;
    char nvnom[10];
    do
    {
        printf(" -----------------------------------------------------------\n");
        printf("|Donner le nom du contact que vous voulez afficher: ");fflush(stdin);gets(nvnom);
        printf(" -----------------------------------------------------------\n");

    }while(!(recherche_nom(l,nvnom)&&valide_nom(nvnom)!=0));
    textcolor(12);
    printf("\nTel\t\t|nom\t\t|prenom\t\t|date naissance\t\t|adresse\t\t\t|mail\n\n");
    textcolor(0);
       while(p1)
    {
        if (strcmp(p1->info.nom,nvnom)==0)
            affiche1(l,p1->info.numtel);
        p1=p1->suiv;
    }
}

//FONCTION AFFICHE D'UN PRENOM DONNE
void affiche_prenom_donne(liste l)
{
    liste p1=l;
    char nvnom[10];
    do
    {
        printf(" -----------------------------------------------------------\n");
        printf("|Donner le nom du contact que vous voulez afficher: ");fflush(stdin);gets(nvnom);
        printf(" -----------------------------------------------------------\n");

    }while(!(recherche_prenom(l,nvnom)&&valide_prenom(nvnom)!=0));
    textcolor(12);
    printf("\nTel\t\t|nom\t\t|prenom\t\t|date naissance\t\t|adresse\t\t\t|mail\n\n");
    textcolor(0);
       while(p1)
    {
        if (strcmp(p1->info.prenom,nvnom)==0)
            affiche1(l,p1->info.numtel);
        p1=p1->suiv;
    }
}

//FONCTION AFFICHE D'UN INDICATIF DONNE
void affiche_indicatif_donne(liste l)
{
    liste p1=l;
    long int val,num;
    char ind[10];
    do
    {
        printf("Donner un indicatif du contact que vous voulez afficher (2 chiffres): ");
        fflush(stdin);gets(ind);
    }while(!(valide_num(ind)!=0&&strlen(ind)==2&&recherche_indicatif(l,ind)));
    num=atol(ind);
    textcolor(12);
    printf("\nTel\t\t|nom\t\t|prenom\t\t|date naissance\t\t|adresse\t\t\t|mail\n\n");
    textcolor(0);
        while(p1)
    {
        val=atol(p1->info.numtel);
        if (val/1000000==num)
            affiche1(l,p1->info.numtel);
        p1=p1->suiv;
    }
}

//FONCTION AFFICHE D'UNE VILLE DONNEE
void affiche_ville_donne(liste l)
{
    liste p1=l;
    adr nv;
    do
    {
        printf("\n\tDonner la ville du contact que vous voulez afficher: ");
        fflush(stdin);gets(nv.ville);
    }while(!(recherche_ville(l,nv.ville)&&valide_ville(nv)!=0));
    textcolor(12);
    printf("\nTel\t\t|nom\t\t|prenom\t\t|date naissance\t\t|adresse\t\t\t|mail\n\n");
    textcolor(0);
       while(p1)
    {
        if (strcmp(p1->info.adresse.ville,nv.ville)==0)
            affiche1(l,p1->info.numtel);
        p1=p1->suiv;
    }
}


//FONCTION AFFICHE2
void affiche2(liste l)
{
 if(l==NULL)
  printf("La liste est vide ");
 else
 {
    textcolor(12);
    printf("\nTEL\t\t|NOM\t\t|PRENOM\t\t|DATE NAISSANCE\t\t|ADRESSE\t\t\t|MAIL\n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    textcolor(0);
    while(l)
    {
        printf("%s\t%s\t\t%s\t\t%d/%d/%d\t\t%s_%s_%s\t\t%s",l->info.numtel,l->info.nom,l->info.prenom,l->info.dn.j,l->info.dn.m,l->info.dn.a,l->info.adresse.rue,l->info.adresse.ville,l->info.adresse.codep,l->info.email);
        printf("\n------------------------------------------------------------------------------------------------------------------\n");
        l=l->suiv;
    }
 }
}

//FONCTION TRI
void tri1(liste l)
{
    repertoire aux;
    liste p1=l,p2;
    long int v1,v2;
    while(p1->suiv)
    {
        p2=p1->suiv;
        while(p2)
        {
            v1=atol(p1->info.numtel);
            v2=atol(p2->info.numtel);
            if(v1<v2)
            {
                aux=p1->info;
                p1->info=p2->info;
                p2->info=aux;
            }
                p2=p2->suiv;
        }
        p1=p1->suiv;
    }
}


//FONCTION CREATION
liste CREATION(liste l)
{
    int pos,t,rep;
    repertoire e;
    do
    {
        t=taille_liste_rep(l);
        do
        {
            printf("\nSaisir la position entre 1 et %d : ",t+1);
            scanf("%d",&pos);
        }while(pos<1||pos>t+1);
        e=saisie_repertoire(l);
        if(pos==1)
            l=insere_tete_tel(l,e);
        else
            if(pos==t+1)
                l=insere_queue_tel(l,e);
            else
                l=insere_pos_tel(l,e,pos);
        do
        {
            printf("Voulez vous ajouter un autre telephone? O/N (0 pour Non,1 pour Oui): ");fflush(stdin);
            scanf("%d",&rep);
        }while(rep!=1&&rep!=0);
    }while(rep==1);
        textcolor(RED);
        printf ("\nEnregistrement du contact dans le fichier %s \n","liste_repertoire.txt");
        textcolor(9);
    return l;
}

//FONCTION CONSTRUCTION D'UNE CHAINE
int construction(char *ligne,int pos,char s,char *ch)
{
    int i,j;
    for(i=pos,j=0;ligne[i]!=s;i++)
            ch[j++]=ligne[i];
        ch[j]='\0';
    //puts(ch);
    return i+1;
}

//FONCTION ENREGISTREMENT D'UN REPERTOIRE
void enregistrement_repertoire(liste l)
{
    FILE *fp;
    fp=fopen("liste_repertoire.txt","w");
    while(l)
    {

        fprintf(fp,"|%s|%s|%s|%d/%d/%d|%s|%s|%s|%s|\n",l->info.numtel,l->info.nom,l->info.prenom,l->info.dn.j,l->info.dn.m,l->info.dn.a,l->info.adresse.rue,l->info.adresse.ville,l->info.adresse.codep,l->info.email);
        l=l->suiv;
    }
    fclose(fp);

}

//FONCTION RECUPERATION DU REPERTOIRE
liste recuperation_repertoire()
{

    FILE *fp;
    liste p=NULL;
    repertoire e;
    int pos;
    char ligne[100];
    char ch[5];
    fp=fopen("liste_repertoire.txt","r");

    if(fp==NULL)
         printf("LISTE REPERTOIRE VIDE\\");
    else
       while(fgets(ligne,100,fp)!=NULL)
       {
            pos=construction(ligne,1,'|',e.numtel);
            pos=construction(ligne,pos,'|',e.nom);
            pos=construction(ligne,pos,'|',e.prenom);
            pos=construction(ligne,pos,'/',ch);
            e.dn.j=atoi(ch);
            pos=construction(ligne,pos,'/',ch);
            e.dn.m=atoi(ch);
            pos=construction(ligne,pos,'|',ch);
            e.dn.a=atoi(ch);
            pos=construction(ligne,pos,'|',e.adresse.rue);
            pos=construction(ligne,pos,'|',e.adresse.ville);
            pos=construction(ligne,pos,'|',e.adresse.codep);
            pos=construction(ligne,pos,'|',e.email);
            p=insere_queue_tel(p,e);
       }
    fclose(fp);
    return p;
}



#endif // FONCTIONS_H_INCLUDED
