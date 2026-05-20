#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char *title;
    char *autor;
    int year;
    float price;
};
void prikaziMeniA(int brojKnjiga, const char *imeDatoteke);
void prikaziMeniB(int brojKnjiga, const char *imeDatoteke);
struct Book* ucitajIzDatoteke(const char *imeDatoteke, int *n);
void spremiUDatoteku(const char *imeDatoteke, struct Book *knjige, int n);

struct Book* dodajKnjigu(struct Book *knjige, int *n);
struct Book* dodajViseKnjiga(struct Book *knjige, int *n);
struct Book* obrisiKnjiguPoNaslovu(struct Book *knjige, int *n);

void ispisiKnjige(struct Book *knjige, int n);
void pretraziPoNaslovu(struct Book *knjige, int n);
void pretraziPoAutoru(struct Book *knjige, int n);
void pretraziPoMaksimalnojCijeni(struct Book *knjige, int n);
void pronadiNajskuplju(struct Book *knjige, int n);
float prosjecnaCijena(struct Book *knjige, int n);
void sortirajPoCijeni(struct Book *knjige, int n);
void izveziHTML(struct Book *knjige, int n);
void oslobodiMemoriju(struct Book *knjige, int n);
int main() {
    system("color 0A");
    struct Book *knjige = NULL;
    int n = 0;
    int izbor;
    char imeDatoteke[100];

    printf("Unesite ime datoteke s knjigama: ");
    fgets(imeDatoteke, sizeof(imeDatoteke), stdin);
    imeDatoteke[strcspn(imeDatoteke, "\n")] = '\0';

    knjige = ucitajIzDatoteke(imeDatoteke, &n);

    if (knjige == NULL) {
        printf("Datoteka ne postoji ili je prazna. Krecemo s praznom listom.\n");
        n = 0;
    }
    int stilMenija;

    printf("Odaberite izgled menija:\n");
    printf("1. Klasicni meni\n");
    printf("2. Retro terminal meni\n");
    printf("Odabir: ");
    scanf("%d", &stilMenija);
    getchar();

    if (stilMenija != 1 && stilMenija != 2) {
        stilMenija = 1;
    }
    do {
        system("cls");
        if (stilMenija == 1) {
            prikaziMeniA(n, imeDatoteke);
        } else {
            prikaziMeniB(n, imeDatoteke);
        }

        scanf("%d", &izbor);
        getchar();

        switch (izbor) {
            case 1:
                knjige = dodajViseKnjiga(knjige, &n);
                spremiUDatoteku(imeDatoteke, knjige, n);
                break;

            case 2:
                ispisiKnjige(knjige, n);
                break;

            case 3:
                pretraziPoNaslovu(knjige, n);
                break;

            case 4:
                pretraziPoAutoru(knjige, n);
                break;

            case 5:
                pretraziPoMaksimalnojCijeni(knjige, n);
                break;

            case 6:
                pronadiNajskuplju(knjige, n);
                break;

            case 7:
                if (n > 0) {
                    printf("Prosjecna cijena: %.2f\n", prosjecnaCijena(knjige, n));
                } else {
                    printf("Nema knjiga za izracun prosjeka.\n");
                }
                break;

            case 8:
                sortirajPoCijeni(knjige, n);
                spremiUDatoteku(imeDatoteke, knjige, n);
                printf("Knjige su sortirane po cijeni.\n");
                break;

            case 9:
                knjige = obrisiKnjiguPoNaslovu(knjige, &n);
                spremiUDatoteku(imeDatoteke, knjige, n);
                break;

            case 10:
                spremiUDatoteku(imeDatoteke, knjige, n);
                break;

            case 11:
                izveziHTML(knjige, n)
                break;

            case 0:
                spremiUDatoteku(imeDatoteke, knjige, n);
                printf("Promjene su spremljene. Izlaz iz programa.\n");
                break;

            default:
                printf("Nepostojeca opcija.\n");
        }
        if (izbor != 0) {
        printf("\nPritisnite Enter za povratak u meni...");
        getchar();
        }


    } while (izbor != 0);

    oslobodiMemoriju(knjige, n);

    return 0;
}
void prikaziMeniA(int brojKnjiga, const char *imeDatoteke) {
    printf("\n");
    printf("============================================================\n");
    printf("              VAULT-BOOK TERMINAL v1.0\n");
    printf("============================================================\n");
    printf(" DATOTEKA: %-45s\n", imeDatoteke);
    printf(" BROJ KNJIGA U SUSTAVU: %-33d\n", brojKnjiga);
    printf("------------------------------------------------------------\n");
    printf(" [1]  Dodaj knjigu\n");
    printf(" [2]  Ispisi sve knjige\n");
    printf(" [3]  Pretrazi knjigu po naslovu\n");
    printf(" [4]  Pretrazi knjigu po autoru\n");
    printf(" [5]  Pretrazi knjige po maksimalnoj cijeni\n");
    printf(" [6]  Pronadi najskuplju knjigu\n");
    printf(" [7]  Izracunaj prosjecnu cijenu\n");
    printf(" [8]  Sortiraj knjige po cijeni\n");
    printf(" [9]  Obrisi knjigu po naslovu\n");
    printf(" [10] Spremi promjene u datoteku\n");
    printf(" [11] Izvezi knjige u HTML\n");
    printf(" [0]  Izlaz iz terminala\n");
    printf("------------------------------------------------------------\n");
    printf(" ODABIR > ");
}
void prikaziMeniB(int brojKnjiga, const char *imeDatoteke) {
    printf("  ________________________________________________\n");
    printf(" /                                                \\\n");
    printf("|              BOOK-TEC ARCHIVE SYSTEM            |\n");
    printf("|__________________________________________________|\n");
    printf("|                                                  |\n");
    printf("|  DATA FILE : %-35s |\n", imeDatoteke);
    printf("|  RECORDS   : %-35d |\n", brojKnjiga);
    printf("|__________________________________________________|\n");
    printf("|                                                  |\n");
    printf("|  [01] ADD BOOK                                  |\n");
    printf("|  [02] LIST ALL BOOKS                            |\n");
    printf("|  [03] SEARCH BY TITLE                           |\n");
    printf("|  [04] SEARCH BY AUTHOR                          |\n");
    printf("|  [05] SEARCH BY MAX PRICE                       |\n");
    printf("|  [06] FIND MOST EXPENSIVE                       |\n");
    printf("|  [07] AVERAGE PRICE                             |\n");
    printf("|  [08] SORT BY PRICE                             |\n");
    printf("|  [09] DELETE BY TITLE                           |\n");
    printf("|  [10] SAVE DATABASE                             |\n");
    printf("|  [11] EXPORT HTML REPORT                        |\n");
    printf("|  [00] EXIT                                      |\n");
    printf("|__________________________________________________|\n");
    printf("\n  COMMAND > ");
}
struct Book* ucitajIzDatoteke(const char *imeDatoteke, int *n) {
    FILE *fp;
    struct Book *knjige;
    int i;
    char buffer[100];

