big_int big_int :: factorial(big_int num){
    try{
        if(isInt(num) == false){
            throw runtime_error(
                "Numbers are invalid!"
            );
        }
    }
    catch(const exception &e){
        cout << "Exception " <<  e.what() << endl;
    }
    clean(num);
    if(num < big_int("0")){
        return big_int("-1");
    }
    if(num.value == "0"){
        return big_int("1");
    }
    big_int ans("1");
    for(big_int i = big_int("1"); i <= num; i = i + big_int("1")){
        ans = ans * i;
    }
    return ans;
}

big_int big_int :: power(big_int num, big_int pow){
    try{
        if(isInt(num) == false){
            throw runtime_error(
                "Numbers are invalid!"
            );
        }
    }
    catch(const exception &e){
        cout << "Exception " <<  e.what() << endl;
    }
    clean(pow);
    if(pow < big_int("0")){
        return big_int("-1");
    }
    if(pow == big_int("0")){
        if(num == big_int("0")){
            return big_int("-1");
        }
        return big_int("1");
    }
    big_int res = power(num, pow / big_int("2"));
    if(pow % big_int("2") == big_int("1")){
        return res * res * num;
    }
    return res * res; 
}
