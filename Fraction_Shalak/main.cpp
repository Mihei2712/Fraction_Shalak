#include"Function.h"


//#define METHODS_CHECK
//#define OPERATORS_CHECK
#define TYPE_CONVERSIONS



void main()
{
	setlocale(LC_ALL, "");
#ifdef METHODS_CHECK
	Fraction A(1, 1, 2);
	cout << A << endl;
	cout << A.to_improper() << endl;
	cout << A.to_proper() << endl;
	Fraction B(54, 120);
	cout << B.reduce() << endl;
	cout << Fraction(120, 54).reduce().to_proper() << endl;
#endif // METHODS_CHECK

#ifdef OPERATORS_CHECK
	/*int a = 2;
int b = 3;
cout << a + b << endl;
Fraction A(10, 20);
Fraction B(30, 40);
cout << A << " * " << B << " = " << A*B << endl;
A *= B;
cout << A << endl;*/

	Fraction A(1, 2);
	Fraction B(5, 10);
	cout << (A == B) << endl;
	cout << (A != B) << endl;

	cout << ++A << endl;
	cout << A << endl;
#endif // OPERATORS_CHECK

#ifdef TYPE_CONVERSIONS
	cout << (int)'+' << endl;	//explicitly conversion from char to int (C-like notation)
	cout << char(444) << endl;	//explicitly conversion from int to char (Functional notation)

	int a = 2;		//no conversions
	//	Conversions from larger to smaller (possible loss of data):
	int b = 3.5;	//implicitly conversion from double to int (possible loss of data).
	int c = 5.;		//implicitly conversion from double to int (no data loss).
	//	Conversions from smaller to larger (impossible loss of data):
	double d = 5;	//implicitly conversion from int to double.
	Fraction A = (Fraction)5;	//implicitly conversion from int to Fraction. Single argument constructor.
	//cout << A << endl;
	Fraction B;
	B = Fraction(7);//explicitly conversion from int to Fraction.

	int f = (int)B;
	cout << f << endl;

	Fraction C(2, 3, 4);
	double weight = C;
	cout << weight << endl;
	//explicit
	float price = C;
	cout << price << endl;
#endif
}

//Single argument constructor