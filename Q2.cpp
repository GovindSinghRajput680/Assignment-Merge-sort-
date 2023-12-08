#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&a,vector<int>&b,vector<int>&v){
    int i =0,j =0,k =0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]) v[k++] = a[i++];
        else v[k++] = b[j++];
    }
    while(i<a.size()) v[k++] = a[i++];
    while(j<b.size()) v[k++] = b[j++];
}
int mergesort(vector<int> &v){int n = v.size(),count = 0;
    //Base case
    if(n == 1 ) return 0;

    //Dividing into two array
    vector<int> a(n/2);
    vector<int> b(n-n/2);

    //Copy
    for(int i =0;i<n/2;i++) a[i] = v[i];
    for(int i =0;i<b.size();i++) b[i] = v[i+n/2];

    //Recursive call
    count+=mergesort(a);
    count+=mergesort(b);

    //Calculating reveres pairs
    int i =0,j = 0;
    while(i<a.size() && j<b.size()){
        if(a[i]>2*b[j]) count+=(a.size()-i),j++;
        else i++;
    }

    //Merge
    merge(a,b,v);

    //Deleting arrays
    a.clear();
    b.clear();

    return count;
}
    
int main(){int n;
    cout<<"Enter size of array : ";
    cin>>n;
    cout<<"Enter elements : ";
    vector<int> v(n);
    for(int i =0;i<n;i++) cin>>v[i];
    cout<<"Number of reverse pairs = "<<mergesort(v);


}