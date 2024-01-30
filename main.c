#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char description[100];
    char priorite;
    int jour;
    int mois;
    int annee;
} Tache;


void ajouter_tache() {
    static int i = 0;

    printf("Entrer la description: ");
    scanf("%99s", L[i].description);

    printf("Entrer la priorite: ");
    scanf(" %c", &L[i].priorite); 

    printf("Entrer la date d'echeance \n");
    printf("Jour: ");
    scanf("%d", &L[i].jour);
    printf("Mois: ");
    scanf("%d", &L[i].mois);
    printf("Annee: ");
    scanf("%d", &L[i].annee);

    i++;
};

void afficher_tache() {
	int j;
    printf("Affichage des taches :\n");
    printf("%-20s%-10s%-10s%-10s%-10s\n", "Description", "Priorite", "Jour", "Mois", "Annee");
        for (j = 0; j < MAX; j++) {
        if (L[j].priorite != 0) { 
            printf("%-20s%-10c%-10d%-10d%-10d\n", L[j].description, L[j].priorite, L[j].jour, L[j].mois, L[j].annee);
        }
    }
    printf("\n");
};

void modifier_tache() {
    int ind;

    printf("Entrer l'indice de la tache  : ");
    scanf("%d", &ind);

    if (ind < 0 || ind >= MAX || L[ind].priorite == 0) {
        printf("invalide.\n");
        return;
    }

    printf("Nouvelle description: ");
    scanf("%s", L[ind].description);

    printf("Nouvelle priorite: ");
    scanf(" %c", &L[ind].priorite);

    printf("Nouvelle date \n");
    printf("Nouveau jour: ");
    scanf("%d", &L[ind].jour);
    printf("Nouveau mois: ");
    scanf("%d", &L[ind].mois);
    printf("Nouvelle annee: ");
    scanf("%d", &L[ind].annee);

};
void supprimer_tache() {
    int ind;

    printf("Entrer l'indice de la tache pour supprimer: ");
    scanf("%d", &ind);

    if (ind < 0 || ind >= MAX || L[ind].priorite == 0) {
        printf("invalide\n");
        return;
    }
        memset(&L[index], 0, sizeof(Tache));

    printf("Tache supprimee avec succes.\n");
}

void swap(Tache *a, Tache *b) {
    Tache temp = *a;
    *a = *b;
    *b = temp;
};

void ordreparldate(int a) {
	  int i;
	  int j;
    for (i = 0; i < MAX - 1; i++) {
        for (j = 0; j < MAX - i - 1; j++) {
            int compareresult;
            if (a) {
                compareresult= (L[j].annee > L[j + 1].annee) ||
                                (L[j].annee == L[j + 1].annee && L[j].mois > L[j + 1].mois) ||
                                (L[j].annee == L[j + 1].annee && L[j].mois == L[j + 1].mois && L[j].jour > L[j + 1].jour);
            } else {
                compareresult= (L[j].annee < L[j + 1].annee) ||
                                (L[j].annee == L[j + 1].annee && L[j].mois < L[j + 1].mois) ||
                                (L[j].annee == L[j + 1].annee && L[j].mois == L[j + 1].mois && L[j].jour < L[j + 1].jour);
            }

            if (compareresult) {
                swap(&L[j], &L[j + 1]);
            }
        }
    }
};
void filter_tache(char priorit) {
	int j;
    printf("Affichage des taches avec priorite %c :\n", priorit);
    printf("%-20s%-10s%-10s%-10s%-10s\n", "Description", "Priorite", "Jour", "Mois", "Annee");
    for (j= 0; j < MAX; j++) {
        if (L[j].priorite == priorit && L[j].priorite != 0) { 
            printf("%-20s%-10c%-10d%-10d%-10d\n", L[j].description, L[j].priorite, L[j].jour, L[j].mois, L[j].annee);
        }
    };


int main() {
    int option;
    
    do {
        printf("***Choisir une operation***\n");
        printf("1: Ajouter une tache\n");
        printf("2: Afficher les taches\n");
        printf("3: Modifier une tache\n");
        printf("4: Supprimer une tache\n");
        printf("5: Ordonner les taches\n");
        printf("6: Filtrer les taches\n");
        printf("7: Quitter\n");

        do {
            printf("Donnez votre choix: ");
            scanf("%d", &option);
            if (option > 7 || option < 1)
                printf("Choix invalide\n");
        } while (option > 7 || option < 1);

        switch (option) {
            case 1:
                ajouter_tache();
                break;
            case 2:
                afficher_tache();
                break;
            case 3:
                modifier_tache();
                break;
            case 4:
                supprimer_tache();
                break;
            case 5:
              case 5:
              
                do {
                    printf("Choisir l'ordre de tri :\n");
                    printf("1: Croissant\n");
                    printf("2: Decroissant\n");
                    printf("Donnez votre choix: ");
                    scanf("%d", &order);
                    if (order != 1 && order != 2) {
                        printf("Choix invalide\n");
                    }
                } while (order != 1 && order != 2);

                if (order == 1) {
                    ordreparldate(1);
                } else {
                    ordreparldate(0);
                }

                printf("Taches avec succes.\n");
                break;
            case 6:
              
                break;
        
        }
    } while (option != 7);

    return 0;
}
