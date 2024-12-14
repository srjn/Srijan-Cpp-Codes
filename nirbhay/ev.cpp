#include <iostream>
using namespace std;

int find(int n){
    if(n==0)
    return 0;
    if(n<2)
    return n-1;
    int first=0;int second=1;

    for(int i=2;i<=n;i++){
        int temp=first + second;
        first = second;
        second =temp;
    }
    return second;
}

int solution(int a, int b){
    int ans=1;
    for(int i=a;i<=b;i++){
        ans*=find(i);
    }
    return ans;
}

int main(){
    cout<<solution(3, 3);
    return 0;
}