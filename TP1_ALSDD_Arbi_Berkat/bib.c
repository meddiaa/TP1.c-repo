#include "bib_header.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>


/**Ce fichier introduit l'implementation C des types et procedures utilises dans le programme initial**/
/*******************************Les machines abstraites d'allocation*******************************************/
void Allouer_Main (Pointeur_Main *P) // allouer un espace de type maillon_main et retourner son adresse
{
*P = (struct Maillon_Main *) malloc( sizeof( struct Maillon_Main)) ;
(*P)->titre=NULL;
(*P)->PT = NULL;
(*P)->Suivant =NULL;
}

void Allouer_Point (Pointeur_Point *P) // allouer un espace de type maillon_point et retourner son adresse
{
*P = (struct Maillon_Point *) malloc( sizeof( struct Maillon_Point)) ;
(*P)->PM = NULL;
(*P)->Suivant=NULL;
}

void Allouer_tab (Pointeur_tab *P) // allouer un espace de type maillon_tab_sym et retourner son adresse
{
*P = (struct Maillon_tab_sym *) malloc( sizeof( struct Maillon_tab_sym)) ;
(*P)->nom=NULL;
(*P)->type=NULL;
(*P)->attribut=NULL;
(*P)->Suivant=NULL;
}
/************************Les machines abstraites pour libirer les espaces allouer*************************/
void Liberer_Main ( Pointeur_Main P) // liberer l'espace Mailloin_main deja alloue
{ free (P);}
void Liberer_Point ( Pointeur_Point P) // liberer l'espace maillon_point deja alloue
{ free (P);}
void Liberer_tab ( Pointeur_tab P) // liberer l'espace maillon_tab_sym deja alloue
{ free (P);}
/**************************Les machines abstraites pour recuperer***************************************/
Pointeur_tab PT_Main (Pointeur_Main P)// retourner la valeur du champ PT du Maillon_main
{return(P->PT);}

Pointeur_Point Suivant_Main(Pointeur_Main P)// retourner la valeur du champ Suivant du Maillon_main
{return (P->Suivant);}

string titre_Main(Pointeur_Main P)// retourner la valeur du champ Titre du Maillon_main
{return (P->titre);}

Pointeur_Main PM_Point(Pointeur_Point P)// retourner la valeur du champ PM du Maillon_point
{return(P->PM);}

Pointeur_Point Suivant_Point(Pointeur_Point P)// retourner la valeur du champ Suivant du Maillon_point
{return(P->Suivant);}

Pointeur_tab Suivant_tab_sym(Pointeur_tab P) // retourner la valeur du champ Suivant du Maillon_tab_sym
{return(P->Suivant);}

string nom_tab_sym(Pointeur_tab P)// retourner la valeur du champ nom du Maillon_tab_sym
{return (P->nom);}

string type_tab_sym(Pointeur_tab P)// retourner la valeur du champ du Maillon_tab_sym
{return (P->type);}

string attribut_tab_sym(Pointeur_tab P)// retourner la valeur du champ attribut du Maillon_tab_sym
{return (P->attribut);}

/******************************Les machines abstraites d'affectation*****************************************/
void AFF_titre_main (Pointeur_Main P,string ph) //affecter la valeur de ph au champ Titre du Maillon_Main
{
    P->titre= ph;
}
void AFF_PT_main (Pointeur_Main P,Pointeur_tab q)//affecter la valeur de q au champ PT du Maillon_Main
{
    P->PT=q;
}
void AFF_Suivant_main (Pointeur_Main P,Pointeur_Point q)//affecter la valeur de q au champ Suivant du Maillon_Main
{
    P->Suivant=q;
}
void AFF_PM_point (Pointeur_Point P,Pointeur_Main q)//affecter la valeur de q au champ PM du Maillon_Point
{
    P->PM=q;
}
void AFF_Suivant_point (Pointeur_Point P,Pointeur_Point q)//affecter la valeur de q au champ Suivant du Maillon_Point
{
    P->Suivant=q;
}
void AFF_nom_tab (Pointeur_tab P,string ph)//affecter la valeur de ph au champ nom du Maillon_tab_sym
{
    P->nom=ph;
}
void AFF_type_tab (Pointeur_tab P,string ph)//affecter la valeur de ph au champ type du Maillon_tab_sym
{
    P->type= ph;
}
void AFF_attribut_tab (Pointeur_tab P,string ph)//affecter la valeur de ph au champ attribut du Maillon_tab_sym
{
    P->attribut= ph;
}
void AFF_Suivant_tab (Pointeur_tab P,Pointeur_tab q)//affecter la valeur de q au champ Suivant du Maillon_tab_sym
{
    P->Suivant=q;
}
/****************************************Les machines abstraite de la pile des pointeurs main**************************************/
void Creerpile_Pi( Pointeur_Pi *P ) // creation d'une pile
{ *P = NULL ; }

bool Pilevide_Pi ( Pointeur_Pi P )//tester si la pile est vide
{ return (P == NULL ); }

void Empiler_Pi ( Pointeur_Pi *P, Pointeur_Main PM )//ajouter un element a la pile
{
Pointeur_Pi Q;
Q = (struct Maillon_Pi *) malloc( sizeof( struct Maillon_Pi)) ;
Q->PM = PM ;
Q->Suivant = *P;
*P = Q;
}

void Depiler_Pi ( Pointeur_Pi *P, Pointeur_Main *PM )//recuperer un element de la pile
{

Pointeur_Pi Sauv;
if (! Pilevide_Pi (*P) )
{
*PM = (*P)->PM ;
Sauv = *P;
*P = (*P)->Suivant;
Sauv->Suivant=NULL;
free(Sauv);
}
else *PM=NULL;
}

void afficher_pile(Pointeur_Pi P) //affichage de la pile
{
	Pointeur_Pi iter;
	iter=P;
	while(iter!=NULL)
	{
		printf("PM= %p \t  @Suiv= %p \n",iter->PM,iter->Suivant);
		iter=iter->Suivant;
	}
}
/***********************************Lea machines abstraites de la pile des pointeurs Point****************************/
void Creerpile_Pip( Pointeur_Pip *P ) // creation d'une pile
{ *P = NULL ; }

bool Pilevide_Pip ( Pointeur_Pip P )//tester si la pile est vide
{ return (P == NULL ); }