    fp = fopen(imeDatoteke, "r");

    if (fp == NULL) {
        return NULL;
    }

    fscanf(fp, "%d", n);
    fgetc(fp);

    if (*n <= 0) {
        fclose(fp);
        return NULL;
    }

    knjige = malloc((*n) * sizeof(*knjige));

    if (knjige == NULL) {
        fclose(fp);
        return NULL;
    }

    for (i = 0; i < *n; i++) {
        knjige[i].title = malloc(100 * sizeof(char));
        knjige[i].autor = malloc(100 * sizeof(char));

        if (knjige[i].title == NULL || knjige[i].autor == NULL) {
            printf("Greska kod alokacije memorije.\n");
            fclose(fp);
            return knjige;
        }

        fgets(knjige[i].title, 100, fp);
        knjige[i].title[strcspn(knjige[i].title, "\n")] = '\0';

        fgets(knjige[i].autor, 100, fp);
        knjige[i].autor[strcspn(knjige[i].autor, "\n")] = '\0';

        fgets(buffer, sizeof(buffer), fp);
        knjige[i].year = atoi(buffer);

        fgets(buffer, sizeof(buffer), fp);
        knjige[i].price = atof(buffer);
    }

    fclose(fp);

    printf("Ucitano knjiga iz datoteke: %d\n", *n);

