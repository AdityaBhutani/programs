// https://leetcode.com/problems/reverse-integer/
#include <iostram>
using namespace std;

// This question reverses the integer given to us. The conditions return 0 are explained as follows
// INT_MAX = 2147483647
// INT_MIN = -2147483648
// INT_MAX/10 = 214748364 and INT_MAX*10 = 2147483640 (it loses its 7 at the end)
// Case: rev=INT_MAX/10(214748364), then we do rev=rev*10+dig, here rev*10 will be 2147483640
// if dig is greater than 7, then rev will be greater than INT_MAX i.e., out of range
int reverse(int x){
	int rev=0, dig, sign=1;
	if(x<0){
		sign = -1;
	}
	x = abs(x);
	while(x!=0){
		dig = x%10;
		if(rev > INT_MAX/10 || rev == INT_MAX/10 && dig > 7){
	    return 0;
	  }
	  if(rev < INT_MIN/10 || rev == INT_MIN/10 && dig < -8){
	    return 0;
	  }
		rev = rev*10 + dig;
		x = x/10;
	}
	return rev*sign;
}

int main(){
	cout << reverse(1534236469);
}