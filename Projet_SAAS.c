#include <stdio.h>
#include <string.h>

/*(Structures)___________________________________________________________________________________________*/

typedef struct
{
    int annee;
    char mois[12];
    int jour;
} date;

typedef struct
{
    char id[10];
    char nom[20];
    char prenom[30];
    int numeroMaillot;
    char poste[15];
    int age;
    int buts;
    date dateInsciption;
    char statut[12];
} joueur;

/*(Variables globales)__________________________________________________________________________________*/

joueur equipe[100];

int totalJoueur = 0;
int compteurId = 1;

/*(Fonctions)___________________________________________________________________________________________*/

// sous fonction sur le choix du poste:
void posteJoueur(int choixPoste){
    int validChoix = 0;

    while (validChoix == 0)
        {
            switch (choixPoste){
            case 1:
                strcpy (equipe[totalJoueur].poste, "Gardien");
                validChoix = 1;
                break;
            case 2:
                strcpy (equipe[totalJoueur].poste, "Defenseur");
                validChoix = 1;
                break;
            case 3:
                strcpy (equipe[totalJoueur].poste, "Milieu");
                validChoix = 1;
                break;
            case 4:
                strcpy (equipe[totalJoueur].poste, "Attaquant");
                validChoix = 1;
                break;
            default:
                printf("Choix invalid\n");
                printf("Donnez une autre nombre: ");
                scanf("%d", &choixPoste);
                break;
        }
        }
}

// sous fonction pour convertir le mois entier en lettres
void Mois(int numMois){
    int validMois = 0;

    while (validMois == 0)
    {
        switch (numMois)
        {
            case 1:
                strcpy (equipe[totalJoueur].dateInsciption.mois, "Janvier");
                validMois = 1;
                break;
            case 2:
                strcpy (equipe[totalJoueur].dateInsciption.mois, "Fevrier");
                validMois = 1;
                break;
            case 3:
                strcpy (equipe[totalJoueur].dateInsciption.mois, "Mars");
                validMois = 1;
                break;
            case 4:
                strcpy (equipe[totalJoueur].dateInsciption.mois, "Avril");
                validMois = 1;
                break;
            case 5:
                strcpy (equipe[totalJoueur].dateInsciption.mois, "Mai");
                validMois = 1;
                break;
            case 6:
                strcpy (equipe[totalJoueur].dateInsciption.mois, "Juin");
                validMois = 1;
                break;
            case 7:
                strcpy (equipe[totalJoueur].dateInsciption.mois, "Juillet");
                validMois = 1;
                break;
            case 8:
                strcpy (equipe[totalJoueur].dateInsciption.mois, "Aout");
                validMois = 1;
                break;
            case 9:
                strcpy (equipe[totalJoueur].dateInsciption.mois, "Septembre");
                validMois = 1;
                break;
            case 10:
                strcpy (equipe[totalJoueur].dateInsciption.mois, "Octobre");
                validMois = 1;
                break;
            case 11:
                strcpy (equipe[totalJoueur].dateInsciption.mois, "Novembre");
                validMois = 1;
                break;
            case 12:
                strcpy (equipe[totalJoueur].dateInsciption.mois, "Decembre");
                validMois = 1;
                break;
            default:
                printf("Invalid mois!\n");
                printf("Donnez un autre nombre du mois valid: ");
                scanf("%d", &numMois);
                break;
        }
    }
    return;
}

