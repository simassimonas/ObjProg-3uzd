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

struct stud{
string vardas;
string pavarde;
vector<int> nd;
int egz;
double galutinis;
};

int tikrinimas();

void ivedimas(stud&);

void generavimas(stud &, int);

double galVid(stud &);

double galMed(stud &);

void tikrinimasBinarinio(int &);

void isvedimas(vector<stud> &, int);

void surusiuotuIsvedimas(vector<stud> &, vector<stud> &);
void surusiuotuIsvedimas(deque<stud> &, deque<stud> &);
void surusiuotuIsvedimas(list<stud> &, list<stud> &);

void rusiavimasStudentu(vector<stud> &, vector<stud> &, vector<stud> &, int);
void rusiavimasStudentu(deque<stud> &, deque<stud> &, deque<stud> &, int);
void rusiavimasStudentu(list<stud> &, list<stud> &, list<stud> &, int);

void surusiuotuIsvedimas(vector<stud> &, vector<stud> &, int);
void surusiuotuIsvedimas(deque<stud> &, deque<stud> &, int);
void surusiuotuIsvedimas(list<stud> &, list<stud> &, int);

void rusiavimasStudentu(vector<stud> &, vector<stud> &, int);
void rusiavimasStudentu(deque<stud> &, deque<stud> &, int);
void rusiavimasStudentu(list<stud> &, list<stud> &, int);

bool isVargsiukas (const stud&);
void rusiavimasSuPartition(vector<stud> &);


void generavimasFailo(int);

void tikrinimasDuom(int &);

#endif // HEADER_H_INCLUDED
