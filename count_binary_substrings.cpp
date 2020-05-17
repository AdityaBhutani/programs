// https://leetcode.com/problems/count-binary-substrings/
#include <iostream>
using namespace std;

// EXPLANATION - http://anothercasualcoder.blogspot.com/2019/01/count-binary-substrings.html

// if we arrive at '0' in string, check if the previous one was zero or not, if not then
// we have arrived at a non consecutive zero, so we reset the count of number_of_consecutive_zeroes to zero
// in the next step we number_of_consecutive_zeroes + 1, as the '0' encountered can be the
// the first among a set of consecutive zeroes.
// we check if the number of consecutive zeroes is less than or equal to number_of_consecutive_ones
// then we can say that we have found a substring matching the criteria
int countBinarySubstrings(string s) {
  int number_of_consecutive_zeroes = 0;
  int number_of_consecutive_ones = 0;
  int result = 0;
  if(s == ""){
    return 0;
  }
  for(int i=0; i<s.length(); i++){
    if(s[i] == '0'){
      if(i-1>=0 && s[i-1] == '1'){
        number_of_consecutive_zeroes = 0;
      }
      number_of_consecutive_zeroes++;
      if(number_of_consecutive_zeroes<=number_of_consecutive_ones){
        result++;
      }
    }
    else{
      if(i-1 >= 0 && s[i-1] == '0'){
        number_of_consecutive_ones = 0;
      }
      number_of_consecutive_ones++;
      if(number_of_consecutive_ones<=number_of_consecutive_zeroes){
        result++;
      }
    }
  }
  return result;
}

int main(){
  cout << countBinarySubstrings("00110011");
  return 0;
}