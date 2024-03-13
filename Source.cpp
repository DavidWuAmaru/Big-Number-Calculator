/*

class Number
class Complex
class DEcimal
class Integer

class bigint...



int main()

*/

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const int priority[] = { 0,1,2,3,4,5,6 };
class Number;
class Integer;
class DEcimal;
class Complex;

struct ImagPart
{
	ImagPart& operator=(const ImagPart& r)
	{
		this->sign = r.sign;
		this->numerator = r.numerator;
		this->denominator = r.denominator;
		return *this;
	}
	bool sign = false; //�w�]������
	std::string numerator = "0";	//�곡���l
	std::string denominator = "0";	//�곡����
};

struct Fraction
{
	Fraction& operator=(const Fraction& r)
	{
		this->sign = r.sign;
		this->numerator = r.numerator;
		this->denominator = r.denominator;
		this->comSign = r.comSign;
		this->imag = r.imag;
		return *this;
	}
	Fraction()
	{
		numerator = "0";
		denominator = "0";
	}
	bool sign = false; //�w�]������
	std::string numerator = "0";	//���l
	std::string denominator = "0"; //����

	bool comSign = false; // �w�]�����O�Ƽ�
	ImagPart imag;//�곡
};
class Number
{
public:
	Number();
	Number(std::string);
	Number(const Number&);
	~Number();

	bool exist = true;


	std::string name;//�s�ܼƦW��
	int errorTyep = -1;//���~�s��

	void setInput(const std::string&);//��J�ƾǦ�	    // set integer A = 3.5 + 1.4 - 4.2 + (-45) + power(1,3)
	void computInput();//�B��	

	std::string printAns();//��X����(�t���b)	
	std::string getInt();
	std::string getDec();
	std::string getCom();
	Fraction getFrac();
	Fraction getReal();
	bool getComSign();

	void setFrac(Fraction);


	virtual void assign();
	virtual void print(std::ostream&)const;

	friend std::ostream& operator<<(std::ostream& outputStream, const Number&); //��X	
	friend std::istream& operator>> (std::istream& inputStream, Number&); //��J			


	//�Ƽơ�
	Fraction toImag(Fraction);//������곡				
	void imagToReal(Fraction, Fraction&);//�곡��곡	
	void realToImag(Fraction&, Fraction);//�곡��곡	
	Fraction comAdd(Fraction, Fraction);//�Ƽƥ[�k		
	Fraction comSub(Fraction, Fraction);//�Ƽƴ�k		
	Fraction comMul(Fraction, Fraction);//�Ƽƭ��k		
	Fraction comDiv(Fraction, Fraction);//�Ƽư��k		
	Fraction comPow(Fraction, Fraction);//�ƼƦ���		

	//�ڸ���
	Fraction comRoot(Fraction, bool);//�Ƽƶ}�ڸ�(���y�Ф�k)	
	Fraction fracRoot(Fraction, bool);//���ƶ}�ڸ�				

	//���ơ�
	Fraction posToStack(std::string);//���or�p�������		
	Fraction fracPow(Fraction, Fraction);//���Ʀ���		
	Fraction fracFac(Fraction);//����					
	Fraction fracAdd(Fraction, Fraction);//���ƥ[�k		
	Fraction fracSub(Fraction, Fraction);//���ƴ�k		
	Fraction fracMul(Fraction, Fraction);//���ƭ��k		
	Fraction fracDiv(Fraction, Fraction);//���ư��k		
	std::string gcd(std::string, std::string);//���̤j���]��	
	Fraction about(Fraction);//����						
	void changeSign(Fraction&);
	bool sign(std::string&);//���t���P�_						

	//��ơ�
	std::string getRoot120(std::string);//���o�@��ƶ}�ڸ��ܤp���I��150��		
	std::string printRoot(std::string);//�}�ڸ���X�p���I��100��				
	std::string mod(std::string, std::string);//�j�ƨ��l��		
	std::string pow(std::string, std::string);//�j�Ʀ���		
	std::string fac(std::string);//�j�ƶ���				
	int multiply(int x, std::vector<int>& ans, int res_size);
	std::string add(std::string, std::string);//�j�ƥ[�k	
	std::string sub(std::string, std::string);//�j�ƴ�k	
	std::string mul(std::string, std::string);//�j�ƭ��k	
	std::string div(std::string, std::string);//�j�ư��k	
	int cmp(std::string, std::string);//�j�Ƥ��		
	std::string get110Dec(Fraction);
	std::string get100Dec(Fraction);
	std::string get10Dec(Fraction);
protected:
	Fraction fracAns;
	std::string input;
};

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



struct N
{
	std::string bigNum;
	bool sign;
};

class BigIntAddSub
{
public:
	BigIntAddSub();
	BigIntAddSub(std::string);
	std::string bigIntAdd(N, N);
	std::string bigIntSub(N, N);
	N getNumber();

private:
	N num;
};
BigIntAddSub::BigIntAddSub()
{
	num.bigNum = "0";
	num.sign = false;
}

BigIntAddSub::BigIntAddSub(string a)
{
	if (a[0] == '-')
	{
		num.sign = true;//-
		a.erase(a.begin());
	}
	else
		num.sign = false;//+
	num.bigNum = a;
}

N BigIntAddSub::getNumber()
{
	return num;
}

string BigIntAddSub::bigIntAdd(N A, N B)
{
	N ans, temp;
	int size1 = A.bigNum.size(), size2 = B.bigNum.size();
	if (A.sign && !B.sign)
	{
		A.sign = false;//-A��+A
		ans.bigNum = bigIntSub(B, A);
		return ans.bigNum;
	}
	else if (!A.sign && B.sign)
	{
		B.sign = false;//-B��+B
		ans.bigNum = bigIntSub(A, B);
		return ans.bigNum;
	}
	else
	{
		if (size1 >= size2)
		{
			ans = A;
			temp = B;
		}
		else
		{
			ans = B;
			temp = A;
		}
	}
	size1 = ans.bigNum.size();
	size2 = temp.bigNum.size();
	int i = size1 - 1, j = size2 - 1;

	for (i; i >= 0; i--, j--)
	{
		if (j >= 0)
			ans.bigNum[i] += temp.bigNum[j] - '0';
		if (ans.bigNum[i] > '9')
		{
			ans.bigNum[i] -= 10;
			if (i > 0)
				ans.bigNum[i - 1] += 1;
			else if (i == 0)
				ans.bigNum.insert(ans.bigNum.begin(), '1');
		}
	}
	if (ans.sign)
		return "-" + ans.bigNum;
	else
		return ans.bigNum;
}

string BigIntAddSub::bigIntSub(N A, N B)
{
	N ans, temp;
	int token = 0;//������ƬۦP�ɱq�Y��_�Ĥ@�Ӥ��P���Ʀr
	int size1 = A.bigNum.size(), size2 = B.bigNum.size();
	if (A.sign && !B.sign)//-A - B = -A + -B
	{
		B.sign = true;
		ans.bigNum = bigIntAdd(A, B);
		return ans.bigNum;
	}
	else if (!A.sign && B.sign)//A - -B = A + B
	{
		B.sign = false;
		ans.bigNum = bigIntAdd(A, B);
		return ans.bigNum;
	}
	else if (A.sign && B.sign)//-A - -B= -A + B = B-A
	{
		A.sign = B.sign = false;
		ans.bigNum = bigIntSub(B, A);
		return ans.bigNum;
	}
	else if (!A.sign && !B.sign)//A - B
	{
		if (size1 > size2)
		{
			ans = A;
			temp = B;
		}
		else if (size1 < size2)
		{
			ans = B;
			ans.sign = true;
			temp = A;
			size1 = ans.bigNum.size();
			size2 = temp.bigNum.size();
		}
		else if (size1 == size2)
		{
			for (int i = 0; i < size1; i++)
			{
				if (A.bigNum[i] > B.bigNum[i])
				{
					ans = A;
					temp = B;
					break;
				}
				else if (A.bigNum[i] < B.bigNum[i])
				{
					ans = B;
					temp = A;
					size1 = ans.bigNum.size();
					size2 = temp.bigNum.size();
					ans.sign = true;
					break;
				}
				else if (i == size1 - 1)
					return "0";
				token = i;
			}
		}
	}
	int i = size1 - 1, j = size2 - 1;
	for (i; i >= 0; i--, j--)
	{
		if (j >= 0)
			ans.bigNum[i] -= temp.bigNum[j] - '0';
		if (ans.bigNum[i] < '0')
		{
			ans.bigNum[i] += 10;
			if (i > 0)
				ans.bigNum[i - 1] -= 1;
		}
	}

	for (; ans.bigNum.size() > 1;)
	{
		if (ans.bigNum[0] == '0')
			ans.bigNum.erase(ans.bigNum.begin());
		else
			break;
	}
	if (ans.sign)
		return "-" + ans.bigNum;
	else
		return ans.bigNum;
}


