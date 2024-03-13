#include "Number.h"

class Integer : public Number
{
public:
	Integer();
	Integer(std::string);
	~Integer();

	std::string getAns()const;
	Fraction getFrac()const;

	std::string getInput()const;
	virtual void assign();
	virtual void print(std::ostream&)const;

	// origin : Integer& operator=
	Integer operator=(Integer);
	Integer operator=(DEcimal);
	//	Integer operator=(Complex&);	
	Integer& operator=(const string&);

	friend Integer operator+(Integer&, Integer&);
	friend Integer operator-(Integer&, Integer&);
	friend Integer operator*(Integer&, Integer&);
	friend Integer operator/(Integer&, Integer&);

	//	friend Complex Power(Integer& left, Integer& right);
	//	friend Complex Power(Integer& left, DEcimal& right);
	//	friend Complex Power(Integer& left, Complex& right);
	//	friend Complex Power(Integer& left, std::string& right);
	friend Integer Factorial(Integer& a);
	friend Integer Factorial(std::string& a);

	//private:
	std::string ans;
};

class DEcimal : public Number
{
public:
	DEcimal();
	DEcimal(std::string);
	~DEcimal();

	std::string getAns()const;
	Fraction getFrac()const;
	std::string getInput()const;
	virtual void assign();
	virtual void print(std::ostream&)const;

	DEcimal& operator=(Integer&);
	DEcimal& operator=(DEcimal&);
	//	DEcimal& operator=(Complex&);
	DEcimal& operator=(std::string&);

	friend DEcimal operator+(Integer&, DEcimal&);
	friend DEcimal operator+(DEcimal&, Integer&);
	friend DEcimal operator+(DEcimal&, DEcimal&);

	friend DEcimal operator-(Integer&, DEcimal&);
	friend DEcimal operator-(DEcimal&, Integer&);
	friend DEcimal operator-(DEcimal&, DEcimal&);

	friend DEcimal operator*(Integer&, DEcimal&);
	friend DEcimal operator*(DEcimal&, Integer&);
	friend DEcimal operator*(DEcimal&, DEcimal&);

	friend DEcimal operator/(Integer&, DEcimal&);
	friend DEcimal operator/(DEcimal&, Integer&);
	friend DEcimal operator/(DEcimal&, DEcimal&);

	//	friend Complex Power(DEcimal& left, Integer& right);
	//	friend Complex Power(DEcimal& left, DEcimal& right);
	//	friend Complex Power(DEcimal& left, Complex& right);
	//	friend Complex Power(DEcimal& left, std::string& right);
	friend Integer Factorial(DEcimal& a);

	//private:
	std::string ans;
};

class Complex : public Number
{
public:
	Complex();
	Complex(std::string);
	~Complex();

	std::string getAns()const;
	Fraction getFrac()const;
	std::string getInput()const;
	virtual void assign();
	virtual void print(std::ostream&)const;

	//  origin : Complex& operator=
	Complex operator=(Integer&);
	Complex operator=(DEcimal&);
	Complex operator=(Complex&);
	Complex operator=(std::string&);

	friend Complex operator+(Complex&, Complex&);
	friend Complex operator+(Complex&, Integer&);
	friend Complex operator+(Complex&, DEcimal&);
	friend Complex operator+(Integer&, Complex&);
	friend Complex operator+(DEcimal&, Complex&);

	friend Complex operator-(Complex&, Complex&);
	friend Complex operator-(Complex&, Integer&);
	friend Complex operator-(Complex&, DEcimal&);
	friend Complex operator-(Integer&, Complex&);
	friend Complex operator-(DEcimal&, Complex&);

	friend Complex operator*(Complex&, Complex&);
	friend Complex operator*(Complex&, Integer&);
	friend Complex operator*(Integer&, Complex&);
	friend Complex operator*(Complex&, DEcimal&);
	friend Complex operator*(DEcimal&, Complex&);

	friend Complex operator/(Complex&, Complex&);
	friend Complex operator/(Complex&, Integer&);
	friend Complex operator/(Integer&, Complex&);
	friend Complex operator/(Complex&, DEcimal&);
	friend Complex operator/(DEcimal&, Complex&);

	friend Complex Power(Complex& left, Integer& right);
	friend Complex Power(Complex& left, DEcimal& right);
	friend Complex Power(Complex& left, Complex& right);
	friend Complex Power(Complex& left, std::string& right);
	friend Integer Factorial(Complex& a);

private:
	std::string ans;

};

