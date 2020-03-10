//https://docs.google.com/document/d/18t2DITvJImrfA0xc1bk4dLzkMXKlWceoxut4Z9A8gso/edit#
#include<iostream>
#include<vector>
using namespace std;

void row_addition(vector<int> &v, int row_number, int add_value, int N){
	for(int i=row_number*N; i<(row_number+1)*N; i++){
		v[i] = v[i] + add_value;
	}
}

void column_addition(vector<int> &v, int col_number, int add_value, int N){
	for(int i=col_number; i<v.size(); i=i+N){
		v[i] = v[i] + add_value;
	}
}

int find_max_element_in_arr(vector<int> v){
	int max = v[0];
	for(int i=0;i<v.size();i++){
		if(v[i] > max){
			max = v[i];
		}
	}
	return max;
}

int main(){
	int N = 3;
	vector<int> v = {0,0,0,0,0,0,0,0,0};
	row_addition(v, 1, 7, N);
	column_addition(v, 2, 6, N);
	row_addition(v, 0, 2, N);
	cout << "MAX ELEMENT IN RESULTANT ARR = " << find_max_element_in_arr(v) << endl;
	for(int i=0; i<v.size(); i++){
		cout << v[i] << ", ";
	}
	return 0;
}