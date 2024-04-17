#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
# include <iomanip>
#include <vector>
using namespace std;


int main()
{
    //i need s in other functions so i define it here in order to refere to it in Import
    double s=0.0;
    string fileread= "data.csv";
    size_t n = 0;

    //this is a simple definition of two addresses, they will become vectors in Import function
    double* w = nullptr;
    double* r = nullptr;


    ofstream filewrite("result.txt");

    if (Import_vectors(fileread, n,w,r,s)){
        cout<<"import successful!"<<endl;
    }else {
        cout<<"something wrong..."<<endl;
        return 1;
    }

    cout<<"S =  "<<fixed<<setprecision(2)<<s<<endl;
    cout<<"n = "<<n<<endl;

    filewrite<<fixed<<setprecision(2)<<"S =  "<<s<<", ";
    filewrite<<setprecision(0)<<"n = "<<n<<endl;


    //recall function to print correctly values of vectors on file result.txt
    //w
    cout<<"w =  "<<ArrayToString(n,w)<<endl;
    filewrite<<"w =  ";
    filewrite<<ArrayToString(n,w)<<endl;
    //r
    cout<<"r =  "<<endl;
    filewrite<<"r =  ";
    filewrite<<ArrayToString(n,r)<<endl;


    //i deduce the rate of return from the final value of portfolio
    //so let's first calculate the final portfolio
    double v=Calculte_valueportfolio(n,s,w,r);
    cout << "Final portfolio value V: "<<setprecision(2)<<v<<endl;
    //than deduce the final ratio using : r=(V/S)-1
    double final_rate=Calculte_rateofreturn(s,v);
    cout << "total rate of return: "<<setprecision(4)<<final_rate<<endl;

    filewrite<<"Rate of return of the portfolio: "<<setprecision(4)<<final_rate<<endl;
    filewrite<<"V: "<<setprecision(2)<<v<<endl;


    filewrite.close();

    return 0;
}

