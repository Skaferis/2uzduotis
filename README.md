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

## Konteinerių testavimas

## Visi konteineriai buvo tikrinami tais pačiais programos sugeneruotais failais ir rušiuoji pagal vidurkį, ir buvo įvertintas jų darbo laikas.

## Vector

| Įrašų skaičius | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
| -------------- | --------------- | -------------- | -------------- |
| 1 000          | 0.0031935       | 0.0011885      | 0.00057        |
| 10 000         | 0.0676135       | 0.0127499      | 0.0048795      |
| 100 000        | 0.262755        | 0.184618       | 0.0530411      |
| 1 000 000      | 2.83759         | 2.39984        | 0.56462        |
| 10 000 000     | 25.4285         | 22.1732        | 4.14701        |

https://prnt.sc/xUvOjmogTLny

## Deque

| Įrašų skaičius | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
|---------------|----------------|----------------|----------------|
| 1 000         | 0.0027926      | 0.0012407      | 0.0002988      |
| 10 000        | 0.0233315      | 0.0163861      | 0.0032776      |
| 100 000       | 0.256054       | 0.269708       | 0.0424128      |
| 1 000 000     | 2.67485        | 3.92968        | 0.604689       |
| 10 000 000    | 26.1153        | 33.8854        | 3.99703        |

https://prnt.sc/l9anm9YWxfQT

## List

| Įrašų skaičius | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
|---------------|----------------|----------------|----------------|
| 1 000         | 0.0044035      | 0.0005226      | 0.0005889      |
| 10 000        | 0.0411307      | 0.0075837      | 0.0073089      |
| 100 000       | 0.374854       | 0.100233       | 0.092111       |
| 1 000 000     | 3.84726        | 1.82138        | 0.926026       |
| 10 000 000    | 41.8413        | 19.7203        | 8.03509        |

https://prnt.sc/YI2qr-p5Lctg

## Rezultatai

Atlikus testavimus su skirtingais konteineriais (std::vector, std::deque, std::list) pastebėta, kad bendras programos našumas labiausiai priklauso nuo naudojamo konteinerio tipo. std::vector pasižymėjo geriausiu bendru veikimo laiku, ypač rūšiavimo operacijoje, std::deque rezultatai buvo labai panašūs į vector, tačiau šiek tiek lėtesni rūšiavime. std::list kai kuriais atvejais parodė geresnius rezultatus rūšiavimo metu, tačiau bendras veikimo laikas buvo didesnis.

## 1 Strategija

## Vector skirstymas

| Įrašų skaičius  | Skirstymas (s) |
| 1 000          | 0.00057        |
| 10 000         | 0.0048795      |
| 100 000        | 0.0530411      |
| 1 000 000      | 0.56462        |
| 10 000 000     | 4.14701        |

## Deque skirstymas

| Įrašų skaičius | Skirstymas (s) |
|---------------|----------------|
| 1 000         | 0.0002988      |
| 10 000        | 0.0032776      |
| 100 000       | 0.0424128      |
| 1 000 000     | 0.604689       |
| 10 000 000    | 3.99703        |

## List skirstymas

| Įrašų skaičius | Skirstymas (s) |
|---------------|----------------|
| 1 000         | 0.0005889      |
| 10 000        | 0.0073089      |
| 100 000       | 0.092111       |
| 1 000 000     | 0.926026       |
| 10 000 000    | 8.03509        |

## Rezultatai

Vector ir deque skirsto panašiai, o list užtrunka gerokai ilgiau.

## 2 Strategija

## Vector skirstymas

| Įrašų skaičius | Skirstymas (s) |
|---------------|----------------|
| 1 000         | 0.0124654      |
| 10 000        | 1.28622        |
| 100 000       | 132.325        |
| 1 000 000     | ??             | -- Užtruko per ilgai
| 10 000 000     | ??            | -- Užtruko per ilgai

# Deque skirtstymas

| Įrašų skaičius | Skirstymas (s) |
|---------------|----------------|
| 1 000         | 0.0208023      |
| 10 000        | 1.94427        |
| 100 000       | 210.984        |
| 1 000 000     | ??             | -- Užtruko per ilgai
| 10 000 000     | ??            | -- Užtruko per ilgai


## List skirstymas

| Įrašų skaičius | Skirstymas (s) |
|---------------|----------------|
| 1 000         | 0.0003278      |
| 10 000        | 0.0031034      |
| 100 000       | 0.0465449      |
| 1 000 000     | 0.530851       |
| 10 000 000    | 6.45129        |

https://prnt.sc/HyYIXIkFZfGb

## 3 Strategija

## Vector 


## List skirstymas (buvo pasiimtas 1 strategijos būdas ir panaudotas copy_if)

| Įrašų skaičius | Skirstymas (s) |
|---------------|----------------|
| 1 000         | 0.00067        |
| 10 000        | 0.0063254      |
| 100 000       | 0.11172        |
| 1 000 000     | 0.904371       |
| 10 000 000    | 10.5409        |

https://prnt.sc/sVjqs_UKpsWK