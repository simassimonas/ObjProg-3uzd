#include "header.h"

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