Integer::Integer() : Number()
{
	ans = "0";
}
Integer::Integer(string input) : Number(input)
{
	ans = getInt();
}
Integer::~Integer() {}

void Integer::assign()
{
	ans = getInt();
}

string Integer::getAns()const
{
	return ans;
}

Fraction Integer::getFrac()const
{
	return fracAns;
}

string Integer::getInput()const
{
	return input;
}

void Integer::print(ostream& out) const
{
	string ret = getAns();
	out << ret;
}

Integer& Integer::operator=(const string& r)
{
	setInput(r);
	computInput();
	assign();
	return *this;
}

Integer Integer::operator=(Integer r)
{
	errorTyep = r.errorTyep;
	fracAns = r.fracAns;
	input = r.input;
	assign();
	return *this;
}

Integer Integer::operator=(DEcimal r)
{
	errorTyep = r.errorTyep;
	fracAns = r.getFrac();
	input = r.getInput();
	assign();
	return *this;
}

//Integer Integer::operator=(Complex& r)
//{
//	errorTyep = r.errorTyep;
//	fracAns = r.getFrac();
//	input = r.getInput();
//	assign();
//	return *this;
//}



Integer operator+(Integer& left, Integer& right)
{
	Integer ret;
	ret.setInput(left.getInt() + '+' + right.getInt());
	ret.computInput();
	ret.assign();
	return ret;
}

Integer operator-(Integer& left, Integer& right)
{
	Integer ret;
	ret.setInput(left.getInt() + '-' + right.getInt());
	ret.computInput();
	ret.assign();
	return ret;
}

Integer operator*(Integer& left, Integer& right)
{
	Integer ret;
	ret.setInput(left.getInt() + '*' + right.getInt());
	ret.computInput();
	ret.assign();
	return ret;
}

Integer operator/(Integer& left, Integer& right)
{
	Integer ret;
	ret.setInput(left.getInt() + '/' + right.getInt());
	ret.computInput();
	ret.assign();
	return ret;
}
//Complex Power(Integer& left, Integer& right)
//{
//	Complex ret;
//	ret.setFrac( left.fracPow(left.posToStack(left.getInt()), right.posToStack(right.getInt())));
//	return ret;
//}
//Complex Power(Integer& left, DEcimal& right)
//{
//	Fraction ret = right.getReal();
//	Complex ret1;
//	if (ret.denominator == "0" || ret.denominator == "1" || (ret.denominator == "2" && ret.numerator == "1"))
//	{
//		ret = left.fracPow(left.posToStack(left.getInt()), ret);
//		ret1.setFrac(ret);
//		return ret1;
//	}
//	else
//	{
//		cout << "Illegal Pow(a,b)" << endl;
//		return ret1;
//	}
//}
//Complex Power(Integer& left, Complex& right)
//{
//	Fraction ret = right.getReal();
//	Complex ret1;
//	if (right.getComSign() == false && (ret.denominator == "0" || ret.denominator == "1" || (ret.denominator == "2" && ret.numerator == "1")))
//	{
//		ret1.setFrac(left.fracPow(left.posToStack(left.getInt()), ret));
//		return ret1;
//	}
//	else
//	{
//		cout << "Illegal Pow(a,b)" << endl;
//		return ret1;
//	}
//}
//Complex Power(Integer& left, string& right)
//{
//	Complex temp(right);
//	Fraction ret = temp.getReal();
//	Complex ret1;
//	if (temp.getComSign() == false && (ret.denominator == "0" || ret.denominator == "1" || (ret.denominator == "2" && ret.numerator == "1")))
//	{
//		ret1.setFrac(left.fracPow(left.posToStack(left.getInt()), ret));
//		return ret1;
//	}
//	else
//	{
//		cout << "Illegal Pow(a,b)" << endl;
//		return ret1;
//	}
//}

Integer Factorial(Integer& a)
{
	Fraction ret = a.posToStack(a.getInt());
	Integer ret1;
	if (ret.sign == false && (ret.denominator == "0" || ret.denominator == "1"))
	{
		ret1.setFrac(a.fracFac(ret));
		return ret1;
	}
	else
	{
		cout << "Illegal Fac(a)" << endl;
		return ret1;
	}
}

