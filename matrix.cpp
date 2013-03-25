#include "matrix.h"

template<class UsingType, unsigned int m, unsigned int n>
my::matrix<UsingType, m, n>::matrix()
{
    pointer = (my::vector<UsingType> *) operator new (m * sizeof(my::vector<UsingType>));
    for (unsigned int i = 0; i < m; i++){
        new (pointer + i) my::vector<UsingType>(n);
    }
}

template<class UsingType, unsigned int m, unsigned int n>
my::matrix<UsingType, m, n>::matrix(const matrix<UsingType, m, n> &_matrix)
{
    pointer = (my::vector<UsingType> *) operator new (m * sizeof(my::vector<UsingType>));
    for (unsigned int i = 0; i < m; i++){
        new (pointer + i) my::vector<UsingType>(_matrix.pointer[i]);
    }
}

template<class UsingType, unsigned int m, unsigned int n>
void my::matrix<UsingType, m, n>::operator=(const matrix<UsingType, m, n> & _matrix)
{
    for (unsigned int i = 0; i < m; i++){
        pointer[i] = _matrix.pointer[i];
    }
}

template<class UsingType, unsigned int m, unsigned int n>
my::vector<UsingType> const & my::matrix<UsingType, m, n>::operator[] (unsigned int i) const
{
    if (i >= m)
        throw "Unexpectable indexes";
    return pointer[i];
}

template<class UsingType, unsigned int m, unsigned int n>
my::vector<UsingType> & my::matrix<UsingType, m, n>::operator[] (unsigned int i)
{
    if (i >= m)
        throw "Unexpectable indexes";
    return pointer[i];
=======
matrix::matrix()
{
>>>>>>> 615dbdaa35f5824ef7e38bfdb13f1fd3c6c04541
}
