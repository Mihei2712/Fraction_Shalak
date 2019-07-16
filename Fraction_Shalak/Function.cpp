#include"Function.h"

int Fraction::get_integer() const
{
	return this->integer;
}
int Fraction::get_numerator() const
{
	return this->numerator;
}
int Fraction::get_denominator() const
{
	return this->denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
//			Constructors:
Fraction::Fraction()
{
	this->integer = int();
	this->numerator = int();
	this->denominator = 1;
	cout << "DefConstruct:\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "SingleArgConstr:" << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyConstructor:" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t" << this << endl;
}

//			Operators:
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:" << this << endl;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction other)
{
	return *this = *this*other;
}

//			Increment/Decrement:
Fraction& Fraction::operator++()	//Prefix increment
{
	this->integer++;
	return *this;
}
Fraction Fraction::operator++(int) //Suffix increment
{
	Fraction temp = *this;
	this->integer++;
	return temp;
}

//			Type cast operators:
Fraction:: operator int()
{
	return this->integer;
}
Fraction::operator double()
{
	double decimal = integer + (double)numerator / denominator;
	return decimal;
}


//			Methods:
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::reduce()	//Сокращает простую дробь
{
	int more, less, reminder;
	if (numerator > denominator)
	{
		more = numerator;
		less = denominator;
	}
	else
	{
		more = denominator;
		less = numerator;
	}
	do
	{
		reminder = more % less;
		more = less;
		less = reminder;
	} while (reminder);
	int GCD = more;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
void Fraction::print()
{
	if (integer != 0)cout << integer;
	if (numerator != 0)
	{
		if (integer != 0)cout << "(" << numerator << "/" << denominator << ")";
		else cout << numerator << "/" << denominator;
	}
	if (integer == 0 && numerator == 0)cout << 0;
	cout << endl;
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	//Fraction result(left.get_numerator()*right.get_numerator(), left.get_denominator()*right.get_denominator());
	/*result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	//return result;
	return Fraction
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).reduce();
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator())
		return true;
	else
		return false;*/
	return left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer() != 0)os << obj.get_integer();
	if (obj.get_numerator() != 0)
	{
		if (obj.get_integer() != 0)os << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";
		else os << obj.get_numerator() << "/" << obj.get_denominator();
	}
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	return os;
}