Integer Factorial(string& s)
{
	Complex temp(s);

	Integer ret1;
	Fraction ret = temp.getReal();
	if (temp.getComSign() == false && ret.sign == false && (ret.denominator == "1" || ret.denominator == "0"))
	{
		ret1.setFrac(ret1.fracFac(ret));
		return ret1;
	}
	else
	{
		cout << "Illegal Fac(a)" << endl;
		return ret1;
	}
}


//Constructor
DEcimal::DEcimal() :Number()
{
	assign();
}
DEcimal::DEcimal(string input) : Number(input)
{
	assign();
}
DEcimal::~DEcimal() {}

string DEcimal::getAns() const
{
	return ans;
}

Fraction DEcimal::getFrac()const
{
	return fracAns;
}

string DEcimal::getInput()const
{
	return input;
}

void DEcimal::assign()
{
	ans = getDec();
}

void DEcimal::print(ostream& out)const
{
	string ret = getAns();
	out << ret;
}


DEcimal& DEcimal::operator=(Integer& r)
{
	errorTyep = r.errorTyep;
	fracAns = r.getReal();
	input = r.getInput();
	assign();
	return *this;
}

DEcimal& DEcimal::operator=(DEcimal& r)
{
	errorTyep = r.errorTyep;
	fracAns = r.fracAns;
	input = r.input;
	assign();
	return *this;
}

//DEcimal& DEcimal::operator=(Complex& r)
//{
//	errorTyep = r.errorTyep;
//	fracAns = r.getReal();
//	input = r.getInput();
//	assign();
//	return *this;
//}

DEcimal& DEcimal::operator=(string& r)
{
	if (input == r)
		return *this;
	setInput(r);
	computInput();
	assign();
	return *this;
}

DEcimal operator+(Integer& left, DEcimal& right)
{
	return right + left;
}

DEcimal operator+(DEcimal& left, Integer& right)
{
	DEcimal ret;
	ret.fracAns = ret.fracAdd(left.getReal(), ret.posToStack(right.getInt()));
	ret.assign();
	return ret;
}
DEcimal operator+(DEcimal& left, DEcimal& right)
{
	DEcimal ret;
	ret.fracAns = ret.fracAdd(left.getReal(), right.getReal());
	ret.assign();
	return ret;
}

DEcimal operator-(Integer& left, DEcimal& right)
{
	DEcimal ret;
	ret.fracAns = ret.fracSub(ret.posToStack(left.getInt()), right.getReal());
	ret.assign();
	return ret;

}

DEcimal operator-(DEcimal& left, Integer& right)
{
	DEcimal ret;
	ret.fracAns = ret.fracSub(left.getReal(), right.posToStack(right.getInt()));
	ret.assign();
	return ret;

}

DEcimal operator-(DEcimal& left, DEcimal& right)
{
	DEcimal ret;
	ret.fracAns = ret.fracSub(left.getReal(), right.getReal());
	ret.assign();
	return ret;
}

DEcimal operator*(Integer& left, DEcimal& right)
{
	return right * left;
}

DEcimal operator*(DEcimal& left, Integer& right)
{
	DEcimal ret;
	ret.fracAns = ret.fracMul(left.getReal(), right.posToStack(right.getInt()));
	ret.assign();
	return ret;
}

DEcimal operator*(DEcimal& left, DEcimal& right)
{
	DEcimal ret;
	ret.fracAns = ret.fracMul(left.getReal(), right.getReal());
	ret.assign();
	return ret;
}

DEcimal operator/(Integer& left, DEcimal& right)
{
	DEcimal ret;
	ret.fracAns = ret.fracDiv(left.posToStack(left.getInt()), right.getReal());
	ret.assign();
	return ret;
}

DEcimal operator/(DEcimal& left, Integer& right)
{
	DEcimal ret;
	ret.fracAns = ret.fracDiv(left.getReal(), right.posToStack(right.getInt()));
	ret.assign();
	return ret;
}

DEcimal operator/(DEcimal& left, DEcimal& right)
{
	DEcimal ret;
	ret.fracAns = ret.fracDiv(left.getReal(), right.getReal());
	ret.assign();
	return ret;
}

Complex Power(DEcimal& left, Integer& right)
{
	Complex ret1;
	ret1.setFrac(left.fracPow(left.getReal(), right.posToStack(right.getInt())));
	return ret1;
}

