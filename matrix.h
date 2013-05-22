#ifndef MATRIX_H
#define MATRIX_H

#include "classVector.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include "resultType.h"

namespace my
{
    template <class UsingType> //matrix with element's type UsingType
    class matrix;

    template<class UsingType>
    istream & operator>> (istream& cin, matrix<UsingType> &_matrix);

    template<class UsingType>
    ostream & operator<< (ostream& cout, matrix<UsingType> const &_matrix);

//    template<class T, class U>
//    typedef R<T, U>::type result;

    template<class T, class U>
    matrix<typename R<T, U>::type > operator* (matrix<T> const &_matrix1, matrix<U> const &_matrix2);

}

using namespace std;

template <class UsingType = int> //matrix m * n with element's type UsingType
class my::matrix
{
private:

    my::vector<my::vector<UsingType> > Data;
    unsigned int m;
    unsigned int n;

    template<class T = double>
    class LUP{
    public:
        my::matrix<T> L;
        my::matrix<T> U;
        my::matrix<T> P;
        int k; //число перестановок строк единичной матрицы
        my::vector<int> change;
    };

    LUP<> FindLUP() const;
    void SolveLUP(LUP<> & _LUP, my::vector<UsingType> &b, my::vector<double> &retVal) const;

public:

    matrix();
    matrix(unsigned int _n);
    matrix(unsigned int _m, unsigned int _n);
    matrix(matrix<UsingType> const & _matrix);
    matrix(UsingType elem, unsigned int _m, unsigned int _n);
    matrix(my::vector<UsingType> const &_Data, unsigned int _m, unsigned int _n);

    ~matrix();

    void operator= (const matrix<UsingType> & _matrix);
    my::vector<UsingType> const & operator[] (unsigned int i) const;
    my::vector<UsingType> & operator[] (unsigned int i);
    my::matrix<UsingType> operator+ (my::matrix<UsingType> const &_matrix) const;
    my::matrix<UsingType> operator+ () const;
    my::matrix<UsingType> operator- (my::matrix<UsingType> const &_matrix) const;
    my::matrix<UsingType> operator- () const;

    template<class T, class U>
    friend my::matrix<typename R<T, U>::type > my::operator* (my::matrix<T> const &_matrix1, my::matrix<U> const &_matrix2);

    my::matrix<UsingType> operator* (const UsingType elem) const;

    template<class T>
    friend istream & operator>> (istream &cin, my::matrix<T> &_matrix);
    template<class T>
    friend ostream & operator<< (ostream &cout, my::matrix<T> const &_matrix);

    void getColumn(int _j, my::vector<UsingType> & retVal) const;
    void getRow(int _i, my::vector<UsingType>& ) const;
    void setRow(my::vector<UsingType>& _row, int _i);
    void setColumn(my::vector<UsingType>& _column, int _j);

    my::matrix<UsingType> SubMatrix(int i, int j) const;
    void swapRows(unsigned int const i, unsigned const int j);

    my::matrix<UsingType> transpose() const;
    my::matrix<double> inverse() const;
    double determinant() const;
    UsingType track() const;
};


#include "matrix.cpp"

#endif // MATRIX_H
