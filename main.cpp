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
    fin >> b;
    fin >> a;
    c = b + a;
    cout << c << endl;
    cout << +c << endl;
    c = b - a;
    cout << c << endl;
    cout << -c << endl;
    c = a + 5;
    cout << c << endl;
    return 0;
}
