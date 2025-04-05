#include<bits/stdc++.h>
using namespace std;

bool big_int :: operator >(big_int num){
    clean(num);
    clean(*this);
    if(greater(num, *this).val == this -> val && num != *this){
        return true;
    }
    return false;
}

bool big_int :: operator <(big_int num){
    clean(num);
    clean(*this);
    if(greater(num, *this).val == num.val && num != *this){
        return true;
    }
    return false;
}

bool big_int :: operator >=(big_int num){
    clean(num);
    clean(*this);
    if(greater(num, *this).val == this -> val){
        return true;
    }
    return false;
}

bool big_int :: operator <=(big_int num){
    clean(num);
    clean(*this);
    if(greater(num, *this).val == num.val){
        return true;
    }
    return false;
}

bool big_int :: operator ==(big_int num){
    clean(num);
    clean(*this);
    if(num.val == this -> val){
        return true;
    }
    return false;
}

bool big_int :: operator !=(big_int num){
    clean(num);
    clean(*this);
    if(num.val != this -> val){
        return true;
    }
    return false;
}