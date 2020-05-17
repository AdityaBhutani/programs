// https://leetcode.com/problems/longest-common-prefix/
#include <iostream>
#include <vector>
using namespace std;

// For finding the longest common prefix, ie., the common string which is present at the start of 
// each given string.
// We take the first string to be the common_prefix
// On the first iteration from the second element(strs[1]), we compare the common_prefix and strs[i]
// the part which is common between the two is stored in common_prefix
// this iteration and comparison is taken to the third element and so on till the last element
// after each comparison the common_prefix is updated with the new common
string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0){
		return "";
	}
	string common_prefix = strs[0];
	int str_common_count, str_itr_length;
	for(int i=0; i < strs.size(); i++){
		str_common_count = 0;
		// the iteration will be done till the shortest of the 2, the element under consideration
		// and common_prefix as we need to find only the common portion among them
		// the part exceeding it can't be same anyway
		str_itr_length = min(strs[i].length(), common_prefix.length());
		for(int j=0; j < str_itr_length; j++){
			if(strs[i][j] == common_prefix[j]){
				str_common_count++;
			}else{
				break;
			}
		}
		common_prefix = common_prefix.substr(0, str_common_count);
	}
	return common_prefix;
}

int main(){
	vector<string> strs = {};
	cout << longestCommonPrefix(strs);
	return 0;
}