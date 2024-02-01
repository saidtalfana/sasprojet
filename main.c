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

Tache L[MAX];
 int i = 0;
void ajouter_tache() {
   

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
}

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
}

void modifier_tache() {
    int index;

    printf("Entrer l'indice de la tache que vous voulez modifier: ");
    scanf("%d", &index);

    if (index < 0 || index >= MAX || L[index].priorite == 0) {
        printf("Indice invalide ou tache non existante.\n");
        return;
    }

    printf("Nouvelle description: ");
    scanf("%99s", L[index].description);

    printf("Nouvelle priorite: ");
    scanf(" %c", &L[index].priorite);

    printf("Nouvelle date d'echeance \n");
    printf("Nouveau jour: ");
    scanf("%d", &L[index].jour);
    printf("Nouveau mois: ");
    scanf("%d", &L[index].mois);
    printf("Nouvelle annee: ");
    scanf("%d", &L[index].annee);

    printf("Tache modifiee avec succes.\n");
}

void supprimer_tache() {
    int index;

    printf("Entrer l'indice de la tache que vous voulez supprimer: ");
    scanf("%d", &index);

    if (index < 0 || index >= MAX || L[index].priorite == 0) {
        printf("Indice invalide ou tache non existante.\n");
        return;
    }

    memset(&L[index], 0, sizeof(Tache));

    printf("Tache supprimee avec succes.\n");
}

void swap(Tache *a, Tache *b) {
    Tache temp = *a;
    *a = *b;
    *b = temp;
}

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
}

void filter_tache(char priority) {
	int j;
    printf("Affichage des taches avec priorite %c :\n", priority);
    printf("%-20s%-10s%-10s%-10s%-10s\n", "Description", "Priorite", "Jour", "Mois", "Annee");
    for (j= 0; j < MAX; j++) {
        if (L[j].priorite == priority && L[j].priorite != 0) { 
            printf("%-20s%-10c%-10d%-10d%-10d\n", L[j].description, L[j].priorite, L[j].jour, L[j].mois, L[j].annee);
        }
    }
    printf("\n");
}

int main() {
    int option;
       int order;
       char filterPriority;

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
                    bubble_sort_by_date(1);
                } else {
                    bubble_sort_by_date(0);
                }

                printf("Taches triees avec succes.\n");
                break;
                 case 6:
              
                printf("Entrer la priorite pour filtrer les taches : ");
                scanf(" %c", &filterPriority);
                filter_tache_by_priority(filterPriority);
                break;
        
        }
    } while (option != 7);

    return 0;
}
