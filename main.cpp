///Simono Šaltenio 2gr. 2pogr. v0.2
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <limits>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <fstream>

using std::cout; using std::endl; using std::cin; using std::string; using std::vector;

struct stud{
string vardas;
string pavarde;
vector<int> nd;
int egz;
double galutinis;
};

int tikrinimas(){
    int input;
    cin >> input;
    if(cin.fail()){
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Ivedete ne int'a" << endl;
        return 0;
    }
    if(input>10){
        cout << "Pazymys negali but daugiau nei 10" << endl;
        return 0;
    }
    else return input;
}

void ivedimas(int i, stud *studentai){
    int input=0;
    while(input>=0){
        input = tikrinimas();
        if(input>0){
            studentai[i].nd.push_back(input);
        }
    }
}

void generavimas(int x, stud *studentai, int kiek){
    srand ( time ( NULL ));
    for(int i=0; i<kiek; i++){
        studentai[x].nd.push_back((int)(1 + ( double ) rand ()/ RAND_MAX * (11 - 1 )));
    }
}

double galVid(int i, stud *studentai){
    double vid;
    if(studentai[i].nd.size()==0) vid=0;
    else{
        int suma=0;
        for(int a: studentai[i].nd){
            suma+=a;
        }
        vid=(double)suma/studentai[i].nd.size();
    }
    double gal;
    gal = 0.4 * vid + 0.6 * (double)studentai[i].egz;
    return gal;
}

double galMed(int i, stud *studentai){
    double mediana;
    //jeigu namu darbu neivesta, tai mediana lygi 0
    if(studentai[i].nd.size()==0) mediana=0;
    else{
        //surusiuoja nd vectoriu
        sort(studentai[i].nd.begin(), studentai[i].nd.end());
        if(studentai[i].nd.size()%2!=0) mediana=studentai[i].nd.at(studentai[i].nd.size()/2);
        else mediana=(double)((studentai[i].nd.at(studentai[i].nd.size()/2)+studentai[i].nd.at((studentai[i].nd.size()/2-1))))/2;
    }
    double gal;
    gal = 0.4 * mediana + 0.6 * (double)studentai[i].egz;
    return gal;
}

void tikrinimasBinarinio(int &sk){
    cin.clear();
    while(1){
        cin >> sk;
        if(cin.fail()){
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Ivedete ne int'a tikrinimas inarinio" << endl;
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
    //rusiavimas pagal vardus
    //i string vectoriu v idedu visus studentu vardus
    vector<string> v;
    for(int i=0; i<n; i++){
        v.push_back(studentai[i].vardas);
    }
    //surusiuoja abeceles tvarka
    sort(v.begin(),v.end());

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v.at(i)==studentai[j].vardas) cout << std::left << std::setw(didVard+3) << studentai[j].vardas << std::left << std::setw(didPav+3) << studentai[j].pavarde << std::left << std::setw(3) << std::fixed << std::setprecision(2) << studentai[j].galutinis << endl;
        }
    }
}

int main()
{
    cout << "Jei norite duomenis nuskaityti is failo, iveskite 1, jei norite juos ivesti pats, iveskite 0" << endl;
    int arDuom=2;
    tikrinimasBinarinio(arDuom);
    if(arDuom){
        cout << "Jei norite skaiciuoti su vidurkiu, iveskite 1, jei su mediana 0: " << endl;
        int ar=2;
        //tikrina ar ivedamas geras skaicius
        tikrinimasBinarinio(ar);

        std::ifstream fin ("duom.txt");
        int n; //kiek is viso studentu
        int m; //kiek is viso pazymiu
        fin >> n;
        if(fin.fail()){
            cout << "Blogas failas" << endl;
            exit (EXIT_FAILURE);
        }
        fin >> m;
        if(fin.fail()){
            cout << "Blogas failas" << endl;
            exit (EXIT_FAILURE);
        }
        stud studentai[n];
        int temp;
        for(int i=0; i<n; i++){
            fin >> studentai[i].vardas >> studentai[i].pavarde;
            for(int j=0; j<m+1; j++){
                fin >> temp;
                if(fin.fail()){
                    cout << "Blogas failas" << endl;
                    exit (EXIT_FAILURE);
                }
                else{
                if(j==m) studentai[i].egz = temp;
                else studentai[i].nd.push_back(temp);
                }
            }
        if(ar==1) studentai[i].galutinis=galVid(i, studentai);
        else studentai[i].galutinis=galMed(i, studentai);
        }
        isvedimas(n, studentai, ar);
    }
    else{
    cout << "Jei norite skaiciuoti su vidurkiu, iveskite 1, jei su mediana 0: " << endl;
    int ar=2;
    //tikrina ar ivedamas geras skaicius
    cin.clear();
    tikrinimasBinarinio(ar);

    cout << "Kiek studentu bus is viso:" << endl;
    int n;
    //tikrina ar ivedamas geras skaicius
    while(1){
        cin >> n;
        if(cin.fail()){
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Ivedete ne int'a grdgdg" << endl;
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
    }

    return 0;
}
