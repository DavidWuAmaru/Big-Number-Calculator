#include "Integer.h"

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

	/*string s1 = "123 * 8 + 456";
	string s2 = "-1.0 / 3 - 45 / 13.0";
	Integer x = s1;
	DEcimal y = s2;

	vector<Number*> nums;
	nums.push_back(&x);
	nums.push_back(&y);
	for (const auto& num : nums)
		cout << *num << endl;*/
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
