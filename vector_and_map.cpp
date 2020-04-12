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
	// IMP: get value from key START
	map<int, string>::iterator finder;
	finder = mp.find(2);
	cout << finder -> first;
	cout << finder -> second << endl;
	map<int, string>::iterator it = mp.begin();
	// IMP: get value from key END
	while (it != mp.end()){
		cout << it->first << "=> ";
		cout << it->second << "\n";
		it++;
	}
	return 0;
}