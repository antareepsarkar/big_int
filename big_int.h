#include<bits/stdc++.h>
using namespace std;

//Class definition
class big_int{
    private:
        static bool isInt(big_int); //Check whether a string can be considered an integer
        static void clean(big_int&); //To get a big_int value free of all unnecessary characters
        big_int partMultiplier(big_int, big_int); //To multiply a number by a single digit
        big_int partDiv(big_int, big_int); //To divide a number by another number number where the the quotient will between 0 to 9

    public:
        string value; //To hold value of the big_int
        big_int(string); //Constructor
        
        //All operators
        big_int operator +(big_int); //Addition
        big_int operator -(big_int); //Subtraction
        big_int operator *(big_int); //Multiplication
        big_int operator /(big_int); //Division
        big_int operator %(big_int); //Modulo
        bool operator >(big_int); //Greater
        bool operator <(big_int); //Lesser
        bool operator >=(big_int); //Greater OR equal
        bool operator <=(big_int); //Lesser OR equal
        bool operator ==(big_int); //Equal to
        bool operator !=(big_int); //not equal to
        void operator +=(big_int); //to increment by some num
        void operator -=(big_int); //to decrement by some num
        void operator *=(big_int); //to increment by some num
        void operator /=(big_int); //to decrement by some num         

        //Methods
        static big_int power(big_int, big_int); 
        static big_int factorial(big_int);
        static big_int greater(big_int, big_int); //returns greater among two numbers
        static big_int smaller(big_int, big_int); //returns smaller among two numbers
};

//Constructor definition
big_int :: big_int(string val = "0"){
    this -> val = val;
}

//All dependent includes
#include "add.cpp"
#include "subtraction.cpp"
#include "greater_smaller.cpp"
#include "partMultiandDiv.cpp"
#include "multiplication.cpp"
#include "division.cpp"
#include "methods.cpp"
#include "relationalOps.cpp"
#include "math_methods.cpp"

//End