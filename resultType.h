#ifndef RESULTTYPE_H
#define RESULTTYPE_H

template<class T, class U>
class R
{
public:
    class type;
};

template<>
class R<int, int>
{
public:
    typedef int type;
};

template<>
class R<int, float>
{
public:
    typedef float type;
};

template<>
class R<float, int>
{
public:
    typedef float type;
};

template<>
class R<float, float>
{
public:
    typedef float type;
};

template<>
class R<int, double>
{
public:
    typedef double type;
};

template<>
class R<double, int>
{
public:
    typedef double type;
};

template<>
class R<double, double>
{
public:
    typedef double type;
};

template<>
class R<double, float>
{
public:
    typedef double type;
};

template<>
class R<float, double>
{
public:
    typedef double type;
};

#endif // RESULTTYPE_H
