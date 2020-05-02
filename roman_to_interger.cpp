// https://leetcode.com/problems/roman-to-integer/
#include <iostream>
using namespace std;
// Implemented with applying multiple if conditions, handling the presence of all roman numerals
// Handling, I can be placed before V (5) and X (10) to make 4 and 9. 
// Handling, X can be placed before L (50) and C (100) to make 40 and 90. 
// Handling, C can be placed before D (500) and M (1000) to make 400 and 900.
// with nested if conditions
int romanToInt(string s){
	int total_sum = 0;
	int n = s.size();
	for(int i=0; i<n; i++){		
		if(s[i] == 'I'){
			if(i+1 < n){
				if(s[i+1] == 'V'){
					total_sum = total_sum + 4;
					i=i+1;
					continue;	
				}
				else if(s[i+1] == 'X'){
					total_sum = total_sum + 9;
					i=i+1;
					continue;
				}				
			}
			total_sum = total_sum + 1;
			continue;
		}
		else if(s[i] == 'X'){			
			if(i+1 < n){				
				if(s[i+1] == 'L'){					
					total_sum = total_sum + 40;
					i=i+1;
					continue;
				}
				else if(s[i+1] == 'C'){
					total_sum = total_sum + 90;
					i=i+1;
					continue;
				}				
			}			
			total_sum = total_sum + 10; 
			continue;
		}
		else if(s[i] == 'C'){
			if(i+1 < n){
				if(s[i+1] == 'D'){
					total_sum = total_sum + 400;
					i=i+1;
					continue;
				}
				else if(s[i+1] == 'M'){
					total_sum = total_sum + 900;
					i=i+1;
					continue;
				}				
			}
			total_sum = total_sum + 100;
			continue;
		}
		else if(s[i] == 'V'){
			total_sum = total_sum + 5;
			continue;
		}
		else if(s[i] == 'L'){
			total_sum = total_sum + 50;
			continue;
		}
		else if(s[i] == 'D'){
			total_sum = total_sum + 500;
			continue;
		}
		else if(s[i] == 'M'){
			total_sum = total_sum + 1000;
			continue;
		}
	}
	return total_sum;
}

int main(){
	string s = "MCMXCIV";
	cout << romanToInt(s);
	return 0;
}