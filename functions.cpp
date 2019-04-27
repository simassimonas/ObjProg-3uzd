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

void Studentas::setGalutinis(double a){
    galutinis=a;
}

void Studentas::setEgz(double a){
    egz=a;
}

bool Studentas::operator==(const Studentas& a){
    if(egz==a.egz) return 1;
    else return 0;
}

bool Studentas::operator!=(const Studentas& a){
    if(egz!=a.egz) return 1;
    else return 0;
}

std::ostream& operator<<(std::ostream& out, const Studentas& a){
    out << a.vardas << " " << a.pavarde << " ";
    for(int i=0; i<a.nd.size(); i++){
        out << a.nd[i] << " ";
    }
    out << "Egz.: " << a.egz << " Galutinis: " << a.galutinis;
    return out;
}

std::istream& operator>>(std::istream& in, Studentas& a){
    cout << "Iveskite varda" << endl;
    in >> a.vardas;
    cout << "Iveskite pavarde" << endl;
    in >> a.pavarde;
    cout << "Iveskite egzamino pazymi" << endl;
    in >> a.egz;
    cout << "Iveskite 10 pazymiu" << endl;
    double temp;
    for(int i=0; i<10; i++){
        in >> temp;
        a.nd.push_back(temp);
    }
    //is ivestu pazymiu paskaiciuoja galutini
    a.setGalutinis();
    return in;
}

Studentas::Studentas(const Studentas& a){
    vardas = a.vardas;
	pavarde = a.pavarde;
	egz = a.egz;
	galutinis = a.galutinis;
	nd = a.nd;
}

Studentas& Studentas::operator=(const Studentas& a)
{
	if (&a == this) return *this;

	vardas = a.vardas;
	pavarde = a.pavarde;
	egz = a.egz;
	galutinis = a.galutinis;
	nd = a.nd;
	return *this;
}

//PARTITION ALGORITMO NAUDOJIMAS
bool isVargsiukas (const Studentas& laikinas) { return laikinas.getGalutinis() < 5.0; }

void rusiavimasSuPartition(vector<Studentas> &studentai){
    auto it = std::partition(studentai.begin(), studentai.end(), isVargsiukas);

    //ISVEDIMAS I FAILUS
    std::ofstream fout ("vargsiukai.txt");
    for (auto i=studentai.begin(); i!=it; i++){
        fout << *i << endl;
    }

    std::ofstream ffout ("kietakai.txt");
    for (auto i=it; i!=studentai.end(); i++){
        ffout << *i << endl;
    }
}
