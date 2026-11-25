#include "entete.h"

typedef struct{
    int indemme;
    int mort;
    int blessegrave;
    int blesseleger;
}Severite; // ici on compte le nombre de victimes par type de sévérité


typedef struct tableaustatique{
  int annee;
  int tab[20]; // l'année est entre 2005 et 2024 avec tab[0]=2005
  int nbaccident; // on compte le nombre d'accidents
  Severite nbvictimes; // on compte le nombre de victimes total
}AnneeAccident;
