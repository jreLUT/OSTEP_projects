# Käyttöjärjestelmät-kurssin miniprojektit

Tämä repositorio sisältää kurssin kolmen miniprojektin lähdekoodit. Raporttidokumentti on palautettu Moodleen PDF tiedostona.

## Repositorion rakenne

*   **Projekti1/**: Warmup to C and Unix programming
*   **Projekti2/**: Unix Utilities
*   **Projekti4/xv6-public/**: Kernel Hacking


---


## Projekti 1 – reverse

### Tiedostot

- reverse.c

### Kääntäminen

gcc reverse.c -o reverse

### Ajaminen

./reverse input.txt output.txt


---



## Projekti 2: Unix Utilities

Tämä kansio sisältää C-kielellä toteutetut ohjelmat Unix-työkaluista: `cat`, `grep`, `zip` ja `unzip`.

### Kääntäminen

Kaikki ohjelmat tulee kääntää `gcc`-kääntäjällä käyttäen `-Wall` ja `-Werror` -lippuja. 

```bash
gcc -o my-cat my-cat.c -Wall -Werror
gcc -o my-grep my-grep.c -Wall -Werror
gcc -o my-zip my-zip.c -Wall -Werror
gcc -o my-unzip my-unzip.c -Wall -Werror
```


---


## Projekti 4: Kernel Hacking (xv6)

Tässä projektissa xv6-käyttöjärjestelmän ytimeen on lisätty uusi järjestelmäkutsu (system call) `getreadcount`. Se pitää kirjaa siitä, kuinka monta kertaa `read()`-kutsua on kutsuttu ytimen käynnistymisen jälkeen.

### Toteutetut pisteytettävät ominaisuudet:
1.  **Perusvaatimus (2p):** Järjestelmäkutsu on lisätty ja se kääntyy/toimii ongelmitta.
2.  **Dokumentaatio (1p):** Lähdekoodi on kommentoitu ja toiminta on dokumentoitu erilliseen PDF-tiedostoon kuvakaappauksineen.
3.  **Laskurin nollaus (1p):** Järjestelmäkutsu ottaa vastaan argumentin, jolla laskurin voi nollata (`readcountTest 1`).

### Kääntäminen ja ajaminen (QEMU)

Siirry `xv6-public` -kansioon ja käännä käyttöjärjestelmä (edellyttää qemu ja make lataamista):

```bash
make clean
make qemu
