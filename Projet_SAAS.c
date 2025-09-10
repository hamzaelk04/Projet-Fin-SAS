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
                getchar();
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
                getchar();
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
        getchar();

        printf("Donnez le poste du joueur :\n");
        printf("1- Gardien\n");
        printf("2- Defenseur\n");
        printf("3- Milieu\n");
        printf("4- Attaquant\n");
        scanf("%d", &choixPoste);
        getchar();
        posteJoueur(choixPoste);

        printf("Donnez l'age du joueur :");
        scanf("%d", &equipe[totalJoueur].age);
        getchar();

        printf("Donnez le nombre du but du joueur :");
        scanf("%d", &equipe[totalJoueur].buts);
        getchar();

        printf("Donnez l'annee d'inscription du joueur :");
        scanf("%d", &equipe[totalJoueur].dateInsciption.annee);
        getchar();

        printf("Donnez le mois d'inscription du joueur :");
        scanf("%d", &numMois);
        getchar();
        Mois(numMois);

        printf("Donnez le jour d'inscription du joueur :");
        scanf("%d", &equipe[totalJoueur].dateInsciption.jour);
        getchar();

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
        getchar();
        
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

// fonction d'affichage
void Afficher(){
    for (int i = 0; i < totalJoueur; i++)
    {
        printf("Id: %s, Nom et prenom du joueur: %s %s\n ", equipe[i].id, equipe[i].nom, equipe[i].prenom);
        printf("Age: %d, numeroMaillot: %d, poste: %s\n", equipe[i].age, equipe[i].numeroMaillot, equipe[i].poste);
        printf("DateInscription: %d/%s/%d, statut: %s\n", equipe[i].dateInsciption.jour, equipe[i].dateInsciption.mois, equipe[i].dateInsciption.annee, equipe[i].statut);
    }
}

//fonction d'afficher juste un joueur
void Afficher1Joueur(int i){
    printf("Id: %s, Nom et prenom du joueur: %s %s\n ", equipe[i].id, equipe[i].nom, equipe[i].prenom);
    printf("Age: %d, numeroMaillot: %d, poste: %s\n", equipe[i].age, equipe[i].numeroMaillot, equipe[i].poste);
    printf("DateInscription: %d/%s/%d, statut: %s\n", equipe[i].dateInsciption.jour, equipe[i].dateInsciption.mois, equipe[i].dateInsciption.annee, equipe[i].statut);
}

// fonction de tri l'age
void TrierAge(){
    int i, j, key;

    for (i = 1; i < totalJoueur; i++)
    {
        joueur key = equipe[i];
        j = i - 1;

        while (j >= 0 && equipe[j].age > key.age)
        {
            equipe[j + 1] = equipe[j];
            j--;
        }
        equipe[j + 1] = key;
    }
}

// fonction de tri les joueurs par alphabet
void TrierAlphabet(){
    int i, j, key;

    for (i = 1; i < totalJoueur; i++)
    {
        joueur key = equipe[i];
        j = i - 1;

        while (j >= 0 && strcmp(equipe[j].nom, key.nom) > 0)
        {
            equipe[j + 1] = equipe[j];
            j--;
        }
        equipe[j + 1] = key;
    }
}

// fonction d'affichage par poste
void AffichagePoste(){
    printf("Les gardiens d'equipe: \n");
    for (int i = 0; i < totalJoueur; i++)
    {
        if (strcmp(equipe[i].poste, "Gardien") == 0)
        {
            Afficher1Joueur(i);
        }
    }
    printf("----------------------------------------\n");

    printf("Les defenseurs d'equipe: \n");
    for (int i = 0; i < totalJoueur; i++)
    {
        if (strcmp(equipe[i].poste, "Defenseur") == 0)
        {
            Afficher1Joueur(i);
        }
    }

    printf("----------------------------------------\n");

    printf("Les milieux d'equipe: \n");
    for (int i = 0; i < totalJoueur; i++)
    {
        if (strcmp(equipe[i].poste, "Milieu") == 0)
        {
            Afficher1Joueur(i);
        }
    }
    printf("----------------------------------------\n");

    printf("Les attaquants d'equipe: \n");
    for (int i = 0; i < totalJoueur; i++)
    {
        if (strcmp(equipe[i].poste, "Attaquant") == 0)
        {
            Afficher1Joueur(i);
        }
    }
}

int main(){
    int choix, numAjoute;
    int choixAffichage;

    
    do
    {
        printf("1. Ajouter un joueur :\n");
        printf("2. Afficher la liste de tous les joueurs :\n");
        // printf("3. Modifier un joueur :\n");
        // printf("4. Supprimer un joueur :\n");
        // printf("5. Rechercher un joueur :\n");
        // printf("6. Afficher les statistiques :\n");
        // printf("7. Quitter :\n");

        printf("Donnez votre choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                printf("Combien de joueurs vous voules d'ajouter : ");
                scanf("%d", &numAjoute);
                getchar();

                Ajouter(numAjoute);

                printf("Les joueurs sont ajoutes avec succes.\n");
                break;

            case 2:
                do
                {
                    printf("1. Le nom des joueurs tries par ordre alphabetique :\n");
                    printf("2. Les joueurs tries par age :\n");
                    printf("3. Afficher les joueurs par poste. :\n");
                    printf("4. retourner au menu.\n");

                    printf("Donnez votre choix: ");
                    scanf("%d", &choixAffichage);

                    switch (choixAffichage)
                    {
                        case 1:
                            TrierAlphabet();

                            Afficher();
                            break;
                        case 2:
                            TrierAge();

                            Afficher();
                            break;
                        case 3:
                            AffichagePoste();
                            break;
                        case 4:
                            break;
                        
                        default:
                            printf("Choix invalid!\n");

                            break;
                    }
                } while (choixAffichage != 4);
                
                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;
            
            case 7:
                break;

            default:
                printf("Votre choix n'est pas valide!");
                break;
        }
    } while (choix != 7);

    return 0;
}