void Empiler_Pip ( Pointeur_Pip *P, Pointeur_Point PP )//ajouter un element a la pile
{
Pointeur_Pip Q;
Q = (struct Maillon_Pip *) malloc( sizeof( struct Maillon_Pip)) ;
Q->PP = PP ;
Q->Suivant = *P;
*P = Q;
}

void Depiler_Pip ( Pointeur_Pip *P, Pointeur_Point *PP )//recuperer un element de la pile
{

Pointeur_Pip Sauv;
if (! Pilevide_Pip (*P) )
{
*PP = (*P)->PP ;
Sauv = *P;
*P = (*P)->Suivant;
Sauv->Suivant=NULL;
free(Sauv);
}
else *PP=NULL;
}

void afficher_pip(Pointeur_Pip P)//affichage de la pile
{
	Pointeur_Pip iter;
	iter=P;
	while(iter!=NULL)
	{
		printf("PP= %p \t @Suiv= %p \n",iter->PP,iter->Suivant);
		iter=iter->Suivant;
	}
}
/***********************************Lea machines abstraites de la pile des entiers****************************/
void Creerpile_Pile( Pointeur_Pile *P )// creation d'une pile
{ *P = NULL ; }

bool Pilevide_Pile ( Pointeur_Pile P )//tester si la pile est vide
{ return (P == NULL ); }

void Empiler_Pile ( Pointeur_Pile *P, int Val )//ajouter un element a la pile
{
Pointeur_Pile Q;
Q = (struct Maillon_Pile *) malloc( sizeof( struct Maillon_Pile)) ;
Q->Val = Val ;
Q->Suivant = *P;
*P = Q;
}

void Depiler_Pile ( Pointeur_Pile *P, int *Val )//recuperer un element de la pile
{

Pointeur_Pile Sauv;
if (! Pilevide_Pile (*P) )
{
*Val = (*P)->Val ;
Sauv = *P;
*P = (*P)->Suivant;
Sauv->Suivant=NULL;
free(Sauv);
}
else printf ("Pile vide \n");
}

void afficher_Pile (Pointeur_Pile P)//affichage de la pile
{
	Pointeur_Pile iter;
	iter=P;
	while(iter!=NULL)
	{
		printf("Val= %d \t @Suiv= %p \n",iter->Val,iter->Suivant);
		iter=iter->Suivant;
	}
}
//fin des machines abstraites
/******************************************* Les modules d'affichage de la table des symboles **************************************************************/
//ce module affiche seulement le champs de la liste (tab_sym) d'un Maillon_Main precis ,on vas l'utiliser dans le module affichage globale
void affich_LTS (Pointeur_Main t)
{
    Pointeur_tab q;
    textcolor(LIGHTBLUE); //affichage en bleu clair 
    printf("TABLES DES SYMBOLES:%s\n",titre_Main(t));
    q=PT_Main(t);
    textcolor(WHITE);//affichage en blanc
    printf("Nom\t|\tType\t|\tAttribut\t\n") ;
    printf("_________________________________________________\n\n");
    while (q!=NULL){//parcours et affichage des maillos de la liste tab_sym
    printf("  %s\t\t%s\t\t%s\t\t\n",nom_tab_sym(q),type_tab_sym(q),attribut_tab_sym(q));
    q=Suivant_tab_sym(q);
    }
}
void affichage (Pointeur_Main t)//affichage de la Table des symboles
{
    Pointeur_Pip p;
    Creerpile_Pip (&p);// utilisation de la pile pour le parcours de tout la table
    Pointeur_Main iter;
    Pointeur_Point q;
    iter=t;
    affich_LTS(iter);//affichage de la liste tab_sym de portee globale
    q=Suivant_Main(iter);//passer au maillon suivante
    do
{
    while(q!=NULL) //parcour de la table verticalement avec affichage
    {
        Empiler_Pip(&p,q);
        iter=PM_Point(q);
        printf("_________________________________________________\n\n");
        affich_LTS(iter);//affichage de la liste tab_sym du maillon main pointe par iter
        q=Suivant_Main(iter);//passer au maillon suivante
    }
    Depiler_Pip(&p,&q);//pour le parcour horizontale
    if (q!=NULL)
    {
    q=Suivant_Point(q);
    }
}while(! Pilevide_Pip(p)||q!=NULL);
}
/********************************************************Le module d'insertion *****************************************************************************/
void insertion (Pointeur_Main *P,string nom,string type,string attribut)//inserer un nouvelle Maillon_tab_sym dans un Maillon_Main
{
    Pointeur_tab q,iter;
    Allouer_tab(&q);// allocation d'un nouveau Maillon_tab_sym
    AFF_nom_tab(q,nom);//remplire les champs du maillon
    AFF_type_tab(q,type);
    AFF_attribut_tab(q,attribut);
    iter=PT_Main(*P);
    if (iter==NULL){AFF_PT_main(*P,q);}//cas d'insertion au debut de la list
    else {
    while (Suivant_tab_sym(iter)!=NULL)//parcours et insertion a la fin de la liste
    {
       iter=Suivant_tab_sym(iter);
    }
    AFF_Suivant_tab(iter,q);//laison
    }
}
/***************************************************** Les modules de la recherche ************************************************************************/
//rechercher si le triplet nom,type,attribut existe dans un maillon main pricis,on vas l'utiliser aussi dans le module recherche general
bool recherche_maillon (Pointeur_Main p,string nom,string type ,string attribut)
{
  Pointeur_tab iter;
  iter=PT_Main(p);
  bool test=0;
  while (iter!=NULL&&test==0)//parcours de la list
  {
      if (nom==nom_tab_sym(iter)&&type==type_tab_sym(iter)&&attribut_tab_sym(iter)==attribut){test=1;} //tester si le tripler existe
      iter=Suivant_tab_sym(iter);//passer au suivant
  }
  return(test);
}

void recherche(Pointeur_Main t,string nom,string type,string attribut)//recherche dans un tab de symbole tout les blocks ou se trouve la variable
{
    Pointeur_Pip p;
    bool test;
    Creerpile_Pip (&p);// utilisation de la pile pour le parcours de tout la table
    Pointeur_Main iter;
    Pointeur_Point q;
    iter=t;
    q=Suivant_Main(iter);
    test=recherche_maillon(iter,nom,type,attribut);//recharche dans la portee globale
    if (test==1)
        {printf("Il est dans la Table des symbole de:\n%s\n",titre_Main(iter));}
do {
    while (q!=NULL)//parcour de la table verticalement et rechercher
    {
        Empiler_Pip(&p,q);
        iter=PM_Point(q);
        if (recherche_maillon(iter,nom,type,attribut))
        {
            if (test==1){printf("%s\n",titre_Main(iter));}
            else
            {
                printf("Il est dans la Table des symbole de:\n%s\n",titre_Main(iter));
                test=1;
            }
        }
        q=Suivant_Main(iter);//passer au suivant
    }
    Depiler_Pip(&p,&q);//pour le parcour horizontale
    if (q!=NULL)
    {
    q=Suivant_Point(q);
    }
}while(! Pilevide_Pip(p)||q!=NULL);
    if (test==0){printf("IL n'existe pas dans la table des symboles\n");}
}

