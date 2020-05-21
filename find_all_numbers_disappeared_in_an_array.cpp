#include <iostream>
#include <vector>
using namespace std;

// using another array to maintain which array element is not avaiable in given array nums
vector<int> findDisappearedNumbers_using_another_array(vector<int>& nums) {
	vector<int> nums_complete, result;
	for(int i=0; i<nums.size(); i++){
		nums_complete.push_back(i+1);
	}
	for(int i=0; i<nums.size(); i++){
		nums_complete[nums[i]-1] = -1;
	}
	for(int i=0; i<nums.size(); i++){
		if(nums_complete[i] != -1){
			result.push_back(nums_complete[i]);
		}
	}
	return result;
}

// We are given that the nos in the given array will lie between the values 1 to n. ie., 1<=a[i]<=n
// Here we have to mark the existence of the nos that are present and those that are not present
// For this we can mark the existence and non-existence of a no. by marking the index of the number
// as +ve and -ve respectively
// For example we come across no. 4 in the array, we can mark 4th of the index as -ve of the no.
// in that position(position 4) to mark that we have found 4 in the array.
// In a way we are accomodating 2 informations in the same array - the elements and the presence 
// and absence of the element by marking the index
// We mark the presence of a number by negating the no. at the index equal to the current no. 
// Since arrays have index from 0, the index we mark is actually current_number-1.
vector<int> findDisappearedNumbers_using_same_array(vector<int>& nums) {
  vector<int> result;
  for(int i=0; i<nums.size(); i++){
    nums[nums[i]-1] = abs(nums[nums[i]-1]) *-1;        
  }
  for(int i=0; i<nums.size(); i++){
    if(nums[i] > 0){
      result.push_back(i+1);
    }
  }
  return result;
}

int main(){
	vector<int> nums = {4,3,2,7,8,2,3,1};
	vector<int> result;
	result = findDisappearedNumbers_using_same_array(nums)
	findDisappearedNumbers_using_another_array(nums)	
	for(int i=0; i< result.size(); i++){
		cout << result[i] << ", ";
	}
	return 0;
}