// fonction d'ajouter les joueurs
void Ajouter(int n){
    int choixPoste;
    int validJour = 0;
    int validStatut = 0, choixStatut = 0;
    int numMois;

    for (int i = 0; i < n; i++)
    {
        sprintf(equipe[totalJoueur].id, "SA%04d", compteurId);

        printf("Donnez le nom du joueur :");
        fgets(equipe[totalJoueur].nom, sizeof(equipe[totalJoueur].nom), stdin);
        equipe[totalJoueur].nom[strcspn(equipe[totalJoueur].nom, "\n")] = 0;

        printf("Donnez le prenom du joueur :");
        fgets(equipe[totalJoueur].prenom, sizeof(equipe[totalJoueur].prenom), stdin);
        equipe[totalJoueur].prenom[strcspn(equipe[totalJoueur].prenom, "\n")] = 0;



        printf("Donnez le numeroMaillot du joueur :");
        scanf("%d", &equipe[totalJoueur].numeroMaillot);

        printf("Donnez le poste du joueur :\n");
        printf("1- Gardien\n");
        printf("2- Defenseur\n");
        printf("3- Milieu\n");
        printf("4- Attaquant\n");
        scanf("%d", &choixPoste);
        posteJoueur(choixPoste);

        printf("Donnez l'age du joueur :");
        scanf("%d", &equipe[totalJoueur].age);

        printf("Donnez le nombre du but du joueur :");
        scanf("%d", &equipe[totalJoueur].buts);

        printf("Donnez l'annee d'inscription du joueur :");
        scanf("%d", &equipe[totalJoueur].dateInsciption.annee);

        printf("Donnez le mois d'inscription du joueur :");
        scanf("%d", &numMois);
        Mois(numMois);

        printf("Donnez le jour d'inscription du joueur :");
        scanf("%d", &equipe[totalJoueur].dateInsciption.jour);
        while (validJour == 0)
        {
            if (equipe[totalJoueur].dateInsciption.jour > 0 && equipe[totalJoueur].dateInsciption.jour <= 31)
            {
                validJour = 1;
            } else
            {
                printf("Jour invalid\n");
                printf("Donnez un autre jour valid: ");
                scanf("%d", &equipe[totalJoueur].dateInsciption.jour);
            }
        }
        

        printf("Donnez le statut du joueur :\n");
        printf("1. Tutilaire.\n");
        printf("2. Remplacant.\n");
        scanf("%d", &choixStatut);
        while (validStatut == 0)
        {
            switch (choixStatut)
            {
                case 1:
                    strcpy(equipe[totalJoueur].statut, "Tutilaire");
                    validStatut = 1;
                    break;
                case 2:
                    strcpy(equipe[totalJoueur].statut, "Remplacant");
                    validStatut = 1;
                    break;
                default:
                    printf("Invalid choix!\n");
                    printf("Donnez un autre nombre: ");
                    scanf("%d", &choixStatut);
                    break;
            }
        }
        validStatut = 0;

        totalJoueur++;
        compteurId++;
    }
}

void Afficher(){
    for (int i = 0; i < totalJoueur; i++)
    {
        printf("Id: %s, Nom et prenom du joueur: %s %s, ", equipe[i].id, equipe[i].nom, equipe[i].prenom);
        printf("age: %d, numeroMaillot: %d, poste: %s, ", equipe[i].age, equipe[i].numeroMaillot, equipe[i].poste);
        printf("dateInscription: %d/%s/%d, statut: %s\n", equipe[i].dateInsciption.jour, equipe[i].dateInsciption.mois, equipe[i].dateInsciption.annee, equipe[i].statut);
    }
}

int main(){
    int choix, numAjoute;
    printf("1. Ajouter un joueur :\n");
    // printf("2. Afficher la liste de tous les joueurs :\n");
    // printf("3. Modifier un joueur :\n");
    // printf("4. Supprimer un joueur :\n");
    // printf("5. Rechercher un joueur :\n");
    // printf("6. Afficher les statistiques :\n");
    // printf("7. Quitter :\n");

    printf("Donnez votre choix: ");
    scanf("%d", &choix);

    do
    {
        switch (choix)
        {
            case 1:
                printf("Combien de joueurs vous voules d'ajouter : ");
                scanf("%d", &numAjoute);
                getchar();

                Ajouter(numAjoute);

                printf("Donnez votre choix: ");
                scanf("%d", &choix);
                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            default:
                printf("Votre choix n'est pas valide!");
                break;
        }
    } while (choix != 0);

    return 0;
}
