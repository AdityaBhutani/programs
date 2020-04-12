// https://leetcode.com/problems/two-sum/solution/
#include<iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  int n = nums.size();
  int result_i = 0, result_j = 0;
  for(int i=0; i< n; i++){
    for(int j=i+1; j < n; j++){
      if(nums[i] + nums[j] == target){
        result_i = i;
        result_j = j;
        break;
      }
    }
  }
  return {result_i, result_j};
}

int main(){
  vector<int> test = {2,7,11,15};
  vector<int> twoSumResult = twoSum(test, 9);
  cout << twoSumResult[0];
  cout << twoSumResult[1];
  return 0;
}
