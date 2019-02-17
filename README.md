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


