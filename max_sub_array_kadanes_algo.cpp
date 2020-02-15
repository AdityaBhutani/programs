#include <iostream>
#include <vector>
using namespace std;

int max_of_2_values(int a, int b){
	if(a >= b){
		return a;
	}else{
		return b;
	}
}

int main()
{
	vector<int> vect = {-2, 3, 2, -1};
	int max_current = vect[0];
	int max_global = vect[0];
	for(int i=1; i < vect.size(); i++){
		max_current = max_of_2_values(vect[i], max_current + vect[i]);
		max_global = max_of_2_values(max_global, max_current);
	}
	cout << "MAX SUM OF A SUBARRAY IN GIVEN ARRAY IS = ";
	cout << max_global;
	return 0;
}