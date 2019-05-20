 # 2 UZDUOTIS 
 ## Programos paleidimas naudojant `GNU C++ Compiler`
**Tiesiog per terminala**
- `g++ -o run main.cpp `
- `./run`

**Su Makefile**

Programos sudarymas:
- `make`

Sudarytu failu istrynimas:
- `clean`

**Po v0.3**

Programos sudarymas:
- `make`

functions.cpp failo sukompiliavimas:
- `fun`

Sudarytu failu istrynimas:
- `clean`

## Versiju istorija

### [v0.1](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.1)
**Pridėta**
- Pirmine programos versija
- .gitignore failas
- Makefile

**Pastebejimas**

Esant tokiam kodui, ciklas veiks, kol ivedami int'ai ir tarkim ivedus raide, jis sustos ir nenuskaitys reiksmes, taciau ivedus float'a, pvz., 2.3 ciklas sustos, bet pries tai nuskaitys reiksme, ja suapvalins iki 2 ir isves i ekrana 

```shell
int x;
    while(cin >> x) {
    cout << x << endl;
    }
```

### [v0.1.1](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.1.1)
**Pridėta**
- cmasyvas.cpp file'as, kuriame n.d rezultatai saugomi ne vectoriuje, o masyve

### [v0.2](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.2)
**Pridėta**
- Antrine programos versija
- duom.txt failas

Pirmas skaicius nurodo, kiek bus studentu, antras skaicius nurodo, kiek bus n.d pazymiu, o kiekvienos eilutes paskutinis skaitmuo yra egzamino rezultatas

```shell
5 3
vardas1 vardas2 3 6 8 3
vardas2 vardas2 5 7 3 1
vardas3 vardas2 1 6 10 6
vardas4 vardas4 6 4 1 10
vardas5 vardas5 7 4 2 7
```

**Papildyta**
- README.md failas

**Pastebejimas**

Deja, laiku nespejau padaryti vardu rusiavimo ir parasyti tvarkingu komentaru, bet tai padarysiu su kitu commitu arba blogiausiu atveju kitu releas'u.

### [v0.2.1](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.2.1)
**Pridėta**
- Pridėtas studentų rūšiavimas pagal vardus

**Papildyta**
- Patobulintas nuskaitymas is failo

Nebereikia pirmu dvieju skaiciu, nurodanciu, kiek bus studentu ir kiek n.d pazymiu jie tures. Dabar kiekvienas studentas gali tureti skirtinga n.d pazymiu kieki, o paskutinis skaicius nurodo egzamino rezultata

```shell
vardas4 vardas 3 6 8 3 6 
vardas3 vardas 5 7 1 4
vardas1 vardas 1 6 10 6 2 6 4 
vardas5 vardas 6 4 5
vardas2 vardas 7 4 2 7
```
### [v0.3](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.3)
**Pridėta**
- exception handling
- header ir funkciju failai

**Papildyta**
- updated makefile

### [v0.4](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.4)
**Pridėta**
- Ketvirta programos versija
- galimybe generuoti atsitiktinius studentu sarasu failus
- studentu rusiavimas i dvi grupes ir isvedimas i skirtingus failus (vargsiukai ir kietakai)
- programos veikimo laiko matavimas

**Programos veikimo laiko testavimas generuojant skirtingo dydzio duomenu failus**

| Irašų sk.  | Trukmė | 
|----------|-------------|
| 10 | 3ms  |
| 100 | 10ms | 
| 1000 | 42ms | 
| 10000 | 308ms | 
| 100000 | 2930ms | 
| 1000000 | 30431ms | 

### [v0.5](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.5)
**Pridėta**
- pridetos persidengiancios funkcijos, todel skaiciavimus galima atlikti su vector, deque ir list tipo konteineriais

**Programos veikimo laiko testavimas naudojant vienodo dydzio duomenu failus, bet skirtingo tipo konteinerius**

| Konteineris | 100000irašų | 500000irašų |
|:---:|:---:|:---:|
| Vector | 2181ms |  10901ms |
| Deque | 2267ms | 11592ms |
| List | 121340ms | error |

 `sitoj versijoje blogai padaryta su list konteineriu, v0.5.1 pataisyta`

### [v0.5.1](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v0.5.1)
**Papildyta**
- buvau pridares nesamoniu su list konteineriu, todel skaiciavimai truko neadekvaciai ilgai, dabar viskas sutvarkyta

| Konteineris | 100000irašų | 500000irašų |
|:---:|:---:|:---:|
| List | 2136ms | 10730ms |

### [v1.0](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v1.0)
**Pridėta**
- antra startegija
- skaiciavimas su std::partition algoritmu

