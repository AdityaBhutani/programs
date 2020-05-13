// https://leetcode.com/problems/unique-email-addresses
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// iterating a given email to check for '@', part before it is local_name_part and after is 
// domain_name_part
// in local_name_part when '+' is found once the portion after it is not added to resultant local_name
// in local_name_part when '.' is found, it is ignored.
// storing the resulting local_name+domain_name in unordered_map to get unique emails after
// manipulations
int numUniqueEmails(vector<string>& emails) {
	string email;
	string local_name_part = "", domain_name_part = "", local_name_final = "";
	unordered_map<string, bool> unique_emails;
	bool at_found, plus_found;
	string email_final;

	for(int i=0; i < emails.size(); i++){
		email = emails[i];
		local_name_part = ""; domain_name_part = ""; local_name_final = "";
		at_found = false, plus_found = false;
		for(string::iterator e = email.begin(); e != email.end(); e++){
			if(at_found == false && *e == '@'){
				at_found = true;
				continue;
			}
			if(at_found == false){
				if(*e == '+'){
					plus_found = true;
				}else if(*e == '.'){
					continue;
				}
				if (plus_found == false){
					local_name_part += *e;
				}
			}else{
				domain_name_part += *e;
			}
		}
		// for(string::iterator l = local_name_part.begin(); l!= local_name_part.end(); l++){
		// 	if(*l == '+'){
		// 		break;
		// 	}else if(*l == '.'){
		// 		continue;
		// 	}
		// 	local_name_final += *l;
		// }
		email_final = local_name_part + '@' + domain_name_part;
		unique_emails.insert({email_final, true});
	}
	return unique_emails.size();
}

// 	BETTER VERSION
// find the position of '@' and divide the given email into parts - local_name_part and
// domain_name using substr() function which gets us the substring in a given string 
// from one position to another
// find the position of '+' in local_name_part and get the part before '+' using substr() function
// iterate over remaining local_name_with_dot to ignore '.' from string
// store the resulting local_name+domain_name in unordered_set which has the property
// of storing only unique elements ie., it doesn't repeat an already exising elememt 
int numUniqueEmailsTry2(vector<string>& emails) {
	string email, local_name_part, domain_name, local_name_with_dot, local_name;
	int pos_of_at, pos_of_plus;
	unordered_set<string> unset;
	for(int i=0; i < emails.size(); i++){		
		email = emails[i];		 
		pos_of_at = email.find_first_of('@');
		local_name_part = email.substr(0, pos_of_at);
		domain_name = email.substr(pos_of_at);	
		pos_of_plus = local_name_part.find_first_of('+');
		local_name_with_dot = local_name_part.substr(0, pos_of_plus);
		local_name = "";	
		for(string::iterator l = local_name_with_dot.begin(); l!= local_name_with_dot.end(); l++){
			if(*l == '.'){
				continue;
			}
			local_name += *l;
		}
	 	unset.insert(local_name + domain_name);
 	}
	return unset.size();
}

int main(){
	vector<string> v= {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
	cout << numUniqueEmails(v);
	cout << numUniqueEmailsTry2(v);
	return 0;
}