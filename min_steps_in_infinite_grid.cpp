// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
#include <iostream>
#include <vector>
using namespace std;

int max_of_2_values(int a, int b){
	if (a>=b){
		return a;
	}else{
		return b;
	}
}

int main(){
	vector<int> A = {0,1,1};
	vector<int> B = {0,1,2};
	int x = 0, y = 0, sum_of_min_dist = 0;
	for(int i=0; i<A.size()-1;i++){
		x = abs(A[i] - A[i+1]);
		y = abs(B[i] - B[i+1]);
		sum_of_min_dist = sum_of_min_dist + max_of_2_values(x,y);
	}
	cout << sum_of_min_dist;
	return 0;
}
