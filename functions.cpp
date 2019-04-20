#include "header.h"

//TIKRINA AR SKAICIUS BINARINIS, AR NE
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

//SUGENERUOJA FAILA SU RANDOM PAZYMIAIS
void generavimasFailo(int kiekIrasu){
    srand ( time ( NULL ));
    std::ofstream fout ("generatedfile.txt");
    for(int i=0; i<kiekIrasu; i++){
        fout << "Vardas" << i+1 << " " << "Pavarde" << i+1 << " ";
        for(int j=0; j<11; j++){
            fout << (int)(1 + ( double ) rand ()/ RAND_MAX * (11 - 1 )) << " ";
        }
        fout << endl;
    }

}

//STUDENTAS KLASES FUNKCIJOS

void Studentas::setEgz(){
    egz = nd[nd.size()-1];
    nd.pop_back();
}

void Studentas::setGalutinis(){
    double vid;
    if(nd.size()==0) vid=0;
    else{
        double suma=0;
        for(double a: nd){
            suma+=a;
        }
        vid=suma/nd.size();
    }
    galutinis = 0.4*vid + 0.6*egz;
}

//PARTITION ALGORITMO NAUDOJIMAS
bool isVargsiukas (const Studentas& laikinas) { return laikinas.getGalutinis() < 5.0; }

void rusiavimasSuPartition(vector<Studentas> &studentai){
    auto it = std::partition(studentai.begin(), studentai.end(), isVargsiukas);

    //ISVEDIMAS I FAILUS
    std::ofstream fout ("vargsiukai.txt");
    for (auto i=studentai.begin(); i!=it; i++){
        fout << i->getVardas() << " " << i->getPavarde() << " ";
        auto nd = i->getNd();
        for(int j=0; j<nd.size(); j++){
            fout << nd[j] << " ";
        }
        fout << "Egz.: " << i->getEgz() << " Galutinis: " << i->getGalutinis() << endl;
    }

    std::ofstream ffout ("kietakai.txt");
    for (auto i=it; i!=studentai.end(); i++){
        ffout << i->getVardas() << " " << i->getPavarde() << " ";
        auto nd = i->getNd();
        for(int j=0; j<nd.size(); j++){
            ffout << nd[j] << " ";
        }
        ffout << "Egz.: " << i->getEgz() << " Galutinis: " << i->getGalutinis() << endl;
    }
}
