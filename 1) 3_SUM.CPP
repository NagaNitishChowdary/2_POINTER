// PROBLEM LINK --- https://leetcode.com/problems/3sum/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028?leftPanelTab=0

#include<bits/stdc++.h>
#define LL long long int 
#define NEXT "\n"

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    // BRUTEFORCE --- TC : O(N^3 LOG M) [LOG M TO INSERT INTO SET]
    /*
    int n = nums.size() ;
    set<vector<int>> st ;
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            for(int k=j+1 ; k<n ; k++){
                if(nums[i]+nums[j]+nums[k] == 0){ // st.insert({nums[i],nums[j],nums[k]});
                    vector<int> h = {nums[i],nums[j],nums[k]} ;
                    sort(h.begin() , h.end()) ;
                    st.insert(h) ;
                }
            }
        }
    }
    vector<vector<int>> ans ;
    for(auto it:st) ans.push_back(it) ;
    return ans ;
    */
    // BETTER APPROACH --- USES HASHMAP
    /*
    set<vector<int>> st ;
    int n = nums.size() ;
    map<int,int> mpp ;
    for(int i=0 ; i<n ; i++) mpp[nums[i]]++ ;
    for(int i=0 ; i<n-2 ; i++){
        mpp[nums[i]]-- ;
        for(int j=i+1 ; j<n-1 ; j++){
            mpp[nums[j]]-- ;
            // FOR C , C = -(A+B) 
            if(mpp[-(nums[i]+nums[j])] != 0){
                vector<int> h = {nums[i],nums[j],-(nums[i]+nums[j])} ;
                sort(h.begin() , h.end()) ;
                st.insert(h) ;
            }
            mpp[nums[j]]++ ;
        }
        mpp[nums[i]]++ ;
    }
    vector<vector<int>> ans ;
    for(auto it:st) ans.push_back(it) ;
    return ans ;
    */
    
    // OPTIMAL APPROACH --- 2 POINTER
    // FIRST STEP OF IT IS TO SORT THE ARRAY
    int n = nums.size() ;
    sort(nums.begin() , nums.end()) ;
    vector<vector<int>> ans ;
    for(int i=0 ; i<n-2 ; i++){
        if( i==0 || ( i>0 && nums[i] != nums[i-1])){
            int low = i+1 , high = n-1 , sum = 0-nums[i] ;
            while(low < high){
                if(nums[low] + nums[high] == sum){
                    ans.push_back({nums[i] , nums[low] , nums[high]}) ;
                    while(low < high && nums[low] == nums[low+1]) low++ ;
                    while(low < high && nums[high] == nums[high-1]) high-- ;
                    low++ ; high-- ;
                }
                else if(nums[low] + nums[high] < sum) low++ ;
                else high-- ;
            }
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
        vector<int> nums(n) ;
        for(int i=0 ; i<n ; i++) cin >> nums[i] ;
        vector<vector<int>> knnc = threeSum(nums) ;
        for(auto it:knnc){
            for(auto vctr:it) cout << vctr << " " ;
            cout << endl ;
        }
    }
    return 0;  
}
