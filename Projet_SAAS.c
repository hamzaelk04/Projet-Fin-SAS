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
    char nom[30];
    char prenom[30];
    int numeroMaillot;
    char poste[15];
    int age;
    int buts;
    date dateInsciption;
    char statut[12];
} joueur;

/*(Variables globales)__________________________________________________________________________________*/

joueur equipe[100] = {
    {"SA0001", "Yamal", "Lamine", 19, "Attaquant", 17, 10, {2023, "Avril", 29}, "Tutilaire"},
    {"SA0002", "Kounde", "Jules", 23, "Defenseur", 26, 5, {2022, "Juillet", 29}, "Tutilaire"},
    {"SA0003", "Cubarsi", "Pau", 2, "Defenseur", 17, 1, {2023, "Mars", 10}, "Tutilaire"},
    {"SA0004", "Araujo", "Ronald", 4, "Defenseur", 25, 8, {2019, "Aout", 6}, "Tutilaire"},
    {"SA0005", "Pedri", "Gonzalez", 8, "Milieu", 22, 20, {2020, "Aout", 14}, "Tutilaire"},
    {"SA0006", "Rashford", "Marcus", 10, "Attaquant", 27, 120, {2016, "Fevrier", 25}, "Tutilaire"},
    {"SA0007", "Lewandowski", "Robert", 9, "Attaquant", 36, 550, {2022, "Juillet", 17}, "Tutilaire"},
    {"SA0008", "Gavi", "Pablo", 6, "Milieu", 20, 15, {2021, "Aout", 29}, "remplacant"},
    {"SA0009", "Lopez", "Fermin", 16, "Milieu", 22, 12, {2023, "Aout", 12}, "Tutilaire"},
    {"SA0010", "Raphinha", "Dias", 11, "Ailier", 28, 50, {2022, "Juillet", 13}, "Remplacant"}
};

int totalJoueur = 10;
int compteurId = 11;

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
        printf("---------------------------------------------\n");
        printf("---------------------------------------------\n");
        printf("Identifiant du joueur: %s\n", equipe[i].id);
        printf("Nom et prenom: %s %s\n", equipe[i].nom, equipe[i].prenom);
        printf("Age du joueur: %d\n", equipe[i].age);
        printf("NumeroMaillot: %d, poste: %s\n", equipe[i].numeroMaillot, equipe[i].poste);
        printf("Nombre de buts: %d\n", equipe[i].buts);
        printf("DateInscription: %d/%s/%d, statut: %s\n", equipe[i].dateInsciption.jour, equipe[i].dateInsciption.mois, equipe[i].dateInsciption.annee, equipe[i].statut);
    }
}

//fonction d'afficher juste un joueur
void Afficher1Joueur(int i){
    printf("---------------------------------------------\n");
    printf("---------------------------------------------\n");
    printf("Identifiant du joueur: %s\n", equipe[i].id);
    printf("Nom et prenom: %s %s\n", equipe[i].nom, equipe[i].prenom);
    printf("Age du joueur: %d\n", equipe[i].age);
    printf("NumeroMaillot: %d, poste: %s\n", equipe[i].numeroMaillot, equipe[i].poste);
    printf("Nombre de buts: %d\n", equipe[i].buts);
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
    int i, j;
    joueur key;

    for (i = 1; i < totalJoueur; i++)
    {
        key = equipe[i];
        j = i - 1;

        while (j >= 0 && strcmp(equipe[j].nom, key.nom) > 0)
        {
            equipe[j + 1] = equipe[j];
            j--;
        }
        equipe[j + 1] = key;
    }
}