// ********************** class Number *************************

void Number::setInput(const string& line)
{
	input.clear();
	istringstream ss(line);
	string in, temp;
	//�����Ů�
	while (ss >> in)
		temp += in;
	//�N�t���ন'!'
	for (int i = 0; i < temp.size(); i++)
	{
		if (i != temp.size() - 1)
		{
			//i������0�Btemp[i]����'-'  ��  temp[i]='-'�Btemp[i+1]='-'
			if ((!i && temp[i] == '-') || ((temp[i] < '0' || temp[i] == '^') && temp[i] != ')' && temp[i + 1] == '-'))
			{
				if (i && temp[i] != '-' || ((temp[i] < '0' || temp[i] == '^') && temp[i] != ')' && temp[i + 1] == '-'))
					input += temp[i++];	//input += '-'(�)
				input += '#';			//input += '#'(�t��)
				continue;
			}
		}
		input += temp[i];
	}
}

//�P�_�r��B�ഫ��Ǧ�
void Number::computInput()
{


	//   infix �� postfix	

	vector<string> _operator, postfix;//stack���|  _operator(���|�����B��l)  postfix(��Ǧ�)
	vector<int> operatorPriority;//�s���|���B��l���u������
	int nowPriority;//�s���e�B��l�u������
	for (int i = 0; i < input.size(); i++)
	{
		//�J�B�⤸������X�� postfix(��Ǧ�)
		if (input[i] <= '9' && input[i] >= '0' || input[i] == '.')
		{
			string temp;
			int j = i;
			while (j < input.size() && (input[j] <= '9' && input[j] >= '0' || input[j] == '.'))
			{
				temp += input[j];//���e�B�⤸
				j++;
			}
			postfix.push_back(temp);
			i = j - 1;
		}
		//�J�k�A��')'��Xstack����operator��')'
		else if (input[i] == ')')
		{
			while (!_operator.empty())
			{
				int top = _operator.size() - 1;
				if (_operator[top] == "(") {
					_operator.pop_back();
					operatorPriority.pop_back();
					break;
				}
				postfix.push_back(_operator[top]);
				_operator.pop_back();
				operatorPriority.pop_back();
			}
		}
		//��L���p�G����B��l�u�����ǡA�çP�_�n�s�J�B��l���|�ο�X�ܫ�Ǧ�
		else {
			switch (input[i])
			{
			case'(':	//���A���u���סG6
				nowPriority = priority[6];
				break;
			case'#':	//�t�����u���סG5
				nowPriority = priority[5];
				break;
			case'i':	//�곡�u���סG4
				nowPriority = priority[4];
				break;
			case'!':	//�����u���סG3
				nowPriority = priority[3];
				break;
			case'^':	//�����u���סG2
				nowPriority = priority[2];
				break;
			case'*':	//�������u���סG1
				nowPriority = priority[1];
				break;
			case'/':	//�������u���סG1
				nowPriority = priority[1];
				break;
			case'+':	//�[�����u���סG0
				nowPriority = priority[0];
				break;
			case'-':	//����u���סG0
				nowPriority = priority[0];
				break;
			}
			//stack�̤W��B��l�u���� �j�󵥩� ���e�B��l�u���� �� ��X��postfix(��Ǧ�)
			//�Y�̤W��B��l�����A���A�h�������|�B��l
			if (!operatorPriority.empty())
			{
				while (operatorPriority[operatorPriority.size() - 1] != 6
					&& operatorPriority[operatorPriority.size() - 1] >= nowPriority)
				{
					postfix.push_back(_operator[_operator.size() - 1]);
					_operator.pop_back();
					operatorPriority.pop_back();
					if (operatorPriority.empty())
						break;
				}
			}
			string operat;//���|operator
			operat = input[i];//char ��s string
			_operator.push_back(operat);//���|���e�B��l��_operator
			operatorPriority.push_back(nowPriority);//���|�B��l�u���צ�operatorPriority
		}
	}
	while (!(_operator.empty()))
	{
		postfix.push_back(_operator[_operator.size() - 1]);
		_operator.pop_back();
		operatorPriority.pop_back();
	}

	//�B���Ǧ�
	vector<Fraction> stack;//stack[���|�����j��(���ƫ��A)]
	for (int i = 0; i < postfix.size(); i++)
	{
		if ((postfix[i][0] < '0' || postfix[i][0] == '^' || postfix[i][0] == 'i') && !stack.empty())
		{
			if (postfix[i][0] == '#') //�t��
			{
				changeSign(stack[stack.size() - 1]);
			}
			else if (postfix[i][0] == 'i') //�곡
			{
				stack[stack.size() - 1] = toImag(stack[stack.size() - 1]);
			}
			else if (postfix[i][0] == '!')
			{
				stack[stack.size() - 1] = fracFac(stack[stack.size() - 1]);
			}
			else if (stack.size() >= 2)
			{
				switch (postfix[i][0])
				{
				case'+':
					stack[stack.size() - 2] = fracAdd(stack[stack.size() - 2], stack[stack.size() - 1]);
					stack.pop_back();
					break;
				case'-':
					stack[stack.size() - 2] = fracSub(stack[stack.size() - 2], stack[stack.size() - 1]);
					stack.pop_back();
					break;
				case'*':
					stack[stack.size() - 2] = fracMul(stack[stack.size() - 2], stack[stack.size() - 1]);
					stack.pop_back();
					break;
				case'/':
					stack[stack.size() - 2] = fracDiv(stack[stack.size() - 2], stack[stack.size() - 1]);
					stack.pop_back();
					break;
				case'^':
					stack[stack.size() - 2] = fracPow(stack[stack.size() - 2], stack[stack.size() - 1]);
					stack.pop_back();
					break;
				default:
					break;
				}
			}
		}
		else
		{
			stack.push_back(posToStack(postfix[i]));
		}

		if (i == postfix.size() - 1)
			fracAns = stack[0];
	}
}

/***********************************************
***************** �� �Ƽƹ�@ �� ***************
************************************************/
//������곡
Fraction Number::toImag(Fraction f)
{
	if (f.denominator == "0" && f.numerator == "0")
		return f;
	f.comSign = true;

	f.imag.denominator = f.denominator;
	f.imag.numerator = f.numerator;
	f.imag.sign = f.sign;
	f.sign = false;
	f.denominator = f.numerator = "0";
	return f;
}

//�곡��곡
void Number::imagToReal(Fraction f, Fraction& a)
{
	a.numerator = f.imag.numerator;
	a.denominator = f.imag.denominator;
	a.sign = f.imag.sign;
	return;
}

//�곡��곡
void Number::realToImag(Fraction& f, Fraction a)
{
	if (a.numerator == "0" && a.denominator == "0")
	{
		f.imag.numerator = "0";
		f.imag.denominator = "0";
		f.comSign = false;
		return;
	}
	f.imag.numerator = a.numerator;
	f.imag.denominator = a.denominator;
	f.imag.sign = a.sign;
	f.comSign = true;
	return;
}

//�Ƽƥ[�k
Fraction Number::comAdd(Fraction left, Fraction right)
{
	Fraction ans, a, b;
	left.comSign = right.comSign = false;
	imagToReal(left, a);
	imagToReal(right, b);

	ans = fracAdd(left, right); //�곡�ۥ[
	a = fracAdd(a, b); //�곡�ۥ[

	realToImag(ans, a);
	if (ans.imag.numerator != "0" && ans.imag.denominator != "0")
		ans.comSign = true;
	return ans;
}

//�Ƽƴ�k
Fraction Number::comSub(Fraction left, Fraction right)
{
	Fraction ans, a, b;
	left.comSign = right.comSign = false;
	imagToReal(left, a);
	imagToReal(right, b);

	ans = fracSub(left, right); //�곡�۴�
	a = fracSub(a, b); //�곡�۴�

	realToImag(ans, a);
	if (ans.imag.numerator != "0" && ans.imag.denominator != "0")
		ans.comSign = true;
	return ans;
}