bool recherche_bool(Pointeur_Main t,string nom,string type,string attribut)//recherche dans un table des symbole generale et donne vrai s'il existe
{
   Pointeur_Pip p;
    bool test=0;
    Creerpile_Pip (&p);// utilisation de la pile pour le parcours de tout la table
    Pointeur_Main iter;
    Pointeur_Point q;
    iter=t;
    q=Suivant_Main(iter);
    test=recherche_maillon(iter,nom,type,attribut);
    if (test==0)
 {
do {
    while (q!=NULL&&test==0)//parcour de la table verticalement et rechercher
    {
        Empiler_Pip(&p,q);
        iter=PM_Point(q);
        if (recherche_maillon(iter,nom,type,attribut))
        {
            test=1;
        }
        q=Suivant_Main(iter);//passer au suivant
    }
    Depiler_Pip(&p,&q);//pour le parcour horizontale
    if (q!=NULL)
    {
    q=Suivant_Point(q);
    }
}while((! Pilevide_Pip(p)||q!=NULL)&&test==0);
}
 return(test);
}

//rechercher dans un Maillon_Main a partir de stdin ,donne vrai s'il existe
int recherche_maillon_stdin (Pointeur_Main p,char nom[],char type[] ,char attribut[])
{
  Pointeur_tab iter;
  iter=PT_Main(p);
  int test=0;
  while (iter!=NULL&&test==0) //parcours de la list
  {
      if (strcmp(nom,nom_tab_sym(iter))==0&&strcmp(type,type_tab_sym(iter))==0&&strcmp(attribut_tab_sym(iter),attribut)==0){test=1;}//tester si le tripler existe
      iter=Suivant_tab_sym(iter);//passer au suivant
  }
  return(test);
}

//recherche a partir de stdin dans un table des symboles tout les blocks ou se trouve la variable
  void recherche_stdin (Pointeur_Main t,char nom[],char type[],char attribut[])//recherche dans un table des symboles tout les blocks ou se trouv la variable
{
    Pointeur_Pip p;
    bool test;
    Creerpile_Pip (&p);// utilisation de la pile pour le parcours de tout la table
    Pointeur_Main iter;
    Pointeur_Point q;
    iter=t;
    q=Suivant_Main(iter);
    test=recherche_maillon_stdin(iter,nom,type,attribut);//recharche dans la portee globale
    if (test==1)
        {gotoxy(30,10);textcolor(GREEN);printf("Elle est dans la Table des symbole de : %s",titre_Main(iter));}
do {
    while (q!=NULL)//parcour de la table verticalement et rechercher
    {
        Empiler_Pip(&p,q);
        iter=PM_Point(q);
        if (recherche_maillon_stdin(iter,nom,type,attribut)==1)
        {
            if (test==1){printf("%s\n",titre_Main(iter));}
            else
            {
                gotoxy(30,10);textcolor(GREEN);
                printf("Elle est dans la Table des symbole de:%s",titre_Main(iter));
                test=1;
            }
        }
        q=Suivant_Main(iter);//passer au suivant
    }
    Depiler_Pip(&p,&q);//pour le parcour horizontale
    if (q!=NULL)
    {
    q=Suivant_Point(q);
    }
}while(! Pilevide_Pip(p)||q!=NULL);
    if (test==0){gotoxy(30,10);textcolor(RED);printf("Elle n'existe pas dans la table des symboles\n");}
}
//rechercher a partir de stdin ,dans une portee pricise de la table des symbole en donnat le titre de cette portee,et donne vrais s'elle existe
int rech_port(Pointeur_Main t,char titre[],char name[], char type[], char attribut[])
 {
   int result=0;
   if (strcmp(titre_Main(t),titre)==0&&recherche_maillon_stdin(t,name,type,attribut)==1)//recherche dana la portee globale
       {result=1;}
   else
    {
    Pointeur_Pip p;
    Creerpile_Pip (&p);// utilisation de la pile pour le parcours de tout la table
    Pointeur_Main iter;
    iter=t;
    Pointeur_Point q;
    q=Suivant_Main(iter);
    do
    {
    while (q!=NULL&& result==0)//parcour de la table verticalement et rechercher
    {
        Empiler_Pip(&p,q);
        iter=PM_Point(q);
        if (strcmp(titre_Main(iter),titre)==0&&recherche_maillon_stdin(iter,name,type,attribut)==1)//tester
         {result=1;}
        else
         {q=Suivant_Main(iter);}//passer au suivant
    }
    Depiler_Pip(&p,&q);//pour le parcour horizontale
    if (q!=NULL)
    {
    q=Suivant_Point(q);
    }
    }while((!Pilevide_Pip(p)||q!=NULL)&&result==0);
    }
    return result ;
}

/**********************************************Les module de traitement des chaines de characters*********************************************************/
int is_type(string mot)//tester si un mot donnee existe dans la table des types (le mot est un type )
{
     for (int i=0 ; i < 5; i++)//parcours du tableau des types
    {
       if (strcmp(mot,types[i])== 0)//comparaison
       {
           return 1;
       }
    }
    return 0;
}

int accolade_ouvrante(char ph[])//tester si une chaine de character contient une accolade_ouvrante
{
    int test=0;
    for(int i = 0 ; i < strlen(ph) ; i++)//parcours de la chaine
    {
        if( ph[i]=='{' ){ test=1; }//comparaison
    }
    return test;
}

int accolade_fermante(char ph[])//tester si une chaine de character contient une accolade_fermante
{
    int test=0;
    for(int i = 0 ; i < strlen(ph) ; i++)//parcours de la chaine
    {
        if(  ph[i] == '}' ){ test=1 ; }//comparaison
    }
    return test;
}

