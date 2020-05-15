// https://leetcode.com/problems/maximum-subarray
#include <iostream>
#include <vector>
using namespace std;

// KADANE'S ALGORITHM FOR MAX SUM SUBARRAY STARTS
// THE CONCEPT - https://www.youtube.com/watch?v=86CQq3pKSUw
// UNDERSTOOD - https://www.youtube.com/watch?v=2MmGzdiKR9Y&t=810s
int max_sum_with_kadanes_algo(vector<int> &nums){
	int max_uptil_now = nums[0];
	int max_global = nums[0];
	for(int i=1; i < nums.size(); i++){
		max_uptil_now = max(max_uptil_now + nums[i], nums[i]);
		max_global = max(max_global, max_uptil_now);
	}
	return max_global;
}
// KADANE'S ALGORITHM FOR MAX SUM SUBARRAY ENDS



// DIVIDE AND CONQUER FOR MAX SUM SUBARRAY STARTS
// CONCEPT - https://www.youtube.com/watch?v=yBCzO0FpsVc
// UNDERSTOOD - https://www.youtube.com/watch?v=9wUr2o39CDU
int max_cross(vector<int> &nums, int l, int mid, int h){
	int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;
	for(int i = mid; i >= l; i--){
		sum = sum + nums[i];
		left_sum = max(left_sum, sum);
	}
	sum = 0;
	for(int i=mid+1; i <= h; i++){
		sum = sum + nums[i];
		right_sum = max(right_sum, sum);
	}
	return max(left_sum + right_sum, max(left_sum, right_sum));
}

int max_sum(vector<int> &nums, int l, int h){
	if (l == h){ return nums[l]; }
	int mid = (l+h)/2;
	int left = max_sum(nums, l, mid);
	int right = max_sum(nums, mid+1, h);
	int cross = max_cross(nums, l, mid, h);
	return max(cross, max(left, right));
}

int maxSubArray(vector<int>& nums){
	return max_sum(nums, 0, nums.size()-1);	
}
// DIVIDE AND CONQUER FOR MAX SUM SUBARRAY ENDS

int main(){
	vector<int> nums = {-84,-87,-78,-16,-94,-36,-87,-93,-50,-22,-63,-28,-91,-60,-64,-27,-41,-27,-73,-37,-12,-69,-68,-30,-83,-31,-63,-24,-68,-36,-30,-3,-23,-59,-70,-68,-94,-57,-12,-43,-30,-74,-22,-20,-85,-38,-99,-25,-16,-71,-14,-27,-92,-81,-57,-74,-63,-71,-97,-82,-6,-26,-85,-28,-37,-6,-47,-30,-14,-58,-25,-96,-83,-46,-15,-68,-35,-65,-44,-51,-88,-9,-77,-79,-89,-85,-4,-52,-55,-100,-33,-61,-77,-69,-40,-13,-27,-87,-95,-40};
	cout << maxSubArray(nums) << endl;
	cout << max_sum_with_kadanes_algo(nums);
}