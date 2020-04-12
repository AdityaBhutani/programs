// https://www.interviewbit.com/problems/power-of-two-integers/
#include <iostream>
#include <cmath>
using namespace std;

int isPower(int A) {
  int is_power_flag = 0;
  for(int a=2; a<A/2+1; a++){
    for(int p=2; p<A; p++){
      if (pow(a, p) == A){
    		std::cout << a << "-" << p;
        is_power_flag = 1;
        break;
      }
    }
  }
  return is_power_flag;
}


int main(){
	std::cout << isPower(124000000);
	return 0;
}