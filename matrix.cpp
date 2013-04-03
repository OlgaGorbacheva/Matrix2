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
{
    for (unsigned int i = 0; i < m ; i++)
        for (unsigned int j = 0; j < n; j++)
            Data[i][j] = 0;
}

template<class UsingType>
my::matrix<UsingType>::matrix(unsigned int _m, unsigned int _n): m(_m), n(_n)
{
    for (unsigned int i = 0; i < m ; i++)
        for (unsigned int j = 0; j < n; j++)
            Data[i][j] = 0;
}

template<class UsingType>
my::matrix<UsingType>::matrix(matrix<UsingType> const &_matrix):m(_matrix.m), n(_matrix.n)
{
    Data = _matrix.Data;
}

template<class UsingType>
my::matrix<UsingType>::matrix(UsingType elem, unsigned int _m, unsigned int _n):m(_m), n(_n)
{
    for (unsigned int i = 0; i < m ; i++)
        for (unsigned int j = 0; j < n; j++)
            if (i == j)
                Data[i][j] = elem;
            else Data[i][j] = 0;
}

template<class UsingType>
my::matrix<UsingType>::matrix(my::vector<UsingType> const &_Data, unsigned int _m, unsigned int _n): m(_m), n(_n)
{
    for (unsigned int i = 0; i < m ; i++)
        for (unsigned int j = 0; j < n; j++)
            Data[i][j] = _Data[i * m + j];
}

////////////////////////

template<class UsingType>
my::matrix<UsingType>::~matrix()
{ }

///////////////////////

template<class UsingType>
void my::matrix<UsingType>::getRow(int _i, my::vector<UsingType> &retVal) const
{
    retVal = Data[_i];
}

template<class UsingType>
void my::matrix<UsingType>::getColumn(int _j, my::vector<UsingType> & retVal) const
{
    my::vector<UsingType> help;
    for (unsigned int i = 0; i < m; i++)
        help[i] = Data[i][_j];
    retVal = help;
}

template<class UsingType>
void my::matrix<UsingType>::setRow(my::vector<UsingType> &_row, int _i)
{
    if (_row.GetSize() != m)
        throw "Unexpectable argument";
    Data[_i] = _row;
}

template<class UsingType>
void my::matrix<UsingType>::setColumn(my::vector<UsingType>& _column, int _j)
{
    if ((unsigned)_column.GetSize() != n)
        throw "Unexpectable argument";
    for (unsigned int i = 0; i < m; i++)
        Data[i][_j] = _column[i];
}

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
my::matrix<UsingType> my::matrix<UsingType>::operator+ (my::matrix<UsingType> const &_matrix) const
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
my::matrix<UsingType> my::matrix<UsingType>::operator+ () const
{
    my::matrix<UsingType> help(*this);
    return help;
}

template<class UsingType>
my::matrix<UsingType> my::matrix<UsingType>::operator- (my::matrix<UsingType> const &_matrix) const
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
my::matrix<UsingType> my::matrix<UsingType>::operator- () const
{
    my::matrix<UsingType> help(*this);
    for (unsigned int i = 0; i < m; i++)
        for (unsigned int j = 0; j < n; j++)
            help[i][j] = -help[i][j];
    return help;
}

template<class UsingType>
my::matrix<UsingType> my::matrix<UsingType>::operator* (my::matrix<UsingType> const &_matrix) const
{
    if (n != _matrix.m){
        throw "Unexpectable argument";
    }
    my::matrix<UsingType> help(m, _matrix.n);
    for (unsigned int i = 0; i < help.m; i++)
        for (unsigned int j = 0; j < help.n; j++)
            for (unsigned int k = 0; k < n; k++){
                help[i][j] += (*this)[i][k] * _matrix[k][j];
            }
    return help;
}

