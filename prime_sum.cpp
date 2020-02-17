// https://www.interviewbit.com/problems/prime-sum/
#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int number){
	bool prime_flag = true;
	for (int i = 2; i <= number/2 + 1 && i!=number; i++){
		if(number%i == 0){
			prime_flag = false;
			break;
		}
	}
	return prime_flag;
}

int main(){
	int number = 4, sub_num_from_i;
	// cin >> number;
	vector<int> result;
	for(int i=2; i<= number - 2; i++){
		if (is_prime(i)){
			sub_num_from_i = number - i;
			if(is_prime(sub_num_from_i)){
				cout << i << " " << sub_num_from_i;
				result = {i, sub_num_from_i};
				break;
			}
		}
	}
	return 0;
}