#pragma once
#include <iostream>

class String {
public:
	String(const char* s);

	String(const String& s);

	String();

	~String();

public:

	friend std::ostream& operator<<(std::ostream& os, const String& st);

	friend std::istream& operator>>(std::istream& is,  String& st);

	friend bool operator<(const String& str1, const String& str2);

	friend bool operator>(const String& str1, const String& str2);

	friend bool operator==(const String& str1, const String& str2);

	friend String operator+(const String& str1, const String& str2);

	String& operator=(const String&);

	String& operator=(const char*);	

public:
	char& at(int index);
	void copy(char str2[], int len, int index);
	int length() { return len; }
	char& operator[](int index);
	const char& operator[](int index)const;

private:
	char* str;
	int len;
};
