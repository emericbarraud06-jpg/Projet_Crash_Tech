
#define AGE 255

typedef struct Victime {
    int type_usager;  // 1: conducteur, 2: passager, 3: piéton 
    int genre;        // 1: masculin, 2: féminin, autre sinon 
    int age;          // Âge au moment de l'accident (ou AGE)
    int gravite;      // 1: indemne, 2: tué, 3: blessé grave, 4: blessé léger
    struct Victime *suivant;
} Victime;

typedef struct Vehicule {
    char vehicule_id[8]; //identifiant vehicule
    int motif_trajet; // raison trajet
    Victime *victimes; //vers struct victime
    struct Vehicule *suivant; //descend vers autre vehicules
} Vehicule;

typedef struct NoeudAccident {
    unsigned long long cle; //cle accident
    Vehicule *vehicules;
    struct NoeudAccident *gauche;
    struct NoeudAccident *droite;
    int equilibre; 
} NoeudAccident, *pNoeud;

void executer_mode_crash_data(const char * JSP);
