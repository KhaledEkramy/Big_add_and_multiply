#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

map<char,int> mapping(){
    map<char,int> mp ;
    string str = "0123456789" ;
    for(int i = 0 ; i <= 9 ; ++i){
        mp[str[i]] = i ;
    }
    return mp ;
}
map<int,char> mapping2(){
    map<int , char > mp ;
    string str = "0123456789" ;
    for(int i = 0 ; i <= 9 ; ++i){
        mp[i] = str[i] ;
    }
    return mp ;
}
map<char,int> charInt = mapping() ;
map<int,char> IntChar = mapping2() ;

string add(const string num1, const string num2 = "9999") {
    int n1 = num1.size();
    int n2 = num2.size();
    int carry = 0;
    string result;

    for (int i = n1 - 1, j = n2 - 1; i >= 0 || j >= 0 || carry; i--, j--) {
        int digit1 = (i >= 0) ? charInt[num1[i]] : 0;
        int digit2 = (j >= 0) ? charInt[num2[j]] : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    reverse(result.begin(), result.end());

    return result;
}

string multi(string st , int num ){
    int reminder = 0 ;
    for(int i = st.size()-1 ; i >= 0 ; --i){
        int x = charInt[st[i]] * num ;
        x += reminder ;
        st[i] = IntChar[x%10] ;
        reminder = x / 10 ;
    }
    if(reminder){
        st = (IntChar[reminder] + st) ;
    }
    return st ;
}
string multiply(string str){
    int times = 9999 ;
    int len = str.size() ;
    if(len < 4){
        times = stoi(str) ;
        str = "9999" ;
    }
    int reminder = 0 ;
    string result = "" ;
    string first = multi(str,times%10) ;
    times /= 10 ;
    result = add(first,"0") ;
    int i = 1 ;
    while(times){
        string current = multi(str,times%10) ;
        int j = i ;
        while(j--) {
            current.push_back('0') ;
        }
        i++ ;
        result = add(current,result) ;
        times /= 10 ;
    }
    return result ;
}
void solve(){
    string str ; cin>> str ;
    string ad = add(str) ;
    cout<< ad << "\n" ;
    string mul = multiply(str) ;
    cout<< mul ;
}
int main() {
    cin.tie(NULL) ;
    cin.sync_with_stdio(false) ;
    solve() ;
    return 0;
}
