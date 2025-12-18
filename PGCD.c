#include <stdio.h>

int main() {
    int a, b, c, reste, a_initial, b_initial;

    printf("Saisir le premier nombre entier (a) : ");
    scanf("%d", &a);
    printf("Saisir le deuxieme nombre entier (b) : ");
    scanf("%d", &b);
    printf("Saisir le troisieme nombre entier (c) : ");
    scanf("%d", &c);

    a_initial = a;
    b_initial = b;
    // --- Algorithme d'Euclide ---
    printf("\n--- Etapes de l'algorithme d'Euclide ---\n");
    while (b != 0) {
        reste = a % b;
        printf("%d = %d * (%d) + %d\n", a, b, a / b, reste);
        a = b;
        b = reste;
    }

    int pgcd = a; // sauvegarde du PGCD

    printf("\n=> Le PGCD(%d, %d) = %d\n", a_initial, b_initial, pgcd);
    if(a=1){printf("----%d et %d sont liee entre eux----",a_initial, b_initial);}
    // --- Théorème de Bézout ---
    int a_temp = a_initial, b_temp = b_initial;
    int x0 = 1, y0 = 0;
    int x1 = 0, y1 = 1;
    int q, r, x2, y2;

    while (b_temp != 0) {
        q = a_temp / b_temp;
        r = a_temp % b_temp;
        x2 = x0 - q * x1;
        y2 = y0 - q * y1;

        a_temp = b_temp;
        b_temp = r;
        x0 = x1; y0 = y1;
        x1 = x2; y1 = y2;
    }

    printf("\n\n\nSelon le theoreme de Bezout :\n");
    printf("%d = (%d)(%d) + (%d)(%d)\n", pgcd, a_initial, x0, b_initial, y0);
    printf("=> x0 = %d, y0 = %d\n", x0, y0);

    // --- Vérification pour l'équation a·x + b·y = c ---
    if (c % pgcd != 0) {
        printf("\nAucune solution entiere, car %d ne divise pas %d.\n", pgcd, c);
    } else {
        int facteur = c / pgcd;
        int x_part = x0 * facteur;
        int y_part = y0 * facteur;

        printf("\nComme %d divise %d, l'equation a·x + b·y = c admet des solutions.\n", pgcd, c);
        printf("Une solution particuliere est : x = %d, y = %d\n", x_part, y_part);

        printf("\nLes solutions generales sont :\n");
        printf("x = %d + k*(%d/%d)\n", x_part, b_initial, pgcd);
        printf("y = %d - k*(%d/%d)\n", y_part, a_initial, pgcd);
        printf("avec k appertient Z\n");
    }

    return 0;
}


