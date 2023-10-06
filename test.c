#include <stdio.h>

static void myFunction() {
    static int i_count = 0;
    i_count++;
    printf("Count: %d\n", i_count);
}

int main() {
    myFunction(); // Ruft myFunction auf
    myFunction(); // Ruft myFunction erneut auf
    return 0;
}
