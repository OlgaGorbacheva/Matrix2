#include "matrix.h"

using namespace std;

int main()
{
    my::matrix<> a;
    my::matrix<> b(a);
    my::matrix<> c;
    c = a;
    my::matrix<double> d;
    my::matrix<char, 1> k;
    my::matrix<float, 2, 6> l;
    a[1][1] = 5;
    a[0][1] = 6;
    cout << a[0][1] << endl << a[1][1] << endl;
    return 0;
}
