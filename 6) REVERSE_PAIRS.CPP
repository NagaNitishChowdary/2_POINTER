// PROBLEM LINK --- https://leetcode.com/problems/reverse-pairs/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/reverse-pairs_1112652
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/count-reverse-pairs/1?page=1&sortBy=newest&query=page1sortBynewest

#include <bits/stdc++.h>
using namespace std;

int countRevPairs(int n, vector<int> arr) {
    // Code here
    // BRUTEFORCE --- O(N^2)
    int cnt = 0 ;
    for(int i=0 ; i<n-1 ; i++){
        for(int j=i+1 ; j<n ; j++){
            long long int knnc = (long long int)arr[i] - 2*(long long int)(arr[j]) ;
            if(knnc > 0) cnt++ ;
        }
    }
    return cnt ;
}

int main() {
    int t ; cin >> t ;
    while (t--) {
        int n ; cin >> n ;
        vector<int> arr;
        for (int i = 0; i < n ; ++i) {
            int x ; cin >> x ;
            arr.push_back(x);
        }
        cout << countRevPairs(n, arr) << endl;
    }
    return 0;
}
