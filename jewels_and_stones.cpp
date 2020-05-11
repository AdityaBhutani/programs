// https://leetcode.com/problems/jewels-and-stones
#include <iostream>
#include <unordered_map>
using namespace std;

// Iterating over string J and storing in hash, then iterating over string S
// and checking if value exists in hash(which will only be present if value exists in J)
int numJewelsInStones(string J, string S){
	unordered_map<char, bool> unmp;
	int jewel_in_stones_count = 0;

	for(string::iterator j_it = J.begin(); j_it!=J.end(); j_it++){
		unmp.insert({*j_it, true});
	}

	for(string::iterator s_it = S.begin(); s_it!=S.end(); s_it++){
		if(unmp.count(*s_it) > 0){
			jewel_in_stones_count = jewel_in_stones_count + 1;
		}
	}

	return jewel_in_stones_count;
}

int main(){
	cout << numJewelsInStones("aA", "aAAbbbb");
	return 0;
}