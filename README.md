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

https://prnt.sc/IICk56_DyjhH

# Deque skirtstymas

| Įrašų skaičius | Skirstymas (s) |
|---------------|----------------|
| 1 000         | 0.0208023      |
| 10 000        | 1.94427        |
| 100 000       | 210.984        |
| 1 000 000     | ??             | -- Užtruko per ilgai
| 10 000 000     | ??            | -- Užtruko per ilgai

https://prnt.sc/TQfSkokNC5Fm


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

## Vector skirstymas (buvo pasiimtas 1 strategijos budas ir panaudotas copy_if)

| Įrašų skaičius | Skirstymas (s) |
|---------------|----------------|
| 1 000         | 0.0002801      |
| 10 000        | 0.0029163      |
| 100 000       | 0.0312289      |
| 1 000 000     | 0.377198       |
| 10 000 000    | 4.07662        |

https://prnt.sc/6bhs9RWqRGFk

## Deque skirstymas (buvo pasiimtas 1 strategijos budas ir panaudotas copy_if)

| Įrašų skaičius | Skirstymas (s) |
|---------------|----------------|
| 1 000         | 0.0002588      |
| 10 000        | 0.0021332      |
| 100 000       | 0.0257383      |
| 1 000 000     | 0.312913       |
| 10 000 000    | 3.57977        |

https://prnt.sc/LxD3_dhFPzLT

## List skirstymas (buvo pasiimtas 1 strategijos būdas ir panaudotas copy_if)

| Įrašų skaičius | Skirstymas (s) |
|---------------|----------------|
| 1 000         | 0.00067        |
| 10 000        | 0.0063254      |
| 100 000       | 0.11172        |
| 1 000 000     | 0.904371       |
| 10 000 000    | 10.5409        |

https://prnt.sc/sVjqs_UKpsWK

## v.pradine release 

Sukurtas ir padarytas initial realese.

## v0.1

Studentų duomenų apdorojimo programa su vidurkio/medianos skaičiavimu, realizuota naudojant std::vector, su atsitiktinių duomenų generavimu.

## v0.2

Pridėtas duomenų nuskaitymas iš failo, studentų rūšiavimas pagal pasirinktus kriterijus ir testavimas su dideliais duomenų failais.

## v0.3

Atliktas programos refaktorizavimas: kodas išskaidytas į kelis `.cpp` ir `.h` failus, panaudotos struktūros bei pridėtas minimalus išimčių valdymas duomenų ir failų tikrinimui.


## v0.4

Pridėtas studentų failų generatorius, realizuotas studentų skirstymas į dvi grupes, rezultatų išvedimas į atskirus failus ir atlikta programos spartos analizė su skirtingo dydžio duomenų failais.


## v1.0

Atliktas std::vector, std::list ir std::deque konteinerių našumo tyrimas, palygintos studentų skirstymo strategijos.

## Kompiliavimas ir paleidimas

### Naudojant Makefile

Projektas turi paruoštą `Makefile`.

Norint sukompiliuoti programos versijas:

```bash
make vector
make deque
main list

## Kompiliuoti terminale:

g++ main_vector.cpp skaiciavimai.cpp ivestis.cpp isvesti.cpp generavimas.cpp -o vector
g++ main_deque.cpp skaiciavimai.cpp ivestis.cpp isvesti.cpp generavimas.cpp -o deque
g++ main_list.cpp skaiciavimai.cpp ivestis.cpp isvesti.cpp generavimas.cpp -o list

./vector.exe
./deque.exe
./list.exe

## Svarbu: norint kompiliuoti deque ar list failą, privalote pakeisti konteinerio tipą į atitinkamą isvestis.h ir isvesti.cpp failuose!!!


## Class ir Struct palyginimas

## Struct

| Įrašų skaičius | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
| -------------- | --------------- | -------------- | -------------- |
| 1 000 000      | 2.83759         | 2.39984        | 0.56462        |
| 10 000 000     | 25.4285         | 22.1732        | 4.14701        |

https://prnt.sc/xUvOjmogTLny

## Class

| Įrašų skaičius | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
| -------------- | --------------- | -------------- | -------------- |
| 1 000 000      | 4.43761         | 6.83953        | 1.01807        |
| 10 000 000     | 54.1757         | 91.1667        | 9.09333        |

https://prnt.sc/2Wn2nqr0MBxP


## Optimizavimo flagų palyginimas

### Failas: studentai1000000.txt

| Flag | Bendras laikas (s) | EXE dydis (KB) |
|------|--------------------|----------------|
| O1   | 8.6348             | 246.79         |
| O2   | 7.60203            | 239.42         |
| O3   | 7.90414            | 260.7          |

https://prnt.sc/_SvENR5k_TZ8

### Failas: studentai100000.txt

| Flag | Bendras laikas (s) | EXE dydis (KB) |
|------|--------------------|----------------|
| O1   | 1.70314            | 246.79         |
| O2   | 2.12781            | 239.42         |
| O3   | 1.5851             | 260.7          |

https://prnt.sc/adRonQMFNraW

Pastaba: optimizavimo flagų poveikis priklauso nuo konkretaus duomenų kiekio ir programos realizacijos, todėl skirtingiems failų dydžiams greičiausias variantas gali skirtis.

## v1.2

Šioje versijoje `Studentas` klasei realizuota penkių metodų taisyklė (Rule of Five) ir įvesties/išvesties operatoriai.

### Rule of Five realizacija

`Studentas` klasėje realizuoti šie metodai:

| Metodas | Paskirtis |
|---|---|
| Destruktorius `~Studentas()` | Atlaisvina objektą sunaikinimo metu |
| Kopijavimo konstruktorius `Studentas(const Studentas& other)` | Sukuria naują objektą kopijuojant kito objekto duomenis |
| Kopijavimo priskyrimo operatorius `operator=(const Studentas& other)` | Priskiria vieno objekto reikšmes kitam jau egzistuojančiam objektui |
| Perkėlimo konstruktorius `Studentas(Studentas&& other) noexcept` | Sukuria objektą perkeliant laikino objekto resursus |
| Perkėlimo priskyrimo operatorius `operator=(Studentas&& other) noexcept` | Perkelia vieno objekto duomenis kitam jau egzistuojančiam objektui |

### Įvesties ir išvesties operatoriai

Realizuoti operatoriai:

| Operatorius | Paskirtis |
|---|---|
| `operator>>` | Leidžia nuskaityti studento duomenis iš įvesties srauto |
| `operator<<` | Leidžia išvesti studento duomenis į išvesties srautą |

Duomenų įvestis programoje galima:
- rankiniu būdu;
- automatiškai generuojant duomenis;
- iš failo.

Duomenų išvestis galima:
- į ekraną;
- į rezultatų failus.

### Testavimas

Sukurtas rankinis testavimo failas `test_student.cpp`, kuriame patikrinta:

| Testuojama dalis | Patikrinimas |
|---|---|
| Default konstruktorius | Sukuriamas tuščias/default objektas |
| Parametrinis konstruktorius | Sukuriamas objektas su pateiktais duomenimis |
| Kopijavimo konstruktorius | Objektas sukuriamas kopijuojant kitą objektą |
| Perkėlimo konstruktorius | Objektas sukuriamas perkeliant kito objekto duomenis |
| Kopijavimo priskyrimo operatorius | Vieno objekto duomenys priskiriami kitam |
| Perkėlimo priskyrimo operatorius | Vieno objekto duomenys perkeliami kitam |
| Išvesties operatorius `<<` | Objektas išvedamas į ekraną |

Testo kompiliavimas:

```bash
g++ test_student.cpp studentas.cpp -o test