// fonction de tri par buts
void TrierBut(){
    int i, j, key;

    for (i = 1; i < totalJoueur; i++)
    {
        joueur key = equipe[i];
        j = i - 1;

        while (j >= 0 && equipe[j].buts > key.buts)
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
    printf("______________________________________________________\n");

    printf("Les defenseurs d'equipe: \n");
    for (int i = 0; i < totalJoueur; i++)
    {
        if (strcmp(equipe[i].poste, "Defenseur") == 0)
        {
            Afficher1Joueur(i);
        }
    }

    printf("______________________________________________________\n");

    printf("Les milieux d'equipe: \n");
    for (int i = 0; i < totalJoueur; i++)
    {
        if (strcmp(equipe[i].poste, "Milieu") == 0)
        {
            Afficher1Joueur(i);
        }
    }
    printf("______________________________________________________\n");

    printf("Les attaquants d'equipe: \n");
    for (int i = 0; i < totalJoueur; i++)
    {
        if (strcmp(equipe[i].poste, "Attaquant") == 0)
        {
            Afficher1Joueur(i);
        }
    }
}

// recherche par Id
int RechercheId(char idRecherche[10]){
    for (int i = 0; i < totalJoueur; i++)
    {
        if (strcmp(idRecherche, equipe[i].id) == 0)
        {
            return i;
        }      
    }
    return -1;
}


// recherche par nom
int RechercheNom(char nomRecherche[30]){
    for (int i = 0; i < totalJoueur; i++)
    {
        if (strcmp(nomRecherche, equipe[i].nom) == 0)
        {
            return i;
        }
    }
    return -1;
}

// sous fonction de modification du poste
void NouveauPoste(int choixPoste, int returnId){
    int validChoix = 0;

    while (validChoix != 0)
    {
        switch (choixPoste){
        case 1:
            strcpy (equipe[returnId].poste, "Gardien");
            validChoix = 0;
            break;
        case 2:
            strcpy (equipe[returnId].poste, "Defenseur");
            validChoix = 0;
            break;
        case 3:
            strcpy (equipe[returnId].poste, "Milieu");
            validChoix = 0;
            break;
        case 4:
            strcpy (equipe[returnId].poste, "Attaquant");
            validChoix = 0;
            break;
        case 0:
            break;
        default:
            printf("Choix invalid\n");
            printf("Donnez un autre nombre: ");
            scanf("%d", &choixPoste);
            getchar();
            break;
        }
    }
}

// fonction de suppression
void Supprimer(int returnId){
    for (int i = returnId; i < totalJoueur - 1; i++)
    {
        equipe[i] = equipe[i + 1];
    }
    totalJoueur--;
}

int main(){
    int choix, numAjoute;
    int choixAffichage, choixRecherche, choixModification, choixPoste, choixStatistique;
    char idRecherche[10], nomRecherche[30], nouveauPoste[15];
    int returnId, returnNom;
    int nouveaubuts, nouveauAge;
    int confSupp;
    int sommeAge = 0;
    float moyenAge = 0;
    int nombreBut;
    
    do
    {
        printf("---------------------Menu Principale:-----------------------\n");
        printf("1. Ajouter un joueur :\n");
        printf("2. Afficher la liste de tous les joueurs :\n");
        printf("3. Modifier un joueur :\n");
        printf("4. Supprimer un joueur :\n");
        printf("5. Rechercher un joueur :\n");
        printf("6. Afficher les statistiques :\n\n");
        printf("0. Quitter :\n");
        printf("------------------------------------------------------------\n");

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
                    printf("3. Afficher les joueurs par poste. :\n\n");
                    printf("0. retourner au menu.\n");

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
                        case 0:
                            break;
                        
                        default:
                            printf("Choix invalid!\n");

                            break;
                    }
                } while (choixAffichage != 0);
                
                break;

            case 3:
                do
                {
                    printf("Donnez l'identifiant du joueur: ");
                    scanf("%s", idRecherche);
                    returnId = RechercheId(idRecherche);

                    if (returnId == -1)
                    {
                        printf("Aucun joueur avec ce identifiant.\n\n");
                    } else
                    {
                        printf("1. Modifier le poste du %s\n", equipe[returnId].nom);
                        printf("2. Modifier l'age du %s\n", equipe[returnId].nom);
                        printf("3. Modifier le nombre de buts marques par %s\n", equipe[returnId].nom);
                        printf("0. Retourner au menu principale\n");

                        printf("Donnez votre choix: ");
                        scanf("%d", &choixModification);

                        do
                        {
                            switch (choixModification)
                            {
                                case 1:
                                    printf("Donnez le nouveu poste du %s", equipe[returnId].nom);
                                    printf("1- Gardien\n");
                                    printf("2- Defenseur\n");
                                    printf("3- Milieu\n");
                                    printf("4- Attaquant\n");
                                    printf("0- Retourner\n");

                                    printf("Donnez votre choix: ");
                                    scanf("%d", &choixPoste);
                                    
                                    NouveauPoste(choixPoste, returnId);
                                    break;
                                case 2:
                                    printf("Donnez le nouveau age du %s", equipe[returnId].nom);
                                    scanf("%d", &nouveauAge);
                                    equipe[returnId].age = nouveauAge;
                                    break;
                                case 3:
                                    printf("Donnez le nouveau nombre du buts du %s", equipe[returnId].nom);
                                    scanf("%d", &nouveaubuts);
                                    equipe[returnId].buts = nouveaubuts;
                                    break;
                                case 0:
                                    break;
                                default:
                                    printf("Votre choix n'est pas valide!\n");

                                    printf("Donnez votre choix: ");
                                    scanf("%d", &choixModification);
                                    break;
                            }
                        } while (choixModification != 0);  
                    }
                } while (returnId == -1);
                
                break;

            case 4:
                do
                {
                    printf("Donnez l'identifiant du joueur: ");
                    scanf("%s", idRecherche);
                    returnId = RechercheId(idRecherche);

                    if (returnId == -1)
                    {
                        printf("Aucun joueur avec ce identifiant.\n");
                    } else
                    {
                        printf("Voulez vous supprimer %s %s\n", equipe[returnId].nom, equipe[returnId].prenom);
                        printf("1. Oui\n2. Non: ");
                        scanf("%d", &confSupp);
                        if (confSupp == 1)
                        {
                            Supprimer(returnId);
                        } else
                        {
                            break;
                        }
                    }
                } while (returnId == -1);
                break;

            case 5:
                do
                {
                    printf("Voulez vous chercher par identifiant ou par nom?\n");
                    printf("1. Rechercher un joueur par Identifiant.\n");
                    printf("2. Rechercher un joueur par nom.\n\n");
                    printf("0. Retourner au menu principale.\n");
                    scanf("%d", &choixRecherche);

                    if (choixRecherche == 1)
                    {
                        printf("Donnez l'identifiant du joueur: ");
                        scanf("%s", idRecherche);
                        returnId = RechercheId(idRecherche);

                        if (returnId == -1)
                        {
                            printf("Aucun joueur avec ce identifiant.\n");
                        } else
                        {
                            Afficher1Joueur(returnId);
                        }
                    } else if (choixRecherche == 2)
                    {
                        printf("Donnez le nom du joueur: ");
                        scanf("%s", nomRecherche);
                        returnNom = RechercheNom(nomRecherche);

                        if (returnNom == -1)
                        {
                            printf("Aucun joueur avec ce nom.\n");
                        } else
                        {
                            Afficher1Joueur(returnNom);
                        }
                    }
                    
                } while (choixRecherche != 0);
                
                break;

            case 6:
                printf("1. Afficher le nombre total de joueurs dans l'equipe.\n");
                printf("2. Afficher l'age moyen des joueurs.\n");
                printf("3. Afficher les joueurs ayant marque plus de certains buts\n");
                printf("4. Afficher le meilleur buteur\n");
                printf("5. Afficher le joueur le plus jeune et le plus age.\n");
                printf("0. Quitter\n");

                printf("Donnez votre choix: ");
                scanf("%d", &choixStatistique);

                switch (choixStatistique)
                {
                    case 1:
                        printf("Le nombre total des joueurs dans l'equipe est: %d.\n", totalJoueur);
                        break;
                    case 2:
                        for (int i = 0; i < totalJoueur; i++)
                        {
                            sommeAge = sommeAge + equipe[i].age;
                        }

                        moyenAge = sommeAge / totalJoueur;

                        printf("L'age moyen des joueurs est: %.1f", moyenAge);
                        break;
                    case 3:
                        printf("Donnez le nombre minimum de but: ");
                        scanf("%d", &nombreBut);

                        for (int i = 0; i < totalJoueur; i++)
                        {
                            if (nombreBut <= equipe[i].buts)
                            {
                                Afficher1Joueur(i);
                            }
                        }
                        break;
                    case 4:
                        TrierBut();

                        printf("Le meilleur buteur de cet equipe est: \n");
                        Afficher1Joueur(totalJoueur - 1);
                        break;
                    case 5:
                        TrierAge();

                        printf("Le joueur le plus age est: \n");
                        Afficher1Joueur(totalJoueur - 1);

                        printf("Le joueur le plus jeune est: \n");
                        Afficher1Joueur(0);
                        break;
                    case 0:

                        break;
                }
                
                break;
            
            case 0:
                break;

            default:
                printf("\nVotre choix n'est pas valide!\n\n");
                break;
        }
    } while (choix != 0);

    return 0;
}