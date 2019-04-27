///Simono Šaltenio 2gr. 2pogr. v0.5.1

#include "header.h"

int main()
{
    //PASIRINKTI KIEK IRASU
    int kiekIrasu=100000;
    generavimasFailo(kiekIrasu);

    //LAIKO SKAICIAVIMAS
    Timer t;  // Paleisti

    vector<Studentas> studentai;

    std::ifstream fin ("generatedfile.txt");
    string line;
    try{
        if(!fin) throw "FAILAS NEEGZISTUOJA";

        while (getline(fin, line)){
            if(line!=""){
                Studentas temp;
                int x;
                string tempString;

                std::istringstream iss(line);

                iss >> tempString;
                temp.setVardas(tempString);
                iss >> tempString;
                temp.setPavarde(tempString);

                while(!iss.eof()){
                    iss >> x;
                    if(iss.fail()) {
                        iss.clear();
                        string laikinas;
                        iss >> laikinas;
                        continue;
                        /*
                        arba butu galima is viso sustabdyti programa
                        cout << "Blogai ivesti duomenys" << endl;
                        exit(EXIT_FAILURE);
                        */
                    }
                    else if(x<0 || x>10){
                    continue;
                    }
                    else temp.pushNd(x);
                }
                temp.setEgz();
                temp.setGalutinis();
                studentai.push_back(temp);
            }
            else continue;
        }

        rusiavimasSuPartition(studentai);

    cout << "Programos trukme: " << t.elapsed() << "s" << endl;
    }catch(const char* msg){
    cout << msg << endl;
    }
    return 0;
}
