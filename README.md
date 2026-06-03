# Studentų rezultatų analizės programa (v3.0)

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

- main_vector.cpp – pagrindinė programos logika
- studentas.h / studentas.cpp – Studentas klasė
- skaiciavimai.cpp / .h – galutinio balo ir medianos skaičiavimas
- ivestis.cpp / .h – įvesties validacija
- isvestis.cpp / .h – rezultatų spausdinimas
- generavimas.cpp / .h – failų generavimas
- vector.h – nuosavas Vector konteineris
- programos_vector.h – konteinerio pasirinkimas tarp std::vector ir Vector
- test_vector.cpp – Vector testai
- benchmark_vector.cpp – std::vector ir Vector push_back palyginimas

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

Atliktas programos refaktorizavimas: kodas išskaidytas į kelis .cpp ir .h failus, panaudotos struktūros bei pridėtas minimalus išimčių valdymas duomenų ir failų tikrinimui.


## v0.4

Pridėtas studentų failų generatorius, realizuotas studentų skirstymas į dvi grupes, rezultatų išvedimas į atskirus failus ir atlikta programos spartos analizė su skirtingo dydžio duomenų failais.


## v1.0

Atliktas std::vector, std::list ir std::deque konteinerių našumo tyrimas, palygintos studentų skirstymo strategijos.

## Kompiliavimas ir paleidimas

### Naudojant Makefile

Projektas turi paruoštą Makefile.

Norint sukompiliuoti programos versijas:

make vector
make deque
make list

## Kompiliuoti terminale:

g++ -std=c++17 -O2 -Wall -Wextra -pedantic -DNUOSAVAS_VECTOR main_vector.cpp studentas.cpp skaiciavimai.cpp ivestis.cpp isvesti.cpp generavimas.cpp -o vector
g++ -std=c++17 -O2 -Wall -Wextra -pedantic main_vector.cpp studentas.cpp skaiciavimai.cpp ivestis.cpp isvesti.cpp generavimas.cpp -o std_vector
g++ main_deque.cpp skaiciavimai.cpp ivestis.cpp isvesti.cpp generavimas.cpp -o deque
g++ main_list.cpp skaiciavimai.cpp ivestis.cpp isvesti.cpp generavimas.cpp -o list

./vector.exe
./std_vector.exe
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

Šioje versijoje Studentas klasei realizuota penkių metodų taisyklė (Rule of Five), įvesties/išvesties operatoriai ir sukurtas rankinis testavimo failas.

### Rule of Five realizacija

| Metodas | Paskirtis |
|---|---|
| Destruktorius ~Studentas() | Objektas sunaikinamas pasibaigus jo gyvavimo laikui |
| Kopijavimo konstruktorius Studentas(const Studentas& other) | Sukuria naują objektą kopijuojant kito objekto duomenis |
| Kopijavimo priskyrimo operatorius operator=(const Studentas& other) | Priskiria vieno objekto reikšmes kitam jau egzistuojančiam objektui |
| Perkėlimo konstruktorius Studentas(Studentas&& other) noexcept | Sukuria objektą perkeliant laikino objekto duomenis |
| Perkėlimo priskyrimo operatorius operator=(Studentas&& other) noexcept | Perkelia vieno objekto duomenis kitam jau egzistuojančiam objektui |

### Duomenų įvestis

| Būdas | Aprašymas |
|------|----------|
| Rankiniu būdu | Naudotojas gali įvesti duomenis per klaviatūrą naudojant std::cin ir operator>> |
| Automatinis generavimas | Duomenys generuojami naudojant generavimas.cpp |
| Iš failo | Duomenys nuskaitomi iš .txt failų |

### Duomenų išvestis

| Būdas | Aprašymas |
|------|----------|
| Į ekraną | Duomenys išvedami naudojant std::cout ir operator<< |
| Į failą | Rezultatai įrašomi į failus naudojant isvestis.cpp |

### Perkrauti operatoriai

