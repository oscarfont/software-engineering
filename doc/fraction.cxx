#include <iostream>
#include <string>

//Declaration of Template MCD function
template <class Type>
Type MCD(Type a, Type b){
	if( a%b == 0 ){
		return b;
	}else if (a % b > 0){
		MCD(b, a%b);
	}
}

//Specialization of above function
template <>
int MCD <int>(int a, int b){
	if( a%b == 0 ){
		return b;
	}else if (a % b > 0){
		MCD(b, a%b);
	}
}

//Declaration of Template Fraction class
template <class ElementType>
class Fraction {	
private:
	ElementType _num;
	ElementType _den;

public:

	Fraction(ElementType num, ElementType den){
		ElementType mcd = MCD(num, den);
		_num = num/mcd;
		_den = den/mcd;
	}

	ElementType num () const {return _num;}
	ElementType den () const {return _den;}

	Fraction<ElementType> operator+(const Fraction<ElementType> & other) const {

		ElementType n = this->num() * other.den() + this->den() * other.num();
		ElementType d = this->den() * other.den();
		Fraction<ElementType> res(n,d);

		return res;
	}

	Fraction<ElementType> operator* (const Fraction<ElementType> & other) const {

		ElementType n = this->num() * other.num();
		ElementType d = this->den() * other.den();
		Fraction<ElementType> res(n,d);

		return res;
	}

	void printFraction (){
		std::cout << std::to_string(this->num()) + "/" + std::to_string(this->den());
	}
};

//Specialization of above function
template <>
class Fraction<int> {
	int _num;
	int _den;
public:
	Fraction(int num, int den){
		int mcd = MCD(num, den);
		_num = num/mcd;
		_den = den/mcd;
	}

	int num () const {return _num;}
	int den () const {return _den;}

	Fraction<int> operator+(const Fraction<int> & other) const {
		
		int n = this->num() * other.den() + this->den() * other.num();
		int d = this->den() * other.den();
		Fraction<int> res (n,d);

		return res;
	}

	Fraction<int> operator* (const Fraction<int> & other) const {

		int n = this->num() * other.num();
		int d = this->den() * other.den();
		Fraction<int> res (n,d);

		return res;
	}

	void printFraction (){
		std::cout << std::to_string(this->num()) + "/" + std::to_string(this->den());
	}
};

//Main function to prove the program works correctly
int main(){

//-------------Example with two unsigned int fractions-------------

	unsigned int d1, n1, d2, n2;
	d1 = 6, n1 = 3, n2 = 1, d2 = 2;

	Fraction<unsigned int> f1(n1, d1);
	Fraction<unsigned int> f2(n2, d2);

	// Sum of Fractions
	std::cout << "Unsigned integers example:" << std::endl;
	Fraction<unsigned int> res1 = f1 + f2;
	f1.printFraction(); 
	std::cout << " + ";
	f2.printFraction();
	std::cout << " = ";
	res1.printFraction();
	std::cout << "\n";

	// Product of Fractions
	Fraction<unsigned int> res2 = f1*f2;
	f1.printFraction(); 
	std::cout << " * ";
	f2.printFraction();
	std::cout << " = ";
	res2.printFraction();
	std::cout << "\n";


//-------------Example with one byte fraction and one short fraction-------------

	char d2_1 = 2, n2_1 = 3;  //we use char to represent ints in one byte
	short d2_2 = 2, n2_2 = 1; 

	Fraction<int> f2_1(n2_1, d2_1);
	Fraction<int> f2_2(n2_2, d2_2);

	// Sum of Fractions
	std::cout << "One byte fraction and one short fraction example:" << std::endl;
	Fraction<int> res2_1 = f2_1 + f2_2;
	f2_1.printFraction(); 
	std::cout << " + ";
	f2_2.printFraction();
	std::cout << " = ";
	res2_1.printFraction();
	std::cout << "\n";

	// Product of Fractions
	Fraction<int> res2_2 = f2_1*f2_2;
	f2_1.printFraction(); 
	std::cout << " * ";
	f2_2.printFraction();
	std::cout << " = ";
	res2_2.printFraction();
	std::cout << "\n";


//-------------Example with one int fraction and one long long fraction-------------

	int d3_1, n3_1; 
	long d3_2, n3_2;
	d3_1 = 4, n3_1 = 2, n3_2 = 12, d3_2 = 2;

	Fraction<long> f3_1(n1, d1);
	Fraction<long> f3_2(n2, d2);

	// Sum of Fractions
	std::cout << "One int fraction and one long fraction example:" << std::endl;
	Fraction<long> res3_1 = f3_1 + f3_2;
	f3_1.printFraction(); 
	std::cout << " + ";
	f3_2.printFraction();
	std::cout << " = ";
	res3_1.printFraction();
	std::cout << "\n";

	// Product of Fractions
	Fraction<long> res3_2 = f3_1*f3_2;
	f3_1.printFraction(); 
	std::cout << " * ";
	f3_2.printFraction();
	std::cout << " = ";
	res3_2.printFraction();
	std::cout << "\n";

	return 0;
}