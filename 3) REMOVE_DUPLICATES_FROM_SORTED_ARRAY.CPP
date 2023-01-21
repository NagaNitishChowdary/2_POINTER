// PROBLEM LINK --- https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-sorted-array_1102307

#include <bits/stdc++.h>
using namespace std;

int remove_duplicate(int a[],int n){
    // code here
    // OPTIMIZED APPROACH --- 2 POINTER 
    // TC --- O(N) , SC --- O(1)
    int j=0;
    for(int i=0;i<n-1;i++){
        if(a[i]!=a[i+1]){
            a[j++]=a[i];
        } 
    }
    a[j++]=a[n-1];
    return j;
}

int main()
{
    int T ; cin >> T ;
    while(T--)
    {
        int N ; cin >> N ;
        int a[N] ;
        for(int i=0;i<N;i++) cin>>a[i]; 
        int n = remove_duplicate(a,N);
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout << endl;
    }
}
