#pragma once
#include<iostream>
using namespace std;

class Fraction;

ostream& operator<<(ostream& os, const Fraction& obj);
Fraction operator*(Fraction left, Fraction right);
bool operator==(Fraction left, Fraction right);
bool operator!=(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;	//целая часть
	int numerator;	//числитель
	int denominator;//знаменатель
public:
	int get_integer() const;
	int get_numerator() const;
	int get_denominator() const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	Fraction();
	explicit Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction other);
	Fraction& operator++();	//Prefix increment

	Fraction operator++(int); //Suffix increment
	explicit operator int();
	operator double();
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction& reduce();	//Сокращает простую дробь
	void print();
};