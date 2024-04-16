//HEADER GUARDS
#pragma ones

#include <iostream>
using namespace std;


//size_t = typename to represent dimensions
//import vectors reading them from the fileread
bool Import_vectors(const string& fileread,
                    size_t& n,
                    double*& w,
                    double*& r,
                    double& s);

string ArrayToString(const size_t& n,
                     const double* const& v);

double Calculte_valueportfolio(const size_t& n,
                               double& s,
                               const double* const& w,
                               const double* const& r);

double Calculte_rateofreturn(
                             const double& s,

                             const double& v);
