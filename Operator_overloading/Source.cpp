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
	Fraction& operator+=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->set_numerator(this->numerator*other.denominator + other.numerator*this->denominator);
		this->set_denominator(this->denominator * other.denominator);
		this->to_proper();
		other.to_proper();
		this->reduce();
		other.reduce();
		return *this;
	}
	Fraction& operator-=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->set_numerator(this->numerator * other.denominator - other.numerator * this->denominator);
		this->set_denominator(this->denominator * other.denominator);
		this->to_proper();
		other.to_proper();
		this->reduce();
		other.reduce();
		return *this;
	}
	Fraction& operator*=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->set_numerator(this->numerator * other.numerator);
		this->set_denominator(this->denominator * other.denominator);
		this->to_proper();
		other.to_proper();
		this->reduce();
		other.reduce();
		return *this;
	}
	Fraction& operator/=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->set_numerator(this->numerator * other.denominator);
		this->set_denominator(this->denominator * other.numerator);
		this->to_proper();
		other.to_proper();
		this->reduce();
		other.reduce();
		return *this;
	}
	/*------------------------------------*/
	void to_proper()
	{   
		int i = 1;
		for (;this->numerator >= this->denominator;i++)
		{
			this->numerator=this->numerator-this->denominator;
			this->integer = i;
		}
	}
	void to_improper()
	{
		this->numerator = this->integer * this->denominator+ this->numerator;
		this->integer = 0;		
	}
	void reduce()
	{
		this->to_improper();
		int CommonMultiple;                                  
		do {
			if (this->numerator < this->denominator)                                    
				CommonMultiple = this->numerator;
			else                                                  
				CommonMultiple = this->denominator;
			for (; CommonMultiple > 0; CommonMultiple--) 
			{                                                 
				if (!(this->numerator % CommonMultiple) && !(this->denominator % CommonMultiple)) 
				{                                    
					this->numerator = this->numerator / CommonMultiple;
					this->denominator = this->denominator / CommonMultiple;
					break;                               
				}
			}
		} while (CommonMultiple != 1);
		this->to_proper();
		
	}
	void print() const
	{
		if (this->numerator && this->integer)
		{
			cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
		}
		else if (!(this->integer))
		{
			cout << numerator << "/" << denominator << endl;
		}
		else
			cout << integer << endl;
	}


};

Fraction operator+(Fraction& left, Fraction& right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
	result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	left.to_proper();
	right.to_proper();
	left.reduce();
	right.reduce();
	result.to_proper();
	result.reduce();
	return result;
}
Fraction operator-(Fraction& left, Fraction& right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
	result.set_numerator(left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	left.to_proper();
	right.to_proper();
	left.reduce();
	right.reduce();
	result.to_proper();
	result.reduce();
	return result;
}
Fraction operator*(Fraction& left, Fraction& right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	left.to_proper();
	right.to_proper();
	left.reduce();
	right.reduce();
	result.to_proper();
	result.reduce();
	return result;
}
Fraction operator/(Fraction& left, Fraction& right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	left.to_proper();
	right.to_proper();
	left.reduce();
	right.reduce();
	result.to_proper();
	result.reduce();
	return result;
}

void main()
{
	setlocale(LC_ALL, "");
	Fraction a(10, 5);
	Fraction b(2, 5);
	a.to_proper();
	cout << "Переводим неправильную дробь в правильную: "; a.print();
	a.to_improper();
	cout << "Переводим правильную дробь в неправильную: "; a.print();
	a.reduce();
	cout << "Сокращаем дробь: "; a.print();
	a += b;
	a.print();
	a -= b;
	a.print();
	a *= b;
	a.print();
	a /= b;
	a.print();
	Fraction c = a + b;
	c.print();
	c = a - b;
	c.print();
	c = a * b;
	c.print();
	c = a / b;
	c.print();

}
	