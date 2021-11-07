#include<iostream>
using namespace std;

class String
{
	char* str;
public:
	char get_str()const
	{
		return *str;
	}
	void set_str(char* str)
	{
		this->str = str;
	}
	
	//              Constructors:
	String()
	{
		str = nullptr;
		cout << "DefaultConstructor: " << this << endl;
	}
	String(char* str)
	{
	   int length = strlen(str);
	   this->str = new char[length + 1];
	   for (int i = 0; i < length; i++)
	   {
		   this->str[i] = str[i];
	   }
	   this->str[length] = "\0";
	}
	~String()
	{
		delete[] this->str;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	String str("Hello");
	
		

}