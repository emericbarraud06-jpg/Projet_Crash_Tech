#include "year_data.h"

AnneeAccident nombre_accidents_par_annee(AnneeAccident e){
        e.nbaccidents++;
        return e;
}


AnneeAccidents nombre_de_type_de_severite(AnneeAccident e, int gravite){
        int count=0;
        // 1 = victime indemme, 2 = victime décédée, 3 = victime gravement blessée, 4 = victime légèrement blessée
        if(gravite==1){
          e.nbvictimes.indemme++;
        }
        if(garvite==2){
          e.nbvictimes.mort++;
        }
        if(gravite==3){
          e.nbvictimes.blessegrave++;
        }
        if(gravite==4){
          e.nbvictimes.blesseleger++;
        }
        count++;

        return e;
}

AnneeAccidents compter_pour_annee(File*fichier, int anneeRecherchee){
        AnneeAccident bilan={0};
        bilan.annee=anneeRecherchee;
        char ligne;

        int anneeLue, graviteLue;

          while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Adapte le sscanf selon l'ordre des colonnes de ton fichier
        if (sscanf(ligne, "%d %d", &anneeLue, &graviteLue) == 2) {
            if (anneeLue == anneeRecherchee) {
                bilan = ajouter_accident(bilan);
                bilan = mettre_a_jour_severite(bilan, graviteLue);
            }
        }
    }

        return bilan;
}



int charger_Donnees_annee(char* fichier, AnneeAccidents* donnees){ //ici on charge les données des accidents par année grâce au fichier
        FILE *fichier = fopen(fichier, "r");
        fichier=fopen("crashtest.csv", "r");
        if(fichier==NULL){
            printf("Ouverture du fichier impossible\n");
            printf("code d'erreur = %d \n", errno );
            printf("Message d'erreur = %s \n", strerror(errno) );
            exit(1);
        }
  
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
        fclose(fichier);
        return 1;
}


void nombre_de_victimes(AnneeAccidents x){




}

