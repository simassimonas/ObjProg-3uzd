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

using std::cout; using std::endl; using std::cin; using std::string; using std::vector; using std::deque; using std::list;

class Studentas {
private:
  string vardas;
  string pavarde;
  vector<double> nd;
  double egz;
  double galutinis;
public:
  Studentas() : egz(0), galutinis(0) { }  // default konstruktorius
  inline string getVardas() const { return vardas;}
  inline string getPavarde() const { return pavarde;}
  inline double getGalutinis() const { return galutinis;}
  inline double getEgz() const { return egz;}
  const vector<double>& getNd() const {return nd;}
  void setVardas(string v) {vardas=v;}
  void setPavarde(string p) {pavarde=p;}
  void pushNd(double n) {nd.push_back(n);}
  void setEgz();
  void setGalutinis();

};

bool isVargsiukas (const Studentas&);
void rusiavimasSuPartition(vector<Studentas> &);

void generavimasFailo(int);

void tikrinimasBinarinio(int &);
int tikrinimas();

#endif // HEADER_H_INCLUDED
