#include <stdio.h>

int main() {
    int n;
    int i, j;
    int est_premier;

    printf("Donnez un nombre : ");
    scanf("%d", &n);

    printf("Les nombres premiers entre 2 et %d sont :\n", n);

    for (i = 2; i <= n; i++) {
        est_premier = 1;

        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                est_premier = 0;
            }
        }

        if (est_premier == 1) {
            printf("%d est un nombre premier.\n", i);
        }
    }

    return 0;
}
