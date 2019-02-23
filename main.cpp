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

void ivedimas(stud &temp){
    int input=0;
    while(input>=0){
        input = tikrinimas();
        if(input>0){
            temp.nd.push_back(input);
        }
    }
}

void generavimas(stud &temp, int kiek){
    srand ( time ( NULL ));
    for(int i=0; i<kiek; i++){
        temp.nd.push_back((int)(1 + ( double ) rand ()/ RAND_MAX * (11 - 1 )));
    }
}

double galVid(stud &temp){
    double vid;
    if(temp.nd.size()==0) vid=0;
    else{
        int suma=0;
        for(int a: temp.nd){
            suma+=a;
        }
        vid=(double)suma/temp.nd.size();
    }
    double gal;
    gal = 0.4 * vid + 0.6 * (double)temp.egz;
    return gal;
}

double galMed(stud &temp){
    double mediana;
    //jeigu namu darbu neivesta, tai mediana lygi 0
    if(temp.nd.size()==0) mediana=0;
    else{
        //surusiuoja nd vectoriu
        sort(temp.nd.begin(), temp.nd.end());
        if(temp.nd.size()%2!=0) mediana=temp.nd.at(temp.nd.size()/2);
        else mediana=(double)((temp.nd.at(temp.nd.size()/2)+temp.nd.at((temp.nd.size()/2-1))))/2;
    }
    double gal;
    gal = 0.4 * mediana + 0.6 * (double)temp.egz;
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

void isvedimas(vector<stud> &studentai, int ar){
    //nustato, kruis studentas turi daugiausia raidziu savo varde ir pavardeje
    int didVard=0, didPav=0, temp;
    for(int i=0; i<studentai.size(); i++){
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
    for(int i=0; i<studentai.size(); i++){
        v.push_back(studentai[i].vardas);
    }
    //surusiuoja abeceles tvarka
    sort(v.begin(),v.end());

    for(int i=0; i<studentai.size(); i++){
        for(int j=0; j<studentai.size(); j++){
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

        vector<stud> studentai;
        std::ifstream fin ("duom.txt");
        string line;
        while (getline(fin, line)){
            if(line!=""){
                stud temp;
                int x;
                std::istringstream iss(line);
                iss >> temp.vardas;
                iss >> temp.pavarde;

                while(!iss.eof()){
                    iss >> x;
                    if(iss.fail()) {
                        iss.clear();
                        string laikinas;
                        iss >> laikinas;
                        continue;
                        /*cout << "Blogai ivesti duomenys" << endl;
                        exit(EXIT_FAILURE);*/
                    }
                    else if(x<0 || x>10){
                    continue;
                    }
                    else temp.nd.push_back(x);
                }
                temp.egz=temp.nd.back();
                temp.nd.pop_back();

                if(ar==1) temp.galutinis=galVid(temp);
                else temp.galutinis=galMed(temp);

                studentai.push_back(temp);
            }
            else continue;
        }
        isvedimas(studentai, ar);
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
                cout << "Ivedete ne int'a" << endl;
            }
            else if (n<=0) cout << "Studentu turi buti daugiau nei 0" << endl;
            else break;
        }

        cout << "Jei norite, kad gautieji balai uz n.d butu sugeneruoti atsitiktinai, iveskite 1, jei norite irasyti patys, iveskite 0" << endl;
        int arNd=2;
        //tikrina ar ivedamas geras skaicius
        tikrinimasBinarinio(arNd);

        vector<stud> studentai;
        for(int i=0; i<n; i++) {
            stud temp;
            cout << "Iveskite studento varda ir pavarde:" << endl;
            cin >> temp.vardas;
            cin >> temp.pavarde;
            cout << "Iveskite egzamino rezultata: " << endl;
            //tikrina ar ivedamas geras skaicius
            while(1){
                cin >> temp.egz;
                if(cin.fail()){
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Ivedete ne int'a" << endl;
                }
                else if (temp.egz>10 || temp.egz<0) cout << "Egzamino rezultatas turi but tarp 0 ir 10" << endl;
                else break;
            }

            if(arNd==0){
                cout << "Ivesktie N.D pazymius (kai noresite nutraukti ivedima, iveskite neigiama int'a): " << endl;
                ivedimas(temp);
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
                generavimas(temp, kiek);
            }

            if(ar==1) temp.galutinis=galVid(temp);
            else temp.galutinis=galMed(temp);

            studentai.push_back(temp);

        }
        isvedimas(studentai, ar);
    }
    return 0;
}
