
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 50
#define CYCLE 200



void initialiser(int matrice[TAILLE][TAILLE])
{
  int i,j;

  for(i=0;i<TAILLE;i++)
    {
      for(j=0;j<TAILLE;j++)
	{
	  matrice[i][j]=rand();
	}
    }

}

void modifierMatrice(int[TAILLE][TAILLE])
{
  for(i=0;i<TAILLE;i++)
    {
      for(j=0;j<TAILLE;j++)
	{
	  if(matrice[i][j]==1)
	    {  
	      switch(AnalyseMatrice(matrice,i,j)
		{
		case 0..1:
		  matrice[i][j]=0;
		  break;
		case 2..3:
		  matrice[i][j]=1;
		  break;
		case 4..:
		  matrice[i][j]=0;
		  break;
		default:
		  printf("Erreur : nombre de voisins inconnu");
		  break;
		}
	    }
	  else
	    {
	      if(nbVoisins(matrice,i,j)==3)
		matrice[i][j]=1;
	    }
        }
    }
}

int nbVoisins(int matrice[TAILLE][TAILLE],int i,int j)
{
  

} 

void afficher(int matrice[TAILLE][TAILLE])
{
  for(i=0;i<TAILLE;i++)
    {
      for(j=0;j<TAILLE;j++)
	{
          printf("%d",matrice[i][j]);
        }
      printf("\n");
    }
}

int rand()
{
  return rand()%(1);
}

int main()
{
  int matrice[TAILLE][TAILLE];
  int i;
  printf("Bienvenue dans le Jeu De La Vie ! Appuyez sur 'Entrer' pour commencer...\n");
  getchar();

  initialiser(matrice);

  for(i=0;i<CYCLE;i++)
    { 
      afficher(matrice);
      modifierMatrice(matrice);
    }

  printf("Nombre de cycle terminé\n");
  return 0;
}
