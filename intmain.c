#include "year_data.h"
#include "crash_data.h"


int main(){
FILE* fichier=NULL;
AnneeAccident x = {0};


fichier=fopen("crashtest.csv", "r");
if(fichier==NULL){
    printf("Ouverture du fichier impossible\n");
    printf("code d'erreur = %d \n", errno );
    printf("Message d'erreur = %s \n", strerror(errno) );
    exit(1);
}
  
do{
    printf("Quelle année souhaitez-vous consulter ?\n");
    scanf("%d", &x.annee);
while{ (x.annee < 2005 || x.annee > 2024);
      
      
fclose(fichier);


  return 0;
}