template<class UsingType>
my::matrix<UsingType> my::matrix<UsingType>::operator* (const UsingType elem) const
{
    my::matrix<UsingType> help(*this);
    for (unsigned int i = 0; i < m; i++)
        for (unsigned int j = 0; j < n; j++)
            help[i][j] = help[i][j] * elem;
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

////////////////////////

template<class UsingType>
void my::matrix<UsingType>::swapRows(const unsigned int i, const unsigned int j)
{
    my::vector<UsingType> help(Data[i]);
    Data[i] = Data[j];
    Data[j] = help;
}

template<class UsingType>
my::matrix<UsingType> my::matrix<UsingType>::SubMatrix(int _i, int _j) const
{
    my::matrix<UsingType> help(m - 1, n - 1);
    int count_i = 0, count_j = 0;
    for(int i = 0; i < m; i++)
        if (i != _i){
            for(int j = 0; j < n; j++)
                if (j != _j)
                    help[count_i, count_j++] = Data[i][j];
            count_i++;
        }
    return help;
}

template<class UsingType>
my::matrix<UsingType>::LUP<> my::matrix<UsingType>::FindLUP() const// PA = LU
{
    if (m != n)
        throw "The matrix is not square.";
    my::matrix<UsingType>::LUP<> retValue;
    for (unsigned int i = 0; i < m; i++){
        retValue.change[i] = i;
    }
    my::matrix<double> help(m, n);
    for (unsigned int i = 0; i < m; i++)
        for (unsigned int j = 0; j < n; j++)
            help[i][j] = (double)(*this)[i][j];
    my::matrix<double> I(1, m, n);
    my::matrix<double> prot(m, n);
    retValue.P = I;
    retValue.L = prot;
    retValue.U = prot;
    retValue.k = 0;
    double abs; //вспомогательная переменная для поиска модуля числа
    for (unsigned int i = 0; i < m; i++){
        double pivotValue = 0; //поиск опорного элемента, который является максимальным по модулю в i столбце не выше iй строки
        int pivot = -1;
        for (unsigned int j = i; j < n; j++){
            if (help[j][i] >= 0)  //извращенный поиск модуля, т.к. класс - шаблонный и abs() или fabs() и т.д. применять не получится
                abs = help[j][i];
            else abs  = -help[j][i];
            if (abs > pivotValue) {
                pivotValue = abs;
                pivot = j;
            }
        }
        if( pivotValue == 0 ) { //столбец из 0 - мтрица вырождена
            throw "The matrix is singular";
            abort();
        }
        retValue.P.swapRows(pivot, i); //меняем местами i-ю строку и строку с опорным элементом
        help.swapRows(pivot, i);
        retValue.L.swapRows(pivot, i);
        swap(retValue.change[pivot], retValue.change[i]);
        if ((unsigned)pivot != i){
            retValue.k++;
        }
        retValue.L[i][i] = 1;
        retValue.U[i][i] = help[i][i];
        for (unsigned int j = i + 1; j < n; j++){
            retValue.L[j][i] = help[j][i] * 1.0 / help[i][i];
            retValue.L[i][j] = 0;
            retValue.U[j][i] = 0;
            retValue.U[i][j] = help[i][j];
            for (unsigned int k = i + 1; k < n; k++){
                help[j][k] -= (help[i][k] * help[j][i] * 1.0 / help[i][i]);
            }
        }
    }
    return retValue;
}

template<class UsingType>
void my::matrix<UsingType>::SolveLUP(my::matrix<UsingType>::LUP<> &_LUP, my::vector<UsingType> &b,
                                                   my::vector<double> &retVal) const
{
    my::vector<double> solution;
    my::vector<double> help;
    for (int i = 0;(unsigned) i < m; i++){
        double sum = 0;
        for (int j = 0; j < i; j++)
            sum += _LUP.L[i][j] * help[j];
        help[i] = b[_LUP.change[i]] - sum;
    }
    for (int i = m - 1; i >= 0; i--){
        double sum = 0;
        for (unsigned int j = i + 1; j < n; j++)
            sum += _LUP.U[i][j] * solution[j];
        solution[i] = (help[i] - sum) / _LUP.U[i][i];
    }
    retVal = solution;
}

////////////////////////

template<class UsingType>
my::matrix<UsingType> my::matrix<UsingType>::transpose() const
{
    my::matrix<UsingType> help(n, m);
    for (int i = 0; i < help.m; i++)
        for (int j = 0; j < help.n; j++)
            help[i][j] = (*this)[j][i];
    return help;
}

template<class UsingType>
my::matrix<double> my::matrix<UsingType>::inverse() const
{
    if (m != n)
        throw "The matrix is not square.";
    my::matrix<UsingType>::LUP<> _LUP = FindLUP();
    my::matrix<double> inv(m, n);
    my::vector<double> currentColumn;
    my::matrix<UsingType> I(1, m, n);
    my::vector<UsingType> b;
    for (unsigned int i = 0; i < m; i++){
        I.getColumn(i, b);
        SolveLUP(_LUP, b, currentColumn);
        inv.setColumn(currentColumn, i);
    }
    return inv;
}

template<class UsingType>
double my::matrix<UsingType>::determinant() const
{
    if (m != n)
        throw "The matrix is not square.";
    my::matrix<UsingType>::LUP<> _LUP;
    try{
        _LUP = FindLUP();
    }
    catch(const char* a){
        const char * s = "The matrix is singular";
        if (strcmp(a, s) == 0)
            return 0;
    }
    double val = 1;
    for (unsigned int i = 0; i < m; i++){
        val *= _LUP.U[i][i];
    }
    for (int i = 0; i < _LUP.k; i++){
        val *= -1;
    }
    return val;
}

template<class UsingType>
UsingType my::matrix<UsingType>::track() const
{
    if (m != n)
        throw "The matrix is not square.";
    UsingType tr = 0;
    for (unsigned int i = 0; i < m; i++){
        tr += (*this)[i][i];
    }
    return tr;
}
