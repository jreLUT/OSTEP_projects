#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    // Tarkistetaan antoiko käyttäjä argumentin readcountTest 1 tms.
    if (argc > 1) {
        int arg = atoi(argv[1]); // Muutetaan teksti numeroksi
        if (arg == 1) {
            getreadcount(1); // Kutsutaan järjestelmäkutsua
            printf(1, "Laskuri nollattu.\n");
            exit();
        }
    }

    // Jos argumenttia ei annettu ajetaan normaali testi
    printf(1, "---- Testi alkaa ----\n");
    printf(1, "Read kutsuja nyt: %d\n", getreadcount(0));

    printf(1, "Luodaan kymmenen read kutsua testitapauksena-... \n");
    char buffer[1];
    for (int i = 0; i < 10; i++) {
        read(0, buffer, 0);
    }

    printf(1, "Read kutsuja lopussa: %d\n", getreadcount(0));
    printf(1, "Laskurin voi resetoida komennolla 'readcountTest 1'\n");
    printf(1, "---- Testi loppu ----\n");

    exit();
}
