#include <bits/stdc++.h>
using namespace std;

class ds{
vector<int> size, parent;

public:
ds(int n)
{
    size.resize(n+1, 0);
    parent.resize(n+1, 0);

    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
}

int find_parent(int val)
{
    if(val==parent[val])
    return val;

    return parent[val]=find_parent(parent[val]);
}

void union_by_size(int a, int b)
{
    int ult_par_a = find_parent(a);
    int ult_par_b = find_parent(b);

    if(ult_par_a==ult_par_b)
    return;

    if(size[ult_par_a]<size[ult_par_b])
    {
        parent[ult_par_a]=ult_par_b;
        size[ult_par_b]+=size[ult_par_a];
    }

    else
    {
        parent[ult_par_b]=ult_par_a;
        size[ult_par_a]+=size[ult_par_b];
    }
}
};

//time complexity : O(4k) which is euqivalent to constant.

int main()
{
    ds disset(7);
    disset.union_by_size(1,2);
    disset.union_by_size(2,3);
    disset.union_by_size(4,5);
    disset.union_by_size(6,7);
    disset.union_by_size(5,6);
   
    if(disset.find_parent(3)==disset.find_parent(7))
    cout<<"same"<<endl;
    else
    cout<<"not same"<<endl;

    disset.union_by_size(3,7);

      if(disset.find_parent(3)==disset.find_parent(7))
    cout<<"same"<<endl;
    else
    cout<<"not same"<<endl;

return 0;
}