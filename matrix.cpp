#include "matrix.h"

template<class UsingType>
my::matrix<UsingType>::matrix():m(2), n(2)
{
    Pointer = (my::vector<UsingType> *) operator new (m * sizeof(my::vector<UsingType>));
    for (unsigned int i = 0; i < m; i++){
        new (Pointer + i) my::vector<UsingType>(n);
    }
}

template<class UsingType>
my::matrix<UsingType>::matrix(unsigned int _n):m(_n), n(_n)
{
    Pointer = (my::vector<UsingType> *) operator new (m * sizeof(my::vector<UsingType>));
    for (unsigned int i = 0; i < m; i++){
        new (Pointer + i) my::vector<UsingType>(n);
    }
}

template<class UsingType>
my::matrix<UsingType>::matrix(unsigned int _m, unsigned int _n): m(_m), n(_n)
{
    Pointer = (my::vector<UsingType> *) operator new (m * sizeof(my::vector<UsingType>));
    for (unsigned int i = 0; i < m; i++){
        new (Pointer + i) my::vector<UsingType>(n);
    }
}

template<class UsingType>
my::matrix<UsingType>::matrix(const matrix<UsingType> &_matrix):m(_matrix.m), n(_matrix.n)
{
    Pointer = (my::vector<UsingType> *) operator new (m * sizeof(my::vector<UsingType>));
    for (unsigned int i = 0; i < m; i++){
        new (Pointer + i) my::vector<UsingType>(_matrix.Pointer[i]);
    }
}

template<class UsingType>
my::matrix<UsingType>::~matrix()
{
    delete[] (my::vector<UsingType> *)Pointer;
}

template<class UsingType>
void my::matrix<UsingType>::operator=(const matrix<UsingType> & _matrix)
{
    if (m < _matrix.m){
        delete Pointer;
        Pointer = (my::vector<UsingType> *) operator new (_matrix.m * sizeof(my::vector<UsingType>));
        for (unsigned int i = 0; i < m; i++){
            new (Pointer + i) my::vector<UsingType>(_matrix.Pointer[i]);
        }
        m = _matrix.m;
        n = _matrix.n;
    }else{
        m = _matrix.m;
        n = _matrix.n;
        for (unsigned int i = 0; i < m; i++){
            Pointer[i] = _matrix.Pointer[i];
        }
    }
}

template<class UsingType>
my::vector<UsingType> const & my::matrix<UsingType>::operator[] (unsigned int i) const
{
    if (i >= m)
        throw "Unexpectable indexes";
    my::vector<UsingType> const & obj = Pointer[i];
    return obj;
}

template<class UsingType>
my::vector<UsingType> & my::matrix<UsingType>::operator[] (unsigned int i)
{
    if (i >= m)
        throw "Unexpectable indexes";
    my::vector<UsingType> & obj = Pointer[i];
    return obj;
}

template<class UsingType>
my::matrix<UsingType> & my::matrix<UsingType>::operator+ (my::matrix<UsingType> const &_matrix)
{
    if (m != _matrix.m || n != _matrix.n){
        throw "Unexpectable argument";
    }
    my::matrix<UsingType> help;
    for(unsigned int i = 0; i < n; i++)
        for(unsigned int j = 0; j < m; j++)
            help[i][j] = Pointer[i][j] + _matrix[i][j];
    my::matrix<UsingType> & obj = help;
    return obj;
}

template<class UsingType>
istream & my::operator>> (istream &cin, my::matrix<UsingType> & _matrix)
{
    for (unsigned int i = 0; i < _matrix.m; i++)
        for (unsigned int j = 0; j < _matrix.n; j++){
            cin >> _matrix.Pointer[i][j];
        }
    return cin;
}

template<class UsingType>
ostream & my::operator<< (ostream &cout, my::matrix<UsingType> const & _matrix)
{
    for (unsigned int i = 0; i < _matrix.m; i++){
        for (unsigned int j = 0; j < _matrix.n; j++){
            cout << _matrix.Pointer[i][j] << ' ';
        }
        cout << endl;
    }
    return cout;
}
