#include<bits/stdc++.h>
using namespace std;

big_int big_int :: greater(big_int num1, big_int num2){
    try{
        if(isInt(num1) == false || isInt(num2) == false){
            throw runtime_error(
                "Numbers are invalid!"
            );
        }
    }
    catch(const exception &e){
        cout << "Exception " <<  e.what() << endl;
    }
    clean(num1);
    clean(num2);
    string n1 = num1.val, n2 = num2.val;
    //Checks whether the first number is negative
    if(n1[0] == '-'){
        if(n2[0] != '-'){
            return big_int(n2);
        }
    int n1L = n1.length(), n2L = n2.length();
    if(n1L > n2L){
        return big_int(n2);
    }
    else if(n2L > n1L){
        return big_int(n1);
    }
    int ind = 1;
    while(ind < n1L){
        if(n1[ind] > n2[ind]){
            return big_int(n2);
        }
        else if(n1[ind] < n2[ind]){
            return big_int(n1);
        }
        ind ++;
    }
    return big_int(n2);
    }
    //Checks whether the second number is negative
    if(n2[0] == '-'){
        if(n1[0] != '-'){
            return big_int(n1);
        }
    }
    //Both are positive
    if(n1[0] == '+'){
        n1 = n1.substr(1);
    }
    if(n2[0] == '+'){
        n2 = n2.substr(1);
    }
    int n1L = n1.length(), n2L = n2.length();
    if(n1L > n2L){
        return big_int(n1);
    }
    else if(n2L > n1L){
        return big_int(n2);
    }
    int ind = 0;
    while(ind < n1L){
        if(n1[ind] > n2[ind]){
            return big_int(n1);
        }
        else if(n1[ind] < n2[ind]){
            return big_int(n2);
        }
        ind ++;
    }
    return big_int(n1);
}
big_int big_int :: smaller(big_int n1, big_int n2){
    //Checks whether the inputs are integers
    try{
        if(isInt(n1) == false || isInt(n2) == false){
            throw runtime_error(
                "Numbers are invalid!"
            );
        }
    }
    catch(const exception &e){
        cout << "Exception " <<  e.what() << endl;
    }
    if(greater(n1, n2).val == n1.val){
        return n2;
    }
    return n1;
}