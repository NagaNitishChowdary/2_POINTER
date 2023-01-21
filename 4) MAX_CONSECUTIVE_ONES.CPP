// PROBLEM LINK --- https://leetcode.com/problems/max-consecutive-ones/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/maximum-consecutive-ones_3843993

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxi = 0 ,c = 0 ;
    int n = nums.size() ;
    for(int i=0 ; i<n ; i++){
        if(nums[i] == 1) c++ ;
        else{ maxi = max(maxi , c) ; c = 0 ; }
    }
    return max(maxi,c) ;
}

int main()
{
    int T ; cin >> T ;
    while(T--)
    {
        int N ; cin >> N ;
        vector<int> nums(N) ;
        for(int i=0;i<N;i++) cin >> nums[i]; 
        cout << findMaxConsecutiveOnes(nums) << endl;
    }
}
