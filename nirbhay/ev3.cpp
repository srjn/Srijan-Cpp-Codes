#include <iostream>
using namespace std;

int solve(int n){
    int cnt=0;
    while(n>0){
        if(n%5==0){
            n/=5;
        }
        else if(n%3==0){
            n/=3;
        }
        else if(n%2==0){
            n/=2;
        }
        else{
            n-=1;
        }
        cnt++;
    }
    return cnt;
}

int main(){
    cout<<solve(5);
    return 0;
}