string get_first(string str) //donne le premier mot d'une chaine de character en fonction de differents delimiteurs
{
    string first_word=NULL;
    int size=0;
    int i = 0;
    if (str[i]=='=')//cas de =, passer au suivant character
        {
         do
         {
             i++;
         }while (str[i]!=','&&str[i]!=';');
         if (str[i]==','||str[i]==';'){i++;} //cas de , ou ; passer au suivant character
        }
    while (str[i] != ' '&& str[i]!=')' && str[i]!='(' &&str[i]!=','&& str[i]!=';'&&str[i]!='}'&&str[i]!='{'&&str[i]!='='&& str[i] != '\0')//parcours avec criters d'arret
    {
          size++;
        first_word=realloc(first_word,size+1);//allocation memoire
        if (first_word == NULL)
        {
            fprintf(stderr, "Erreur: Echec d'allocation m�moire.\n");
            exit(EXIT_FAILURE);
        }
        first_word[size-1] = str[i];
        first_word[size] = '\0';//ajouter le character NULL a la fin du mot
         i++;
    }
    if (str[0]=='{'||str[0]=='}'||str[0]=='('||str[0]==')')//cas de { ou } ou( ou ) le retourner
    {
               size++;
        first_word=realloc(first_word,size+1);//allocation memoire
        if (first_word == NULL)
        {
            fprintf(stderr, "Erreur: Echec d'allocation m�moire.\n");
            exit(EXIT_FAILURE);
        }
        first_word[0]=str[0];
        first_word[1]='\0';
    }
return (first_word);
}

int traiter_ligne (char str[])// donne vrai s'il faut traiter la ligne donne
{
    if((accolade_fermante(str) ||accolade_ouvrante(str) || is_type(get_first(str))) == true) { return 1;}//condition de traitement
    return 0 ;
}

void sup_first(char str[])//supprime le premier mot d'une chaine de character en fonction de differents delimiteurs
 {
     int i=0,j=0;
     int test=0;
     while (str[j]!=';'&&str[j]!=','&&str[j]!=' '&&str[j]!='{'&&str[j]!='}'&&str[j]!=')'&&str[j]!='(')//compter le nombre de char a decaler en fonction des delimiteurs
     {
         if (test==0){test=1;}
         j++;

     }
     while(str[j]==';'||str[j]==','||str[j]==' ')//cas de l'espace ou , ou ;
        {
            if (test==0){test=1;}
            j++;
        }
    if ((str[j]=='{'||str[j]=='}'||str[j]=='('||str[j]==')')&& test==0){j++;}
     i=j;
     while (i < strlen(str))//declage
    {
      str[i-j] = str[i];
      i++;
    }
    str[i-j] = '\0';//ajouter le charachter NULL a la fin de la chaine

 }

void sup_til_del (char str[],char del)// supprimer de la chaine les characters jusqua'un character donne
{
    int j=0;
    while(str[j]!=del)//compter le nombre de character a supprimer
    {
        j++;
    }
    int i=j;
    while (i<strlen(str))
    {
        str[i-j]=str[i];//decalage
        i++;
     }
     str[i-j]='\0';//ajouter le character NULL a la fin de la chaine de characters
}

void sup_espace (string str)// Cette fonction supprime les espaces au début et à la fin d'une chaîne de caractères
//ainsi que les espaces successifs au milieu de la chaîne.
 {
    int i, j, k;
    int len = strlen(str);
    i = 0;
    // Supprimer les espaces au début de la chaîne
    while (isspace(str[i]))//vérifier si un caractère est un espace (espace, tabulation, retour à la ligne, etc.)
    {
        i++;
    }
    if (i > 0) {
        memmove(str, str + i, len - i + 1);//déplacer des blocs de mémoire.
        len -= i;
    }
    // Supprimer les espaces à la fin de la chaîne
    j = len - 1;
    while (isspace(str[j])) //vérifier si un caractère est un espace (espace, tabulation, retour à la ligne, etc.)
    {
        j--;
    }
    str[j + 1] = '\0';//ajouter le character Null a la fin de la chaine
    len = j + 1;

    // supprimer les espaces de milieu de la  chaine de char
    i = 0;
    j = 0;
    while (j < len) {
        if (isspace(str[j])) {
            k = j + 1;
            while (isspace(str[k])) {
                k++;
            }
            if (k < len) {
                memmove(str + i + 1, str + k, len - k + 1);//déplacer des blocs de mémoire.
                len -= k - (j + 1);
            }
        }
        i++;
        j++;
    }
}

int parenthese (char ph[])//tester si une chaine de character contient un parenthese
{
    int test=0;
    for(int i = 0 ; i < strlen(ph) ; i++)//parcours de la chaine
    {
        if( ph[i] == '('){ test=1; } //test
    }
    return (test) ;
}

/************************************D'autre Module a utiliser dans la creation de la table des symboles****************************************************/
Pointeur_Point find_courant_PP (Pointeur_Main t)//retourne un pointeur vers le dernier maillon de la liste des Maillon_Point
{
    Pointeur_Point p=Suivant_Main(t);
    while (Suivant_Point(p)!=NULL)//parcours de la liste
    {
        p=Suivant_Point(p);
    }
  return(p);
}

int mot_fonction_present(string titre)//testwer si le mot fonction existe dans le champs titre de Maillon_Main
{
    // Cherche le mot "fonction" dans la chaîne de caractères.
    string mot_fonction = strstr(titre, "fonction");

    // Si le mot est présent, retourne vrai.
    if (mot_fonction != NULL) {
        return 1;
    }

    // Sinon, retourne faux.
    return 0;
}

int cmpt_block(Pointeur_Main t)//compter le nombre des sous blocks d'un block donne (=le nombre des Maillons_Point de la liste attachee au Maillon_Main)
{
  int cpt=0;
  Pointeur_Point q;
  q=Suivant_Main(t);
  while (q!=NULL)//parcoyrs de la liste
   {
      cpt++;//incrementation de compteur
      q=Suivant_Point(q);//passer au suivant
   }
   return cpt;
}

/*********************************************Les modules de construction des titre des blocks**************************************************************/
string titre_fonc_glob(string name)// construire le titre de portee globale d'une fonc
{
    string statement = malloc(strlen("Portee globale de la fonction") + strlen(name) + 1);//allocation memoire pour la chaine de characters
    sprintf(statement, "Portee globale de la fonction %s", name);//coposition de la chaine de characters (titre)
    return statement;
}

