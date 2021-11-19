#pragma once
#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n----------------------\n"

/////////////////////////////////////////////////////////////////////////////////
////////////////////////      ОБЪЯВЛЕНИЕ КЛАССА - CLASS DECLARATION     /////////
class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	int size;   //Размер строки в Байтах
	char* str;  //Адрес строки в динамической памяти
public:
	char* get_str();
	const char* get_str()const;
	int get_size()const;
	//           Constructors:
	explicit String(int size = 80);
	String(const char* str);
	//         The rule of three
	String(const String& other);
	String(String&& other);
	~String();

	//                Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);

	const char& operator[](int i)const;
	char& operator[](int i);

	void print()const;
};
/////////////      КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА - CLASS DECLARATION END     //////////
/////////////////////////////////////////////////////////////////////////////////