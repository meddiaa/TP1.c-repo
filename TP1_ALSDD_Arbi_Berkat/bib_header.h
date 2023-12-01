#ifndef BIB_INCLUDED
#define BIB_INCLUDED
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include "./conio21/conio.c"

/***********************************Les types*************************************************/
typedef char* string ;
/**************************************Les tableaux ********************************************************/
string types[5]={"int","void","bool","float","char"};//declaration du tableau des types
/***********************************Les constantes********************************************/
#define MAX_LEN 500
#define MAX_LINE_LENGTH 1024
/***********************************Les types des pointeurs***********************************/
typedef struct Maillon_Main * Pointeur_Main;//Le type des pointeurs qui pointent les maillon de type Maillon_Main
typedef struct Maillon_Point * Pointeur_Point;//Le type des pointeurs qui pointent les maillon de type Maillon_Point
typedef struct Maillon_tab_sym * Pointeur_tab;//Le type des pointeurs qui pointent les maillon de type Maillon_tab_sym
/*******************************les types des maillon****************************************/
struct Maillon_Main
{
string titre;
Pointeur_tab PT ;
Pointeur_Point Suivant;
} ; // on definit la strcuture du maillon initial

 struct Maillon_Point
 {
     Pointeur_Main PM;
     Pointeur_Point Suivant;
 };// on definit la strcuture du maillon des pointeur

 struct Maillon_tab_sym
 {
     string nom;
     string type;
     string attribut;
     Pointeur_tab Suivant;
 };// on definit la strcuture du maillon de tableau des symboles
/*********************************************************la pile***************************************************************/
typedef struct Maillon_Pi * Pointeur_Pi;//Le type des pointeurs qui pointent les maillon de type Maillon_Pi(la pile des pointeurs main)

struct Maillon_Pi
{
 Pointeur_Main PM;
Pointeur_Pi Suivant ;
} ;// on definit la strcuture du maillon de la pile des pointeurs main

typedef struct Maillon_Pip * Pointeur_Pip;//Le type des pointeurs qui pointent les maillon de type Maillon_Pip (la pile des pointeurs point)

struct Maillon_Pip
{
Pointeur_Point PP;
Pointeur_Pip Suivant ;
} ;// on definit la strcuture du maillon de la pile des pointeurs main

typedef struct Maillon_Pile * Pointeur_Pile ;//Le type des pointeurs qui pointent les maillon de type Maillon_Pile (la pile des entiers)

struct Maillon_Pile
{
int Val ;
Pointeur_Pile Suivant ;
} ;// on definit la strcuture du maillon de la pile des entiers

