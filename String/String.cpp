#pragma warning(disable:4326)
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


/////////////////////////////////////////////////////////////////////////////////
////////////////////////      ОПРЕДЕЛЕНИЕ КЛАССА - CLASS DEFINITION     /////////
char* String::get_str()
{
	return str;
}
const char* String::get_str()const
{
	return str;
}
int String::get_size()const
{
	return size;
}
//           Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)  //Делегируем выделение памяти конструктору по умолчанию
{
	for (int i = 0; i < size; i++)
	{
		this->str[i] = str[i];
	}
	cout << "Constructor:\t\t" << this << endl;
}
//         The rule of three
String::String(const String& other) :String(other.str)
{
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	other.str = nullptr;
	other.size = 0;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}

//                Operators:
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	other.size = 0;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

//:: - Global scope (Глобальное пространство имён)
::String operator+(const String& left, const String& right)
{
	String result (left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		//result.get_str()[i] = left.get_str()[i];   
		result[i] = left[i];   
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

///////////////		КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА - CLASS DEFINITION END		////////
////////////////////////////////////////////////////////////////////////////////

//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str;   //Default constructor
	str.print();

	String str1 = "Hello";  //Single-argument constructor
	//str1.print();
	cout << str1 << endl;

	String str2 = str1;   //Copy constructor
	cout << str2 << endl;

	String str3;
	str3 = str2;         //Shallow copy - поверхностное копирование
	cout << str3 << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	/*String str1 = "Hello";
str1 = str1;
cout << str1 << endl;*/

	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	/*cout << delimiter << endl;
	str1 += str2;
	cout << delimiter << endl;
	cout << str1 << endl;*/
#endif // OPERATOR_PLUS_CHECK

	String str1(25);   //Default constructor;
	str1.print();
	String str2 = "Hello";   //Single-argument constructor;
	str2.print();
	String str3("World");    //Single-argument constructor;
	cout << str3 << endl;
	String str4();    //Здесь НЕ создаётся объект, объявляется функция str4, которая ничего не принимает и возвращает объект класса String
	//cout << str4 << endl;
	String str5{};    //Явный вызов конструктора по умолчанию
	cout << str5 << endl;
	String str6{ "Параметры в конструктор можно передавать в фигурных скобках" };
	cout << str6 << endl;
	String str7 = str6;   
	cout << str7 << endl;
	cout << str2 + " " + str3 << endl;
}