Studentas klasėje realizuoti operatoriai:

| Operatorius | Paskirtis |
|---|---|
| operator>> | Leidžia įvesti studento duomenis iš įvesties srauto |
| operator<< | Leidžia išvesti studento duomenis į išvesties srautą |

https://prnt.sc/bo7Rt40WibG4

## v1.5

Šioje versijoje programa išplėsta panaudojant paveldėjimą ir abstrakčias klases.

### Abstrakti klasė Zmogus

Sukurta bazinė klasė Zmogus, skirta bendrai aprašyti žmogų. Ši klasė yra abstrakti. 

https://prnt.sc/4RWDRDKIl90Z
---

# v3.0 - Nuosavas Vector konteineris

Šioje versijoje pradėtas kurti nuosavas šabloninis Vector<T> konteineris, kuris funkcionalumu yra artimas std::vector. Konteineris realizuotas faile vector.h ir naudoja dinaminę atmintį, Rule of Five, iteratorius, elementų pasiekimo funkcijas, talpos valdymą bei pagrindines modifikavimo funkcijas.

## Vector konteinerio realizacijos principas

Vector<T> saugo elementus vientisame dinaminės atminties bloke. Klasėje naudojami trys pagrindiniai laukai:

T* data_;
std::size_t size_;
std::size_t capacity_;

- data_ rodo į dinaminės atminties pradžią;
- size_ nurodo, kiek elementų šiuo metu yra konteineryje;
- capacity_ nurodo, kiek elementų galima sutalpinti be naujo atminties perskirstymo.

Kai push_back() metu size_ == capacity_, talpa padidinama dvigubai. Taip sumažinamas atminties perskirstymų skaičius.

## Realizuotos funkcijų grupės

### Member types

Realizuoti pagrindiniai tipų sinonimai:

value_type
size_type
reference
const_reference
pointer
const_pointer
iterator
const_iterator
reverse_iterator
const_reverse_iterator

### Konstruktoriai ir Rule of Five

Realizuota:

Vector()
Vector(size_type count)
Vector(size_type count, const T& value)
Vector(std::initializer_list<T> values)
Vector(const Vector& other)
Vector(Vector&& other) noexcept
Vector& operator=(const Vector& other)
Vector& operator=(Vector&& other) noexcept
~Vector()

### Elementų pasiekimas

Realizuota:

operator[]
at()
front()
back()
data()

### Iteratoriai

Realizuota:

begin()
end()
cbegin()
cend()
rbegin()
rend()
crbegin()
crend()

### Talpos valdymas

Realizuota:

empty()
size()
capacity()
max_size()
reserve()
shrink_to_fit()

### Modifikavimo funkcijos

Realizuota:

clear()
push_back()
emplace_back()
pop_back()
resize()
insert()
erase()
assign()
swap()

### Non-member funkcijos

Realizuota:

operator==
operator!=
operator<
operator<=
operator>
operator>=
swap()

## 5 Vector funkcijų naudojimo pavyzdžiai

### 1. push_back()

push_back() įdeda naują elementą į konteinerio pabaigą.

Vector<int> v;
v.push_back(10);
v.push_back(20);
v.push_back(30);

Po šių veiksmų v.size() yra 3, o elementai yra 10, 20, 30.

### 2. at()

at() leidžia pasiekti elementą pagal indeksą ir tikrina ribas.

Vector<int> v = {1, 2, 3};
std::cout << v.at(1); // 2

Jeigu indeksas išeina už ribų, metama std::out_of_range išimtis.

### 3. reserve()

reserve() iš anksto rezervuoja atmintį, bet nekeičia elementų kiekio.

Vector<int> v;
v.reserve(100);

Po šios operacijos capacity() yra bent 100, bet size() vis dar yra 0.

### 4. insert()

insert() įterpia elementą į nurodytą poziciją.

Vector<int> v = {1, 3, 4};
v.insert(v.begin() + 1, 2);

