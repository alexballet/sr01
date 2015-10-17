
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Constantes
#define TAILLE 50


//Fonctions utilisees, préprocesseur
void initialiser(char **matrice);
void afficher(char **matrice);
void modifierMatrice(char **matrice);
int comptNbVoisins(char **sousmatrice);
int AnalyseMatrice(char **matrice, int l, int c);






/*
 **************************
 Début des fonctions outils
 **************************
 */



//Initialisation de la matrice au hasard
void initialiser(char **matrice)
{
    int i,j;
    
    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            if(rand()%(2)==1)
                matrice[i][j]='0';
            else
                matrice[i][j]='.';
        }
    }
    
}


//Affichage "graphique"
void afficher(char **matrice)
{
    int i, j;
    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            printf("%c  ",matrice[i][j]);
        }
        printf("\n");
    }
}


//Modification de la vie en fontion de l'entourage
void modifierMatrice(char **matrice)
{
    int i, j,retourAnalMat;
    
    int k; // déclaration mat temporaire
    char **mat;
    mat = malloc(TAILLE*sizeof(char*));
    for (k = 0; k < TAILLE; k++)
        mat[k] = malloc (sizeof(char)*TAILLE);

    for(i=0;i<TAILLE;i++) //initialisation mat temporaire
    {
        for(j=0;j<TAILLE;j++)
        {
                mat[i][j]=matrice[i][j];
        }
    }

    
    for(i=0;i<TAILLE;i++)
    {
        for(j=0;j<TAILLE;j++)
        {
            retourAnalMat=AnalyseMatrice(matrice,i,j);
            if(matrice[i][j]=='0')
            {
                if(0<=retourAnalMat && 1>=retourAnalMat)
                {
                    mat[i][j]='.';
                }
                else if(2<=retourAnalMat && 3>=retourAnalMat)
                {
                    mat[i][j]='0';
                }
                else if (4<=retourAnalMat && 8>=retourAnalMat)
                {
                    mat[i][j]='.';
                }
                else
                    printf("Erreur : nombre de voisins inconnu");
            }
            else
            {
                if(retourAnalMat==3)
                {
                    mat[i][j]='0';
                }
            }
        }
    }
    
    for(i=0;i<TAILLE;i++) //copie de mat temporaire dans matrice
    {
        for(j=0;j<TAILLE;j++)
        {
            matrice[i][j]=mat[i][j];
        }
    }
}



//Compte le nombre de cellule vivante ou morte autour d'une case
int comptNbVoisins(char **sousmatrice)
{
    int i, j;
    int compteur_Nb_Voisins=0;
    
    for (i=0 ; i<3 ; i++){
        for (j=0 ; j<3 ; j++)
        {
            if(sousmatrice[i][j]=='0')
                compteur_Nb_Voisins++;
        }
    }
    
    if (sousmatrice[1][1] == '0')
        compteur_Nb_Voisins--;
    
    return compteur_Nb_Voisins;
}



//Analyse case par case la matrice
int AnalyseMatrice(char **matrice, int l, int c)
{
    int i, j, k, t;
    int nbRetour;
    
    char **sous_Matrice;
    sous_Matrice=malloc(3*sizeof(char*));
    for (i=0 ; i<3 ; i++)
        sous_Matrice[i]=malloc(3*sizeof(char));
    
    
    for(k=0,i=l-1 ; i<=l+1 ; i++,k++)
    {
        for(t=0,j=c-1 ; j<=c+1 ; t++,j++)
        {
            sous_Matrice[k][t]=matrice[(i+TAILLE)%TAILLE][(j+TAILLE)%TAILLE];
        }
    }
    
    nbRetour=comptNbVoisins(sous_Matrice);
    return nbRetour;
}



//Programme principal
int main()
{
    int i;
    char **matrice;
    matrice = malloc(TAILLE*sizeof(char*));
    for (i = 0; i < TAILLE; ++i)
        matrice[i] = malloc (sizeof(char)*TAILLE);
    
    //Il faudrait vérifier si l'allocation dynamique s'est bien déroulée
    
    
    srand (time(NULL));
    
    printf("Bienvenue dans le Jeu De La Vie ! Appuyez sur 'Entrer' pour commencer...\n");
    getchar();
    
    
    initialiser(matrice);
    
    printf("La population au départ : \n");
    afficher(matrice);
    printf("\nPressez sur ENTER pour continuer...\n");
    getchar();
    
    
    i=1;
    
    while(1)
    {
        printf("La population après %d cycles: \n",i);
        afficher(matrice);
        modifierMatrice(matrice);
        printf("\n\n");
        sleep(1);
        i++;
    }
    
    printf("Matrice finale atteinte !\n");
    return 0;
}

/*Tracé des lignes peut être intéressant
 void ligne(int largeur)
 {
 int i;
 for(i=0; i<largeur; i++)
 printf("+-");
 printf("+\n");
 }
 */
