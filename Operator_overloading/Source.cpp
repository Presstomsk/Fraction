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
		if (x >= 0)this->integer = x;
		else this->integer = -x;
	}
	void set_numerator (int x)
	{
		if (x >= 0)this->numerator = x;
		else this->numerator = -x;
	}
	void set_denominator(int x)
	{
		if (x >= 0)this->denominator = x;
		else this->denominator = -x;
	}
	/*--------------------------------*/

	Fraction(int x = 0, int y = 0, int z=0)
	{
		this->integer = z;
		this->numerator = x;
		this->denominator = y;
		
	}
	Fraction(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->integer = other.integer;
	}
	~Fraction()
	{
		
	}
	/*-----------------------------------*/
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		return *this;
	}
	Fraction& operator+=(Fraction& other)
	{
		this->to_improper();
		other.to_improper();
		this->set_numerator(this->numerator*other.denominator + other.numerator*this->denominator);
		this->set_denominator(this->denominator * other.denominator);
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
		this->reduce();
		other.reduce();
		return *this;
	}
	Fraction& operator++()
	{
		this->to_improper();		
		this->set_numerator(this->numerator+this->denominator);
		this->reduce();
		return *this;

	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		this->to_improper();
		this->set_numerator(this->numerator + this->denominator);
		this->reduce();
		return old;
	}
	Fraction& operator--()
	{
		this->to_improper();
		this->set_numerator(this->numerator - this->denominator);
		this->reduce();
		return *this;

	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		this->to_improper();
		this->set_numerator(this->numerator - this->denominator);
		this->reduce();
		return old;
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
		int CommonMultiple;                                  
		do {
			if ((this->numerator < this->denominator) && (this->numerator != 0))
				CommonMultiple = this->numerator;
			else if (this->numerator > this->denominator)
				CommonMultiple = this->denominator;
			else break;
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
		else if (!(this->integer) && this->numerator)
		{
			cout << numerator << "/" << denominator << endl;
		}

		else
			cout << integer << endl;
	}


};

Fraction operator+(Fraction left, Fraction right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
	result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	result.reduce();
	return result;
}
Fraction operator-(Fraction left, Fraction right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
	result.set_numerator(left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	result.reduce();
	return result;
}
Fraction operator*(Fraction left, Fraction right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	result.reduce();
	return result;
}
Fraction operator/(Fraction left, Fraction right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	result.to_proper();
	result.reduce();
	return result;
}
/*------------------------------------------------------------*/
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() == right.get_numerator();
}
bool operator!=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() != right.get_numerator();
}
bool operator<=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() <= right.get_numerator();
}
bool operator>=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() >= right.get_numerator();
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() > right.get_numerator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() < right.get_numerator();
}
/*-------------------------------------------------------------*/
ostream& operator<<(ostream& os, const Fraction& obj)
{
	
		if (!(obj.get_numerator()))
			os << obj.get_integer();
		else if (!(obj.get_integer()) && obj.get_numerator())
			os << obj.get_numerator() << "/" << obj.get_denominator();
		else if (obj.get_integer() && obj.get_numerator())
			os << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";

		return os;
	
}
istream& operator>>(istream& is, Fraction& obj) //есть вопросы , нужно доработать
{
	int x, y;
	char c;
	is >> x >> c >> y;
	while(c != '/')
	{
		cout << "Введите корректное значение: "; is >> x >> c >> y;
	}
	obj.set_integer(0);
	obj.set_numerator(x);
	obj.set_denominator(y);
	return is;
}

void main() 
{
	setlocale(LC_ALL, "");
	Fraction a;
	cout << "Введите дробь 'a' в формате x/y: "; cin >> a;
	cout << "Вы ввели дробь 'a': "; cout << a ;
	a.to_proper();
	cout << endl;
	cout << "Переводим неправильную дробь в правильную: "; a.print();
	a.to_improper();
	cout << "Переводим правильную дробь в неправильную: "; a.print();
	a.reduce();
	cout << "Сокращаем дробь: "; a.print();
	Fraction b;
	cout << "Введите дробь 'b' в формате x/y: "; cin >> b;
	cout << "Вы ввели дробь 'b': "; cout << b << endl;
	cout << "Значение выражения (a+=b) равно : "; (a += b).print();
	cout << "Значение выражения (a-=b) равно : "; (a -= b).print();
	cout << "Значение выражения (a*=b) равно : "; (a *= b).print();
	cout << "Значение выражения (a/=b) равно : "; (a /= b).print();
	Fraction c = a + b;
	cout << "Значение выражения (a+b) равно : "; c.print();
	c = a - b;
	cout << "Значение выражения (a-b) равно : "; c.print();
	c = a * b;
	cout << "Значение выражения (a*b) равно : "; c.print();
	c = a / b;
	cout << "Значение выражения (a/b) равно : "; c.print();
	cout << "Значение выражения (++a) равно : "; (++a).print();
	cout << "Значение выражения (a++) равно : "; a++.print();
	cout << "Значение выражения (--a) равно : "; (--a).print();
	cout << "Значение выражения (a--) равно : "; a--.print();
	cout << "Значение выражения (a == b) равно : " << (a == b) << endl;
	cout << "Значение выражения (a != b) равно : " << (a != b) << endl;
	cout << "Значение выражения (a <= b) равно : " << (a <= b) << endl;
	cout << "Значение выражения (a >= b) равно : " << (a >= b) << endl;
	cout << "Значение выражения (a > b) равно : " << (a > b) << endl;
	cout << "Значение выражения (a < b) равно : " << (a < b) << endl;
	
}  
	