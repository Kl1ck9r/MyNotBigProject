#pragma warning(disable : 4996) .
#include "string.h"

String::String()
{
	str = new char[1];
	str[0] = '\0';
	len = 10;
}

String::String(const String& s)
{
	len = s.len;
	str = new char[s.len+1];
	strcpy(str, s.str);
}

String::String(const char* s)
{
	len = strlen(s);
	str =new char[len+1];
	strcpy(str, s);
}

String::~String()
{
	delete[]str;
}

char& String::operator[](int index)
{
	return str[index];
}

const char& String::operator[](int index)const
{
	return str[index];
}

String & String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[]str;

	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;
}

String& String::operator=(const char*st)
{
	delete[]str;
	len = strlen(st);
	str = new char[len + 1];
	strcpy(str, st);
	return *this;
}

String operator+(const String& str1, const String& str2)
{
	String temp;
	delete[]temp.str;
	temp.len = str1.len + str2.len;
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, strcat(str1.str, str2.str));
	return temp;
}

void String::copy(char str2[], int len, int index)
{
	for (int i = 0; i < len; i++) {
		str2[i] = str[index+ i];
	}
	str2[len] = '\0';
}

char& String::at(int index)
{
	return str[index];
}

bool operator==(const String& str1, const String& str2) 
 {
	return (strcmp(str1.str, str2.str) == 0);

 }

bool operator>(const String& str1, const String& str2)
 {
	return str1>str2;

 }

bool operator<(const String& str1, const String& str2)
{
	return (strcmp(str1.str,str2.str)<0);

}

std::ostream& operator<<(std::ostream& oc, const String& st)
{
	oc << st.str << " ";
	return oc;
}

std::istream& operator>>(std::istream& is,String& st)
{
	char temp[30];
	is.get(temp, 30);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}