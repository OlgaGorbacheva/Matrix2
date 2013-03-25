#ifndef MATRIX_H
#define MATRIX_H

<<<<<<< HEAD
#include "classVector.h"

namespace my
{
    template <class UsingType, unsigned int m, unsigned int n> //matrix m * n with element's type UsingType
    class matrix;
}

template <class UsingType = int, unsigned int m = 2, unsigned int n = 2> //matrix m * n with element's type UsingType
class my::matrix
{
private:
    my::vector<UsingType>* pointer;
public:
    matrix();
    matrix(const matrix<UsingType, m, n> & _matrix);
    void operator=(const matrix<UsingType, m, n> & _matrix);
    my::vector<UsingType> const & operator[] (unsigned int i) const;
    my::vector<UsingType> & operator[] (unsigned int i);
};

#include "matrix.cpp"

=======
class matrix
{
public:
    matrix();
};

>>>>>>> 615dbdaa35f5824ef7e38bfdb13f1fd3c6c04541
#endif // MATRIX_H
