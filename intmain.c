#include "year_data.h"



int main(){
FILE* fichier=NULL;
AnneeAccidents x = {0};


fichier=fopen("crashtest.csv", "r");
if(fichier==NULL){
    printf("Ouverture du fichier impossible\n");
    printf("code d'erreur = %d \n", errno );
    printf("Message d'erreur = %s \n", strerror(errno) );
    exit(1);
}
  
do{
    printf("Quelle année souhaitez vous consulter ?\n");
    scanf("%d", &x.annee);
while{ (x.annee < 2005 || x.annee > 2024);
      
 // ici on demande à l'utilisateur de saisir une année à consulter entre 2005 et 2024

char ligne[1024];
int anneeLue; 
int graviteLue;

 fgets(ligne, sizeof(ligne), fichier);

while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // ATTENTION : À adapter selon l'ordre exact des colonnes de crashtest.csv
        // Exemple ici si l'année est la 1ère colonne et la gravité la 2ème (séparées par ;)
        if (sscanf(ligne, "%d;%d", &anneeLue, &graviteLue) == 2) {
            
            if (anneeLue == x.annee) {
                x.nbaccidents++; // On compte l'accident

                // On compte la sévérité 1= indemme, 2 = mort, 3 = gravement blessé, 4 = légèrement blessé
                if (graviteLue == 1) x.nbvictimes.indemme++;
                else if (graviteLue == 2) x.nbvictimes.mort++;
                else if (graviteLue == 3) x.nbvictimes.blessegrave++;
                else if (graviteLue == 4) x.nbvictimes.blesseleger++;

              int total=x.nbvictimes.indemme+x.nbvictimes.mort+x.nbvictimes.blessegrave+x.nbvictimes.blesseleger;
            }
        }
    }

printf("\n Nombre d'accidents en %d : %d \n", x.annee, x.nbaccidents);
printf("\n Nombre de victimes : %d \n Indemmes %d , Tuées : %d, Gravement blessées : %d, Légèrement blessées : %d \n", total, x.nbvictimes.indemme, x.nbvictimes.mort, x.nbvictimes.blessegrave, x.nbvictimes.blesseleger);
      

      
fclose(fichier);


  return 0;
}