Po šios operacijos elementai yra 1, 2, 3, 4.

### 5. erase()

erase() pašalina elementą arba intervalą.

Vector<int> v = {1, 2, 3, 4};
v.erase(v.begin() + 1);

Po šios operacijos elementai yra 1, 3, 4.

## Unit testai

Vector testavimui paruoštas failas:

test_vector.cpp

Kompiliavimas:

g++ -std=c++17 -Wall -Wextra -pedantic test_vector.cpp -o test_vector

Paleidimas:

./test_vector

## std::vector ir Vector push_back() spartos palyginimas

Benchmark testas yra faile:

benchmark_vector.cpp

Kompiliavimas:

g++ -std=c++17 -O2 -Wall -Wextra -pedantic benchmark_vector.cpp -o benchmark_vector

Greitas testas:

./benchmark_vector quick

Pilnas testas:

./benchmark_vector

### Rezultatų lentelė

|       Dydis | std::vector laikas (s) | std::vector perskirstymai | Vector laikas (s) | Vector perskirstymai |
| ----------: | ---------------------: | ------------------------: | ----------------: | -------------------: |
|      10 000 |               0.000038 |                        15 |          0.000048 |                   15 |
|     100 000 |               0.000230 |                        18 |          0.000300 |                   18 |
|   1 000 000 |               0.001702 |                        21 |          0.001922 |                   21 |
|  10 000 000 |               0.025157 |                        25 |          0.028848 |                   25 |
| 100 000 000 |               0.243895 |                        28 |          0.259655 |                   28 |


### Išvada

std::vector yra standartinės bibliotekos konteineris, kuris yra labai optimizuotas, todėl kai kuriais atvejais jis gali veikti greičiau.


### Vector vs std::vector

| Failas                | Konteineris | Nuskaitymas | Rūšiavimas | Skirstymas |  Įrašymas | Operacijų suma |
| --------------------- | ----------- | ----------: | ---------: | ---------: | --------: | -------------: |
| studentai100000.txt   | std::vector |    0.322654 |   0.061694 |   0.034922 |  0.346233 |       0.765503 |
| studentai100000.txt   | Vector      |    0.284720 |   0.068381 |   0.043423 |  0.289048 |       0.685572 |
| studentai1000000.txt  | std::vector |    2.817360 |   0.722522 |   0.443347 |  3.123580 |       7.106809 |
| studentai1000000.txt  | Vector      |    2.847310 |   0.837787 |   0.380090 |  2.876570 |       6.941757 |
| studentai10000000.txt | std::vector |   45.853800 |   8.785990 |   4.259140 | 30.294800 |      89.193730 |
| studentai10000000.txt | Vector      |   31.866800 |  10.629000 |   4.441410 | 29.645600 |      76.582810 |


| Failas                | std::vector operacijų suma | Vector operacijų suma | Rezultatas                    |
| --------------------- | -------------------------: | --------------------: | ----------------------------- |
| studentai100000.txt   |                 0.765503 s |            0.685572 s | Vector greitesnis apie 10.4 % |
| studentai1000000.txt  |                 7.106809 s |            6.941757 s | Vector greitesnis apie 2.3 %  |
| studentai10000000.txt |                89.193730 s |           76.582810 s | Vector greitesnis apie 14.1 % |

Pastaba: Vector ir std::vector programos buvo paleistos su tais pačiais sugeneruotais failais. Failų generavimas į šį palyginimą neįtrauktas, nes jis labiau priklauso nuo disko įrašymo spartos, o ne nuo konteinerio veikimo.

## Doxygen dokumentacija

Projektui paruoštas Doxyfile failas. Dokumentacija generuojama komanda:

doxygen Doxyfile

Sugeneruota HTML dokumentacija atsiranda aplanke:

docs/html/index.html

Dokumentacijoje aprašomas nuosavas Vector konteineris, Studentas klasė, Zmogus abstrakti klasė ir pagalbinės programos funkcijos.