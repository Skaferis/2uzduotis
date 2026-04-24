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