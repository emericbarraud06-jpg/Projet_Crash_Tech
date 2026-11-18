#include "entete.h"

typedef struct{
    int indemme;
    int mort;
    int blessegrave;
    int blesseleger;
}Severité;


typedef struct tableaustatique{
  int tab[20];
  int nbaccident;
  Severité nbvictimes;
}AnnéeAccident;
