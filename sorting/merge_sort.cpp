#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int i, int j, int m){
    int a=m-i+1;
    int b=j-m;
    vector<int> left(a);
    vector<int> right(b);

    for(int k=0;k<a;k++){
        left[k]=v[i+k];
    }

    for(int k=0;k<b;k++){
        right[k]=v[m+k+1];
    }

    int x=0;int y=0;int z=i;
    while(x<a and y<b){
        if(left[x]>right[y]){
            v[z]=left[x];
            x++;
        }
        else{
            v[z]=right[y];
            y++;
        }
        z++;
    }

    while(x<a){
        v[z]=left[x];
        z++;x++;
    }

    while(y<b){
        v[z]=right[y];
        z++;y++;
    }
}

void merge_sort(vector<int> &v, int i, int j){
    if(i<j){
        int m=i+(j-i)/2;

    merge_sort(v, i, m);
    merge_sort(v, m+1, j);

    merge(v, i, j, m);
    }
}

int main(){
    vector<int> arr = {5,4,3,2,1};
    merge_sort(arr, 0, 4);

    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}