//�Ƽƭ��k
Fraction Number::comMul(Fraction left, Fraction right)
{
	Fraction ans, a, b;
	left.comSign = right.comSign = false;
	imagToReal(left, a);
	imagToReal(right, b);
	Fraction t1 = fracMul(left, right), t2 = fracMul(a, b);
	ans = fracSub(fracMul(left, right), fracMul(a, b));	//�곡
	a = fracAdd(fracMul(left, b), fracMul(right, a));	//�곡
	if (a.denominator != "0")
		a = about(a);
	if (ans.denominator != "0")
		ans = about(ans);

	realToImag(ans, a);
	if (ans.imag.numerator != "0" && ans.imag.denominator != "0")
		ans.comSign = true;
	return ans;
}

//�Ƽư��k
Fraction Number::comDiv(Fraction left, Fraction right)
{
	Fraction ans, temp, a, b, p;
	left.comSign = right.comSign = false;
	imagToReal(left, a);
	imagToReal(right, b);
	// p=2
	p.numerator = "2";
	p.denominator = "1";

	ans = fracAdd(fracMul(left, right), fracMul(a, b));	//�곡
	temp = fracSub(fracMul(right, a), fracMul(left, b));//�곡

	Fraction t1 = fracAdd(fracPow(right, p), fracPow(b, p)), t2 = fracPow(right, p), t3 = fracPow(b, p);

	ans = fracDiv(ans, fracAdd(fracPow(right, p), fracPow(b, p))); //�곡
	temp = fracDiv(temp, fracAdd(fracPow(right, p), fracPow(b, p))); //�곡

	realToImag(ans, temp);
	if (ans.imag.numerator != "0" && ans.imag.denominator != "0")
		ans.comSign = true;
	return ans;
}

//�ƼƦ���
Fraction Number::comPow(Fraction a, Fraction b)
{
	if (b.numerator == "1" && b.denominator == "2")
		return comRoot(a, b.sign);
	else if (b.denominator == "0")
	{
		Fraction f;
		f.numerator = f.denominator = "1";
		return f;
	}
	else if (b.denominator != "1")
		cout << "Illegal Power(a,b)" << endl;

	//if (right == "0.5" || right == "1/2")  return root(left);
	int tempPow = 0, count = 0;

	for (int i = 0; i < b.numerator.size(); i++)   //�r������
	{
		tempPow *= count;
		tempPow += (b.numerator[i] - '0');
		count = 10;
	}

	Fraction ans, t, temp;
	Fraction basisTwo = comMul(a, a);  //�G����
	string ts = "0.";
	ts.insert(ts.end(), 110, '0');
	imagToReal(basisTwo, t);
	if (get110Dec(t) == ts)
		realToImag(basisTwo, temp);
	if (get110Dec(basisTwo) == ts)
	{
		imagToReal(temp, basisTwo);
	}

	int i;
	if (tempPow % 2 == 0)
	{
		ans = basisTwo;
		i = 1;
	}
	else
	{
		ans = a;
		i = 0;
	}
	tempPow /= 2;

	for (i; i < tempPow; i++)
	{
		imagToReal(basisTwo, t);
		if (get110Dec(t) == ts)
			realToImag(basisTwo, temp);
		if (get110Dec(basisTwo) == ts)
		{
			imagToReal(temp, basisTwo);
		}
		ans = comMul(ans, basisTwo);
	}

	if (b.sign)
	{
		Fraction i;
		i.numerator = i.denominator = "1";
		return comDiv(i, ans);
	}

	return ans;
}


/***********************************************
***************** �� �Ƽƹ�@ �� ***************
************************************************/



/***********************************************
***************** �� �ڸ���@ �� ***************
************************************************/

//���ƶ}�ڸ�
Fraction Number::fracRoot(Fraction f, bool sign)
{
	if (f.comSign)
		return comRoot(f, sign);
	if (f.sign)
	{
		Fraction t;
		f.sign = false;
		f = fracRoot(f, sign);
		realToImag(t, f);
		return t;
	}
	string t1, t2, s;
	t1 = getRoot120(f.numerator);
	t2 = getRoot120(f.denominator);
	s.insert(s.end(), 50, '0');
	size_t f1, f2;
	f1 = t1.find('.');
	f2 = t2.find('.');
	if (t1.substr(f1 + 1, 50) == s && t2.substr(f2 + 1, 50) == s)
	{
		f.numerator.assign(t1.begin(), t1.begin() + f1);
		f.denominator.assign(t2.begin(), t2.begin() + f2);
		if (sign)
		{
			string temp = f.denominator;
			f.denominator = f.numerator;
			f.numerator = temp;
		}
		return f;
	}
	else
	{
		t1.erase(f1, 1);
		t2.erase(f2, 1);
		if (sign)
			f.numerator = t2, f.denominator = t1;
		else
			f.numerator = t1, f.denominator = t2;
	}
	if (f.denominator != "0")
		f = about(f);
	return f;
}

//�Ƽƶ}�ڸ�
Fraction Number::comRoot(Fraction a, bool sign)
{
	//a:�곡 b:�곡
	//t1: x^2+y^2 = root(a^2+b^2)
	//t2: 2*x*y = b
	Fraction x, y, b, t1, t, p;
	a.comSign = false;
	imagToReal(a, b);
	p.numerator = "2", p.denominator = "1";
	bool k = false;
	t1 = fracRoot(fracAdd(fracPow(a, p), fracPow(b, p)), k);
	t = fracRoot(fracAdd(t1, b), k);
	b = fracRoot(fracSub(t1, b), k);
	if (a.sign)
	{
		x = fracDiv(fracSub(t, b), p);
		y = fracSub(t, x);
		realToImag(x, y);
	}
	else
	{
		y = fracDiv(fracSub(t, b), p);
		x = fracSub(t, y);
		realToImag(x, y);
	}
	p.numerator = "1";

	if (sign)
		return fracDiv(p, x);
	return x;
}

/***********************************************
***************** �� �ڸ���@ �� ***************
************************************************/



/***********************************************
***************** �� ���ƹ�@ �� ***************
************************************************/
//��Ǧ�string �ন���l�B��������
Fraction Number::posToStack(string pos)
{
	//�P�_�O�_���p��
	int index = 0;
	for (int i = 0; i < pos.size() - 1; i++)
	{
		if (pos[i] == '.')
		{
			index = i;
			break;
		}
	}
	Fraction f;
	if (index == 0 || pos == "0")
	{
		if (pos != "0")
		{
			f.numerator.assign(pos);
			f.denominator = "1";
		}
		else
			f.denominator = "0";
	}
	else
	{
		string a = "1";
		pos.erase(pos.begin() + index);
		for (int i = pos.size() - index; i > 0; i--)
			a.push_back('0');
		f.denominator.assign(a);
		while (pos.size())
		{
			if (pos[0] == '0')
				pos.erase(pos.begin());
			else if (pos[0] != '0')
				break;
		}
		f.numerator.assign(pos);
	}
	if (f.denominator != "0")
		f = about(f);//����
	return f;
}

//�t��
void Number::changeSign(Fraction& f)
{
	if (f.numerator != "0" && f.denominator != "0")
		f.sign = !f.sign;
	if (f.comSign)
		if (f.imag.numerator != "0" && f.imag.denominator != "0")
			f.imag.sign = !f.imag.sign;
}

//����
Fraction Number::about(Fraction f)
{
	if (f.numerator.size() > 150 && f.denominator.size() > 150)
	{
		long long s1 = f.numerator.size(), s2 = f.denominator.size();
		s1 -= s2;
		f.numerator.erase(f.numerator.begin() + 150 + s1, f.numerator.end());
		f.denominator.erase(f.denominator.begin() + 150, f.denominator.end());
	}
	string g = gcd(f.numerator, f.denominator);
	int c1 = cmp(g, f.numerator), c2 = cmp(g, f.denominator);
	f.numerator = div(f.numerator, g);
	f.denominator = div(f.denominator, g);

	return f;
}

//�̤j���]��GCD
string Number::gcd(string a, string b)
{
	if (b == "0")
		return a;
	else
		return gcd(b, mod(a, b));
}

//���l�� left%right
string Number::mod(string left, string right)
{
	string a = left;
	a += 'r';//�[�@�ӧP�_�r��
	return div(a, right);
}

//���t���P�_
bool Number::sign(string& str)
{
	bool s = false;
	if (str[0] == '-')
	{
		s = true;
		str.erase(str.begin());
	}
	return s;
}

