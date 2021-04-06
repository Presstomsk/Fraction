/*
Реализовать класс Fraction, описывающий простую дробь. 
В классе должны быть все обязательные методы, а так же методы:
	- to_proper();		//Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
	- to_improper();	//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
	- reduce();			//Сокращает дробь: 5/10 => 1/2;
1. Арифметические операторы: +, -, *, /;
2. Составные присваивания: +=, -=, *=, /=;
3. Increment/Decrement (++/--);
4. Операторы сравнения: ==, !=, >, <, >=, <=;
5. Операторы для работы с потоками: <<, >> 
*/

#include <iostream>
using namespace std;

#define tab "\t"

class Fraction
{
	int integer, numerator, denominator;

public:

	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	/*-------------------------------*/
	void set_integer(int x)
	{
		this->integer = x;	
	}
	void set_numerator (int x)
	{
		this->numerator = x;
	}
	void set_denominator(int x)
	{
		this->denominator = x;
	}
	/*--------------------------------*/

	Fraction(int x = 0, int y = 0, int z=0)
	{
		this->integer = z;
		this->numerator = x;
		this->denominator = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	/*-----------------------------------*/
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment: \t" << this << endl;
		return *this;
	}
	/*------------------------------------*/
	void to_proper()
	{   
		int dif = 0, i = 1;
		for (;this->numerator >= this->denominator;i++)
		{
			this->numerator=this->numerator-this->denominator;
			this->integer = i;
		}
	}
	void to_improper()
	{
		this->numerator = this->integer * this->denominator + this->numerator;
		this->integer = 0;
	}


};

void main()
{
	setlocale(LC_ALL, "");
	Fraction a(17, 5);
	Fraction b(3, 4, 6);
	a.to_proper();
	cout << a.get_integer() << "(" << a.get_numerator() << "/" << a.get_denominator() << ")" << endl;
	a.to_improper();
	cout << a.get_numerator() << "/" << a.get_denominator() << endl;
}
	