#include<bits/stdc++.h>
using namespace std;

big_int big_int :: operator +(big_int num){
    //Checks whether the inputs are integers
    try{
        if(isInt(num) == false || isInt(*this) == false){
            throw runtime_error(
                "Numbers are invalid!"
            );
        }
    }
    catch(const exception &e){
        cout << "Exception " <<  e.what() << endl;
    }
    clean(*this);
    clean(num);
    big_int ans; //ans big_int variable
    string v = this -> val;
    string add = num.val;
    if(v[0] == '-' && add[0] == '-'){ //When both numbers are negative
        v = v.substr(1);
        add = add.substr(1);
        ans = big_int(add) + big_int(v);
        ans.val.insert(ans.val.begin(), '-');
        clean(ans);
        return ans;
    }
    if(v[0] != '-' && add[0] == '-'){ //When first number is positive but second number is negative
        add = add.substr(1);
        ans = big_int(v) - big_int(add);
        clean(ans);
        return ans;
    }
    if(v[0] == '-' && add[0] != '-'){ //When first number is negative but second number is positive
        v = v.substr(1);
        ans = big_int(add) - big_int(v);
        clean(ans);
        return ans;
    }

    //Both are positive
    int addInd = add.length() - 1;
    int valInd = v.length() - 1;
    string res(max(addInd + 2, valInd + 2), '0');
    int resInd = res.length() - 1;
    int carry = 0;
    while(addInd >= 0 || valInd >= 0){
        int n1 = 0, n2 = 0;
        if(addInd >= 0){
            n1 = add[addInd] - '0';
            addInd --;
        }
        if(valInd >= 0){
            n2 = v[valInd] - '0';
            valInd --;
        }
        res[resInd] = (char)(((n1 + n2 + carry) % 10) + '0');
        carry = (n1 + n2 + carry) / 10;
        resInd --;
    }
    res[0] = (char)(carry + '0');
    ans.val = res;
    clean(ans);
    return ans;
}