//���Ʀ���
Fraction Number::fracPow(Fraction a, Fraction b)
{


	if ((b.denominator != "1" && b.denominator != "0") && !(b.numerator == "1" && b.denominator == "2") ||
		(b.comSign && b.imag.denominator != "0"))
	{
		if (errorTyep == -1)
			errorTyep = 2;
		return a;
	}
	if (a.comSign)
		return comPow(a, b);
	if (b.numerator == "1" && b.denominator == "2")
		return fracRoot(a, b.sign);
	else if (b.denominator == "0")
	{
		a.numerator = a.denominator = "1";
		a.sign = false;
		return a;
	}
	if (mod(b.numerator, "2") == "0")
		a.sign = false;

	a.numerator = pow(a.numerator, b.numerator);
	a.denominator = pow(a.denominator, b.numerator);

	if (a.denominator != "0")
		a = about(a);//����

	if (b.sign)
	{
		string temp;
		temp = a.denominator;
		a.denominator = a.numerator;
		a.numerator = temp;
	}
	return a;
}

//����
Fraction Number::fracFac(Fraction f)
{
	string s = get100Dec(f);
	f = posToStack(s);
	if (f.denominator == "0" && f.numerator == "0")
	{
		Fraction ret;
		ret.numerator = "1";
		ret.denominator = "1";
		return ret;
	}

	if (f.denominator != "1" || f.comSign == true || f.sign)
	{
		if (errorTyep == -1)
			errorTyep = 1;
	}
	else
		f.numerator = fac(f.numerator);
	return f;
}

//���ƥ[�k
Fraction Number::fracAdd(Fraction left, Fraction right)
{
	if (left.comSign || right.comSign)
		return comAdd(left, right);
	Fraction f;
	//�٭�t��
	if (left.sign)
		left.numerator.insert(0, "-");
	if (right.sign)
		right.numerator.insert(0, "-");

	int c = cmp(left.denominator, right.denominator);
	if (c == 0)//�Y�����ۦP�A���l�����ۥ[
	{
		f.numerator = add(left.numerator, right.numerator);
		f.denominator = left.denominator;
	}
	else if (left.numerator == "0" && left.denominator == "0")
	{
		right.sign = sign(right.numerator);
		return right;
	}
	else if (right.numerator == "0" && right.denominator == "0")
	{
		left.sign = sign(left.numerator);
		return left;
	}
	else//�Y�������ۦP�A�q����ۥ[
	{
		f.denominator = mul(left.denominator, right.denominator);
		left.numerator = mul(left.numerator, right.denominator);
		right.numerator = mul(right.numerator, left.denominator);
		f.numerator = add(left.numerator, right.numerator);
	}
	f.sign = sign(f.numerator);
	if (f.numerator == "0")
		f.denominator = "0";
	if (f.denominator != "0")
		f = about(f);//����
	return f;
}

//���ƴ�k
Fraction Number::fracSub(Fraction left, Fraction right)
{
	if (left.comSign || right.comSign)
		return comSub(left, right);
	Fraction f;
	//�٭�t��
	if (left.sign)
		left.numerator.insert(0, "-");
	if (right.sign)
		right.numerator.insert(0, "-");

	int c = cmp(left.denominator, right.denominator);
	if (c == 0)//�Y�����ۦP�A���l�����ۥ[
	{
		f.numerator = sub(left.numerator, right.numerator);
		f.denominator = left.denominator;
	}
	else if (left.numerator == "0" && left.denominator == "0")
	{
		right.sign = !sign(right.numerator);
		return right;
	}
	else if (right.numerator == "0" && right.denominator == "0")
	{
		left.sign = sign(left.numerator);
		return left;
	}
	else//�Y�������ۦP�A�q����۴�
	{
		f.denominator = mul(left.denominator, right.denominator);
		left.numerator = mul(left.numerator, right.denominator);
		right.numerator = mul(right.numerator, left.denominator);
		f.numerator = sub(left.numerator, right.numerator);
	}
	f.sign = sign(f.numerator);
	if (f.numerator == "0")
		f.denominator = "0";
	if (f.denominator != "0")
		f = about(f);//����
	return f;
}

//���ƭ��k
Fraction Number::fracMul(Fraction left, Fraction right)
{
	if (left.comSign || right.comSign)
		return comMul(left, right);
	Fraction f;
	if (left.sign && right.sign)
		f.sign = false;
	else if (left.sign || right.sign)
		f.sign = true;
	else f.sign = false;



	f.numerator = mul(left.numerator, right.numerator);
	f.denominator = mul(left.denominator, right.denominator);

	if (f.numerator == "0" && f.denominator == "0")
		f.sign = false;

	if (f.denominator != "0")
		f = about(f);//����
	return f;
}

//���ư��k
Fraction Number::fracDiv(Fraction left, Fraction right)
{
	if (right.denominator == "0" && right.imag.denominator == "0")
	{
		if (errorTyep == -1)
			errorTyep = 3;
		return left;
	}
	if (left.comSign || right.comSign)
		return comDiv(left, right);
	Fraction f;
	if (left.sign && right.sign)
		f.sign = false;
	else if (left.sign || right.sign)
		f.sign = true;
	else f.sign = false;

	//���ۭ������� �~�ۭ������l

	f.numerator = mul(left.numerator, right.denominator);
	f.denominator = mul(left.denominator, right.numerator);

	if (f.denominator != "0")
		f = about(f);//����
	return f;
}
/***********************************************
***************** �� ���ƹ�@ �� ***************
************************************************/



/***********************************************
***************** �� ��ƹ�@ �� ***************
************************************************/
//�j�Ʀ���
string Number::pow(string left, string right)
{
	if (right == "1")
		return left;
	if (right == "2")
		return mul(left, left);

	int tempPow = 0, count = 10;

	for (int i = 0; i < right.size(); i++)   //�r������
	{
		tempPow *= count;
		tempPow += (right[i] - '0');
	}

	int ret = tempPow / 2;
	return mul(pow(left, to_string(ret)), pow(left, to_string(tempPow - ret)));
	//}
	////if (right == "0.5" || right == "1/2")  return root(left);
	//if (right == "0") return "1";

	//int tempPow = 0, count = 10;

	//for (int i = 0; i < right.size(); i++)   //�r������
	//{
	//	tempPow *= count;
	//	tempPow += (right[i] - '0');
	//}

	//string ans;
	//int i;
	//if (tempPow % 2 == 0)
	//{
	//	ans = mul(left, left);
	//	i = 1;
	//}
	//else
	//{
	//	ans = left;
	//	i = 0;
	//}
	//tempPow /= 2;

	//string basisTwo = mul(left, left);  //�G����

	//for (i; i < tempPow; i++)
	//	ans = mul(ans, basisTwo);

	//return ans;
}

//�j�ƶ���
string Number::fac(string str)
{
	int n = 0, count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		n *= count;
		n += (str[i] - '0');
		count = 10;
	}
	vector<int> ans;
	ans.push_back(1);
	int res_size = 1;
	for (int x = 2; x <= n; x++)
		res_size = multiply(x, ans, res_size);

	str.clear();
	for (int i = res_size - 1; i >= 0; i--)
		str += ans[i] + '0';
	return str;
}

