#include "crash_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pNoeud rotationgauche(pNoeud n){

  if(n==NULL || n->fd==NULL){
    return n;
  }
  pNoeud pivot = n->fd;
  int anc_a = n->equilibre;
  int anc_p = pivot->equilibre;
  
  n->fd = pivot->fg;
  pivot->fg = n;
  
  n->equilibre = anc_a - 1;
  if(anc_p > 0){
    n->equilibre = n->equilibre - an_p;
  }
  pivot->equilibre = anc_p - 1;
  if(n->equilibre < 0){
    pivot->equilibre = pivot->equilibre + n->equilibre;
  }
  return pivot;
}

pNoeud rotationdroite(pNoeud n){

  if(n==NULL || n->fg==NULL){
    return n;
  }
  pNoeud pivot = n->fg;
  int anc_a = n->equilibre;
  int anc_p = pivot->equilibre;
  
  n->fg = pivot->fd;
  pivot->fd = n;
  
  n->equilibre = anc_a + 1;
  if(anc_p < 0){
    n->equilibre = n->equilibre - an_p;
  }
  pivot->equilibre = anc_p + 1;
  if(n->equilibre > 0){
    pivot->equilibre = pivot->equilibre + n->equilibre;
  }
  return pivot;
}

pNoeud doublerotationgauche(pNoeud n){
  
  if(n!= NULL && n->fd!= NULL){
  
    n->fd = rotationdroite(n->fd);
    n = rotationgauche(n);
  }
  return n;
}

pNoeud doublerotationdroite(pNoeud n){
  
  if(n!= NULL && n->fg!= NULL){
  
    n->fg = rotationgauche(n->fg);
    n = rotationdroite(n);
  }
  return n;
}

pNoeud equilibreAVL(pNoeud n){

  if(n==NULL){
    return NULL;
  }
  if(n->equilibre >= 2){
    
    if(n->fd != NULL && n->fg->equilibre >=0){
      
      return rotationgauche(n);
    }
    else{
      
      return doublerotationgauche(n);
    }
  }
  else if(n->equilibre <=-2){
    
    if(n->fg != NULL && n->fg->equilibre <= 0){
      
      return rotationdroite(n);
    }
    else{
      
      return doublerotationdroite(n);
    }
  }
  return n;
}

sVictime *creer_victime(int type_usager,int genre, int age,int gravite) {
    Victime *v = malloc(sizeof(Victime));
    if (v == NULL) {
        exit(1);
    }
    v->type_usager = type_usager;
    v->genre = genre;
    v->age = age;
    v->gravite = gravite;
    v->suivant = NULL;
    return v;
}

pNoeud creer_noeud_accident(unsigned long long cle) {
    pNoeud noeud = malloc(sizeof(NoeudAccident));
    if (noeud == NULL) {
        exit(1);
    }
    noeud->cle = cle;
    noeud->vehicules = NULL;
    noeud->fg = NULL;
    noeud->fd = NULL;
    noeud->equilibre = 0;
    return noeud;
}

pNoeud inserer_ou_recuperer_noeud(pNoeud n,unsigned long long cle, int *h,pNoeud *noeud_cible) {

    if (n == NULL) {
        *noeud_cible = creer_noeud_accident(cle);
        *h = 1;
        return *noeud_cible;
    }

    if (cle < n->cle) {
        n->fg = inserer_ou_recuperer_noeud(n->fg, cle, h, noeud_cible);
        if (*h != 0) {
            n->equilibre += 1;
            if (n->equilibre == 0) {
                *h = 0;
            } else if (n->equilibre == 2) {
                racine = equilibrer_avl(n);
                *h = 0;
            }
        }
    } else if (cle > n->cle) {
        n->fd = inserer_ou_recuperer_noeud(n->fd, cle, h, noeud_cible);
        if (*h != 0) {
            n->equilibre -= 1;
            if (n->equilibre == 0) {
                *h = 0;
            } else if (n->equilibre == -2) {
                n = equilibrer_avl(n);
                *h = 0;
            }
        }
    } else {
        *noeud_cible = n;
        *h = 0;
    }

    return n;
}


pNoeud ajouter_donnee_accident(pNoeud racine, unsigned long long cle, int *vehicule_id, int motif_trajet, int type_usager, int genre, int age, int gravite) {
    pNoeud accident = NULL;
    int h = 0;
    racine = inserer_ou_recuperer_noeud(racine, cle, &h, &accident);

    // Recherche du véhicule dans la liste chaînée de l'accident
    Vehicule *veh_courant = accident->vehicules;
    while (veh_courant != NULL && strcmp(veh_courant->vehicule_id, vehicule_id) != 0) {
        veh_courant = veh_courant->suivant;
    }

    // Si le véhicule n'existe pas encore, on l'ajoute en tête
    if (veh_courant == NULL) {
    
        veh_courant = creer_vehicule(vehicule_id, motif_trajet);
        veh_courant->suivant = accident->vehicules;
        accident->vehicules = veh_courant;
    }

    // Ajout de la victime en tête de la liste du véhicule 
    Victime *nouvelle_victime = creer_victime(type_usager, genre, age, gravite);
    nouvelle_victime->suivant = veh_courant->victimes;
    veh_courant->victimes = nouvelle_victime;

    return racine;
}

pNoeud rechercher_accident(pNoeud n, unsigned long long cle) {
    while (n != NULL && n->cle != cle) {
        if (cle < n->cle) {
            n = n->gauche;
        } else {
            n = n->droite;
        }
    }
    return n;
}
