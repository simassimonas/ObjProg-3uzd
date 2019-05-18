#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <limits>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <deque>
#include <list>
#include <algorithm>
#include <iomanip>

using std::cout; using std::endl; using std::cin; using std::string; using std::vector; using std::deque; using std::list;

class Zmogus {
protected:
    string vardas;
    string pavarde;
    Zmogus(string v = "", string p = "") : vardas(v), pavarde(p) { }
public:
    virtual void niekoNereiskianti() = 0;
    void setVardas(string vard) { vardas = vard;}
	void setPavarde(string pav) { pavarde = pav;}
    inline string getVardas() const { return vardas;}
    inline string getPavarde() const { return pavarde;}
};

class Studentas : public Zmogus {
protected:
  vector<double> nd;
  double egz;
  double galutinis;
public:
    virtual void niekoNereiskianti(){};
    Studentas(string v = "", string p = "", double eg = 0, double gal = 0) : Zmogus(v, p), egz(eg), galutinis(gal) { nd.clear(); }  // default konstruktorius
    Studentas(Studentas&& a) : Zmogus(a.vardas, a.pavarde), egz{a.egz}, nd{std::move(a.nd)} {};
    Studentas(const Studentas& a);
    inline double getGalutinis() const { return galutinis;}
    inline double getEgz() const { return egz;}
    const vector<double>& getNd() const {return nd;}
    void pushNd(double n) {nd.push_back(n);}
    void setEgz();
    void setEgz(double a);
    void setGalutinis();
    void setGalutinis(double a);
    friend std::ostream& operator<<(std::ostream& out, const Studentas& a);
    friend std::istream& operator>>(std::istream& in, Studentas& a);
    bool operator==(const Studentas& a);
    bool operator!=(const Studentas& a);
    Studentas& operator=(const Studentas& a);
};



class Timer {
 private:
  // per using sutrumpiname ilgus chrono bibliotekos tipus
  using hrClock = std::chrono::high_resolution_clock;
  using durationDouble = std::chrono::duration<double>;
  std::chrono::time_point<hrClock> start;

 public:
  Timer() : start{hrClock::now()} {}
  void reset() { start = hrClock::now(); }
  double elapsed() const {
    return durationDouble(hrClock::now() - start).count();
  }
};

bool isVargsiukas (const Studentas&);
void rusiavimasSuPartition(vector<Studentas> &);

void generavimasFailo(int);

void tikrinimasBinarinio(int &);
int tikrinimas();



#endif // HEADER_H_INCLUDED
