# Käyttöjärjestelmät-kurssin miniprojektit

Tämä repositorio sisältää kurssin kolmen miniprojektin lähdekoodit. Raporttidokumentti on palautettu Moodleen PDF tiedostona.

## Repositorion rakenne

*   **Projekti1/**: Warmup to C and Unix programming
*   **Projekti2/**: Unix Utilities
*   **Projekti4/xv6-public/**: Kernel Hacking

---

## Projekti 3: Kernel Hacking (xv6)

Tässä projektissa xv6-käyttöjärjestelmän ytimeen on lisätty uusi järjestelmäkutsu (system call) `getreadcount`. Se pitää kirjaa siitä, kuinka monta kertaa `read()`-kutsua on kutsuttu ytimen käynnistymisen jälkeen.

### Toteutetut pisteytettävät ominaisuudet:
1.  **Perusvaatimus (2p):** Järjestelmäkutsu on lisätty ja se kääntyy/toimii ongelmitta.
2.  **Dokumentaatio (1p):** Lähdekoodi on kommentoitu ja toiminta on dokumentoitu erilliseen PDF-tiedostoon kuvakaappauksineen.
3.  **Laskurin nollaus (1p):** Järjestelmäkutsu ottaa vastaan argumentin, jolla laskurin voi nollata (`readcountTest 1`).

### Kääntäminen ja ajaminen (QEMU)

Siirry `xv6-public` -kansioon ja käännä käyttöjärjestelmä:

```bash
make clean
make qemu-nox
