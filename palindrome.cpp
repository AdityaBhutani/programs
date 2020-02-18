// http://codeforces.com/contest/1304/problem/B
#include <iostream>

bool isPalindrome(std::string s){
	bool palindrome_flag = true;
	for(int i =0; i <= (s.length()/2)-1;i++){
		if(s[i] != s[s.length()-1-i]){
			palindrome_flag = false;
			break;
		}
	}
	return palindrome_flag;
};

int main(){
	std::string s = "moon";
	if (isPalindrome(s)){
		std::cout << "PALINDOMR";
	}else{
		std::cout << "NOT PALINDOMR";
	}
	return 0;
}