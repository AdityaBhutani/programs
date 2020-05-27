// https://leetcode.com/problems/positions-of-large-groups/
#include <iostream>
#include <vector>
using namespace std;

// Initially set group_count(gc) = 1 and group_start_index(gsi) = 0. This represent the
// First element. This is because we are iterating on S [1:n-1], we start from 1 because
// we are comparing current element with the previous element.
// gsi maintains the first index of an element forming a group.
// gc maintains the count of the elements in the group.
// At first we check S[i-1] != S[i], here we are checking whether the current_element(S[i])
// is the same as it's previous element(S[i-1]). If they are not the same, this means, 
// we are encountering a change of group.
// We check if gc >=3 to see if on changing of group, the previous element had created
// a group of 3 or more elements, if it has we add it to the result
// Thus we set gsi to present index(i) and gc to 1, taking into account the first element of the group
// If S[i-1] == S[i] then gc++ because we have encountered another element in the group
// in the end we check whether we have reached the last element and check if we have found
// a group of 3 or more
// This handles the situation where the last group of elements has created a large group
// here there will be no change of group as this is the last element of the last group
// Example: "aaa" or "bbbaaaaa", in both the examples the group of 'a' will be the last 
// group and there wont be any change in group but 'a' forms a group and needs to be added
// to the result
vector<vector<int>> largeGroupPositions(string S) {
	vector<vector<int>> result;
	int group_count = 1, group_start_index = 0;
	for(int i=1; i < S.length(); i++){		
		if(S[i-1] != S[i]){
			if(group_count >= 3){
				result.push_back({group_start_index, group_start_index + group_count - 1});
			}
			group_start_index = i;
			group_count = 1;
		}
		else{
			group_count++;
		}
		if(i==S.length()-1 && group_count >= 3){
			result.push_back({group_start_index, group_start_index + group_count - 1});
		}
	}
	return result;
}

int main(){
	vector<vector<int>> result;
	result = largeGroupPositions("aaa");
	// result.push_back({1,2});
	// result.push_back({3,4});
	for(int i=0; i< result.size(); i++){
		for(int j=0; j< result[i].size(); j++){
			cout << result[i][j] << ", ";
		}
		cout << endl;
	}
	return 0;
}