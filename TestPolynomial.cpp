#include "LinkedPolynomial.h"
#include <iostream>

using namespace std;

LinkedPolynomial<double> CreatePolynomialFromInput()
{
	//Format used for geting information on a polynomial from user

	LinkedPolynomial<double> poly;
	double input1=1, input2=1;
	cout << "Type 0 for a coefficient to stop creating polynomial." << endl;
	while (input1 != 0)
	{
		cout << "Enter coefficient for term " << poly.GetCurrentSize()+1 << ": ";
		cin >> input1;
		if(input1==0)
			break;
		cout << "Enter exponent for term " << poly.GetCurrentSize()+1 << ": ";
		cin >> input2;
		poly.Add(input1,input2);
	}
	return poly;
}

void TestPolynomial()
{
	cout<< endl << "Create a polynomial:" << endl;
	LinkedPolynomial<double> poly1 = CreatePolynomialFromInput();
	double s, new_coef;
	cout << "Calling DisplayPolynomial():" <<endl;
	poly1.DisplayPolynomial(); cout << endl;
	cout << "The degree of this polynomial is " << poly1.Degree() << endl;
	cout << "Provide an exponent to search for it's corresponding coefficient:";
	cin >> s;
	cout << "The coefficient for that exponent is " << poly1.Coefficient(s) << endl;
	cout << "Please enter a new coefficient for exponent " << s << ": ";
	cin >> new_coef;
	cout << "ChangeCoefficient() returned " << poly1.ChangeCoefficient(new_coef,s) << endl;
	cout << "Calling DisplayPolynomial(): " <<endl;
	poly1.DisplayPolynomial(); cout << endl;
}

void TestAddition()
{
	//Makes user create two polynomials
	cout<< "Create polynomial A:" << endl;
	LinkedPolynomial<double> polyA = CreatePolynomialFromInput();
	cout << "Polynomial A is:" << endl;
	polyA.DisplayPolynomial();

	cout<< "Create polynomial B:" << endl;
	LinkedPolynomial<double> polyB = CreatePolynomialFromInput();
	cout << "Polynomial B is:" << endl;

	polyB.DisplayPolynomial();

	cout << endl << "Adding the two polynomials. The Sum is:" << endl;
	//Add both polynomials
	polyA.AddPolynomial(polyB);
	//Display the result of the addition (which polyA was changed to reflecr)
	polyA.DisplayPolynomial();

}

int main(int argc, const char * argv[])
{
	TestPolynomial();
	TestAddition();
	return 1;
}