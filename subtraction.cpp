#include<bits/stdc++.h>
using namespace std;

big_int big_int :: operator -(big_int num){
    //Checking for valid inputs
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
    big_int ans("0");
    clean(*this);
    clean(num);
    string v = this -> val, sub = num.val;
    if(this -> val == num.val){
        clean(ans);
        return ans;
    }
    if(greater(*this, num).val ==  num.val){
        ans = (big_int)num - *this;
        ans.val.insert(ans.val.begin(), '-');
        clean(ans);
        return ans;        
    }
    if(v[0] == '-' && sub[0] == '-'){ //When both numbers are negative
        v = v.substr(1);
        sub = sub.substr(1);
        ans = big_int(sub) - big_int(v);
        clean(ans);
        return ans;
    }
    if(v[0] != '-' && sub[0] == '-'){ //When first number is positive but second number is negative
        sub = sub.substr(1);
        ans = big_int(sub) + *this;
        clean(ans);
        return ans;
    }
    //The case where both numbers are positive and the first number is greater than the second number
    int carry = 0;
    int vL = v.length() - 1, subL = sub.length() - 1;
    string res(max(vL + 1, subL + 1), '0');
    int resInd = res.length() - 1;
    while(vL >= 0 || subL >= 0){
        int sub1 = 0, sub2 = 0;
        if(vL >= 0){
            sub1 = v[vL] - '0';
            vL --;
        }
        if(subL >= 0){
            sub2 = sub[subL] - '0';
            subL --;
        }
        if(sub1 - sub2 - carry < 0){
            res[resInd] = char((10 + sub1 - sub2 - carry) + '0');
            carry = 1;
            resInd --;
        }
        else{
            res[resInd] = char((sub1 - sub2 - carry) + '0');
            carry = 0;
            resInd --;
        }
    }
    int n = res.length();
    int remove = n;
    for(int i = 0; i < n; i ++){
        if(res[i] != '0'){
            remove = i;
            break;
        }
    }

    res = res.substr(remove);
    ans.val = res;
    clean(ans);
    return ans;
}