string titre_fonc_block(string name, int n)// construire le titre des block d'une fonction
{
    // calculate length of statement
    int length = strlen("block ") + sizeof(int) + strlen(" de la fonction ") + strlen(name) + 1;

    // allocate memory for statement
    string statement = (char*)malloc(length * sizeof(char));

    // build statement
    sprintf(statement, "block %d de la fonction %s", n, name);

    return statement;
}

string titre_block_glob( int n)// construire le titre des block de la portee globale
{
    // calculate length of statement
    int length = strlen("block ") + sizeof(int) + strlen(" de la portee globale ") ;

    // allocate memory for statement
    string statement = (char*)malloc(length * sizeof(char));

    // build statement
    sprintf(statement, "block %d de la portee globale ", n);

    return statement;
}

/************************************************Les modules d'affichage de menu initial********************************************************************/
void loading_screen(int num_dots)//affiche un écran de chargement avec un nombre donné de points pour simuler le chargement d'une tâche
// Le nombre de points à afficher est spécifié en entrée de la fonction en tant que paramètre "num_dots"
{
    printf("Loading : ");
    for (int i = 0; i < num_dots; i++) //une boucle "for" pour afficher chaque point "#" à l'écran
    {
        printf("#");
       // Entre chaque affichage de point, un délai de 0,005 secondes est appliqué en utilisant la fonction "Sleep()"
        Sleep(5);
            fflush(stdout);  // La fonction "fflush(stdout)" est appelée pour vider le tampon de sortie et assurer l'impression immédiate de chaque point à l'écran
    }
    printf("\n");//une nouvelle ligne "\n" pour séparer l'écran de chargement de la sortie suivante.
}

void print_image(FILE *fptr, char *filename, int x, int y)//afficher une image stockée dans un fichier texte sur l'écran, à une position spécifiée
{
    char read_string[MAX_LEN];
    if ((fptr = fopen(filename, "r")) == NULL)// Le fichier texte contenant l'image est ouvert en lecture seule en utilisant la fonction "fopen()" et stocké dans un pointeur de fichier "fptr"
    {
        fprintf(stderr, "error opening %s\n", filename);// Si le fichier ne peut pas être ouvert, un message d'erreur est affiché à l'écran avec la fonction "fprintf()" et la fonction se termine avec une sortie d'erreur
        // exit with failure
        exit(1);
    }

    while (fgets(read_string, sizeof(read_string), fptr) != NULL)// La fonction "fgets()" est utilisée pour lire chaque ligne du fichier texte stockée dans la variable "read_string" jusqu'à la fin du fichier
    {
        gotoxy(x, y);// La fonction "gotoxy()" permet de déplacer le curseur à la position spécifiée par les coordonnées x et y en utilisant des commandes de console
        printf("%s", read_string);// La chaîne de caractères stockée dans "read_string" est imprimée à l'écran avec la fonction "printf()"
        y++;// La variable y est incrémentée pour passer à la ligne suivante de l'image
    }
}

void affichage_ini()// Cette fonction permet d'afficher un écran d'accueil avec des informations sur l'école et les développeurs du programme
{
    // Les noms des fichiers texte contenant les images à afficher sont stockés dans les variables "filename" et "filename2"
    FILE *fptr;
    FILE *fptr2;
    char *filename2 = "./compilateur.txt";// Les pointeurs de fichier "fptr" et "fptr2" sont initialisés
    char *filename = "./esi.txt";
    textcolor(BLUE);// La couleur du texte est changée en bleu avec la fonction "textcolor()" pour la première image à afficher
    print_image(fptr, filename, 1, 1);// La fonction "print_image()" est appelée pour afficher l'image spécifiée par "filename" à la position (1, 1) en utilisant le pointeur de fichier "fptr"
    gotoxy(1, 7);// Le curseur est positionné à la ligne 7 avec la fonction "gotoxy()"
    textcolor(WHITE);// La couleur du texte est changée en blanc avec la fonction "textcolor()"
    printf("%ccole nationale sup%crieure d'informatique\n", 130, 130, 130);// Des informations sur l'école sont imprimées à l'écran avec la fonction "printf()"
    printf("Oued Smar, Alger, Alg%crie\n", 130);
    filename = "compilateur.txt";// La variable "filename" est mise à jour avec une nouvelle valeur "compilateur.txt"
    // go to the middle of the screen
    textcolor(WHITE);// La couleur du texte est à nouveau changée en blanc pour la deuxième image à afficher
    print_image(fptr2, filename2, 1, 13);// La fonction "print_image()" est appelée pour afficher l'image spécifiée par "filename2" à la position (1, 13) en utilisant le pointeur de fichier "fptr2"
    // go to the bottom of the screen
    gotoxy(90, 3);// Le curseur est positionné en bas à droite de l'écran avec la fonction "gotoxy()"
    textcolor(WHITE);
    printf("r%calis%cs par : \n", 130, 130);// Des informations sur les développeurs du programme sont imprimées à l'écran avec la fonction "printf()"
    gotoxy(90, 5);
    printf("- ARBI mohamed diaa eddine G12");
    gotoxy(90, 6);
    printf("- BERKAT cheraz G11");
    gotoxy(90, 29);
    textcolor(WHITE);
    printf("Ann%ce universitaire 2022-2023", 130);
    // go to the bottom middle of the screen
    gotoxy(15, 22);// Le curseur est positionné au milieu inférieur de l'écran avec la fonction "gotoxy()"
    textcolor(RED);
    printf("Appuyez sur H pour afficher l'aide et d'autre detailles sur notre programme ");// Un message invitant l'utilisateur à appuyer sur la touche "H" pour afficher l'aide et les détails du programme est imprimé à l'écran avec la fonction "printf()"
    gotoxy(15, 23);
    printf("Appuyez sur n'importe quelle touche pour continuer ...");// Un message invitant l'utilisateur à appuyer sur n'importe quelle touche pour continuer est imprimé à l'écran avec la fonction "printf()"
}

