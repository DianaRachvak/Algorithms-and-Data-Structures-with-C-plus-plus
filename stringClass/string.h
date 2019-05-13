#ifndef STRING_H
#define STRING_H

#include <iostream>


class String {
	friend std::ostream &operator <<(std::ostream &os, const String &s);
	friend bool operator ==(const String &s1, const String &s2);
	friend String operator +(const String &s1, const String &s2);
public:
	String(const char *cs="");
	String(const String &s);
	~String();
	String &operator =(const String &rhs);
	char &operator [](int index);
	String &operator +=(const String &s);
	int find(char c) const;
	int length() const;
	void clear();
private:
	char *cs;
	int len;
};

#endif
