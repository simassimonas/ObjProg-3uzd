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
Su 10 irasu: 3ms
Su 100 irasu: 10ms
Su 1000 irasu: 42ms
Su 10000 irasu: 308ms 
Su 100000 irasu: 2930ms
Su 1000000 irasu: 30431ms
