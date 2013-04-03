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
    my::matrix<> a(3, 3);
    fin >> a;
    cout << a.determinant() << endl;
    return 0;
}
