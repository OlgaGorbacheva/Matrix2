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
    my::matrix<> a(2, 3), b(3, 3);
    fin >> a;
    fin >> b;
    cout << a * b * 2;
    return 0;
}
