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