    return knjige;
}
void spremiUDatoteku(const char *imeDatoteke, struct Book *knjige, int n) {
    FILE *fp;
    int i;

    fp = fopen(imeDatoteke, "w");

    if (fp == NULL) {
        printf("Greska kod otvaranja datoteke za spremanje.\n");
        return;
    }

    fprintf(fp, "%d\n", n);

    for (i = 0; i < n; i++) {
        fprintf(fp, "%s\n", knjige[i].title);
        fprintf(fp, "%s\n", knjige[i].autor);
        fprintf(fp, "%d\n", knjige[i].year);
        fprintf(fp, "%.2f\n", knjige[i].price);
    }

    fclose(fp);

    printf("Podaci su spremljeni u datoteku.\n");
}
void izveziHTML(struct Book *knjige, int n) {
    FILE *fp;
    int i;

    fp = fopen("knjige.html", "w");

    if (fp == NULL) {
        printf("Greska kod stvaranja HTML datoteke.\n");
        return;
    }

    fprintf(fp, "<!DOCTYPE html>\n");
    fprintf(fp, "<html lang=\"hr\">\n");
    fprintf(fp, "<head>\n");
    fprintf(fp, "<meta charset=\"UTF-8\">\n");
    fprintf(fp, "<title>Popis knjiga</title>\n");

    fprintf(fp, "<style>\n");
    fprintf(fp, "body { font-family: Arial, sans-serif; margin: 40px; }\n");
    fprintf(fp, "h1 { text-align: center; }\n");
    fprintf(fp, "table { width: 100%%; border-collapse: collapse; }\n");
    fprintf(fp, "th, td { border: 1px solid #333; padding: 8px; text-align: left; }\n");
    fprintf(fp, "th { background-color: #f2f2f2; }\n");
    fprintf(fp, "</style>\n");

    fprintf(fp, "</head>\n");
    fprintf(fp, "<body>\n");

    fprintf(fp, "<h1>Popis knjiga</h1>\n");

    if (n == 0) {
        fprintf(fp, "<p>Nema unesenih knjiga.</p>\n");
    } else {
        fprintf(fp, "<table>\n");
        fprintf(fp, "<tr>\n");
        fprintf(fp, "<th>Redni broj</th>\n");
        fprintf(fp, "<th>Naslov</th>\n");
        fprintf(fp, "<th>Autor</th>\n");
        fprintf(fp, "<th>Godina</th>\n");
        fprintf(fp, "<th>Cijena</th>\n");
        fprintf(fp, "</tr>\n");

        for (i = 0; i < n; i++) {
            fprintf(fp, "<tr>\n");
            fprintf(fp, "<td>%d</td>\n", i + 1);
            fprintf(fp, "<td>%s</td>\n", knjige[i].title);
            fprintf(fp, "<td>%s</td>\n", knjige[i].autor);
            fprintf(fp, "<td>%d</td>\n", knjige[i].year);
            fprintf(fp, "<td>%.2f</td>\n", knjige[i].price);
            fprintf(fp, "</tr>\n");
        }

        fprintf(fp, "</table>\n");
    }

    fprintf(fp, "</body>\n");
    fprintf(fp, "</html>\n");

    fclose(fp);

    printf("HTML izvjestaj je stvoren: knjige.html\n");
}
struct Book* dodajKnjigu(struct Book *knjige, int *n) {
    struct Book *temp;

    temp = realloc(knjige, (*n + 1) * sizeof(*knjige));

    if (temp == NULL) {
        printf("Greska kod prosirenja memorije.\n");
        return knjige;
    }

    knjige = temp;

    knjige[*n].title = malloc(100 * sizeof(char));

    if (knjige[*n].title == NULL) {
        printf("Greska kod alokacije naslova.\n");
        return knjige;
    }

    knjige[*n].autor = malloc(100 * sizeof(char));

    if (knjige[*n].autor == NULL) {
        printf("Greska kod alokacije autora.\n");
        free(knjige[*n].title);
        return knjige;
    }

    printf("Unesi naslov: ");
    fgets(knjige[*n].title, 100, stdin);
    knjige[*n].title[strcspn(knjige[*n].title, "\n")] = '\0';

    printf("Unesi autora: ");
    fgets(knjige[*n].autor, 100, stdin);
    knjige[*n].autor[strcspn(knjige[*n].autor, "\n")] = '\0';

    printf("Unesi godinu: ");
    scanf("%d", &knjige[*n].year);

    printf("Unesi cijenu: ");
    scanf("%f", &knjige[*n].price);
    getchar();

    (*n)++;

    printf("Knjiga je dodana.\n");

    return knjige;
}
struct Book* dodajViseKnjiga(struct Book *knjige, int *n) {
    char nastavi;

    do {
        knjige = dodajKnjigu(knjige, n);

        printf("Zelite li dodati jos jednu knjigu? d/n: ");
        scanf(" %c", &nastavi);
        getchar();

    } while (nastavi == 'd' || nastavi == 'D');

