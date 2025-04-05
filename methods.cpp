#include<bits/stdc++.h>
using namespace std;

bool big_int :: isInt(big_int num){
    string n = num.value;
    int length = n.length();
    if(length == 0){
        return false;
    }
    if(n[0] != '+' && n[0] != '-' && (n[0] - '0' > 9 || n[0] - '0' < 0)){
        return false;
    }
    for(int i = 1; i < length; i ++){
        if(n[i] - '0' > 9 || n[i] - '0' < 0){
            return false;
        }
    }
    return true;
}

//Only works if num is a valid big_int
void big_int :: clean(big_int& num){
    string n = num.value;
    if(n[0] == '+'){
        n = n.substr(1);
    }
    int length = n.length();
    int ind = length;
    int start = 0;
    if(n[0] == '-'){
        start = 1;
    }
    for(int i = start; i < length; i ++){
        if(n[i] != '0'){
            ind = i;
            break;
        }
    }
    if(ind == length){
        n = "0";
    }
    else
        n = n.substr(ind);
    if(start == 1 && ind != length){
        n.insert(n.begin(), '-');
    }
    num.value = n;
    return;
}

void big_int :: operator +=(big_int num){
    clean(*this);
    *this = *this + num;
}

void big_int :: operator -=(big_int num){
    clean(*this);
    *this = *this - num;
}

void big_int :: operator /=(big_int num){
    clean(*this);
    *this = *this / num;
}

void big_int :: operator *=(big_int num){
    clean(*this);
    *this = *this * num;
}