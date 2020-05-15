#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vect = {-2,1,-3,4,-1,2,1,-5,4};
	int max_current = vect[0];
	int max_global = vect[0];
	for(int i=1; i < vect.size(); i++){
		max_current = max(vect[i], max_current + vect[i]);
		max_global = max(max_global, max_current);
	}
	cout << "MAX SUM OF A SUBARRAY IN GIVEN ARRAY IS = ";
	cout << max_global;
	return 0;
}