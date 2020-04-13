// https://leetcode.com/problems/two-sum/solution/
#include<iostream>
#include <vector>
#include <unordered_map>
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

vector<int> twoSumTwoPassHash(vector<int> &nums, int target){
  unordered_map<int, int> ump;
  int complement;
  int complement_index;
  int number_index;
  for(int i=0; i< nums.size(); i++){
    ump.emplace(nums[i], i);
  }
  unordered_map<int, int>::iterator finder;
  for(int i=0; i< nums.size(); i++){
    complement = target - nums[i];
    finder = ump.find(complement);
    if(finder != ump.end() && ump[complement] != i){
      number_index = i;
      complement_index = finder -> second;
      break;
    }
  }
  if (number_index <= complement_index){
    return {number_index, complement_index};   
  }else{
    return {complement_index, number_index};   
  }
}

int main(){
  vector<int> test = {3,3};
  vector<int> twoSumResult = twoSum(test, 6);
  cout << twoSumResult[0];
  cout << twoSumResult[1];
  cout << "RESULT USING 2 PASS HASH:" << endl;
  vector<int> twoSumTwoPassHashResult = twoSumTwoPassHash(test, 6);
  cout << twoSumTwoPassHashResult[0];
  cout << twoSumTwoPassHashResult[1];
  return 0;
}
