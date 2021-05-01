#include"Fraction.h"


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
	cout << "Преобразование типов : " << endl;
	Fraction A(2, 3, 4);
	cout << A << endl;
	int m = (int)A;
	cout << m << endl;
	double n = (double)A;
	cout << n << endl;
	Fraction B = (Fraction)3;//Преобразование значения '3' типа 'int' во Fraction
	               //Это преобразование возможно благодаря конструктору с одним параметром
	cout << B << endl;
	B.to_proper();
	Fraction C = 0.185;
	C.print();
	cout << C << " = " << (double)C << endl;
}  
	