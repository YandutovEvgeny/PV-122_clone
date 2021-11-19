#pragma warning(disable:4326)
#include"String.h"

//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "russian");
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
	String str6{"Параметры в конструктор можно передавать в фигурных скобках"};
	cout << str6 << endl;
	String str7 = str6;   
	cout << str7 << endl;
	cout << str2 + " " + str3 << endl;
}