#include <stdio.h>
#include "bib.c"
#define MENU_ITEMS_COUNT 6
#define margin 40
// tableau des items du menu principal
char *menuItems[MENU_ITEMS_COUNT] = {
    "creation de la table des symboles", // é is \x82
    "Affichage la table des symboles",
    "Rechercher d'une variable dans la table des symboles",
    "Rechercher une fonction dans la table des symboles",
    "Recherche dans une portee specifique", // é is \x82
    "Quitter"};

int main()
{
    Pointeur_Main tete = NULL; // tete de la liste chainee à creer
    int selectedItemIndex = 0;
    bool creation = false;     // variable pour verifier si la table des symboles a ete cree ou non
    char choix;                // choix de l'utilisateur
    FILE *fptr;                // pointeur vers le fichier d'entree
    // initialisation de la console
    textbackground(BLACK);
    clrscr();
    affichage_ini(); // affichage de l'interface utilisateur
    choix = getch();

    if (choix == 'h' || choix == 'H')
    {
        system("cls");
        gotoxy(1, 10);
        textcolor(WHITE);
        printfslow("- Notre projet consiste a simuler le travail d'un compilateur pour generer les tables de symboles d'un code source en langage C.\n\n - Nous avons implemente les operations d'insertion et de recherche des symboles a l'aide de machines abstraites,\nen utilisant une structure de donnees de liste chainee pour stocker les tables de symboles.\n\n- Notre programme analyse le code source pour detecter les symboles tels que les variables,les fonctions et les constantes et les ajoute a la table de symboles appropriee.\n\n- Notre programme fournit une interface utilisateur simple pour entrer le fichier source C et visualiser les tables de symboles generees.\n\n- Le but de ce projet est de mieux comprendre le fonctionnement d'un compilateur et de mettre en pratique nos connaissances en langage C et en structures de donnees.", 10);
        getch();
        system("cls");
        main();
    }
    else
    {
        clrscr();
    menu:
        while (1)
        {
            textcolor(WHITE);
            textbackground(BLACK);
            gotoxy(25, 2);
            cprintf("=========================================================================");
            textcolor(GREEN);
            textbackground(BLACK);
            print_image(fptr, "./bienvenue.txt", 40, 2);
            textcolor(WHITE);
            gotoxy(25, 10);
            cprintf("=========================================================================");
            gotoxy(45, 12);
            for (int i = 0; i < MENU_ITEMS_COUNT; i++)
            {
                gotoxy(margin, 13 + i);

                if (i == selectedItemIndex)
                {
                    textcolor(WHITE);
                    textbackground(RED);
                }
                else
                {
                    textcolor(WHITE);
                    textbackground(BLACK);
                }

                printf("%s\n", menuItems[i]);
            }
            gotoxy(25, 20);
            textbackground(BLACK);
            textcolor(WHITE);
            cprintf("=========================================================================");

            // attendre l'entree de l'utilisateur
            int key = getch();

            // traiter l'entree de l'utilisateur
            switch (key)
            {
            case 224: // les touches fleches sont codees sur 2 octets (224 et la valeur de la touche)
                key = getch();

                switch (key)
                {
                case 72: // Up arrow
                    selectedItemIndex = (selectedItemIndex - 1 + MENU_ITEMS_COUNT) % MENU_ITEMS_COUNT;
                    break;
                case 80: // Down arrow
                    selectedItemIndex = (selectedItemIndex + 1) % MENU_ITEMS_COUNT;
                    break;
                }

                break;
            case 13: // la touche entree est codee sur 1 octet (13)
                // permettre a l'utilisateur de choisir un item du menu
                textbackground(BLACK);
                clrscr();
                switch (selectedItemIndex)
                {
                case 0:
                {
                    Liberer_Main(tete);
                    creation = true;
                    submenu(&tete , fptr);
                    clrscr();
                    gotoxy(38, 15);
                    textcolor(RED);
                    loading_screen(50);
                    clrscr();
                    textcolor(GREEN);
                    gotoxy(38, 15);
                    printf("Table des symboles cr%ce avec succ%cs ! ", 130, 130);
                    getch();
                    clrscr();
                    goto menu;
                    break;
                }
                case 1:
                {
                    if (!creation)
                    {
                        clrscr();
                        gotoxy(40, 15);
                        textcolor(RED);
                        printf("Vous n'avez encors cr%cer la table des symboles", 130);
                        getch();
                        goto menu;
                    }
                    else
                    {
                        clrscr();
                        affichage(tete);
                        getch();
                        clrscr();
                    }
                    break;
                }
                case 2:
                {
                    if (!creation)
                    {
                        clrscr();
                        gotoxy(40, 15);
                        textcolor(RED);
                        printf("Vous n'avez encors cr%cer la table des symboles", 130);
                        getch();
                        goto menu;
                    }
                    else
                    {
                        clrscr();
                        char nom_v[20];
                        char type_v[10];
                        char attribut_v[15];
                        printf("Entrer le nom de la variable : ");
                        scanf("%s", &nom_v);
                        printf("\nEntrer le type de la variable : ");
                        scanf("%s", &type_v);
                        printf("\nEntrer l'attribut de la variable : ");
                        scanf("%s", &attribut_v);
                        recherche_stdin(tete, nom_v, type_v, attribut_v);
                        getch();
                        clrscr();
                    }
                    break;
                }
                case 3:
                {
                    if (!creation)
                    {
                        clrscr();
                        gotoxy(40, 15);
                        textcolor(RED);
                        printf("Vous n'avez encors cr%cer la table des symboles", 130);
                        getch();
                        goto menu;
                    }
                    else
                    {
                        clrscr();
                        char nom_f[20];
                        char type_f[10];
                        printf("Entrer le nom de la fonction : \n");
                        scanf("%s", &nom_f);
                        printf("Entrer le type de la fonction  : \n");
                        scanf("%s", &type_f);
                        recherche_stdin(tete, nom_f, type_f, "fonction");
                        getch();
                        clrscr();
                    }
                    break;
                }
                case 4:
                {
                    if (!creation)
                    {
                        clrscr();
                        gotoxy(40, 15);
                        textcolor(RED);
                        printf("Vous n'avez encors cr%cer la table des symboles", 130);
                        getch();
                        goto menu;
                    }
                    else
                    {
                        clrscr();
                        char nomv[20];
                        char temp;
                        char typev[10];
                        char attributv[15];
                        char titrev[50];
                        printf("Entrer le nom de la variable : ");
                        scanf("%s", &nomv);
                        printf("\nEntrer le type de la variable : ");
                        scanf("%s", &typev);
                        printf("\nEntrer l'attribut de la variable : ");
                        scanf("%s", &attributv);
                        printf("\nEntrer le titre de la port%ce : ", 130);
                        // lire le titre de la portee avec les espaces
                        scanf("%c", &temp);
                        scanf("%[^\n]", titrev);
                        printf("\n");
                        if (rech_port(tete, titrev, nomv, typev, attributv) == 1)
                        {
                            gotoxy(40, 15);
                            textcolor(GREEN);
                            printf("Elle existe dans cette port%ce \n", 130);
                            getch();
                            clrscr();
                        }
                        else
                        {
                            gotoxy(40, 15);
                            textcolor(RED);
                            printf("Elle n'existe pas dans cette port%ce \n", 130);
                            getch();
                            clrscr();
                        }
                    }
                    break;
                }
                case 5:
                {
                    clrscr();
                    textcolor(MAGENTA);
                    print_image(fptr, "./bye.txt", 35, 8);
                    delay(1000);
                    clrscr();
                    Liberer_Main(tete);
                    exit(0);
                    break;
                }
                default:
                {
                    break;
                }
            }

        }

    }

}
    return 0;
}
