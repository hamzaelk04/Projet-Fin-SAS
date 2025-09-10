#include <stdio.h>

typedef struct
{
    int annee;
    int mois;
    int jour;
} date;

typedef struct
{
    int id;
    char nom[20];
    char prenom[30];
    int numeroMaillot;
    char poste[15];
    int age;
    int buts;
    date dateInsciption;
    char statut[12];
} joueur;

joueur equipe[100];

int compteur = 0;
int compteurId = 0;

void Ajouter(int n){
    for (int i = 0; i < n; i++)
    {
        equipe[i].id = compteurId +1;

        printf("Donnez le nom du joueur :");
        scanf("%s", equipe[i].nom);

        printf("Donnez le prenom du joueur :");
        scanf("%s", equipe[i].prenom);

        printf("Donnez le numeroMaillot du joueur :");
        scanf("%d", equipe[i].numeroMaillot);

        printf("Donnez le poste du joueur :");
        scanf("%s", equipe[i].poste);

        printf("Donnez l'age du joueur :");
        scanf("%d", equipe[i].age);

        printf("Donnez le nombre du but du joueur :");
        scanf("%d", equipe[i].buts);

        printf("Donnez l'annee d'inscription du joueur :");
        scanf("%s", equipe[i].dateInsciption.annee);
        printf("Donnez le mois d'inscription du joueur :");
        scanf("%s", equipe[i].dateInsciption.mois);
        printf("Donnez le jour d'inscription du joueur :");
        scanf("%s", equipe[i].dateInsciption.jour);

        printf("Donnez le statut du joueur :");
        scanf("%s", equipe[i].statut);

        compteur++;
        compteurId++;
    }
}

int main(){
    int choix;
    printf("1. Ajouter un joueur :\n");
    printf("2. Afficher la liste de tous les joueurs :\n");
    printf("3. Modifier un joueur :\n");
    printf("4. Supprimer un joueur :\n");
    printf("5. Rechercher un joueur :\n");
    printf("6. Afficher les statistiques :\n");
    printf("7. Quitter :\n");

    // do
    // {
    //     switch (choix)
    //     {
    //         case 1:

    //             break;

    //         case 2:

    //             break;

    //         case 3:

    //             break;

    //         case 4:

    //             break;

    //         case 5:

    //             break;

    //         case 6:

    //             break;

    //         default:
    //             break;
    //     }
    // } while (choix != 0);

    return 0;
}