//����function
int Number::multiply(int x, vector<int>& ans, int res_size)
{
	int carry = 0;
	for (int i = 0; i < res_size; i++)
	{
		int prod = ans[i] * x + carry;
		ans[i] = prod % 10;
		carry = prod / 10;
	}
	while (carry)
	{
		ans.push_back(carry % 10);
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}

//�j�ƥ[�k left+fight
string Number::add(string left, string right)
{
	BigIntAddSub A(left), B(right);
	return A.bigIntAdd(A.getNumber(), B.getNumber());
}

//�j�ƴ�k left-right
string Number::sub(string left, string right)
{
	BigIntAddSub A(left), B(right);
	return A.bigIntSub(A.getNumber(), B.getNumber());
}

//�j�ƭ��k left*right
string Number::mul(string left, string right)
{
	//�P�_���t��
	bool mulSign = false;//�s���t���Adefault������(false)
	if (left[0] == '-' && right[0] == '-')
	{
		left.erase(left.begin());
		right.erase(right.begin());
	}
	else if (left[0] == '-')
	{
		left.erase(left.begin());
		mulSign = true;
	}
	else if (right[0] == '-')
	{
		right.erase(right.begin());
		mulSign = true;
	}

	//�j�ƭ��k��@
	int integer[10] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> num;
	int now = 0, next, index;
	for (int j = right.size() - 1; j >= 0; j--)
	{
		index = right.size() - j - 1;
		for (int i = left.size() - 1; i >= 0; i--, index++)
		{
			next = 0;
			if (integer[left[i] - '0'] != 0 && integer[right[j] - '0'] != 0) //�J�s�i��
			{
				now += integer[left[i] - '0'] * integer[right[j] - '0'];
			}
			if (now >= 10)//�W�L10�N�i���next
			{
				next += now / 10;
				now %= 10;
			}
			if (num.size() <= index)
				num.push_back(now);
			else
			{
				num[index] += now;
				if (num[index] >= 10)//�W�L10�N�i���next
				{
					next += num[index] / 10;
					num[index] %= 10;
				}
			}
			now = next;
		}
		while (now > 0)
		{
			num.push_back(now % 10);
			now /= 10;
		}
	}
	while (now > 0)
	{
		num.push_back(now % 10);
		now /= 10;
	}


	//����vector<int>���নstring
	string strNum;
	bool zero = true;
	for (int i = num.size() - 1; i >= 0; i--)
	{
		if (num[i] != 0)
			zero = false;
		if (!zero)
			strNum += num[i] + '0';
		else if (i == 0)
			strNum = "0";
	}
	if (mulSign && strNum != "0")
		return "-" + strNum; //�ۭ����G���t��
	return strNum;	//�ۭ����G������
}

//�j�ư��k left/right �����l�ƥ\��
string Number::div(string left, string right)
{
	bool r = false;//�P�_�O�_�n���l��
	if (left[left.size() - 1] == 'r')
	{
		r = true;
		left.pop_back();
	}

	if (right == "0")
	{
		cout << "Illegal input!" << endl;
		return "0";
	}
	//�P�_���t��
	bool divSign = false;//�s���t���Adefault������(false)
	if (left[0] == '-' && right[0] == '-')
	{
		left.erase(left.begin());
		right.erase(right.begin());
	}
	else if (left[0] == '-')
	{
		left.erase(left.begin());
		divSign = true;
	}
	else if (right[0] == '-')
	{
		right.erase(right.begin());
		divSign = true;
	}

	string rem; //�l��
				//�P�_�j�p
	int c = cmp(left, right);
	if (c == 0)//��Ƭ۵�
	{
		rem = "0";
		if (r)
			return rem;
		if (divSign)
			return "-1";
		return "1";
	}
	else if (c == 1)//����>�Q����
	{
		rem = left;
		if (r)
			return rem;
		return "0";
	}
	else
	{
		string rem = left, R = right;
		string quotient;
		int s = left.size() - right.size() + 1;
		for (int i = 0; i < s - 1; i++) //�Y���פ��@�ˡA�Nleft�ɹs�ܻPright�@�˪�
			R.push_back('0');
		while (s--)
		{
			string a, m;
			for (int i = 9; i >= 0; i--)
			{
				a = '0' + i;
				m = mul(R, a);
				c = cmp(m, rem);
				if (c >= 0)
				{
					quotient += a;
					rem = sub(rem, m);
					break;
				}
			}
			R.pop_back();
		}
		if (r)
			return rem;

		if (quotient[0] == '0')
			quotient.erase(quotient.begin());

		if (divSign)
			return "-" + quotient;
		return quotient;
	}
}

//Intent: �j�Ƥ��
//Per: ��J��ӫD�t���
//Post: 0:�۵� 1:left<right -1:left>right
int Number::cmp(string left, string right)
{
	int size1 = left.size();
	int size2 = right.size();

	if (size1 > size2)
		return -1;
	else if (size1 < size2)
		return 1;
	else if (size1 == size2)
	{
		for (int i = 0; i < size1; i++)
		{
			if (left[i] > right[i])
				return -1;
			else if (left[i] < right[i])
				return 1;
			else if (i == size1 - 1)
				return 0;
		}
	}
}
/***********************************************
***************** �� ��ƹ�@ �� ***************
************************************************/

string Number::get110Dec(Fraction f)
{
	if (f.numerator == "0" && f.denominator == "0")
	{
		string s;
		s.assign(110, '0');
		return "0." + s;
	}
	string temp;
	string quotient = div(f.numerator, f.denominator);
	int len = quotient.length();
	if (cmp(f.numerator, f.denominator) == 1 && f.numerator != "0")
	{
		temp = "0.";
		while (cmp(f.numerator, f.denominator) == 1)
		{
			temp += '0';
			f.numerator += '0';
		}
		if (temp[temp.size() - 1] == '0')
			temp.pop_back();
		f.numerator.insert(f.numerator.end(), 110, '0');
		quotient = div(f.numerator, f.denominator);
		temp += quotient;
		return temp.assign(temp, 0, len + 111);
	}
	else
	{
		f.numerator.insert(f.numerator.end(), 110, '0');
		quotient = div(f.numerator, f.denominator);
		quotient.insert(len, ".");
		return quotient.assign(quotient, 0, len + 111);
	}

}

string Number::get100Dec(Fraction f)
{
	string get110 = get110Dec(f);
	string s;
	size_t index;
	index = get110.find('.');
	s.assign(105, '9');
	if (s == get110.substr(index + 1, 105))
	{
		get110.assign(get110.begin(), get110.begin() + index);
		get110 = add(get110, "1");
		get110 += '.';
		get110.insert(get110.end(), 110, '0');
	}
	s.assign(10, '9');
	if (s == get110.substr(index + 100, 10))
	{
		string temp;
		temp.assign(get110.begin(), get110.begin() + index); //�p���I�e
		get110 = get110.substr(index + 1, 110);
		while (get110[0] == '0')
		{
			get110.erase(get110.begin());
		}
		get110 = add(get110, "1");
		if (get110.size() > 110)
		{
			string a;
			a = get110[0];
			get110.erase(get110.begin());
			temp = add(temp, a);
		}

		temp += '.';
		temp += get110;
		get110 = temp;
	}
	return get110.assign(get110, 0, get110.size() - 10);
}

string Number::get10Dec(Fraction f)
{
	string get100 = get100Dec(f);
	return get100.assign(get100, 0, get100.size() - 90);
}

string Number::getRoot120(string s)
{
	string ans;
	int len1;
	s.length() % 2 == 0 ? len1 = s.length() / 2 : len1 = s.length() / 2 + 1;
	s.insert(s.end(), 300, '0');
	int len = s.length();
	int i, j;
	int x[300] = {}, y[600] = {};
	for (i = 0, j = len - 1; j >= 0; i++)
	{
		x[i] = s[j] - '0';
		if (j - 1 >= 0)    x[i] = x[i] + (s[j - 1] - '0') * 10;
		if (j - 2 >= 0)    x[i] = x[i] + (s[j - 2] - '0') * 100;
		if (j - 3 >= 0)    x[i] = x[i] + (s[j - 3] - '0') * 1000;
		j -= 4;
	}
	int xlen = len, ylen = 0, head = 0;
	while (xlen >= 0 && x[xlen] == 0) xlen--;
	for (j = (len - 1) / 8, i = j * 2; j >= 0; j--, i -= 2)
	{
		ylen++;
		for (int p = ylen; p >= 1; p--)
			y[p] = y[p - 1];
		y[0] = 0;
		if (xlen < j)
		{
			if (!head)
				ans.push_back('0'), head = 1;
			else
				ans = ans + "0000";
			continue;
		}
		int l = 0, r = 9999, p;
		int z[300]; // z = (y*10 + p)*p;
		while (l <= r)
		{
			p = (l + r) / 2;
			y[0] += p;
			z[0] = 0;
			for (int q = 0; q <= ylen + 5; q++)
			{
				z[q] += p * y[q];
				z[q + 1] = z[q] / 10000;
				z[q] %= 10000;
			}
			int chflag = 0;
			for (int q = ylen + 5; q >= 0; q--)
			{
				if (z[q] > x[i + q])
				{
					chflag = 1;
					break;
				}
				else if (z[q] < x[i + q])
				{
					chflag = 0;
					break;
				}
			}
			y[0] -= p;
			if (chflag)
				r = p - 1;
			else
				l = p + 1;
		}
		p = l - 1;
		y[0] = p;
		z[0] = 0;
		for (int q = 0; q <= ylen + 5; q++)
		{
			z[q] += p * y[q];
			z[q + 1] = z[q] / 10000;
			z[q] %= 10000;
		}
		for (int q = ylen + 5; q >= 0; q--)
			x[i + q] -= z[q];
		for (int q = 0; q <= ylen + 5; q++)
		{
			while (x[i + q] < 0)
				x[i + q] += 10000, x[i + q + 1]--;
		}
		y[0] += p;
		for (int q = 0; q <= ylen + 5; q++)
		{
			if (y[q] >= 10000)
			{
				y[q + 1] += y[q] / 10000;
				y[q] %= 10000;
			}
		}
		ylen += 5;
		while (ylen >= 0 && y[ylen] == 0)    ylen--;
		while (xlen >= 0 && x[xlen] == 0)    xlen--;
		if (!head)
		{
			ans = ans + to_string(p);
			head = 1;
		}
		else
		{
			string str = to_string(p);
			for (int w = 0; w < 4 - str.length(); w++)
				ans.push_back('0');
			ans = ans + str;
		}
	}
	ans.insert(len1, ".");
	return ans;
}

string Number::printRoot(string s)
{
	string ans;
	int len1;
	s.length() % 2 == 0 ? len1 = s.length() / 2 : len1 = s.length() / 2 + 1;
	s.insert(s.end(), 200, '0');
	int len = s.length();
	int i, j;
	int x[300] = {}, y[300] = {};
	for (i = 0, j = len - 1; j >= 0; i++)
	{
		x[i] = s[j] - '0';
		if (j - 1 >= 0)    x[i] = x[i] + (s[j - 1] - '0') * 10;
		if (j - 2 >= 0)    x[i] = x[i] + (s[j - 2] - '0') * 100;
		if (j - 3 >= 0)    x[i] = x[i] + (s[j - 3] - '0') * 1000;
		j -= 4;
	}
	int xlen = len, ylen = 0, head = 0;
	while (xlen >= 0 && x[xlen] == 0) xlen--;
	for (j = (len - 1) / 8, i = j * 2; j >= 0; j--, i -= 2)
	{
		ylen++;
		for (int p = ylen; p >= 1; p--)
			y[p] = y[p - 1];
		y[0] = 0;
		if (xlen < j)
		{
			if (!head)
				ans.push_back('0'), head = 1;
			else
				ans = ans + "0000";
			continue;
		}
		int l = 0, r = 9999, p;
		int z[300]; // z = (y*10 + p)*p;
		while (l <= r)
		{
			p = (l + r) / 2;
			y[0] += p;
			z[0] = 0;
			for (int q = 0; q <= ylen + 5; q++)
			{
				z[q] += p * y[q];
				z[q + 1] = z[q] / 10000;
				z[q] %= 10000;
			}
			int chflag = 0;
			for (int q = ylen + 5; q >= 0; q--)
			{
				if (z[q] > x[i + q])
				{
					chflag = 1;
					break;
				}
				else if (z[q] < x[i + q])
				{
					chflag = 0;
					break;
				}
			}
			y[0] -= p;
			if (chflag)
				r = p - 1;
			else
				l = p + 1;
		}
		p = l - 1;
		y[0] = p;
		z[0] = 0;
		for (int q = 0; q <= ylen + 5; q++)
		{
			z[q] += p * y[q];
			z[q + 1] = z[q] / 10000;
			z[q] %= 10000;
		}
		for (int q = ylen + 5; q >= 0; q--)
			x[i + q] -= z[q];
		for (int q = 0; q <= ylen + 5; q++)
		{
			while (x[i + q] < 0)
				x[i + q] += 10000, x[i + q + 1]--;
		}
		y[0] += p;
		for (int q = 0; q <= ylen + 5; q++)
		{
			if (y[q] >= 10000)
			{
				y[q + 1] += y[q] / 10000;
				y[q] %= 10000;
			}
		}
		ylen += 5;
		while (ylen >= 0 && y[ylen] == 0)    ylen--;
		while (xlen >= 0 && x[xlen] == 0)    xlen--;
		if (!head)
		{
			ans = ans + to_string(p);
			head = 1;
		}
		else
		{
			string str = to_string(p);
			for (int w = 0; w < 4 - str.length(); w++)
				ans.push_back('0');
			ans = ans + str;
		}
	}
	ans.insert(len1, ".");
	return ans;
}

//Number��X����
string Number::printAns()
{
	if (errorTyep > 0)
	{
		switch (errorTyep)
		{
		case 1:
			return "Error (1) : �D����ƶ���";
			break;
		case 2:
			return "Error (2) : �D��Ʃ�0.5����";
			break;
		case 3:
			return "Error (3) : ���Ƥ��i��0";
			break;
		default:
			break;
		}
	}
	string s = "0.0000000000";
	Fraction temp;
	imagToReal(fracAns, temp);

	if (fracAns.comSign && get10Dec(temp) != s)
		return getCom();
	else if (fracAns.denominator != "1" && fracAns.denominator != "0")
	{
		string test = getDec();
		s.assign(100, '0');
		size_t index = test.find('.');
		if (test.substr(index + 1) == s)
		{
			return getInt();
		}
		return test;
	}

	else
		return getInt();
}

Number::Number() :Number("0") {}


Number::Number(const Number& n)
{
	this->name = n.name;
	this->setInput(n.input);
	this->computInput();
}


Number::Number(string input)
{
	setInput(input);
	computInput();
}
Number::~Number() {}


string Number::getInt()
{
	if (errorTyep > 0)
		return printAns();
	string ret;
	ret = get100Dec(fracAns);
	if (fracAns.sign)
		ret.insert(ret.begin(), '-');
	ret.assign(ret, 0, ret.size() - 101);
	if (ret == "-0")
		return "0";
	return ret;
}

string Number::getDec()
{
	if (errorTyep > 0)
		return printAns();
	string ret;
	ret = get100Dec(fracAns);
	if (fracAns.sign)
		ret.insert(ret.begin(), '-');
	string s = "-0.";
	s.insert(s.begin(), 100, '0');
	if (ret == s)
		ret.erase(ret.begin());
	return ret;
}

string Number::getCom()
{
	if (errorTyep > 0)
		return printAns();
	string s = "-0.0000000000";
	string ret1, ret2;
	if (fracAns.sign)
		ret1 += '-';
	else
		ret1 += ' ';
	ret1 += get10Dec(fracAns);
	Fraction temp;
	imagToReal(fracAns, temp);
	if (temp.sign)
		ret2 += '-';
	else
		ret2 += '+';
	ret2 += get10Dec(temp);
	if (ret1 == s)
		ret1.erase(ret1.begin());
	if (ret2 == s)
		ret2[0] = '+';
	return ret1 + " " + ret2 + "i";
}

void Number::assign() {}

void Number::print(ostream&)const {}


ostream& operator<<(ostream& outputStream, const Number& a)
{
	a.print(outputStream);
	return outputStream;
}

istream& operator>> (istream& inputStream, Number& a)
{
	string in;
	inputStream >> in;
	a.setInput(in);
	a.computInput();
	a.assign();
	return inputStream;
}


Fraction Number::getFrac()
{
	return fracAns;
}

Fraction Number::getReal()
{
	Fraction ret;
	ret.sign = fracAns.sign;
	ret.denominator = fracAns.denominator;
	ret.numerator = fracAns.numerator;
	return ret;
}


bool Number::getComSign()
{
	return fracAns.comSign;
}

void Number::setFrac(Fraction f)
{
	fracAns = f;
}



// ***************** class Integer **************************

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


//************************* class DEcimal  **********************

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

// **************************** class Complex *********** 

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



int main()
{


	// *** API  ***

	//	Integer i;
	//	DEcimal d;
	//	cin >> i >> d;
	//	cout << i + d << endl ;


	//	string s = "123+200";
	//	string t = "2*5.1";
	//	Integer i1 = s;
	//	DEcimal d1 = t;
	//	cout << i1 << endl ;
	//	cout << d1 << endl ;

	//              *************�U��code *******
	//Integer x;
	//DEcimal y;
	//
	//cin >> x; // ��J 123456789
	//cin >> y; // ��J 3.1415926
	//
	//cout << x + y << endl;
	//cout << x - y << endl;
	//cout << x * y << endl;
	//cout << x / y << endl;

	string s1 = "123 * 8 + 456";
	string s2 = "-1.0 / 3 - 45 / 13.0";
	Integer x = s1;
	DEcimal y = s2;

	vector<Number*> nums;
	nums.push_back(&x);
	nums.push_back(&y);
	for (const auto& num : nums)
		cout << *num << endl;
	//******************************************
	/*
	class character      // �����O
		 name level arms

	class warrrior      // �l���O
		 name level arms skills


	class wizard
		name level arms magic


	warrior

	��parent type �h�ŧi �x�schild type����

	user1    character = warrior
	user2    character = wizard


	vector <Number> nums; // i1 address,  d1 address
	NUmber addresss


	*/
	//	vector<Number*> nums;
	//	nums.push_back(&i1);
	//	nums.push_back(&d1);
	//	for(const auto& num:nums)
	//		cout << *num << endl; 
	//*************************************


	vector<Integer> ints;
	vector<DEcimal> decs;
	vector<Complex> coms;




	while (1)
	{

		string in, order;
		getline(cin, in);
		istringstream ss(in);   //  set Integer A = 3.5

		while (ss >> order)
		{

			if (order == "Set" || order == "set")
			{
				string type, name, temp;
				int t = 0;
				ss >> type;
				if (type == "Integer" || type == "integer")
					t = 1;
				else if (type == "Decimal" || type == "decimal")
					t = 2;

				ss >> name;





				if (ss >> temp)
				{

					string temp2;   // �B�⦡ 
					string t1;
					while (ss >> t1)
					{
						temp2 += t1;

					}
					temp = temp2;
					string exp;
					//					cout << "temp:" << temp << endl ;
					//					cout << "temp2:" << temp2 << endl ;
					if ((temp2.find("power") != temp2.npos || temp2.find("Power") != temp2.npos))        // �Ʀr�[�Wpower �O? 
					{

						//				cout << temp1 << endl ;

						string tempExp = temp2;


						for (int i = 0; i < tempExp.size(); i++)     // Power(2,Power(3,2))
						{
							// �Ҽ{�u���v���D 
							if (tempExp[i] == '(')
							{
								exp += "((";
							}
							else if (tempExp[i] == ')')
							{
								exp += "))";
							}
							else if (isdigit(tempExp[i]) || tempExp[i] == '.')             // floating number
							{
								exp += tempExp[i];
							}
							else if (tempExp[i] == ',')
							{

								exp += ")^(";
							}
							else if (tempExp[i] == '-' && isdigit(tempExp[i + 1]))           // negative sign       
							{
								exp += "(";
								int j = i;
								while (tempExp[j] != ')')
								{
									exp += tempExp[j];
									j++;
								}
								exp += ")";
								i = j;
							}
							else if (!isalpha(tempExp[i]))
							{
								exp += tempExp[i];                                         //    +-*/^
							}

						}

						//					cout << "exp: " << exp << endl ;
						bool found = false;
						int foundIndex = 0;
						bool foundInInt = false;
						bool foundInDec = false;


						switch (t)
						{
						case 1:

							for (int i = 0; i < ints.size(); i++)
							{
								//							cout <<ints[i]->name << endl ;
								if (name == ints[i].name && ints[i].exist)
								{

									found = true;
									foundIndex = i;
									break;
								}
							}
							if (!found)
							{
								for (int i = 0; i < decs.size(); i++)
								{
									//							cout <<ints[i]->name << endl ;
									if (name == decs[i].name && decs[i].exist)
									{
										foundInDec = true;
										found = true;
										foundIndex = i;
										break;
									}
								}
							}
							if (!found) {
								Integer i;
								i.name = name;
								i.setInput(exp);
								i.computInput();
								i.assign();
								ints.push_back(i);

							}
							else if (foundInDec)
							{
								Integer i;
								i.name = name;
								i.setInput(exp);
								i.computInput();
								i.assign();
								ints.push_back(i);
								decs[foundIndex].exist = false;

							}
							else
							{

								ints[foundIndex].setInput(exp);
								ints[foundIndex].computInput();
								ints[foundIndex].assign();
							}
							break;
						case 2:
							for (int i = 0; i < decs.size(); i++)
							{
								//							cout <<ints[i]->name << endl ;
								if (name == decs[i].name && decs[i].exist)
								{

									found = true;
									foundIndex = i;
									break;
								}
							}
							if (!found)
							{

								for (int i = 0; i < ints.size(); i++)
								{
									//							cout <<ints[i]->name << endl ;
									if (name == ints[i].name && ints[i].exist)
									{

										found = true;
										foundInInt = true;
										foundIndex = i;
										break;
									}
								}
							}
							if (!found) {
								DEcimal d;
								d.name = name;
								d.setInput(exp);
								d.computInput();
								d.assign();
								decs.push_back(d);

							}
							else if (foundInInt)
							{
								DEcimal d;
								d.name = name;
								d.setInput(exp);
								d.computInput();
								d.assign();
								decs.push_back(d);
								ints[foundIndex].exist = false;
							}
							else
							{
								decs[foundIndex].setInput(exp);
								decs[foundIndex].computInput();
								decs[foundIndex].assign();
							}
							break;


						default:
							break;
						}
					}

					//					Complex c;
					else {

						//						cout << "temp: " << temp << endl ;
						bool found = false;
						int foundIndex = 0;
						bool foundInInt = false;
						bool foundInDec = false;


						switch (t)
						{
						case 1:

							for (int i = 0; i < ints.size(); i++)
							{
								//							cout <<ints[i]->name << endl ;
								if (name == ints[i].name && ints[i].exist)
								{

									found = true;
									foundIndex = i;
									break;
								}
							}
							if (!found)
							{
								for (int i = 0; i < decs.size(); i++)
								{
									//							cout <<ints[i]->name << endl ;
									if (name == decs[i].name && decs[i].exist)
									{
										foundInDec = true;
										found = true;
										foundIndex = i;
										break;
									}
								}
							}
							if (!found) {
								Integer i;
								i.name = name;
								i.setInput(temp);
								i.computInput();
								i.assign();
								ints.push_back(i);

							}
							else if (foundInDec)
							{
								Integer i;
								i.name = name;
								i.setInput(temp);
								i.computInput();
								i.assign();
								ints.push_back(i);
								decs[foundIndex].exist = false;

							}
							else
							{

								ints[foundIndex].setInput(temp);
								ints[foundIndex].computInput();
								ints[foundIndex].assign();
							}
							break;
						case 2:
							for (int i = 0; i < decs.size(); i++)
							{
								//							cout <<ints[i]->name << endl ;
								if (name == decs[i].name && decs[i].exist)
								{

									found = true;
									foundIndex = i;
									break;
								}
							}
							if (!found)
							{

								for (int i = 0; i < ints.size(); i++)
								{
									//							cout <<ints[i]->name << endl ;
									if (name == ints[i].name && ints[i].exist)
									{

										found = true;
										foundInInt = true;
										foundIndex = i;
										break;
									}
								}
							}
							if (!found) {
								DEcimal d;
								d.name = name;
								d.setInput(temp);
								d.computInput();
								d.assign();
								decs.push_back(d);

							}
							else if (foundInInt)
							{
								DEcimal d;
								d.name = name;
								d.setInput(temp);
								d.computInput();
								d.assign();
								decs.push_back(d);
								ints[foundIndex].exist = false;
							}
							else
							{
								decs[foundIndex].setInput(temp);
								decs[foundIndex].computInput();
								decs[foundIndex].assign();
							}
							break;


						default:
							break;
						}
					}
				}
				else
				{
					if (t == 1)
					{
						Integer newI;
						newI.name = name;
						ints.push_back(newI);
					}
					else if (t == 2)
					{
						DEcimal newD;
						newD.name = name;
						decs.push_back(newD);
					}
					else if (t == 3)
					{
						Complex newC;
						newC.name = name;
						coms.push_back(newC);
					}
				}

			}
			else if (isalpha(order[0]) && order.find("power") == order.npos && order.find("Power") == order.npos)
			{


				string name = order;

				string equal;
				if (ss >> equal)
				{


					if (equal == "=")   // A = 1 + 3   A = A + B   A = 1 + A
					{
						bool found = false;
						string temp;
						string exp;
						while (ss >> temp)
						{
							if (isalpha(temp[0]))
							{
								bool isInt = false;
								bool isDec = false;
								int index = 0;
								for (int i = 0; i < ints.size(); i++)
								{
									if (ints[i].name == temp && ints[i].exist)
									{

										index = i;
										isInt = true;

										break;
									}
								}
								for (int i = 0; i < decs.size(); i++)
								{
									if (decs[i].name == temp && decs[i].exist)
									{
										index = i;
										isDec = true;
										break;
									}
								}
								if (isInt)
								{
									exp += ints[index].ans;
								}
								if (isDec)
								{
									exp += ints[index].ans;
								}
							}
							else
							{
								exp += temp;
							}
						}
						//						cout << "exp:" << exp << endl ;

						for (int i = 0; i < ints.size() && !found; i++)
						{
							if (ints[i].name == name && ints[i].exist)
							{
								ints[i].setInput(exp);
								ints[i].computInput();
								ints[i].assign();
								found = true;

							}
						}
						for (int i = 0; i < decs.size() && !found; i++)
						{
							if (decs[i].name == name && decs[i].exist)
							{
								decs[i].setInput(exp);
								decs[i].computInput();
								decs[i].assign();
								found = true;
							}
						}
						if (!found)
							cout << "Not found." << endl;
					}
					else    // A + A  
					{
						string exp;
						int firstIndex = 0;
						bool isInt = false;
						bool isDec = false;

						for (int i = 0; i < ints.size(); i++)
						{
							if (ints[i].name == name && ints[i].exist)
							{

								exp = exp + ints[i].ans;
								firstIndex = i;
								isInt = true;
								break;
							}
						}
						for (int i = 0; i < decs.size(); i++)
						{
							if (decs[i].name == name && decs[i].exist)
							{
								exp += decs[i].ans;
								firstIndex = i;
								isDec = true;
								break;

							}
						}
						exp += equal;
						string t;
						while (ss >> t)
						{
							if (!isalpha(t[0]))
							{
								exp += t;

							}
							else {
								for (int i = 0; i < ints.size(); i++)
								{
									if (ints[i].name == t && ints[i].exist)
									{
										exp += ints[i].ans;
									}
								}
								for (int i = 0; i < decs.size(); i++)
								{
									if (decs[i].name == t && decs[i].exist)
									{
										exp += decs[i].ans;
									}
								}
							}
						}
						//						cout << "exp: " << exp << endl ;
						Number n1(exp);
						cout << n1.printAns() << endl;

						//						if(isInt)
						//						{
						//							
						//							ints[firstIndex].setInput(exp);
						//							ints[firstIndex].computInput();
						//							ints[firstIndex].assign();
						//						}
						//						else if(isDec)
						//						{
						//							decs[firstIndex].setInput(exp);
						//							decs[firstIndex].computInput();
						//							decs[firstIndex].assign();
						//						}
					}


				}
				else {                // A  �B B 

//				    cout << "**" << endl ;
					bool found = false;
					for (int i = 0; i < ints.size() && !found; i++)
					{

						if (ints[i].name == name && ints[i].exist)
						{

							cout << ints[i] << endl;

							found = true;
						}
					}
					for (int i = 0; i < decs.size() && !found; i++)
					{
						if (decs[i].name == name && decs[i].exist)
						{
							cout << decs[i] << endl;

							found = true;
						}
					}
					for (int i = 0; i < coms.size() && !found; i++)
					{
						if (coms[i].name == name)
						{
							cout << endl << coms[i] << endl;

							found = true;
						}
					}
					if (!found)
						cout << "Not found." << endl;
				}
			}
			else
			{


				string temp1 = order;
				string t1;
				while (ss >> t1)
				{
					temp1 += t1;

				}
				if ((temp1.find("power") != temp1.npos || temp1.find("Power") != temp1.npos))        // �Ʀr�[�Wpower �O? 
				{

					//				cout << temp1 << endl ;

					string tempExp = temp1;
					string exp;

					for (int i = 0; i < tempExp.size(); i++)     // Power(2,Power(3,2))
					{
						// �Ҽ{�u���v���D 
						if (tempExp[i] == '(')
						{
							exp += "((";
						}
						else if (tempExp[i] == ')')
						{
							exp += "))";
						}
						else if (isdigit(tempExp[i]) || tempExp[i] == '.')             // floating number
						{
							exp += tempExp[i];
						}
						else if (tempExp[i] == ',')
						{

							exp += ")^(";
						}
						else if (tempExp[i] == '-' && isdigit(tempExp[i + 1]))           // negative sign       
						{
							exp += "(";
							int j = i;
							while (tempExp[j] != ')')
							{
								exp += tempExp[j];
								j++;
							}
							exp += ")";
							i = j;
						}
						else if (!isalpha(tempExp[i]))
						{
							exp += tempExp[i];                                         //    +-*/^
						}

					}

					//					cout << "exp: " << exp << endl ;
					Number n1(exp);
					cout << n1.printAns() << endl;



				}





				else if (order == "Factoirial" || order == "factorial")
				{
					string name, temp;
					ss >> name;
					Integer integer;
					if (ss >> temp)
					{
						integer = Factorial(temp);
						cout << integer << endl;

					}
					else
					{
						bool found = false;
						for (int i = 0; i < ints.size() && !found; i++)
						{
							if (ints[i].name == name)
							{
								integer = Factorial(ints[i]);
								found = true;
							}
						}
						for (int i = 0; i < decs.size() && !found; i++)
						{
							if (decs[i].name == name)
							{
								integer = Factorial(decs[i]);
								found = true;
							}
						}
						for (int i = 0; i < coms.size() && !found; i++)
						{
							if (coms[i].name == name)
							{
								integer = Factorial(coms[i]);
								found = true;
							}
						}
						if (!found)
							cout << "Not found." << endl;
						else
						{
							cout << integer << endl;

						}
					}
				}
				else
				{
					// 12+--12+-11-1   = 12
										// 1++++1--+-+---1 = 3
										// 1--2+12-22--+2+-1 = -6

					//					cout << temp1 << endl ;	

					bool error1 = false;
					bool error2 = false;

					for (int i = 0; i < temp1.size(); i++)
					{
						if (!isdigit(temp1[i]))
						{
							if (temp1[i] == '+' && temp1[i + 1] == '+')
							{
								temp1.erase(i + 1, 1);
								i -= 1;
							}
							else if (temp1[i] == '+' && temp1[i + 1] == ')')
							{
								error2 = true;
							}
							else if (temp1[i] == '+' && temp1[i + 1] == '-')
							{
								temp1.erase(i, 1);
								i -= 1;
							}
							else if (temp1[i] == '-' && temp1[i + 1] == '+')
							{
								temp1.erase(i + 1, 1);
								i -= 1;
							}
							else if (temp1[i] == '-' && temp1[i + 1] == '-')
							{
								temp1.erase(i, 2);
								temp1.insert(i, "+");
								i -= 1;
							}

							else if (temp1[i] == '*' && temp1[i + 1] == '*')
							{
								temp1.erase(i + 1, 1);
								i -= 1;
							}
							else if (temp1[i] == '*' && temp1[i + 1] == '/')
							{
								error1 = true;
							}
							else if (temp1[i] == '/' && temp1[i + 1] == '/')
							{
								temp1.erase(i + 1, 1);
								i -= 1;
							}
							else if (temp1[i] == '^' && temp1[i + 1] == '^')
							{
								temp1.erase(i + 1, 1);
								i -= 1;
							}

							else if (isalpha(temp1[i]))
							{
								int t = i + 1;
								string tempStr = "";
								tempStr += temp1[i];

								while (isalpha(temp1[t]))
								{
									if (isalpha(temp1[t]))
									{
										tempStr += temp1[t];
									}
									temp1.erase(i + 1, 1);
									t++;
								}

								//								cout << "tempStr: " << tempStr << endl ;
								//								i = t - 1;

								int f_index = 0;
								//								bool found = false;
								bool f_in_Int = false;
								bool f_in_Dec = false;
								for (int i = 0; i < ints.size(); i++)
								{
									//						cout <<ints[i]->name << endl ;
									if (tempStr == ints[i].name && ints[i].exist)
									{

										//										found = true;
										f_in_Int = true;
										f_index = i;
										break;
									}
								}
								for (int i = 0; i < decs.size(); i++)
								{
									//						cout <<ints[i]->name << endl ;
									if (tempStr == decs[i].name && decs[i].exist)
									{

										//										found = true;
										f_in_Dec = true;
										f_index = i;
										break;
									}
								}

								temp1.erase(i, t - i);

								if (f_in_Int)
								{
									temp1.insert(i, ints[f_index].ans);
									i = i + ints[f_index].ans.size() - 1;
								}
								else if (f_in_Dec)
								{
									temp1.insert(i, decs[f_index].ans);
									i = i + decs[f_index].ans.size() - 1;
								}


							}
						}
					}
					//					cout << temp1 << endl ;	

										// set integer variable = 2
										// 1 + variable


					if (error1 || error2)
					{
						cout << "���X�k�B�⦡" << endl;
					}

					if (!error1 && !error2)
					{
						Number n1(temp1);
						cout << n1.printAns() << endl;
					}

				}
			}
		}


	}

	return 0;
}