void aide()// afficher une description de projet pour expliquer son fonctionnement et son but.
{
    //La variable aide est initialisée avec une chaîne de caractères contenant cette description.
    char aide[820] = "Notre projet consiste a simuler le travail d'un compilateur pour generer les tables de symboles d'un code source en langage C. Nous avons implemente les operations d'insertion et de recherche des symboles a l'aide de machines abstraites, en utilisant une structure de donnees de liste chainee pour stocker les tables de symboles. Notre programme analyse le code source pour detecter les symboles tels que les variables, les fonctions et les constantes, et les ajoute a la table de symboles appropriee. Notre programme fournit une interface utilisateur simple pour entrer le fichier source C et visualiser les tables de symboles generees. Le but de ce projet est de mieux comprendre le fonctionnement d'un compilateur et de mettre en pratique nos connaissances en langage C et en structures de donnees.";
    gotoxy(2, 10);// placer le curseur à la position (2, 10) pour commencer l'affichage de la description.
    textcolor(WHITE);
    for (int i = 0; i < 820; i++)//afficher chaque caractère de la chaîne de caractères aide à l'aide de la fonction putchar.
    {
        putchar(aide[i]);
        fflush(stdout); // afficher immédiatement le caractère
        usleep(1000);   // Délai de 0.1 seconde
    }
    gotoxy(2, 30);//placer le curseur à la position (2, 30)
    //afficher un message pour demander à l'utilisateur d'appuyer sur n'importe quelle touche pour retourner au menu.
    printf("Appuyez sur n'importe quelle touche pour retourner au menu ...");
}

void printfslow(char ch[], int temps) // ecrire une chaine de caractere avec un temp d'arret entre chaque caractere
{
    //La chaîne de caractères est passée en paramètre à la fonction.
    //Le temps d'arrêt entre chaque caractère est spécifié par le deuxième paramètre temps.
    int i;
    for (i = 0; i < strlen(ch); i++)//parcourt la chaîne de caractères
    {
        printf("%c", ch[i]);//écrit chaque caractère
        delay(temps);//suspendre l'exécution du programme pendant le temps d'arrêt.
    }
}

void submenu(Pointeur_Main* tete , FILE *fp) // affiche un sous-menu à l'utilisateur pour choisir un code source à compiler

{
    int choix2 = 1; // choix par défaut est la première option
    int numOptions = 5;// nombre total d'options dans le menu
    int keyPressed;
    int yStart = 15;  // coordonnée y de la première option dans le menu
    // Efface l'écran et affiche le menu
    clrscr();
     gotoxy(33,13);
    textcolor(GREEN) ;
    printf("Choisissez le code que vous voulez compiler : ");
    textbackground(BLACK); // définir la couleur de fond par défaut en noir
    textcolor(WHITE); // définir la couleur de texte par défaut en blanc
    gotoxy(45, yStart);
    printf("CODE1\n");
    gotoxy(45, yStart+1);
    printf("CODE2\n");
    gotoxy(45, yStart+2);
    printf("CODE3\n");
    gotoxy(45, yStart+3);
    printf("Entrer le nom de votre fichier\n");
    gotoxy(45, yStart+4);
    printf("Saisir votre propre code source\n");

    do {
        // attendre l'entrée de l'utilisateur
        keyPressed = getch();

        // mettre à jour l'option sélectionnée en fonction de l'entrée de l'utilisateur
        switch (keyPressed) {
            case 72: // up arrow
                choix2 = choix2 > 1 ? choix2 - 1 : numOptions;
                break;
            case 80: // down arrow
                choix2 = choix2 < numOptions ? choix2 + 1 : 1;
                break;
            default:
                break;
        }

        // mettre à jour l'affichage du menu en fonction de l'option sélectionnée
        for (int i = 1; i <= numOptions; i++) {
            gotoxy(45, yStart+i-1);
            textbackground(i == choix2 ? RED : BLACK); // définir la couleur de fond en blanc pour l'option sélectionnée
            textcolor(i == choix2 ? BLACK : WHITE); // définir la couleur de texte en noir pour l'option sélectionnée
        switch (i) {
                case 1:
                    printf("CODE1\n");
                    break;
                case 2:
                    printf("CODE2\n");
                    break;
                case 3:
                    printf("CODE3\n");
                    break;
                case 4:
                    printf("Entrer le nom de votre fichier\n");
                    break;
                case 5:
                    printf("Saisir votre propre code source\n");
                    break;
                default:
                    break;
            }
            textbackground(BLACK);  // définir la couleur de fond en noir
            textcolor(WHITE); // définir la couleur de texte en blanc
        }
    } while (keyPressed != 13); // continuer jusqu'à ce que la touche Entrée soit pressée
    // effectuer l'action en fonction de l'option sélectionnée
    switch (choix2) {
        case 1:
            *tete = creer("code1.c");
            break;
        case 2:
            *tete = creer("code2.c");
            break;
        case 3:
            *tete = creer("code3.txt");
            break;
        case 4:
            clrscr();
            char titre[20];
            scanf("%s", &titre);
            *tete = creer(titre);
            break;
        case 5 :
            clrscr();
            wr_file();
            *tete = creer("stdin.txt");
            break;
        default:
            break;
    }
}

