#include "entete.h"

typedef struct{
    int indemme;
    int mort;
    int blessegrave;
    int blesseleger;
}Severité; // ici on compte le nombre de victimes par type de sévérité


typedef struct tableaustatique{
  int tab[20]; // l'année est entre 2005 et 2024
  int nbaccident;
  Severité nbvictimes; // on compte le nombre de victimes total
}AnnéeAccident;