Complex Power(DEcimal& left, DEcimal& right)
{
	Fraction ret = right.getReal();
	Complex ret1;
	if (ret.denominator == "0" || ret.denominator == "1" || (ret.denominator == "2" && ret.numerator == "1"))
	{
		ret1.setFrac(left.fracPow(left.getReal(), ret));
		return ret1;
	}
	else
	{
		cout << "Illegal Pow(a,b)" << endl;
		return ret1;
	}
}

Complex Power(DEcimal& left, Complex& right)
{
	Fraction ret = right.getReal();
	Complex ret1;
	if (right.getComSign() == false && (ret.denominator == "0" || ret.denominator == "1" || (ret.denominator == "2" && ret.numerator == "1")))
	{
		ret1.setFrac(left.fracPow(left.getReal(), ret));
		return ret1;
	}
	else
	{
		cout << "Illegal Pow(a,b)" << endl;
		return ret1;
	}
}

Complex Power(DEcimal& left, string& right)
{
	Complex temp(right);
	Fraction ret = temp.getReal();
	Complex ret1;
	if (temp.getComSign() == false && (ret.denominator == "0" || ret.denominator == "1" || (ret.denominator == "2" && ret.numerator == "1")))
	{
		ret1.setFrac(left.fracPow(left.getReal(), ret));
		return ret1;
	}
	else
	{
		cout << "Illegal Pow(a,b)" << endl;
		return ret1;
	}
}

Integer Factorial(DEcimal& a)
{
	Fraction ret = a.getReal();
	Integer ret1;
	if (ret.sign == false && (ret.denominator == "0" || ret.denominator == "1"))
	{
		ret1.setFrac(a.fracFac(ret));
		return ret1;
	}
	else
	{
		cout << "Illegal Fac(a)" << endl;
		return ret1;
	}
}

Complex::Complex() :Number()
{
	assign();
}
Complex::Complex(string input) : Number(input)
{
	assign();
}
Complex::~Complex() {}

string Complex::getAns()const
{
	return ans;
}

Fraction Complex::getFrac()const
{
	return fracAns;
}

string Complex::getInput()const
{
	return input;
}

void Complex::assign()
{
	ans = getCom();
}

void Complex::print(ostream& out)const
{
	string ret = getAns();
	out << ret;
}

Complex Complex::operator=(Integer& r)
{
	errorTyep = r.errorTyep;
	fracAns = r.getFrac();
	input = r.getInput();
	assign();
	return *this;
}

Complex Complex::operator=(DEcimal& r)
{
	errorTyep = r.errorTyep;
	fracAns = r.getFrac();
	input = r.getInput();
	assign();
	return *this;
}

Complex Complex::operator=(Complex& r)
{
	errorTyep = r.errorTyep;
	fracAns = r.fracAns;
	input = r.input;
	assign();
	return *this;
}

// origin Complex& Complex...
Complex Complex::operator=(string& r)
{
	if (input == r)
		return *this;
	setInput(r);
	computInput();
	assign();
	return *this;
}

Complex operator+(Complex& left, Complex& right)
{
	Complex ret;
	ret.fracAns = ret.fracAdd(left.getFrac(), right.getFrac());
	ret.assign();
	return ret;
}

Complex operator+(Complex& left, Integer& right)
{
	Complex ret = left;
	ret.fracAns = ret.fracAdd(ret.fracAns, ret.posToStack(right.getInt()));
	ret.assign();
	return ret;
}

Complex operator+(Integer& left, Complex& right)
{
	return right + left;
}

Complex operator+(Complex& left, DEcimal& right)
{
	Complex ret = left;
	ret.fracAns = ret.fracAdd(ret.fracAns, right.getReal());
	ret.assign();
	return ret;
}

Complex operator+(DEcimal& left, Complex& right)
{
	return right + left;
}

Complex operator-(Complex& left, Complex& right)
{
	Complex ret;
	ret.fracAns = ret.fracSub(left.getFrac(), right.getFrac());
	ret.assign();
	return ret;
}

Complex operator-(Complex& left, Integer& right)
{
	Complex ret;
	ret.fracAns = ret.fracSub(left.getFrac(), ret.posToStack(right.getInt()));
	ret.assign();
	return ret;

}

Complex operator-(Complex& left, DEcimal& right)
{
	Complex ret;
	ret.fracAns = ret.fracSub(left.getFrac(), right.getReal());
	ret.assign();
	return ret;
}

