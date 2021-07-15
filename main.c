#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <myconio.h>
#include <stdio.h>
#include <windows.h>
#include "fonctions.h"
#include "structure.h"


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void addmenus(HWND);
void CreateBtt(HWND hwnd) ;

HWND hname ,hage,hout,hogo,Add,Finnish;
 HDC hdc;
HMENU hmenu ;

HBITMAP hlogoImage , hgenerateImage;
int intro=1 ;
char ch[30] ;
long p ;
int pos,rep ;
char tel[10];
repertoire e;
adr a;
char b[3];
int t;

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("Gestion Contact");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+7;


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Répertoire téléphonique"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1250,                 /* The programs width */
           768,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){

static HBITMAP  hBmp;

    switch (message)                  /* handle the messages */
    {

        case WM_COMMAND:
        switch(wParam)
        {

        case 1:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                e=saisie_repertoire(l);
                l=insere_tete_tel(l,e);
                enregistrement_repertoire(l);
                MessageBox(hwnd,"Insertion tete avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");

                break;
        case 2:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                e=saisie_repertoire(l);
                l=insere_queue_tel(l,e);
                enregistrement_repertoire(l);
                MessageBox(hwnd,"Insertion queue avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 3:


                system("color F9");
                ShowWindow(hwnd,SW_HIDE);

                l=CREATION(l);
                enregistrement_repertoire(l);
                MessageBox(hwnd,"Creation avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");

                break;
        case 4:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                l=supprimer_tete_tel(l);
                MessageBox(hwnd,"Suppression avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 5:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                l=supprimer_queue_tel(l);
                MessageBox(hwnd,"Suppression avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 6:


                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                 do
                {
                printf("\n\tDonner la position: ");
                scanf("%d",&pos);
                if( !( pos>=0 && pos<=taille_liste_rep(l) ) ){
                    printf("Saisie Invalid");
                }
                }while( !( pos>=0 && pos<=taille_liste_rep(l) ) );
                suppression_pos_tel(l,pos);
                MessageBox(hwnd,"Suppression avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 7:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                do
                {
                printf("\n\tDonner le telephone: ");
                fflush(stdin);gets(tel);
                if(!(valide_num(tel)!=0&&strlen(tel)==8&&recherche_tel(l,tel))){
                    printf("Saisie Invalid");
                }
                }while(!(valide_num(tel)!=0&&strlen(tel)==8&&recherche_tel(l,tel)));
                l=suppression_tel_donne(l,tel);
                MessageBox(hwnd,"Suppression avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 8:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
               do
                {
                printf("\n\tDonner la ville: ");
                fflush(stdin);gets(a.ville);
                }while(!(valide_ville(a)!=0&&recherche_ville(l,a.ville)));
                l=suppression_ville_donnee(l,a.ville);
                MessageBox(hwnd,"Suppression avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");

                break;
        case 9:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                do
                {
                printf("\n\tDonner l'indicatif (2 chiffres): ");
                fflush(stdin);gets(b);
                if(!(strlen(b)==2&&recherche_indicatif(l,b))){
                    printf("Saisie Invalid");
                }
                }while(!(strlen(b)==2&&recherche_indicatif(l,b)));
                l=suppression_indicatif_donnee(l,b);
                MessageBox(hwnd,"Suppression avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");

                break;
        case 11:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                modification_adresse(l);
                MessageBox(hwnd,"Adresse modofier avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 12:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                modification_tel(l);
                MessageBox(hwnd,"Telephone modifier avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 13:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                affiche2(l);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 14:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                affiche_tel_donne(l);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 15:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                affiche_indicatif_donne(l);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 16:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                affiche_nom_donne(l);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 17:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                affiche_ville_donne(l);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 18:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                tri1(l);
                MessageBox(hwnd,"Tri avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 19:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                if(taille_liste_rep(l) == 0){
                     printf("cette liste est vide\n");
                     do
                    {
                       printf("Voulez vous importer votre liste repertoire et ajouter un contact? O/N (0 pour Non,1 pour Oui): ");
                       fflush(stdin);
                       scanf("%d",&rep);
                    }while(rep!=1&&rep!=0);
                    if(rep == 1){
                        l=recuperation_repertoire();
                        e=saisie_repertoire(l);
                        l=insere_tete_tel(l,e);
                        enregistrement_repertoire(l);
                    }else {
                        exit( EXIT_SUCCESS );
                    }

                }else
                enregistrement_repertoire(l);
                MessageBox(hwnd,"Enregistrement avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 20:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                l=recuperation_repertoire();
                MessageBox(hwnd,"Recuperation avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;


        case 21:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                l=CREATION(l);
                enregistrement_repertoire(l);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;

        case 22:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                modification_nom(l);
                MessageBox(hwnd,"Nom modifier avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;

        case 23:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                modification_prenom(l);
                MessageBox(hwnd,"Nom modifier avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;

        case 24:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                affiche_prenom_donne(l);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;

        case 25:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                modification_date(l);
                MessageBox(hwnd,"Date naissance modifier avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;

        case 26:

                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                modification_email(l);
                MessageBox(hwnd,"Email modifier avec succées", "succees", MB_OK | MB_ICONINFORMATION);
                printf("\n\n\n\n");
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;


        case 10:
                if (MessageBox(hwnd,"       Vous voulez quitter ?", "QUITTER", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {
                    DestroyWindow(hwnd);
                    system("cls");
                }
                break;

        }


    case WM_CREATE :

        addmenus(hwnd);

            /*****************AJOUTER FOND**********************/
            hBmp=LoadImage(NULL,"contacts.bmp",IMAGE_BITMAP,1370,700,LR_LOADFROMFILE);

            break;

    case WM_PAINT :

        {
            PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            DrawState(hdc,NULL,NULL,(intptr_t)hBmp,0,0,0,0,0,DST_BITMAP);

            EndPaint(hwnd, &ps);
        }
        break;

    case WM_DESTROY:
            PostQuitMessage (0);        /* send a WM_QUIT to the message queue */
            break;
    default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void addmenus(HWND hwnd)
{
    hmenu=CreateMenu();
    HMENU htp1=CreateMenu();
    HMENU htp2=CreateMenu();
    HMENU htp3=CreateMenu();
    HMENU hex=CreateMenu();
    HMENU hex1=CreateMenu();
    HMENU hex2=CreateMenu();

    //AppendMenu(hmenu,MF_STRING,0,"création du repertoire");
/*******************************************************/
    AppendMenu(hmenu,MF_STRING,21,"creation contact");

/***************************************************************/

    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp1,"Mise a jour");

      AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex,"Ajouter un téléphone");
        AppendMenu(hex,MF_STRING,1,"En tête"); /*Sous partie */
        AppendMenu(hex,MF_STRING,2,"En queue");
        AppendMenu(hex,MF_STRING,3,"A partir d'une position");

      AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex1,"Supprimer un téléphone");
        AppendMenu(hex1,MF_STRING,4,"En tête"); /*Sous partie */
        AppendMenu(hex1,MF_STRING,5,"En queue");
        AppendMenu(hex1,MF_STRING,6,"A partir d'une position");
        AppendMenu(hex1,MF_STRING,7,"D'un téléphone");
        AppendMenu(hex1,MF_STRING,8,"D'une ville");
        AppendMenu(hex1,MF_STRING,9,"D'un indicatif ");

      AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex2,"Modifier les données d'un téléphone");
        AppendMenu(hex2,MF_STRING,11,"Adresse"); /*Sous partie */
        AppendMenu(hex2,MF_STRING,12,"Téléphone");
        AppendMenu(hex2,MF_STRING,22,"Nom");
        AppendMenu(hex2,MF_STRING,23,"Prenom");
        AppendMenu(hex2,MF_STRING,25,"Date de naissance");
        AppendMenu(hex2,MF_STRING,26,"Email");

/***************************************************************/
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp2,"Recherche affichage et tri");

      AppendMenu(htp2,MF_STRING,13,"Afficher Tout les contacts ");
      AppendMenu(htp2,MF_STRING,14,"Recherche par numéro ");
      AppendMenu(htp2,MF_STRING,15,"Recherche par indicatif ");
      AppendMenu(htp2,MF_STRING,16,"Recherche par nom ");
      AppendMenu(htp2,MF_STRING,24,"Recherche par prenom ");
      AppendMenu(htp2,MF_STRING,17,"Recherche par ville ");
      AppendMenu(htp2,MF_STRING,18,"Tri");

/***************************************************************/
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp3,"Enregistrement et récuperation ");

      AppendMenu(htp3,MF_STRING,19,"Enregistrement ");
      AppendMenu(htp3,MF_STRING,20,"Récuperation ");

/******************************************************************/
    AppendMenu(hmenu,MF_STRING,10,"Quitter");
    SetMenu(hwnd,hmenu);
}

