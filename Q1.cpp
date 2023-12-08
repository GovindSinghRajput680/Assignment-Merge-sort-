#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& a,vector<int> &b,vector<int> &v){
    int i =0,j =0,k =0;
    while(i<a.size() && j<b.size()){
        if(a[i]>=b[j]) v[k++] = a[i++];
        else v[k++]  = b[j++];
    }
    while(i<a.size()) v[k++] = a[i++];
    while(j<b.size()) v[k++] = b[j++];
    }
void mergesort(vector<int> &v){int n = v.size();
    //Base case
    if(n == 1) return;
    //Divide into two vectors
    vector<int> a(n/2);
    vector<int> b(n-n/2);
    //Copy
    for(int i =0;i<a.size();i++) a[i]= v[i];
    for(int i =0;i<b.size();i++)  b[i]= v[i+n/2];
    //Recursive call
    mergesort(a);
    mergesort(b);

    //Merge
    merge(a,b,v);
    a.clear();
    b.clear();

}

int main(){int n;
    cout<<"Enter size of array : ";
    cin>>n;
    cout<<"Enter elements : ";
    vector<int> v(n);
    for(int i =0;i<n;i++) cin>>v[i];
    mergesort(v);
    cout<<"Sorted in dec order : ";
    for(int i =0;i<n;i++) cout<<v[i]<<" ";

}