Complex operator-(Integer& left, Complex& right)
{
	Complex ret;
	ret.fracAns = ret.fracSub(ret.posToStack(left.getInt()), right.getFrac());
	ret.assign();
	return ret;
}
Complex operator-(DEcimal& left, Complex& right)
{
	Complex ret;
	ret.fracAns = ret.fracSub(left.getReal(), right.getFrac());
	ret.assign();
	return ret;
}

Complex operator*(Complex& left, Complex& right)
{
	Complex ret;
	ret.fracAns = ret.fracMul(left.getFrac(), right.getFrac());
	ret.assign();
	return ret;
}

Complex operator*(Complex& left, Integer& right)
{
	Complex ret;
	ret.fracAns = ret.fracMul(left.getFrac(), ret.posToStack(right.getInt()));
	ret.assign();
	return ret;
}

Complex operator*(Integer& left, Complex& right)
{
	return right * left;
}

Complex operator*(Complex& left, DEcimal& right)
{
	Complex ret;
	ret.fracAns = ret.fracMul(left.getFrac(), right.getReal());
	ret.assign();
	return ret;
}

Complex operator*(DEcimal& left, Complex& right)
{
	return right * left;
}

Complex operator/(Complex& left, Complex& right)
{
	Complex ret;
	ret.fracAns = ret.fracDiv(left.getFrac(), right.getFrac());
	ret.assign();
	return ret;
}

Complex operator/(Complex& left, Integer& right)
{
	Complex ret;
	ret.fracAns = ret.fracDiv(left.getFrac(), ret.posToStack(right.getInt()));
	ret.assign();
	return ret;
}

Complex operator/(Integer& left, Complex& right)
{
	Complex ret;
	ret.fracAns = ret.fracDiv(ret.posToStack(left.getInt()), right.getFrac());
	ret.assign();
	return ret;
}

Complex operator/(Complex& left, DEcimal& right)
{
	Complex ret;
	ret.fracAns = ret.fracDiv(left.getFrac(), right.getReal());
	ret.assign();
	return ret;
}

Complex operator/(DEcimal& left, Complex& right)
{
	Complex ret;
	ret.fracAns = ret.fracDiv(left.getReal(), right.getFrac());
	ret.assign();
	return ret;
}


Complex Power(Complex& left, Integer& right)
{
	Complex ret1;
	ret1.setFrac(left.fracPow(left.getFrac(), right.posToStack(right.getInt())));
	return ret1;
}

Complex Power(Complex& left, DEcimal& right)
{
	Fraction ret = right.getReal();
	Complex ret1;
	if (ret.denominator == "0" || ret.denominator == "1" || (ret.denominator == "2" && ret.numerator == "1"))
	{
		ret1.setFrac(left.fracPow(left.getFrac(), ret));
		return ret1;
	}
	else
	{
		cout << "Illegal Pow(a,b)" << endl;
		return ret1;
	}
}

Complex Power(Complex& left, Complex& right)
{
	Fraction ret = right.getReal();
	Complex ret1;
	if (right.getComSign() == false && (ret.denominator == "0" || ret.denominator == "1" || (ret.denominator == "2" && ret.numerator == "1")))
	{
		ret1.setFrac(left.fracPow(left.getFrac(), ret));
		return ret1;
	}
	else
	{
		cout << "Illegal Pow(a,b)" << endl;
		return ret1;
	}
}

Complex Power(Complex& left, string& right)
{
	Complex temp(right);
	Fraction ret = temp.getReal();
	Complex ret1;
	if (temp.getComSign() == false && (ret.denominator == "0" || ret.denominator == "1" || (ret.denominator == "2" && ret.numerator == "1")))
	{
		ret1.setFrac(left.fracPow(left.getFrac(), ret));
		return ret1;
	}
	else
	{
		cout << "Illegal Pow(a,b)" << endl;
		return ret1;
	}
}

Integer Factorial(Complex& a)
{
	Fraction ret = a.getReal();
	Integer ret1;
	if (a.getComSign() == false && ret.sign == false && (ret.denominator == "1" || ret.denominator == "0"))
	{
		ret1.setFrac(a.fracFac(ret));
		return ret1;
	}
	else
	{
		cout << "Illegal Fac(a)" << endl;
		return ret1;
	}
}