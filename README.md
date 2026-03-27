# Studentų rezultatų analizės programa (v0.4)

Programa skirta studentų duomenų apdorojimui. Ji gali:

- generuoti studentų failus su atsitiktiniais pažymiais
- nuskaityti studentų duomenis iš failo
- apskaičiuoti galutinį balą
- surūšiuoti studentus pagal pasirinktą kriterijų
- padalinti studentus į dvi grupes:
  - vargšiukai (galutinis < 5.0)
  - galvočiai (galutinis ≥ 5.0)
- išvesti rezultatus į naujus failus

## Programos struktūra

Projektas suskirstytas į kelis failus:

- main.cpp – pagrindinė programos logika
- studentas.h – Studentas struktūra
- skaiciavimai.cpp / .h – galutinio balo ir medianos skaičiavimas
- ivestis.cpp / .h – įvesties validacija
- isvestis.cpp / .h – rezultatų spausdinimas
- generavimas.cpp / .h – failų generavimas

## Sugeneruoti duomenų failai

Programos testavimui buvo sugeneruoti šie failai:

| Failas | Studentų skaičius |
|------|------|
| studentai1000.txt | 1 000 |
| studentai10000.txt | 10 000 |
| studentai100000.txt | 100 000 |
| studentai1000000.txt | 1 000 000 |
| studentai10000000.txt | 10 000 000 |

## 1 tyrimas – failų generavimo sparta, kai ND kiekis = 3

Buvo matuojamas laikas, reikalingas sugeneruoti studentų failus.

## 2 tyrimas – duomenų apdorojimo sparta, kai ND kiekis = 3 ir rušiuojama pagal rezultatą

Buvo matuojamas:

- failo nuskaitymo laikas
- rūšiavimo laikas
- studentų skirstymo laikas
- rezultatų įrašymo laikas
- bendras programos veikimo laikas

## Rezultatų analizė

Didėjant studentų skaičiui programos veikimo laikas proporcingai didėja. 
Didžiausią dalį vykdymo laiko užima duomenų nuskaitymas ir rūšiavimas.

Failų generavimas taip pat tampa žymiai lėtesnis su labai dideliais duomenų kiekiais.

## Programos paleidimas

Programa kompiliuojama:

g++ -O2 main.cpp skaiciavimai.cpp ivestis.cpp isvestis.cpp generavimas.cpp -o programa

Paleidimas:

./programa

## Rezultatų nuotraukos

https://prnt.sc/XKvfu3bsZgqw

https://prnt.sc/0OaFDSNmRW8w


## Konteinerių testavimas (std::deque)

Testavimas atliktas naudojant std::deque<Studentas> konteinerį.
Kiekvienam studentui generuoti 3 namų darbų pažymiai (ND = 3).

Testavimo sąlygos
Duomenys generuojami automatiškai
Failų dydžiai:
1 000
10 000
100 000
1 000 000
10 000 000 įrašų
Matavimo vienetas: sekundės (s)