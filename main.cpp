///Simono Šaltenio 2gr. 2pogr. v0.2
#include "header.h"

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
        try{
            if(!fin) throw "FAILAS NEEGZISTUOJA";

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
        }catch(const char* msg){
        cout << msg << endl;
        }
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
