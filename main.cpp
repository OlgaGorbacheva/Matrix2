#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    if (!fin.is_open()){
        cerr << "Input error" << endl;
        return 0;
    }
    my::matrix<> a;
    my::matrix<> b(a);
    my::matrix<> c;
    c = a;
    my::matrix<double> d;
    my::matrix<> k(5);
    c = k;
    my::matrix<float> l(3, 4);
    a[1][1] = 5;
    a[0][1] = 6;
    l[1][5] = 10;
    cout << a[0][1] << endl << a[1][1] << endl << l[1][5] << endl;
    fin >> b;
    fin >> a;
    c = b + a;
    cout << c;
    return 0;
}