**Programos veikimo laiko testavimas naudojant skirtingo dydzio duomenu failus ir skirtingas strategijas**

**Vector**

| Irašų sk. | 1 strategija | 2 strategija |
|:---:|:---:|:---:|
| 1000 | 26ms | 128ms |
| 10000 | 240ms | 9s |
| 100000 | 2,2s | 897s |
| 1000000 | 22s | Per ilgai |


 **Deque**

| Irašų sk. | 1 strategija | 2 strategija |
|:---:|:---:|:---:|
| 1000 | 24ms | 70ms |
| 10000 | 240ms | 3.5s |
| 100000 | 2,2s | 375s |
| 1000000 | 23s | Per ilgai |


**List**

| Irašų sk. | 1 strategija | 2 strategija |
|:---:|:---:|:---:|
| 1000 | 30ms | 30ms |
| 10000 | 270ms | 212ms |
| 100000 | 2,1s | 2.1s |
| 1000000 | 22s | 21s |

**Skaiciavimu trukme, pritaikius std::partition algoritma vectoriui**

| Irašų sk. | std::partition |
|:---:|:---:|
| 1000 | 26ms | 
| 10000 | 230ms | 
| 100000 | 2,1s | 
| 1000000 | 21s | 

### [PAPILDOMA UZDUOTIS](https://github.com/simassimonas/ObjProg-2uzd/releases/tag/v1.1)
**Pridėta**
- raskMinkstus() ir iterpkKietus() funkcijos

| Irašų sk. | raskMinkstus() | iterpkKietus(vector) | terpkKietus(deque) |
|:---:|:---:|:---:|:---:|
| 10000 | 9.2s | 9ms | 13ms |
| 100000 | 894s | 90ms | 150ms |


### [v1.1](https://github.com/simassimonas/ObjProg-3uzd/releases/tag/v1.1)
**Pridėta**
- studento klase

**Skaiciavimu trukme, pritaikius std::partition algoritma ir vectoriu naudojant sena struct**

| Irašų sk. | std::partition |
|:---:|:---:|
| 10000 | 230ms | 
| 100000 | 2,1s | 
| 500000 | 21s | 

**Skaiciavimu trukme, pritaikius std::partition algoritma ir vectoriu naudojant nauja class**

| Irašų sk. | std::partition |
|:---:|:---:|
| 10000 | 430ms | 
| 100000 | 4,3s | 
| 500000 | 21s | 

**Skaiciavimu trukme, pritaikius std::partition algoritma, vectoriu ir naudojant nauja class bei optimization flags (sie skaiciavimai buvo atlikti ne ant Windows'u, o ant Ubuntu, todel greiciai gerokai skiriasi nuo praeitu)**

| Irašų sk. | default | O1 | O2 | O3 |
|:---:|:---:|:---:|:---:|:---:|
| 10000 | 100ms | 77ms | 73ms | 71ms | 
| 100000 | 1050Ms | 750ms | 750ms | 750ms | 
| 500000 | 5s | 3,7s | 3,7s | 3,7s |  

### [v1.2](https://github.com/simassimonas/ObjProg-3uzd/releases/tag/v1.2)
**Pridėta**
- Prideti operatoriu overload'ai

### [v1.5](https://github.com/simassimonas/ObjProg-3uzd/releases/tag/v1.5)
**Pridėta**
- Sukurtos based ir derived klases

### [v2.0](https://github.com/simassimonas/ObjProg-3uzd/releases/tag/v2.0)
**Pridėta**
- doxygen dokumentacija 
- unit testai

**GoogleTest testai**

```shell
TEST(Studentas, arTeisingasVardas) {
	Studentas stud;
	stud.setVardas("Simas");
	EXPECT_EQ("Simas", stud.getVardas());
}

TEST(Studentas, arGalutinis) {
	Studentas stud;
	stud.setGalutinis();
	EXPECT_EQ(0, stud.getGalutinis());
}

TEST(Studentas, arDefined) {
	Studentas stud;
	EXPECT_EQ(0, stud.getEgz());
}
```
**GoogleTest testu rezultatai**

```shell
Running main() from e:\a\_work\1173\s\thirdparty\googletest\googletest\src\gtest_main.cc
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from Studentas
[ RUN      ] Studentas.arTeisingasVardas
[       OK ] Studentas.arTeisingasVardas (0 ms)
[ RUN      ] Studentas.arGalutinis
[       OK ] Studentas.arGalutinis (0 ms)
[ RUN      ] Studentas.arDefined
[       OK ] Studentas.arDefined (0 ms)
[----------] 3 tests from Studentas (4 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test case ran. (7 ms total)
[  PASSED  ] 3 tests.
```
