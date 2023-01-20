// PROBLEM LINK --- https://leetcode.com/problems/trapping-rain-water/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/trapping-rainwater_630519

#include<bits/stdc++.h>
#define LL long long int 
#define NEXT "\n"

using namespace std;

int trap(vector<int>& height) {
    // BRUTEFORCE --- O(N^2)
    /*
    int n = height.size() ;
    int ans = 0 ;
    for(int i=0 ; i<n ; i++){
        int leftMax = 0 , rightMax = 0 ;
        for(int j=i ; j<n ; j++) rightMax = max(rightMax , height[j]) ;
        for(int j=i ; j>=0 ; j--) leftMax = max(leftMax , height[j]) ;
        ans += (min(leftMax,rightMax) - height[i]) ;
    }
    return ans ;
    */
    // BETTER APPROACH --- PREFIX SUM 
    /*
    int n = height.size() ;
    vector<int> prefixSum(n) , suffixSum(n) ;
    int preMax = 0 , sufMax = 0 ;
    for(int i=0 ; i<n ; i++){
        preMax = max(preMax , height[i]) ;
        prefixSum[i] = preMax ;
    }
    for(int i=n-1 ; i>=0 ; i--){
        sufMax = max(sufMax , height[i]) ;
        suffixSum[i] = sufMax ;
    }
    int ans = 0 ;
    for(int i=0 ; i<n ; i++){
        ans += (min(prefixSum[i],suffixSum[i])-height[i]) ;
    }
    return ans ;
    */
    // MOST OPTIMIZED APPROACH --- 2 POINTER 
    int n = height.size() ;
    int rightmax = 0 , maxleft = 0 ;
    int left = 0 , right = n-1 , ans = 0 ;
    while(left <= right){
        if(height[left] <= height[right]){
            // WE DEAL WITH LEFT BLOCK
            if(height[left] >= maxleft) maxleft = height[left] ;
            else ans +=  maxleft-height[left] ;
            left++ ;
        }
        else {
            // WE DEAL WITH RIGHT BLOCK 
            if(height[right] >= rightmax) rightmax = height[right] ;
            else ans +=  rightmax-height[right] ;
            right-- ;
        }
    }
    return ans ;
}

int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    LL testCases ; cin >> testCases ;
    while(testCases--){
        int n ; cin >> n ;
        vector<int> height(n) ;
        for(int i=0 ; i<n ; i++) cin >> height[i] ;
        cout << trap(height) << endl ;
    }
    return 0;  
}
