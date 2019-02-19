//Simono Šaltenio 2gr. 2pogr. v0.1.1 versija padaryta naudojant masyvus vietoj vectoriu
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <limits>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <algorithm>

using std::cout; using std::endl; using std::cin; using std::string; using std::vector;

struct stud{
string vardas;
string pavarde;
int *nd;
int ndKiek;
int egz;
double galutinis;
};

void ivedimas(int x, stud *studentai){
    int input=0;
    int kiek=0;
    int *temp;
    int *pagr;
    while(input>=0){
        cin >> input;
        // tikrinu, ar ivestas skaicius yra int'as, viskas veikai isskyrus atveji,
        // kai ivedamas float'as, tada ismeta errora, taciau input'a nuskaito ir suapvalina
        // per pratybas parodziau destytojui, bet ir jam nepavyko issiaiskinti kodel taip vyksta
        if(cin.fail()){
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Ivedete ne int'a" << endl;
            input=0;
        }
        else if(input>10) cout << "Pazymys negali but daugiau nei 10" << endl;
        else{
            if(input>=0){
                kiek++;
                temp = new int[kiek];
                for(int i=0; i<kiek; i++){
                    if(i==kiek-1) temp[i]=input;
                    else temp[i]=pagr[i];
                }
                delete[] pagr;
                pagr=temp;
                studentai[x].nd=pagr;
                studentai[x].ndKiek=kiek;
            }
        }
    }
}

void generavimas(int x, stud *studentai, int kiek){
    srand ( time ( NULL ));
    studentai[x].nd = new int[kiek];
    studentai[x].ndKiek = kiek;
    for(int i=0; i<kiek; i++){
        studentai[x].nd[i] = (int)(1 + ( double ) rand ()/ RAND_MAX * (11 - 1 ));
    }
}

double galVid(int i, stud *studentai){
    double vid;
    if(studentai[i].ndKiek==0) vid=0;
    else{
        int suma=0;
        for(int j=0; j<studentai[i].ndKiek; j++){
            suma+=studentai[i].nd[j];
        }
        vid=(double)suma/studentai[i].ndKiek;
    }
    double gal;
    gal = 0.4 * vid + 0.6 * (double)studentai[i].egz;
    return gal;
}

double galMed(int i, stud *studentai){
    double mediana;
    if(studentai[i].ndKiek==0) mediana=0;
    else{
        std::sort(studentai[i].nd, studentai[i].nd + studentai[i].ndKiek);
        if(studentai[i].ndKiek%2!=0) mediana=studentai[i].nd[studentai[i].ndKiek/2];
        else mediana=(double)((studentai[i].nd[studentai[i].ndKiek/2]+studentai[i].nd[studentai[i].ndKiek/2-1]))/2;
    }
    double gal;
    gal = 0.4 * mediana + 0.6 * (double)studentai[i].egz;
    return gal;
}

void tikrinimasBinarinio(int &sk){
    while(1){
        cin >> sk;
        if(cin.fail()){
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Ivedete ne int'a" << endl;
            sk = 2;
        }
        if(sk==1) break;
        else if(sk==0) break;
        else cout << "Turite ivesti 0 arba 1" << endl;
    }
}

void isvedimas(int n, stud *studentai, int ar){
    //nustato, kruis studentas turi daugiausia raidziu savo varde ir pavardeje
    int didVard=0, didPav=0, temp;
    for(int i=0; i<n; i++){
        temp = studentai[i].vardas.length();
        if(temp>didVard) didVard=temp;

        temp = studentai[i].pavarde.length();
        if(temp>didPav) didPav=temp;
    }

    cout << std::left << std::setw(didVard+3) << "Vardas" << std::left << std::setw(didPav+3) << "Pavarde";
    if(ar) cout << "Galutinis (Vid.)" << endl;
    else cout << "Galutinis (Med.)" << endl;
    for(int i=0; i<didVard+didPav+23; i++){
        cout << "-";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << std::left << std::setw(didVard+3) << studentai[i].vardas << std::left << std::setw(didPav+3) << studentai[i].pavarde << std::left << std::setw(3) << std::fixed << std::setprecision(2) << studentai[i].galutinis << endl;
    }
}

int main()
{
    cout << "Jei norite skaiciuoti su vidurkiu, iveskite 1, jei su mediana 0: " << endl;
    int ar=2;
    //tikrina ar ivedamas geras skaicius
    tikrinimasBinarinio(ar);

    cout << "Kiek studentu bus is viso:" << endl;
    int n;
    //tikrina ar ivedamas geras skaicius
    while(1){
        cin >> n;
        if(cin.fail()){
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Ivedete ne int'a" << endl;
        }
        else if (n<=0) cout << "Studentu turi buti daugiau nei 0" << endl;
        else break;
    }

    cout << "Jei norite, kad gautieji balai uz n.d butu sugeneruoti atsitiktinai, iveskite 1, jei norite irasyti patys, iveskite 0" << endl;
    int arNd=2;
    //tikrina ar ivedamas geras skaicius
    tikrinimasBinarinio(arNd);

    stud studentai[n];
    for(int i=0; i<n; i++) {
        cout << "Iveskite studento varda ir pavarde:" << endl;
        cin >> studentai[i].vardas;
        cin >> studentai[i].pavarde;
        cout << "Iveskite egzamino rezultata: " << endl;
        //tikrina ar ivedamas geras skaicius
        while(1){
            cin >> studentai[i].egz;
            if(cin.fail()){
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Ivedete ne int'a" << endl;
            }
            else if (studentai[i].egz>10 || studentai[i].egz<0) cout << "Egzamino rezultatas turi but tarp 0 ir 10" << endl;
            else break;
        }

        if(arNd==0){
            cout << "Ivesktie N.D pazymius (kai noresite nutraukti ivedima, iveskite neigiama int'a): " << endl;
            ivedimas(i, studentai);
        }
        else{
            cout << "Kiek n.d pazymiu norite, jog butu sugeneruota?" << endl;
            int kiek;
            //tikrina ar ivedamas geras skaicius
            while(1){
                cin >> kiek;
                if(cin.fail()){
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Ivedete ne int'a" << endl;
                }
                else if (kiek<=0) cout << "Pazymiu turi buti daugiau nei 0" << endl;
                else break;
            }
            generavimas(i, studentai, kiek);
        }

        if(ar==1) studentai[i].galutinis=galVid(i, studentai);
        else studentai[i].galutinis=galMed(i, studentai);
    }

    isvedimas(n, studentai, ar);

    return 0;
}
