int main(){
int x;
  

printf("Quelle année souhaitez vous consulter ?\n");
scanf("%d", &x.annee);
while(x.annee < 2005 || x.annee > 2024){
  printf("Quelle année souhaitez vous consulter ?\n");
  scanf("%d", &x.annee);
}  // ici on demande à l'utilisateur de saisir une année à consulter




  return 0;
}