/******************************************** Le module initial de la creaction de la table des symboles*******************************************************************/
Pointeur_Main creer(char nom_f[])//creation de la table de symbole a partir d'un fichier .txt ou .c
{
  FILE *fp;
  char ligne[100];
  //INITIALISATION DES VAR
  int dep = 0, cpt = 0, test_ttr = 0, first_var_block = 0, fonction = 0;
//dep booleen pour tester s'il faut depiler quand trouver } ou non
//test_ttr booleen pour tester si le titre de Maillon_main contient le mot fonction
//first_var_block booleen pour tester si la variable est la premiers dans le block ( il faut inserer la variable dans un noveau block)
//fonction booleen pour tester si la varible est une fonction avec parametre
  string nom = NULL, type = NULL, attribut = NULL, snom_f = NULL;
//snom_f une variable pour sauvegarder le nom de la variable
  Pointeur_Main courant_main = NULL, t = NULL;
  Pointeur_Point courant_PP = NULL, new_PP = NULL;
  Pointeur_Pi p, f;
  Pointeur_Pile d;
  Allouer_Main(&t);// allocation memoire pour la portee globale
  if (t == NULL)
  {
    printf("failed to allocate memory\n");
    return NULL;
  }
  courant_main = t;
  AFF_titre_main(courant_main, "PORTEE GLOBALE");//affectation du champs titre de portee globale
  Creerpile_Pi(&p);//creation de la pile des pointeur point pour sauvgarder les @ des blocks
  Creerpile_Pi(&f);//creation de la pile des pointeur point pour sauvgarder les @ des blocks des fonction dans le cas d'une fonction avec parametres
  Creerpile_Pile(&d);//creation d'une pile des entiers pour sauvgarder les valeurs de la variable dep de chaque block
  // Ouvre le fichier en mode lecture
  fp = fopen(nom_f, "r");
  // Vérifie si le fichier est ouvert avec succès
  if (fp == NULL)
  {
    printf("Impossible d'ouvrir le fichier.\n");
    return 0;
  }

  while (fgets(ligne, 100, fp) != NULL)// Lit le fichier ligne par ligne
  {
    sup_espace(ligne);//supprimer les espaces de la ligne
//----------------------------------------------------------------------------------------------------------------------------------------------------//
    while (strlen(ligne) > 0 && traiter_ligne(ligne) == 1)//tester s'il faut traiter la ligne en bouclant jusqu'a la longeur de la ligne est =0
    {
      if (is_type(get_first(ligne)) == 1)//tester si le premier mot de la ligne est un type
      {
        type = get_first(ligne);//extraction du type de la variable
        sup_first(ligne);//supression du premier mot dejas extraire
        nom = get_first(ligne);//extraction du nom de la variable
        sup_first(ligne);//supression du premier mot dejas extraire
//--------------------------------------------------------------------------------------------------------------------------------------------------//
        if (first_var_block == 1)//tester si la variable est le premier declaration dans le block
            //si oui allocation memoire
        {
          dep = 1;//affectation de la variable dep a 1
          if (fonction == 0) // tester si la variable est une fonction avec parametre
            //si non allocation memoire
          {
            Allouer_Point(&new_PP);//allocation d'un Maillon_Point
            if (Suivant_Main(courant_main) == NULL)//tester si le champ Suivant de Maillon_Main est NULL
            { //si oui laison avec Maillon_point dejas alloue
              AFF_Suivant_main(courant_main, new_PP);
            }
            Empiler_Pi(&p, courant_main);//Empiler l'@ du Maillon_Main courante
            courant_PP = find_courant_PP(courant_main);//mise a jour de la variable courant_PP
            if (courant_PP != NULL && courant_PP != new_PP)/*tester si la variable courant_PP qui pointe le Maillon_Point est diferrent de NULL
            et de la valeur de new_PP qui pointe noveau Maillon_Point alloue*/
            {//si oui
              AFF_Suivant_point(courant_PP, new_PP);//laison entre le maillon pointe par courant_PP et New_PP
            }
            cpt = cmpt_block(courant_main);//compter le nombre de block dans Maillon_Main pour la consruction du titre
            test_ttr = mot_fonction_present(titre_Main(courant_main));//affecter a la vaiable test_ttr le resultat de test si le titre du Maillon_Main courante conient le mot fonction
            Allouer_Main(&courant_main);//allocation d'un noveau Maillon_Main
            if (strcmp(attribut, "fonction") == 0)//tester si la variable est une fonction avec parametre
            {//si oui
              AFF_titre_main(courant_main, titre_fonc_glob(snom_f));//affectation au champs titre de Maillon_Main un titre d'une fonction globale
            }
            else
            { //si non
              if (test_ttr == 1)//tester si le champs titre du Maillon_Main contient le mot fonction
              {//si oui
                AFF_titre_main(courant_main, titre_fonc_block(snom_f, cpt));//affectation au champs titre de Maillon_Main un titre d'un block de fonction
              }
              else
              {//si non
                AFF_titre_main(courant_main, titre_block_glob(cpt));//affectation au champs titre de Maillon_Main un titre d'un block de portee globale
              }
            }
            courant_PP = new_PP;//mise a jour de courant_Point avec new_PP (pour qu'il pointe le dernier Maillon_POint)
            AFF_PM_point(courant_PP, courant_main);//laison entre Maillon_point courante et Maillon_Main
            first_var_block = 0;//affectation de la valeur zero a la variable first_var_block (la varible est ne plus la premiere dans le block
          }
          else
          // si non trouver l'@ de maillon de la fonction
          {
            Empiler_Pi(&p, courant_main);//sauvgarder l'@ de maillon_main courante
            Depiler_Pi(&f, &courant_main);//depiler l'@ de la pile des adresses des blocks des fonctions
            fonction = 0;//mise a jour de la variable fonctiona zero (on a traiter le cas d'une fonction avec des parametres )
          }
        }
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//
        if (strcmp(type, "void") == 0 || parenthese(ligne) == 1) // cas d'une variable fonction
        {
          attribut = "fonction";//affectation au variable attribut la valeur "fonction"
          snom_f = nom;//sauvgarder le nom de la fonction pour l'utiliser apres dans le titre
          if (recherche_maillon(courant_main, nom, type, attribut) == 0) //tester si la fonction n'exite pas dans ce block
          {//si oui
            insertion(&courant_main, nom, type, attribut);//insertion
          }
          sup_first(ligne);//supprimer le premier mot de la ligne
          if (*get_first(ligne) != ')' && get_first(ligne) != NULL)//tester si la fonction a des parametres
          { //si oui
            attribut = "parametre";//affectation au variable attribut la valeur "parametre"
            Allouer_Point(&new_PP);//allocation memoire d'un noveau Maillon_Point
            if (Suivant_Main(courant_main) == NULL)//tester si le champ Suivant de Maillon_Main est NULL
            {//si oui laison avec Maillon_point dejas alloue
              AFF_Suivant_main(courant_main, new_PP);
            }
            Empiler_Pi(&p, courant_main);//Empiler l'@ du Maillon_Main courante
            courant_PP = find_courant_PP(courant_main);//mise a jour de la variable courant_PP

            if (courant_PP != NULL && courant_PP != new_PP)/*tester si la variable courant_PP qui pointe le Maillon_Point est diferrent de NULL
            et de la valeur de new_PP qui pointe noveau Maillon_Point alloue*/
            {//si oui
              AFF_Suivant_point(courant_PP, new_PP);//laison entre le maillon pointe par courant_PP et New_PP
            }
            Allouer_Main(&courant_main);//allocation d'un noveau Maillon_Main
            AFF_titre_main(courant_main, titre_fonc_glob(nom));//affectation au champs titre de Maillon_Main un titre d'un block de portee globale
            courant_PP = new_PP;//mise a jour de courant_Point avec new_PP (pour qu'il pointe le dernier Maillon_POint)
            AFF_PM_point(courant_PP, courant_main);//laison entre Maillon_point courante et Maillon_Main
            type = get_first(ligne);//extraction du type de la variable
            sup_first(ligne);//supression du premier mot dejas extraire
            nom = get_first(ligne);//extraction du nom de la variable
            sup_first(ligne);//supression du premier mot dejas extraire
            if (recherche_maillon(courant_main, nom, type, attribut) == 0)//tester si la variable n'exite pas dans ce block
            {//si oui laison avec Maillon_point dejas alloue
              insertion(&courant_main, nom, type, attribut);
            }
            while (get_first(ligne) != NULL && strcmp(get_first(ligne), ")") != 0)//traitement de cas de plusieurs parametres
              if (is_type(get_first(ligne)) == 1)//tester si le premier mot est un type
              {
                type = get_first(ligne);//extraction du type de la variable
                sup_first(ligne);//supression du premier mot dejas extraire
                nom = get_first(ligne);//extraction du nom de la variable
                sup_first(ligne);//supression du premier mot dejas extraire
                if (recherche_maillon(courant_main, nom, type, attribut) == 0)//tester si la variable n'exite pas dans ce block
                {//si non laison avec Maillon_point dejas alloue
                  insertion(&courant_main, nom, type, attribut);
                }
              }
              else
              {//traitement de cas de plusieurs parametres de meme type
                nom = get_first(ligne);//extraction du type de la variable
                sup_first(ligne);//supression du premier mot dejas extraire
                if (recherche_maillon(courant_main, nom, type, attribut) == 0)//tester si la variable n'exite pas dans ce block
                {//si non laison avec Maillon_point dejas alloue
                  insertion(&courant_main, nom, type, attribut);
                }
              }
            fonction = 1;//mise a jour de la variable fonction a 1 (fonction avec parametre)
            Empiler_Pi(&f, courant_main);//sauvegarder l'@ de blocks de la fonction dans la pile des @ des blocks des fonctions
            Depiler_Pi(&p, &courant_main);//recupirerl'@ du block ou se trouv cette fonction
          }
        }
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------//
        else //cas d'une variable
        {
          attribut = "var";//affectation au variable attribut la valeur "var"
          if (recherche_maillon(courant_main, nom, type, attribut) == 0)//tester si la variable n'exite pas dans ce block
          {//si non laison avec Maillon_point dejas alloue
            insertion(&courant_main, nom, type, attribut);
          }
          while (get_first(ligne) != NULL)//traitement de cas de plusieurs parametres de meme type
          {
            nom = get_first(ligne);//extraction du type de la variable
            if (recherche_maillon(courant_main, nom, type, attribut) == 0)//tester si la variable n'exite pas dans ce block
            {//si non laison avec Maillon_point dejas alloue
              insertion(&courant_main, nom, type, attribut);
            }
            sup_first(ligne);//supression du premier mot dejas extraire
          }
        }
      }
      else
      {//si le premier mot de la ligne n'est pas un type
        if (accolade_ouvrante(ligne) == 1)//tester si la ligne contient une accolade_ouvrante
        {
          sup_til_del(ligne, '{');//suppression jusqua'un delimiteur '{'
          first_var_block = 1;//affectation de la variable first_var_block a 1 (un noveau blocks)
          Empiler_Pile(&d, dep);// sauvgarder la valeur de la variable dep dans la pile des entiers
          dep = 0;//mise a jour de la variable dep
          sup_first(ligne);//supprimer le premier mot de la ligne (='}')
        }
        else
        {//si la ligne ne contien pas un accolade_ouvrante (donc il contient accolade_fermante)
          if (dep == 1)//tester si dep =1 (donc il faut dipiler)
          {
            Depiler_Pi(&p, &courant_main);//recuperer l'@ de Maillon_Main de la pile des Pointeurs_Main car le block est ferme
            courant_PP = find_courant_PP(courant_main);//mise a jours de courant_PP
          }
          Depiler_Pile(&d, &dep);//recuperer la valeur de dep de ce block de la pile des entiers
          fonction = 0;//affectation de la valeur zero a la variable fonction
          first_var_block = 0;//affectation de la valeur zero a la variable first_var_block
          sup_til_del(ligne, '}');//suppression jusqua'un delimiteur '}'
          sup_first(ligne);//supprimer le premier mot de la ligne (='{')
        }
      }
    }
  }
  fclose(fp);
  return t;
}
/***********************************************Le module qui cree une fichier a partir de stdin***********************************************************/
void wr_file()//creation d'une fichier .txt a partir stdin
{
    char line[MAX_LINE_LENGTH]; // ligne de code source à enregistrer dans le fichier 
    int count = 0; // nombre de lignes de code source enregistrées dans le fichier
    char **lines = NULL; // tableau dynamique des lignes de code source enregistrées dans le fichier
    int dollar_count = 0; // nombre de lignes de code source qui contiennent uniquement le caractère '$'
    int finished = 0; 

    printf("Tapez les lignes de code source à enregistrer dans le fichier. Entrez '$' pour terminer :\n");
    // on a opté pour finir le fichier avec un seul caractère '$' car il n'est pas utulisé dans le langage C 
    while (!finished && fgets(line, MAX_LINE_LENGTH, stdin) != NULL) { // on lit une ligne de code source à la fois
        if (line[0] == '$' && line[1] == '\n') {
            dollar_count++;
            if (dollar_count == 1) {
                finished = 1; // on a lu une ligne contenant uniquement le caractère '$' donc on arrête de lire stdin 
            }
        } else {
            dollar_count = 0;
            lines = realloc(lines, (count + 1) * sizeof(char *)); // on alloue de la mémoire pour stocker une nouvelle ligne de code source
            if (lines == NULL) {
                fprintf(stderr, "Error: Failed to reallocate memory for lines.\n");
                exit(EXIT_FAILURE);
            }
            lines[count] = malloc((strlen(line) + 1) * sizeof(char));// on alloue de la mémoire pour stocker la ligne de code source
            if (lines[count] == NULL) {
                fprintf(stderr, "Error: Failed to allocate memory for line.\n");
                exit(EXIT_FAILURE);
            }
            strcpy(lines[count], line);
            count++;
        }
    }
    FILE *fp; // pointeur sur le fichier à créer 
    fp = fopen("stdin.txt", "w"); // on ouvre le fichier en mode écriture
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open output file.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s", lines[i]); // on écrit chaque ligne de code source dans le fichier 
    }

    fclose(fp); // on ferme le fichier 

    for (int i = 0; i < count; i++) {
        free(lines[i]); // on libère la mémoire allouée pour chaque ligne de code source 
    }
    free(lines); // on libère la mémoire allouée pour le tableau des lignes de code source 
}
//-------------------------------------------------------fin de la bib-------------------------------------------------------------------------------------//
