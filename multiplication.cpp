#include<bits/stdc++.h>
using namespace std;


big_int big_int :: operator *(big_int multiplier){
    try{
        if(isInt(multiplier) == false || isInt(*this) == false){
            throw runtime_error(
                "Numbers are invalid!"
            );
        }
    }
    catch(const exception &e){
        cout << "Exception " <<  e.what() << endl;
    }
	big_int ans("0");
	clean(multiplier);
	clean(*this);
	string v = this -> value, num = multiplier.value;
	if(num[0] != '-' && v[0] == '-'){
		v = v.substr(1);
		ans = big_int(v) * big_int(num);
		ans.value.insert(ans.value.begin(), '-');
		clean(ans);
		return ans;
	}
	if(num[0] == '-' && v[0] != '-'){
		num = num.substr(1);
		ans = big_int(v) * big_int(num);
		ans.value.insert(ans.value.begin(), '-');
		clean(ans);
		return ans;
	}
	if(num[0] == '-' && v[0] == '-'){
		v = v.substr(1);
		num = num.substr(1);
		multiplier.value = num;
	}
	int vInd = v.length() - 1, numInd = num.length() - 1;
	int carry = 0;
	int t = 0;
	for(int i = vInd; i >= 0; i --){
		string s = "";
		s.push_back(v[i]);
		big_int partRes = partMultiplier(multiplier, big_int(s));
		partRes.value.append(t, '0');
		t ++;
		ans = ans + partRes;
	}
	clean(ans);
	return ans;
}