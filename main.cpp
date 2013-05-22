#include "matrix.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    if (!fin.is_open()){
        cerr << "Input error" << endl;
        return 0;
    }
    my::matrix<int> a(3, 3);
    fin >> a;
    my::matrix<double> b(5, 5);
//    b = a.inverse();
    b = a * a.inverse();
    cout << b << endl;
    return 0;
}
