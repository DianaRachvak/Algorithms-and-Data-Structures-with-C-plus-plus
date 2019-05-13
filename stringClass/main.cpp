#include <iostream>
#include <cstdlib>

#include "string.h"

using namespace std;

int main() {
	String s = "Hello";

	cout << s << endl;
	cout << s.length() << endl;

	cout << s + " world" << endl;

	cout << s[1] << endl;

	String s1 = s;		// making sure copy constructor makes deep copy
	String s2;
	s2 = s;			// making sure assignment operator makes deep copy
	s[0] = 'j';
	cout << "s: " << s << endl;
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;

	for (int i = 0; i < 5; i++) {
		s += s;
		cout << s << endl;
	}

	for (int i = 0; i < 5; i++)
		s += s;
	cout << s << endl;

	s.clear();
	cout << s << endl;

	return 0;
}

