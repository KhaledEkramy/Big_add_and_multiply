#include <iostream>
#include <map>
using namespace std;

map<char,int> mapping(){
    map<char,int> mp ;
    string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
    for(int i = 0 ; i <= 35 ; ++i){
        mp[str[i]] = i ;
    }
    return mp ;
}
map<int,char> mapping2(){
    map<int , char > mp ;
    string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
    for(int i = 0 ; i <= 35 ; ++i){
        mp[i] = str[i] ;
    }
    return mp ;
}
void from_base_to_decimal(string str, int base) {
    map<char,int> mp = mapping() ;
    long long decimalValue = 0;
    for(char ch : str){
        decimalValue = decimalValue * base + mp[ch] ; // remember we start taking characters from left to right .
    }
    cout<< decimalValue ;
}

void  from_decimal_to_base(int num, int base) {
    map<int ,char > mp = mapping2() ;
    string result = "" ;
    while(num){
        int curr = num % base ;
        result = mp[curr] + result ;
        num /= base ;
    }
    cout<< result ;
}
int main() {
    cin.tie(NULL) ;
    cin.sync_with_stdio(false) ;
    int t , x ; string n ;
    cin>> t >> n >> x ;
    if(t == 1){
        from_base_to_decimal(n,x) ;
    }
    else{
        int num = stoi(n) ;
        from_decimal_to_base(num , x) ;
    }
    return 0;
}