    return knjige;
}
void ispisiKnjige(struct Book *knjige, int n) {
    int i;

    if (n == 0) {
        printf("Nema unesenih knjiga.\n");
        return;
    }

    printf("\n--- ISPIS KNJIGA ---\n");

    for (i = 0; i < n; i++) {
        printf("\nKnjiga %d\n", i + 1);
        printf("Naslov: %s\n", knjige[i].title);
        printf("Autor: %s\n", knjige[i].autor);
        printf("Godina: %d\n", knjige[i].year);
        printf("Cijena: %.2f\n", knjige[i].price);
    }
}
void pretraziPoNaslovu(struct Book *knjige, int n) {
    char naslov[100];
    int i;
    int pronadeno = 0;

    if (n == 0) {
        printf("Nema knjiga za pretragu.\n");
        return;
    }

    printf("Unesi naslov: ");
    fgets(naslov, sizeof(naslov), stdin);
    naslov[strcspn(naslov, "\n")] = '\0';

    for (i = 0; i < n; i++) {
        if (strcmp(knjige[i].title, naslov) == 0) {
            printf("\nNaslov: %s\n", knjige[i].title);
            printf("Autor: %s\n", knjige[i].autor);
            printf("Godina: %d\n", knjige[i].year);
            printf("Cijena: %.2f\n", knjige[i].price);
            pronadeno = 1;
        }
    }

    if (!pronadeno) {
        printf("Knjiga nije pronadena.\n");
    }
}
void pretraziPoAutoru(struct Book *knjige, int n) {
    char pojam[100];
    int i;
    int pronadeno = 0;

    if (n == 0) {
        printf("Nema knjiga za pretragu.\n");
        return;
    }

    printf("Unesi ime, prezime ili dio imena autora: ");
    fgets(pojam, sizeof(pojam), stdin);
    pojam[strcspn(pojam, "\n")] = '\0';

    for (i = 0; i < n; i++) {
        if (strstr(knjige[i].autor, pojam) != NULL) {
            printf("\nNaslov: %s\n", knjige[i].title);
            printf("Autor: %s\n", knjige[i].autor);
            printf("Godina: %d\n", knjige[i].year);
            printf("Cijena: %.2f\n", knjige[i].price);

            pronadeno = 1;
        }
    }

    if (!pronadeno) {
        printf("Nema knjiga koje odgovaraju trazenom autoru.\n");
    }
}
void pretraziPoMaksimalnojCijeni(struct Book *knjige, int n) {
    float maxCijena;
    int i;
    int pronadeno = 0;

    if (n == 0) {
        printf("Nema knjiga za pretragu.\n");
        return;
    }

    printf("Unesi maksimalnu cijenu: ");
    scanf("%f", &maxCijena);
    getchar();

    for (i = 0; i < n; i++) {
        if (knjige[i].price <= maxCijena) {
            printf("\nNaslov: %s\n", knjige[i].title);
            printf("Autor: %s\n", knjige[i].autor);
            printf("Godina: %d\n", knjige[i].year);
            printf("Cijena: %.2f\n", knjige[i].price);
            pronadeno = 1;
        }
    }

    if (!pronadeno) {
        printf("Nema knjiga do te cijene.\n");
    }
}
void pronadiNajskuplju(struct Book *knjige, int n) {
    int i;
    int max = 0;

    if (n == 0) {
        printf("Nema unesenih knjiga.\n");
        return;
    }

    for (i = 1; i < n; i++) {
        if ((knjige+i)->price > (knjige+max)->price) {
            max = i;
        }
    }

    printf("\n--- NAJSKUPLJA KNJIGA ---\n");
    printf("Naslov: %s\n", (knjige+max)->title);
    printf("Autor: %s\n", (knjige+max)->autor);
    printf("Godina: %d\n", (knjige+max)->year);
    printf("Cijena: %.2f\n", (knjige+max)->price);
}
float prosjecnaCijena(struct Book *knjige, int n) {
    int i;
    float suma = 0;

    if (n == 0) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        suma += (knjige+i)->price;
    }

    return suma / n;
}
void sortirajPoCijeni(struct Book *knjige, int n) {
    int i, j;
    struct Book temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ((knjige+j)->price > (knjige+j+1)->price) {
                temp = *(knjige+j);
                *(knjige+j) = *(knjige+j+1);
                *(knjige+j+1) = temp;
            }
        }
    }
}
struct Book* obrisiKnjiguPoNaslovu(struct Book *knjige, int *n) {
    char naslov[100];
    int i, j;
    int index = -1;
    struct Book *temp;

    if (*n == 0) {
        printf("Nema knjiga za brisanje.\n");
        return knjige;
    }

    printf("Unesi naslov knjige za brisanje: ");
    fgets(naslov, sizeof(naslov), stdin);
    naslov[strcspn(naslov, "\n")] = '\0';

    for (i = 0; i < *n; i++) {
        if (strcmp(knjige[i].title, naslov) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Knjiga nije pronadena.\n");
        return knjige;
    }

    free(knjige[index].title);
    free(knjige[index].autor);

    for (j = index; j < *n - 1; j++) {
        knjige[j] = knjige[j + 1];
    }

    (*n)--;

    if (*n == 0) {
        free(knjige);
        printf("Knjiga je obrisana. Lista je sada prazna.\n");
        return NULL;
    }

    temp = realloc(knjige, (*n) * sizeof(*knjige));

    if (temp == NULL) {
        printf("Knjiga je obrisana, ali memorija nije smanjena.\n");
        return knjige;
    }

    knjige = temp;

    printf("Knjiga je obrisana.\n");

    return knjige;
}
void oslobodiMemoriju(struct Book *knjige, int n) {
    int i;

    if (knjige == NULL) {
        return;
    }

    for (i = 0; i < n; i++) {
        free((knjige+i)->title);
        free((knjige+i)->autor);
    }

    free(knjige);
}
