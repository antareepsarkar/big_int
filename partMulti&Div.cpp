#include<bits/stdc++.h>
using namespace std;

big_int big_int :: partMultiplier(big_int num1, big_int num2){//num2 only has one digit without any sign, also num1 does not have any sign
    big_int ans("0");    
    string n1 = num1.val;
    string n2 = num2.val;
    int n1Ind = n1.length() - 1;
    string res(n1Ind + 2, '0');
    int resInd = n1Ind + 1;
    int val2 = n2[0] - '0';
    int carry = 0;
    for(int i = n1Ind; i >= 0; i --){
        int val1 = n1[i] - '0';
        int temp = (val1 * val2) + carry;
        res[resInd] = char((temp % 10) + '0');
        carry = temp / 10;
        resInd --;
    }
    res[0] = char(carry + '0');
    ans.val = res;
    clean(ans);
    return ans;
}

big_int big_int :: partDiv(big_int num1, big_int num2){
    big_int q("9");
    for(big_int i = big_int("0"); i <= big_int("8"); i = i + big_int("1")){
        if(num2 * i <= num1 && num2 * (i + (big_int("1"))) > num1){
            q = i;
        }
    }
    clean(q);
    return q;
}