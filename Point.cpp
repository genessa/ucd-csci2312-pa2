//
// Created by Genessa Moodie on 2/18/16.
// Implementation of Point.h

#include <cmath>
#include "Point.h"

using namespace Clustering;
using std::cout;
using std::cin;

unsigned int Point::__idGen = 0;

// Constructor which takes one int argument (how many dimensions the new point will have)
Point::Point(int dim)
    {
        __dim = dim;
        __id = __idGen;
        __idGen++;
    }

// Constructor which takes an int argument of the new Point's dimensions and a
//    pointer to dynamically allocate a double array of the Point's.. points.
Point::Point(int dim, double *arrayPtr)
    {
        __dim = dim;
        arrayPtr = __values;
        __id = __idGen;
        __idGen++;
    }

// Copy constructor
Point::Point(const ::Clustering::Point::Point &p1)
    {
        // copy p1's __id to calling point's __id
        // assign calling point's arrayptr to p1's
        __id = p1.__id;
        __values = p1.__values;
    }

// Overloaded assignment operator
Point &Point::operator=(const Point& p1)
    {
        // recycle copy constructor's code
        // but I think it will need its own __id rather than a copy
        __id = __idGen;
        ++__idGen;
        __values = p1.__values;
        // how to return a new point?
    }

// Destructor
Point::~Point()
    {
        //delete ; but what?
    }

// ID accessor function
int Point::getId() const
    { return __id;}

// Dimension accessor function
int Point::getDims() const
    { return __dim;}

// Dimension and (double) mutator function
void Point::setValue(int dim, double d)
    {
        __dim = dim;
        //__values = d;
    }

// Accessor function which returns   a thing.
double Point::getValue(int dim) const
    {
        // for loop! for loop! for to cycle through the double array
        // counter < dim. :)
        if(dim == 0)
        { return 0; }
        else
        {
            for (int counter = 1; counter <= dim; ++counter)
                return __values[counter];
        }
    }


// Finds distance between the point calling it and another point
double Point::distanceTo(const Point &p2) const
    {
        double distance;
        distance = sqrt( pow((p2.x-pointA.x),2.0) + pow((p2.y-pointA.y),2.0) + pow((p2.z-pointA.z),2.0) );
        return distance; // I htink this will require overloading the [] and running through each value.
    }

Point &operator*=(double) // p *= 6; p.operator*=(6);
    {

    }

Point &Point::operator/=(double d)
    {
        for (int i = 0; i < __dim; i++)
            __values[i] /= d;
        return *this;
    }

const Point Point::operator*(double d) const // prevent (p1 * 2) = p2;
    {
        // is returning *this doing the preventy thing?
        for (int i = 0; i < __dim; i++)
        __values[i] = __values[i] * d;
        return *this;


    }

const Point operator/(double) const; // p3 = p2 / 2;
    {
        // so.. is this returning a new point? is that what the p3 is implying?
    }

double Point::&operator[](int index)
    {
        return Point::getValue(index);
    }
// Friends
friend Point &operator+=(Point &, const Point &);
friend Point &operator-=(Point &, const Point &);