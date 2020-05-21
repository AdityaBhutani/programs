// https://leetcode.com/problems/nth-digit
#include <iostream>
#include <vector>
using namespace std;

// No. Range 				No. of digit in 1 number 				No. of digits in range
//	 1-9										  1																9	
//  10-99											2															90*2
// 100-999										3															900*3
//1000-9999										4															9000*4

// Example: N=1000
// ==== PART 1 STARTS ====
// Then N = N-9 = 911
// Then N = N-180 = 811
// Then Not possible
// ==== PART 1 ENDS ====

// This means the digit to be found is the 811th digit in the range [100-999]
// We know each no. in range [100-999] have 3 digits, so (811-1)/3 = 270

// Now we know that the 270th No. in range [100-999] is the number.
// The 270+100th(start from 100) = 370 is the no. in which the digit exists
// Now, 370 has 3 digits [3,7,0], which one of them is the digit we want
// (811-1)%3 = 1. So the 1st no. is the answer, returning 3.
int findNthDigit(int n) {
	int digit_position;
	long m = n;
	long range_start = 1, no_of_digit_in_1_no_for_range = 1, no_of_all_digits_in_range = 9, number;
	// ==== PART 1 STARTS ====
	while(m > no_of_digit_in_1_no_for_range * no_of_all_digits_in_range){
		m = m - no_of_digit_in_1_no_for_range * no_of_all_digits_in_range;
		no_of_all_digits_in_range*=10;
		no_of_digit_in_1_no_for_range++;
		range_start*=10;
	}
	// ==== PART 1 ENDS ====

	number = range_start + (m-1)/no_of_digit_in_1_no_for_range;

	digit_position = (m-1)%no_of_digit_in_1_no_for_range;

	string s = to_string(number);

	return (s[digit_position] - '0');
}

int main(){
	cout << findNthDigit(1000);
	return 0;	
}