#include "Utils.hpp"
//#include <iostream>
#include <fstream>
#include <sstream>
# include <iomanip>
#include <vector>

//using namespace std;

bool Import_vectors(const string& fileread,
                    size_t& n,
                    double*& w,
                    double*& r,
                    double& s){
    ifstream file;
    file.open(fileread);

    if (file.fail()){
        cerr <<"File not found"<<endl;
        return false;//terminate function
    }



    string desc;
    getline(file, desc, ';');

    //read of sum S to invest
    string val;
    getline(file, val);
    istringstream converts(val);
    converts >> s;
    converts.clear();



    //read of how many assets (n)
    string lungh;
    getline(file, desc, ';');
    getline(file, lungh);

    istringstream convertn(lungh);

    convertn >> n;
    convertn.clear();


    //ignoring description line
    getline(file, desc);


    string valuew;
    string valuer;

    double fract_value;
    double rate_value;
    //from here they are a dynamic memory object
    w = new double [n];
    r = new double [n];

    for ( size_t i = 0; i<n; ++i) {

        getline(file, valuew, ';');
        getline(file, valuer);

        istringstream convertw(valuew);
        convertw>>fract_value;
        w[i]=fract_value;
        //convertw.clear(); inutile

        istringstream convertr(valuer);
        convertr>>rate_value;
        r[i]=rate_value;
        //convertr.clear(); inutile
    }


    file.close();

    return true;


}

string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}

double Calculte_valueportfolio(const size_t& n,
                             double& s,
                             const double* const& w,
                             const double* const& r){
    double v=0.0;

    for ( size_t i = 0; i<n; ++i) {
        v += w[i]*s*(r[i]+1);
    }
    return v;


}


double Calculte_rateofreturn(const double& s,
                             const double& v){

    //the rate of return is: r=(V/S)-1
    double final_rate=0.0;
    final_rate= (v/s)-1;


    return final_rate;


}
