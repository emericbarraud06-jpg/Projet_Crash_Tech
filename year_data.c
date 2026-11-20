#include "year_data.h"

AnneeAccident nombre_accidents_par_année(AnnéeAccident e){
        e.nbaccidents++;
        return e;
}


AnneeAccidents nombre_de_type_de_severite(AnnéeAccident e, int gravite){
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
