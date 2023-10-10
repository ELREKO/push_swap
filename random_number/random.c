#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Funktion zum Überprüfen, ob eine Zahl bereits in einem Array vorhanden ist
int isDuplicate(int num, int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1; // Die Zahl ist ein Duplikat
        }
    }
    return 0; // Die Zahl ist kein Duplikat
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Verwendung: %s <Anzahl>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]); // Die gewünschte Anzahl von Zufallszahlen

    if (n <= 0) {
        printf("Die Anzahl muss eine positive Ganzzahl sein.\n");
        return 1;
    }

    srand(time(NULL));

    int *randomNumbers = malloc(n * sizeof(int));

    if (randomNumbers == NULL) {
        printf("Speicher konnte nicht alloziert werden.\n");
        return 1;
    }

    int generated = 0;

    while (generated < n) {
        int num = 0;

        // Zufällige Bits für jeden der 32 Bits generieren
        for (int i = 0; i < 32; i++) {
            num |= (rand() % 2) << i;
        }

        if (!isDuplicate(num, randomNumbers, generated)) {
            randomNumbers[generated] = num;
            generated++;
        }
    }

    FILE *file = fopen("random_numbers.txt", "w");

    if (file == NULL) {
        printf("Die Datei konnte nicht geöffnet werden.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", randomNumbers[i]);
    }

    fclose(file);

    printf("Generierte eindeutige Zufallszahlen wurden in 'random_numbers.txt' gespeichert.\n");

    free(randomNumbers);

    return 0;
}
