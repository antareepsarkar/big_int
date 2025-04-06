# Introduction
This is a C++ library named 'big_int' which is made to handle big integers. It performs all four arithmetic operations and has methods for computing power, factorial, etc. It uses Object-Oriented Programming, thus each big_int variable is
an object of the big_int class. More methods can be added to this library as per the user's needs.

# Installation and Modification
![zip file download](images/big_int.png)

This library can be installed by downloading a zip folder of the repository. To download the zip file click on the 'code' button and then on 'Download ZIP'.

To include it in any project, include the header file 'big_int.h' to your code. All the files are well arranged and the names of all the files are self-explanatory. It will be very easy to modify the library as needed.

# Declaration of Variables
Any big int variable takes a number in the form of a string as the input. It takes positive as well as negative numbers as inputs.

```cpp
#include<iostream>
#include "path\big_int.h"
using namespace std;

int main(){
    big_int a("6"); //Declares a big_int variable named 'a' with the value of 6.
    big_int b = big_int("-2"); //Declares a big_int variable named 'b' with the value -2.
}
```
Both the ways mentioned above can be used to declare variables.

# Value of a big_int variable
The 'val' member of a big_int object gives the value of a big_int variable as a string. It can be accessed using the '.' operator.
```cpp
#include<iostream>
#include "path\big_int.h"
using namespace std;

int main(){
    big_int a("6");
    cout << a.value << endl; //Prints '6', the 'value' member returns the value as a string
}
```
# Arithmetic Operations
All four arithmetic operations namely addition, subtraction, multiplication and division can be done with the arithmetic operators i.e. '+', '-', '*' and '/'.

'/' operator does integer division. The modulo operator '%' is also available. 

All of these operators follow operator precedence.
```cpp
#include<iostream>
#include "path\big_int.h"
using namespace std;

int main(){
    big_int a("6");
    big_int b("2");
    big_int add = a + b; //Adds 'a' and 'b'.
    big_int subtract = a - b; //Subtracts 'b' from 'a'.
    big_int multiply = a * b; //Multiplies 'a' with 'b'.
    big_int divi = a / b; //Divides 'a' by 'b'.
    big_int mod = a % b; //Gives the remainder when a is divided by b.
    big_int expo = a + b * big_int("9"); //Evaluates the expression as per operator precedence. 
}
```
# Other operations
This library also has the '>', '<', '>=', '<=', '==' and '!=' relational operators which do the same thing as when working with numbers. All these operators return a boolean value.
# Methods
This library has 4 in-built methods and all are static. These are:

1. greater: It takes two big_int variables as input and returns the greater amongst them.
   
1. smaller: It takes two big_int variables as input and returns the smaller amongst them.
1. power: It takes two big_int variables as input. The first one being the number and the second one being the exponent. It raises the the first argument to the power of the second argument.
1. factorial: It takes a single big_int variable as the input and returns the factorial of that number.

```cpp
#include<iostream>
#include "path\big_int.h"
using namespace std;

int main(){
    big_int a("4");
    big_int b("-124354355768787465354436546");
    big_int g = big_int :: greater(big_int("9"), big_int("4")); //returns '9'.
    big_int s = big_int :: smaller(a, b); //returns '-124354355768787465354436546'.
    big_int p = big_int :: power(a, big_int("12")); //returns '16777216'.
    big_int fact = big_int :: factorial(a); //retuns '120'.
}
```
# Conclusion
The features of this library have been explained. This library is released under the MIT License. This library is highly customisable as only the basic operations are in-built and all the files are very well organised. Thus, any other methods needed by the user can be implemented by the users without much problem.  
