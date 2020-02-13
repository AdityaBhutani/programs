#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){	
	cout << "VECTOR" << "\n";
	vector<int> vect;
	vect.push_back(10);
	vect.push_back(20);
	vect.push_back(30);
	for(int i=0; i<vect.size(); i++){
		cout << vect[i] << " ";
	}
	cout << "\n";
	cout << "MAP" << "\n";
	map<int, string> mp;
	mp[1] = "one";
	mp[2] = "two";
	mp[3] = "three";
	map<int, string>::iterator it = mp.begin();
	while (it != mp.end()){
		cout << it->first << "=> ";
		cout << it->second << "\n";
		it++;
	}
	return 0;
}