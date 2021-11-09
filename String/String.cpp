#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String
{
	int size;   //Размер строки в Байтах
	char* str;  //Адрес строки в динамической памяти
public:
	const char* get_str()const
	{
		return str;
	}
	//           Constructors:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t\t" << this << endl;
	}
	//         The rule of three
	String(const String& other)
    {
		//Deep copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
			cout << "CopyConstructor:\t" << this << endl;
		}
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//                Operators:
	String& operator=(const String& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
			cout << "CopyAssignment:\t\t" << this << endl;
		}
		return *this;
	}

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
 	}
};

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK

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

	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

}