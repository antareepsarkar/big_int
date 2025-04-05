#include<bits/stdc++.h>
using namespace std;

big_int big_int :: operator /(big_int num){
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
    if(num == big_int("0")){
        throw runtime_error(
            "Zero division error"
        );
    }
    string n = this -> val;
    string d = num.val;
    if(n[0] == '-' && d[0] != '-'){
        n = n.substr(1);
        big_int ans = big_int(n) / big_int(d);
		ans.val.insert(ans.val.begin(), '-');
        clean(ans);
        return ans;
    }
    if(n[0] != '-' && d[0] =='-'){
        d = d.substr(1);
        big_int ans = big_int(n) / big_int(d);
		ans.val.insert(ans.val.begin(), '-');
        clean(ans);
        return ans;
    }
    if(n[0] == '-' && d[0] == '-'){
        n = n.substr(1);
        d = d.substr(1);
        big_int ans = big_int(n) / big_int(d);
        clean(ans);
        return ans;
    }
    big_int ans("0");
    big_int temp("0");
    int l = n.length();
    for(int i = 0; i < l; i ++){
        temp.val.push_back(n[i]);
        big_int bi = partDiv(temp, num);
        ans.val.push_back(bi.val[0]);
        temp = temp - num * bi;
        clean(temp);
    }
    clean(ans);
    return ans;  
}

big_int big_int :: operator %(big_int num){
    big_int temp = (*this) / num;
    big_int ans = (*this) - (temp) * num;
    return ans;
}