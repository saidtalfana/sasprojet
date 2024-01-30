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

void modifier_tache() {};
void supprimer_tache() {};

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
              
                break;
            case 6:
              
                break;
        
        }
    } while (option != 7);

    return 0;
}