/*******************************Les machines abstraites d'allocation*******************************************/
void Allouer_Main (Pointeur_Main *P); // allouer un espace de type maillon_main et retourner son adresse
void Allouer_Point (Pointeur_Point *P); // allouer un espace de type maillon_point et retourner son adresse
void Allouer_tab (Pointeur_tab *P); // allouer un espace de type maillon_tab_sym et retourner son adresse
/************************Les machines abstraites pour libirer les espaces allouer*************************/
void Liberer_Main ( Pointeur_Main P); // liberer l'espace Mailloin_main deja alloue
void Liberer_Point ( Pointeur_Point P); // liberer l'espace maillon_point deja alloue
void Liberer_tab ( Pointeur_tab P); // liberer l'espace maillon_tab_sym deja alloue
/**************************Les machines abstraites pour recuperer***************************************/
Pointeur_tab PT_Main (Pointeur_Main P);// retourner la valeur du champ PT de Maillon_main
Pointeur_Point Suivant_Main(Pointeur_Main P);// retourner la valeur du champ Suivant de Maillon_main
string titre_Main(Pointeur_Main P);// retourner la valeur du champ Titre de Maillon_main
Pointeur_Main PM_Point(Pointeur_Point P);// retourner la valeur du champ PM de Maillon_point
Pointeur_Point Suivant_Point(Pointeur_Point P);// retourner la valeur du champ Suivant de Maillon_point
Pointeur_tab Suivant_tab_sym(Pointeur_tab P);// retourner la valeur du champ Suivant de Maillon_tab_sym
string nom_tab_sym(Pointeur_tab P);// retourner la valeur du champ nom de Maillon_tab_sym
string type_tab_sym(Pointeur_tab P);// retourner la valeur du champ de Maillon_tab_sym
string attribut_tab_sym(Pointeur_tab P);// retourner la valeur du champ attribut de Maillon_tab_sym
/******************************Les machines abstraites d'affectation*****************************************/
void AFF_titre_main (Pointeur_Main P,string ph);//affecter la valeur de ph au champ Titre du Maillon_Main
void AFF_PT_main (Pointeur_Main P,Pointeur_tab q);//affecter la valeur de q au champ PT du Maillon_Main
void AFF_Suivant_main (Pointeur_Main P,Pointeur_Point q);//affecter la valeur de q au champ Suivant du Maillon_Main
void AFF_PM_point (Pointeur_Point P,Pointeur_Main q);//affecter la valeur de q au champ PM du Maillon_Point
void AFF_Suivant_point (Pointeur_Point P,Pointeur_Point q);//affecter la valeur de q au champ Suivant du Maillon_Point
void AFF_nom_tab (Pointeur_tab P,string ph);//affecter la valeur de ph au champ nom du Maillon_tab_sym
void AFF_type_tab (Pointeur_tab P,string ph);//affecter la valeur de ph au champ type du Maillon_tab_sym
void AFF_attribut_tab (Pointeur_tab P,string ph);//affecter la valeur de ph au champ attribut du Maillon_tab_sym
void AFF_Suivant_tab (Pointeur_tab P,Pointeur_tab q);//affecter la valeur de q au champ Suivant du Maillon_tab_sym
/****************************************Les machines abstraite de la pile des pointeurs main**************************************/
void Creerpile_Pi( Pointeur_Pi *P ); // pile videbool Pilevide_Pi
bool Pilevide_Pi ( Pointeur_Pi P );//tester si la pile est vide
void Empiler_Pi ( Pointeur_Pi *P, Pointeur_Main PM );//ajouter un element a la pile
void Depiler_Pi ( Pointeur_Pi *P, Pointeur_Main *PM );//recuperer un element de la pile
void afficher_pile(Pointeur_Pi P);//affichage de la pile
/***********************************Lea machines abstraites de la pile des pointeurs Point****************************/
void Creerpile_Pip( Pointeur_Pip *P ); // creation d'une pile
bool Pilevide_Pip ( Pointeur_Pip P );//tester si la pile est vide
void Empiler_Pip ( Pointeur_Pip *P, Pointeur_Point PP );//ajouter un element a la pile
void Depiler_Pip ( Pointeur_Pip *P, Pointeur_Point *PP );//recuperer un element de la pile
void afficher_pip(Pointeur_Pip P);//affichage de la pile
/***********************************Lea machines abstraites de la pile des entiers****************************/
void Creerpile_Pile( Pointeur_Pile *P );// creation d'une pile
bool Pilevide_Pile ( Pointeur_Pile P );//tester si la pile est vide
void Empiler_Pile ( Pointeur_Pile *P, int Val );//ajouter un element a la pile
void Depiler_Pile ( Pointeur_Pile *P, int *Val );//recuperer un element de la pile
void afficher_Pile (Pointeur_Pile P);//affichage de la pile
//fin des machines abstraites
/******************************************* Les modules d'affichage de la table des symboles ***********************************************************/
void affich_LTS (Pointeur_Main t);// affichage des champs de la liste (tab_sym) d'un Maillon_Main precise
void affichage (Pointeur_Main t);//affichage de la Table des symboles
/******************************************************Le module d'insertion *****************************************************************************/
void insertion (Pointeur_Main *P,string nom,string type,string attribut);//inserer un nouvelle Maillon_tab_sym dans un Maillon_Main
/************************************************* Les modules de la recherche ***************************************************************************/
bool recherche_maillon (Pointeur_Main p,string nom,string type ,string attribut);//rechercher si le triplet nom,type,attribut existe dans un maillon main pricis
void recherche(Pointeur_Main t,string nom,string type,string attribut);//recherche dans un tab de symbole tout les blocks ou se trouve la variable
bool recherche_bool(Pointeur_Main t,string nom,string type,string attribut);//recherche dans un table des symbole generale et donne vrai s'il existe
int recherche_maillon_stdin (Pointeur_Main p,char nom[],char type[] ,char attribut[]);//rechercher dans un Maillon_Main a partir de stdin ,donne vrai s'il existe
void recherche_stdin (Pointeur_Main t,char nom[],char type[],char attribut[]);//recherche dans un tab de symbole tout les blocks ou se trouv la variable
int rech_port(Pointeur_Main t,char titre[],char name[], char type[], char attribut[]);//rechercher a partir de stdin ,dans une portee pricise de la table des symbole en donnat le titre de cette portee
/**********************************************Les module de traitement des chaines de characters***********************************************************/
int is_type(string mot);//tester si un mot est donnee existe dans la table des types
int accolade_ouvrante(char ph[]);//tester si une chaine de character contient une accolade_ouvrante
int accolade_fermante(char ph[]);//tester si une chaine de character contient une accolade_fermante
string get_first(string str);//donne le premier mot d'une chaine de character en fonction de differents delimiteurs
int traiter_ligne (char str[]);// donne vrai s'il faut traiter la ligne donne
void sup_first(char str[]);// supprimer de la chaine les characters jusqua'un character donne
void sup_til_del (char str[],char del);// supprimer de la chaine les characters jusqua'un character donne
void sup_espace (string str);// Cette fonction supprime les espaces au début et à la fin d'une chaîne de caractères,ainsi que les espaces successifs au milieu de la chaîne.
int parenthese (char ph[]);//tester si une chaine de character contient un parenthese
/************************************D'autre Module a utiliser dans la creation de la table des symboles****************************************************/
Pointeur_Point find_courant_PP (Pointeur_Main t);//retourne un pointeur vers le dernier maillon de la liste des Maillon_Point
int mot_fonction_present(string titre);//testwer si le mot fonction existe dans le champs titre de Maillon_Main
int cmpt_block(Pointeur_Main t);//compter le nombre des sous blocks d'un block donne
/*********************************************Les modules de construction des titre des blocks**************************************************************/
string titre_fonc_glob(string name);// construire le titre de portee globale d'une fonc
string titre_fonc_block(string name, int n);// construire le titre des block d'une fonction
string titre_block_glob( int n);// construire le titre des block de la portee globale
/************************************************Les modules d'affichage de menu initial********************************************************************/
void loading_screen(int num_dots);//affiche un écran de chargement avec un nombre donné de points pour simuler le chargement d'une tâche
void print_image(FILE *fptr, char *filename, int x, int y);//afficher une image stockée dans un fichier texte sur l'écran, à une position spécifiée
void affichage_ini();// Cette fonction permet d'afficher un écran d'accueil avec des informations sur l'école et les développeurs du programme
void aide();// afficher une description de projet pour expliquer son fonctionnement et son but.
void printfslow(char ch[], int temps); // ecrire une chaine de caractere avec un temp d'arret entre chaque caractere
void submenu(Pointeur_Main* tete , FILE *fp); // affiche un sous-menu à l'utilisateur pour choisir un code source à compiler
/******************************************Le module initial de la creaction de la table des symboles****************************************************/
Pointeur_Main creer(char nom_f[]);//creation de la table de symbole a partir d'un fichier .txt ou .c
/***********************************************Le module qui cree une fichier a partir de stdin***********************************************************/
void wr_file();//creation d'une fichier .txt a partir stdin
#endif // BIB_INCLUDED
