#include"Fraction.h"


int Fraction::get_integer() const
{
	return integer;
}
int Fraction::get_numerator() const
{
	return numerator;
}
int Fraction::get_denominator() const
{
	return denominator;
}
/*-------------------------------*/
void Fraction::set_integer(int x)
{
	if (x >= 0)this->integer = x;
	else this->integer = -x;
}
void Fraction::set_numerator(int x)
{
	if (x >= 0)this->numerator = x;
	else this->numerator = -x;
}
void Fraction::set_denominator(int x)
{
	/*if (x > 0) this->denominator = x;
	else if(x < 0) this->denominator = -x;
	else this->denominator = 1;*/
	if (x == 0)throw exception("Zero in denominator");//Ѕросаем исключение с сообщением об ошибке
	this->denominator = x;
}
/*--------------------------------*/
Fraction::Fraction()
{
	integer = 0;
	numerator = 0;
	denominator = 0;
	cout << "Constructor0:\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "Constructor1:\t" << this << endl;
}
Fraction::Fraction(double decimal)
{
	this->set_integer(0);
	this->set_denominator(1);
	this->set_numerator(decimal);
	for (; decimal - this->get_numerator() > 0; this->denominator *= 10)
	{
		this->numerator = decimal * this->denominator;
		decimal *= this->denominator;
	}
	this->reduce();
	cout << "Constructor1.1:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor2:\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor3:\t" << this << endl;

}
Fraction::Fraction(const Fraction& other)
{
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	this->integer = other.integer;
}
Fraction::~Fraction()
{

}
/*-----------------------------------*/
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	return *this;
}
Fraction& Fraction::operator+=(Fraction& other)
{
	this->to_improper();
	other.to_improper();
	this->set_numerator(this->numerator * other.denominator + other.numerator * this->denominator);
	this->set_denominator(this->denominator * other.denominator);
	this->reduce();
	other.reduce();
	return *this;
}
Fraction& Fraction::operator-=(Fraction& other)
{
	this->to_improper();
	other.to_improper();
	this->set_numerator(this->numerator * other.denominator - other.numerator * this->denominator);
	this->set_denominator(this->denominator * other.denominator);
	this->reduce();
	other.reduce();
	return *this;
}
Fraction& Fraction::operator*=(Fraction& other)
{
	this->to_improper();
	other.to_improper();
	this->set_numerator(this->numerator * other.numerator);
	this->set_denominator(this->denominator * other.denominator);
	this->reduce();
	other.reduce();
	return *this;
}
Fraction& Fraction::operator/=(Fraction& other)
{
	this->to_improper();
	other.to_improper();
	this->set_numerator(this->numerator * other.denominator);
	this->set_denominator(this->denominator * other.numerator);
	this->reduce();
	other.reduce();
	return *this;
}
Fraction& Fraction::operator++()
{
	this->to_improper();
	this->set_numerator(this->numerator + this->denominator);
	this->reduce();
	return *this;

}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	this->to_improper();
	this->set_numerator(this->numerator + this->denominator);
	this->reduce();
	return old;
}
Fraction& Fraction::operator--()
{
	this->to_improper();
	this->set_numerator(this->numerator - this->denominator);
	this->reduce();
	return *this;

}
Fraction Fraction::operator--(int)
{
	Fraction old = *this;
	this->to_improper();
	this->set_numerator(this->numerator - this->denominator);
	this->reduce();
	return old;
}

/*------------------------------------*/
void Fraction::to_proper()
{
	int i = 1;
	for (; this->numerator >= this->denominator; i++)
	{
		this->numerator = this->numerator - this->denominator;
		this->integer = i;
	}
}
void Fraction::to_improper()
{
	this->numerator = this->integer * this->denominator + this->numerator;
	this->integer = 0;
}
void Fraction::reduce()
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
void Fraction::print() const
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
Fraction::operator int()const
{
	return integer;
}
Fraction::operator double()const
{
	return (this->integer + (double)this->numerator / this->denominator);
}


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
	while (c != '/')
	{
		cout << "¬ведите корректное значение: "; is >> x >> c >> y;
	}
	obj.set_integer(0);
	obj.set_numerator(x);
	obj.set_denominator(y);
	return is;
}