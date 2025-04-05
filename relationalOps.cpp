#include<bits/stdc++.h>
using namespace std;

bool big_int :: operator >(big_int num){
    clean(num);
    clean(*this);
    if(greater(num, *this).value == this -> value && num != *this){
        return true;
    }
    return false;
}

bool big_int :: operator <(big_int num){
    clean(num);
    clean(*this);
    if(greater(num, *this).value == num.value && num != *this){
        return true;
    }
    return false;
}

bool big_int :: operator >=(big_int num){
    clean(num);
    clean(*this);
    if(greater(num, *this).value == this -> value){
        return true;
    }
    return false;
}

bool big_int :: operator <=(big_int num){
    clean(num);
    clean(*this);
    if(greater(num, *this).value == num.value){
        return true;
    }
    return false;
}

bool big_int :: operator ==(big_int num){
    clean(num);
    clean(*this);
    if(num.value == this -> value){
        return true;
    }
    return false;
}

bool big_int :: operator !=(big_int num){
    clean(num);
    clean(*this);
    if(num.value != this -> value){
        return true;
    }
    return false;
}