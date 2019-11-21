#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 struct Case
  {
    char Lettre;
    int Trouve;
    int Fin_de_Chaine;
  };

  typedef struct Case Case;


void Pendu(Case Mot[], int taille,char Soluce[], char * Indice){
  int Chances = 11;
  char Etat_Mot[30];
  int indice = 0;
  char Lettres_Used[22]={'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'};
  int Nb_Used = 0;
  int L[0];
  int Un_Trouve = 0;
  int Gagne = 0;
  int Ok = 0;
  int Deb = 1;
  int Used = 0;
  int Tampon;
  int Indice_Vu = 0;


    
  //printf("Je suis avant la boucle");

  Lettres_Used[0] = '\0';
  Etat_Mot[taille] = '\0';

  while ((Chances > 0)&&(Gagne == 0)){

    while (Mot[indice].Fin_de_Chaine != 1){
      if (Mot[indice].Trouve == 1){
	Etat_Mot[indice]=Mot[indice].Lettre;
      }
      else{
	Etat_Mot[indice] = '-';
      }
      indice++;
      //printf("Indice = %d\n",indice);
    }
    printf("\n      ############################################    \n");

    printf("\nVoilà où vous en êtes pour le moment : %s\n",Etat_Mot);

    indice = 0;

    printf("Vous avez déjà utilisé ces lettres : %s\n\n\n",Lettres_Used);

    if ((Deb == 0)&&(Indice_Vu == 0)){
      printf("Voulez vous voir l'indice afin de vous aider à trouver le mot ? Tapez o si oui, autre chose sinon.\n");
      Tampon = getchar();
      if (Tampon == 'o'){
	printf("L'indice est : %s",Indice);
	Indice_Vu = 1;
      }
      Tampon = getchar();
    }
      

    while (Ok == 0){
      if (Deb ==1){
	Deb =0;
	Ok = 1;
      }
      indice = 0;
      Used = 0;
      printf("Rentrez votre lettre pour ce tour, sachant qu'il vous reste %d chances.\n",Chances);
      //printf("Indice dans la boucle = %d\n",indice);
      //fgets(L,2*sizeof(char),stdin);
      //scanf("%c",L);
      L[0] = getchar();
      Tampon = getchar();
      printf("\n");
      //printf("L = %c\n",L[0]);
      while ((Nb_Used > indice)&&(Used == 0)) {
	//printf("Je suis dans la boucle.\n");
	if (Lettres_Used[indice] == L[0]){
	  printf("La lettre %c a déjà été utilisée, veuillez en rentrer une nouvelle svp.\n\n",L[0]);
	  Used = 1;
	}
	indice++;
	if ((indice == Nb_Used)&&(Used==0)){
	  Ok = 1;
	}
	/*printf("Ok = %d\n",Ok);
	printf("Nb_Used = %d\n",Nb_Used);
	printf("indice = %d\n",indice); */
      }
    }

    


    indice = 0;
    Ok= 0;

    printf("Lettre prise en compte !\n");
    printf("Lettre est : %c\n",L[0]);
    Lettres_Used[Nb_Used]= L[0];
    Lettres_Used[Nb_Used + 1] = '\0';
    Nb_Used++;
    //printf("Nb_Used = %d\n",Nb_Used);
    

    while (Mot[indice].Fin_de_Chaine != 1){
      if (Mot[indice].Lettre == L[0]){
	Mot[indice].Trouve = 1;
	Un_Trouve = 1;
      }
      indice++;
    }

    indice =0;

    if (Un_Trouve == 1){
      printf("Bravo, votre lettre était dans le mot !\n\n");
    }
    else{
      printf("Raté, votre lettre n'est pas dans le mot...\n\n");
      Chances--;
      //printf("Chances = %d",Chances);
    }
    Un_Trouve = 0;

    Gagne = 1;

    while (Mot[indice].Fin_de_Chaine != 1){
      if (Mot[indice].Trouve == 0){
	Gagne = 0;
      }
      indice++;
    }
    indice = 0;
  }

  if (Gagne == 1){
    printf("Bravo, vous avez trouvé le mot! C'était : %s\n",Soluce);
    system("notify-send -t 4000 \"Vous avez gagné, yaaaaaay :)\"");
  }
  else{
    printf("Perdu! Le mot était : %s\n",Soluce);
    system("notify-send -t 4000 \"Vous avez perdu, dommage :(\"");
  }
}     
    
int main()
{

  system("clear");
  char Mot[30];
  Case Mot_Jeu[30];
  char * Indice;

  Indice = malloc(sizeof(char)*200);


  printf("\n\n######## BIENVENUE AU PENDU TALI, LE PENDU DE TOUTES LES FOLIES ########\n\nVeuillez rentrer votre mot pour le jeu du pendu svp : ");
  fgets(Mot,25,stdin);
  //scanf("%s\n",Mot);

  int taille = 0;

  while (Mot[taille] != '\0'){
    Mot_Jeu[taille].Lettre=Mot[taille];
    Mot_Jeu[taille].Trouve = 0;
    Mot_Jeu[taille].Fin_de_Chaine = 0;
    taille++;
  }
  taille--;

  Mot_Jeu[taille].Fin_de_Chaine = 1;

  /*for (i=0;i<=taille;i++){
    printf("i : %d\n",i);
    printf("Fin de chaine : %d\n",Mot_Jeu[i].Fin_de_Chaine);
    if (i < taille){
      printf("Lettre : %c\n",Mot_Jeu[i].Lettre);
      printf("Trouve : %d\n\n",Mot_Jeu[i].Trouve);
    }
    } */
  printf("Veuillez rentrer un indice svp : ");
  fgets(Indice, sizeof(char)*200, stdin);

  system("clear");


  Pendu(Mot_Jeu,taille,Mot,Indice);

  return 0;

}



    
    

  
