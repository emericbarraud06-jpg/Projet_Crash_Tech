#include "year_data.h"



int main(){
FILE* fichier=NULL;
int x;


fichier=fopen("crashtest.csv", "r");
if(fichier==NULL){
  printf("Ouverture du fichier impossible\n");
  printf("code d'erreur = %d \n", errno );
  printf("Message d'erreur = %s \n", strerror(errno) );
  exit(1);
}
  

printf("Quelle année souhaitez vous consulter ?\n");
scanf("%d", &x.annee);
while(x.annee < 2005 || x.annee > 2024){
  printf("Quelle année souhaitez vous consulter ?\n");
  scanf("%d", &x.annee);
}  // ici on demande à l'utilisateur de saisir une année à consulter

fclose(fichier);


  return 0;
}
