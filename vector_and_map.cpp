#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
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
	// INSERT VALUE IN MAP-HASH START
	mp.insert({4, "four"});
	// INSERT VALUE IN MAP-HASH END
	// IMP: get value from key START
	cout << "========================";
	map<int, string>::iterator finder;
	finder = mp.find(990);
	cout << finder -> first;
	// cout << finder -> second << endl;
	if (finder -> second == ""){
		cout << "FOUND ";
	}
	// CHECK IF VALUE EXISTS IN HASH(MAP/UNORDERED MAP) START

	if (mp.count(99) > 0){
		cout << "99 key is present in map";
	}else{
		cout << "99 key NOT present in map";
	}

	// CHECK IF VALUE EXISTS IN HASH(MAP/UNORDERED MAP) END

	cout << "========================";
	// IMP: get value from key END
	map<int, string>::iterator it = mp.begin();	
	while (it != mp.end()){
		cout << it->first << "=> ";
		cout << it->second << "\n";
		it++;
	}
	// Unordered Map - to be used when sorting of hash keys is not required
	unordered_map<int, int> ump;
	return 0;
}