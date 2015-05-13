#ifndef HANDLING_FILE
#define HANDLING_FILE

#include "include.h"
using namespace std;


/*--code take here https://www.safaribooksonline.com/library/view/c-cookbook/0596007612/ch04s07.html
allow to split a string with a delimiter
*/
static void split(const string& s, char c,vector<string>& v) {
	string::size_type i = 0;
	string::size_type j = s.find(c);

	while (j != string::npos) {
		v.push_back(s.substr(i, j - i));
		i = ++j;
		j = s.find(c, j);

		if (j == string::npos)
			v.push_back(s.substr(i, s.length()));
	}
}

#endif // HANDLING_FILE