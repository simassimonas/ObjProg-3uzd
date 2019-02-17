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

### [v0.1]()
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
