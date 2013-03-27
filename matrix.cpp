#include "matrix.h"

template<class UsingType>
my::matrix<UsingType>::matrix():m(2), n(2)
{
    for (unsigned int i = 0; i < m ; i++)
        for (unsigned int j = 0; j < n; j++)
            Data[i][j] = 0;
}

template<class UsingType>
my::matrix<UsingType>::matrix(unsigned int _n):m(_n), n(_n)
{ }

template<class UsingType>
my::matrix<UsingType>::matrix(unsigned int _m, unsigned int _n): m(_m), n(_n)
{ }

template<class UsingType>
my::matrix<UsingType>::matrix(const matrix<UsingType> &_matrix):m(_matrix.m), n(_matrix.n)
{
    Data = _matrix.Data;
}

////////////////////////

template<class UsingType>
my::matrix<UsingType>::~matrix()
{ }

///////////////////////

template<class UsingType>
my::vector<UsingType> const & my::matrix<UsingType>::operator[] (unsigned int i) const
{
    return Data[i];
}

template<class UsingType>
my::vector<UsingType> & my::matrix<UsingType>::operator[] (unsigned int i)
{
    return Data[i];
}

template<class UsingType>
void my::matrix<UsingType>::operator=(const matrix<UsingType> & _matrix)
{
    m = _matrix.m;
    n = _matrix.n;
    Data = _matrix.Data;
}

template<class UsingType>
my::matrix<UsingType> my::matrix<UsingType>::operator+ (my::matrix<UsingType> const &_matrix)
{
    if (m != _matrix.m || n != _matrix.n)
        throw "Unexpectable argument";
    my::matrix<UsingType> help(m, n);
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < m; j++)
            help[i][j] = Data[i][j] + _matrix[i][j];
    return help;
}

template<class UsingType>
my::matrix<UsingType> my::matrix<UsingType>::operator+ (UsingType const &elem)
{
    if (m != n)
        throw "Unexpectable argument";
    my::matrix<UsingType> help(m, n);
    for (unsigned int i = 0; i < n; i++)
        help[i][i] = Data[i][i] + elem;
    return help;
}

template<class UsingType>
my::matrix<UsingType> my::matrix<UsingType>::operator+ ()
{
    my::matrix<UsingType> help(*this);
    return help;
}

template<class UsingType>
my::matrix<UsingType> my::matrix<UsingType>::operator- (my::matrix<UsingType> const &_matrix)
{
    if (m != _matrix.m || n != _matrix.n)
        throw "Unexpectable argument";
    my::matrix<UsingType> help(m, n);
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < m; j++)
            help[i][j] = Data[i][j] - _matrix[i][j];
    return help;
}

template<class UsingType>
my::matrix<UsingType> my::matrix<UsingType>::operator- ()
{
    my::matrix<UsingType> help(*this);
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < m; j++)
            help[i][j] = -help[i][j];
    return help;
}

/////////////////////////

template<class UsingType>
istream & my::operator>> (istream &cin, my::matrix<UsingType> & _matrix)
{
    for (unsigned int i = 0; i < _matrix.m; i++)
        for (unsigned int j = 0; j < _matrix.n; j++)
            cin >> _matrix[i][j];
    return cin;
}

template<class UsingType>
ostream & my::operator<< (ostream &cout, my::matrix<UsingType> const & _matrix)
{
    for (unsigned int i = 0; i < _matrix.m; i++){
        for (unsigned int j = 0; j < _matrix.n; j++)
            cout << _matrix[i][j] << ' ';
        if (i != _matrix.m - 1)
            cout << endl;
    }
    return cout;
}
