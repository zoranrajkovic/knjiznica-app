# knjiznica-app
Konzolna C aplikacija za evidenciju osobne knjižnice.

## Mogućnosti

- dodavanje knjiga
- ispis svih knjiga
- pretraga po naslovu
- pretraga po autoru
- pretraga po maksimalnoj cijeni
- pronalazak najskuplje knjige
- izračun prosječne cijene
- sortiranje knjiga po cijeni
- brisanje knjige po naslovu
- spremanje podataka u tekstualnu datoteku
- izvoz knjiga u HTML
- evidencija posudbe knjiga

## Planirane nadogradnje

- ISBN
- naslovnica knjige
- žanr
- jezik knjige
- status: papirnata knjiga ili e-knjiga
- podaci o osobi koja je posudila knjigu
- upozorenje ako je knjiga posuđena dulje od 30 dana
- web verzija aplikacije u Flasku

## Pokretanje

Program se kompajlira kao C program.

Primjer s GCC compilerom:

```bash
gcc main.c -o knjiznica
./knjiznica

## Pokretanje

Otvori Code::Blocks.
Napravi novi C projekt ili otvori postojeći.
Preuzmi main.c s GitHuba:
otvori main.c
klikni Raw
kopiraj kod
zalijepi u Code::Blocks
Klikni Build and Run.
