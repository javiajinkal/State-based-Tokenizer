///////////////////////////////////////////////////////////////////////
// TestExecutive.cpp - tests requirements of Project1                //
// ver 1.0                                                           //
// Language:    C++, Visual Studio 2015                              //
// Application: Project1 , CSE687 - Object Oriented Design           //
// Platform:    Lenovo Yoga 3, Core-i5, Windows 10				     //
// Author:      Jinkal Arvind Javia, SUID: 425325424     	         //
//              jjavia@syr.edu		                                 //
// Source:		Jim Fawcett, Syracuse University, CST 4-187          //
//              jfawcett@twcny.rr.com								 //
///////////////////////////////////////////////////////////////////////
/*
TestExecutive package is automated unit test suite that exercises all of 
the special cases that seem appropriate for packages Tokenizer and SemiExp
for Project1 of CSE687 - Object Oriented Design

Build Process:
------------------------
Required Files: Tokenizer.h, Tokenizer.cpp, SemiExp.h, SemiExp.cpp, 
                itokcollection.h, TestExecutive.cpp
Build Command: devenv Project1.sln /rebuild debug

Maintenance History:
------------------------
	ver 1.0 : 09 Feb 16
    first release
*/

#include "../Tokenizer/Tokenizer.h"
#include "../SemiExp/SemiExp.h"
#include "../SemiExp/itokcollection.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace Scanner;

//Demonstrates Requirement 3 of Project1
void Req3()
{
	std::cout <<"\n------------------------DEMONSTRATES REQUIREMENT 3------------------------\n";
	std::cout << "\nC++ packages for Tokenizing, collecting SemiExpressions, and a scanner interface, ITokCollection is provided\n";
}

//Demonstrates Requirement 4 and 5 of Project1
void Req4_5()
{
	std::string fileSpec = "TestReq4.txt";
	std::ifstream in(fileSpec);
	bool first = true;
	if (!in.good()){
		std::cout << "\n  can't open " << fileSpec << "\n\n";
		return;
	}
	Toker toker;
	toker.attach(&in);
	std::string tok;
	std::cout << "\n------------------------DEMONSTRATES REQUIREMENT 5------------------------\n";
	std::cout << "Before calling getTok() : " << tok << "\n\n";
	do
	{
		tok = toker.getTok();
		if (first)
		{
			first = false;
			std::cout << "After calling getTok() : " << tok << "\n\n";
			std::cout << "Demonstrates : \n";
			std::cout << "Toker class in Tokenizer package produces 1 token for each call to a member function getTok()" << "\n";
			std::cout << "\n------------------------DEMONSTRATES REQUIREMENT 4------------------------\n";
		}
		if (tok == "\n")
			tok = "newline";
		std::cout << "\n -- " << tok;
	} while (in.good());
	toker.reset();
	std::cout << "\n\n";
}

//Demonstrates Requirement 6 of Project1
void Req6()
{
	std::cout <<"\n------------------------DEMONSTRATES REQUIREMENT 6------------------------\n";
	std::cout << "SemiExpression package containing class SemiExp for retrieving collections of tokens by calling Toker::getTok() repeatedly until one of the SemiExpression termination conditions provided is satisfied.\n";
}

//Demonstrates Requirement 7 of Project1
void Req7()
{
	std::cout << "\n------------------------DEMONSTRATES REQUIREMENT 7------------------------\n";
	Toker toker;
	std::string fileSpec = "TestReq7.txt";
	std::fstream in(fileSpec);
	if (!in.good()){
		std::cout << "\n  can't open file " << fileSpec << "\n\n";
		return;
	}
	toker.attach(&in);
	toker.reset();
	SemiExp semi(&toker);
	while (semi.get())
	{
		std::string temp;
		std::cout << "\n  -- semiExpression --";
		temp = semi.show();
		std::cout << "\n" << temp << "\n";
	}
	// May have collected tokens, but reached end of stream before finding SemiExp terminator.
	if (semi.length() > 0)
	{
		std::string temp;
		std::cout << "\n  -- semiExpression --";
		temp = semi.show();
		std::cout << "\n" << temp << "\n";
	}
}

//Demonstrates Requirement 8 of Project1
void Req8()
{
	std::cout << "\n------------------------DEMONSTRATES REQUIREMENT 8------------------------\n";
	Toker toker;
	std::string fileSpec = "TestReq8.txt";
	std::fstream in(fileSpec);
	if (!in.good()){
		std::cout << "\n  can't open file " << fileSpec << "\n\n";
		return;
	}
	toker.attach(&in);
	toker.reset();
	SemiExp semi(&toker);
	while (semi.get())
	{
		std::string temp;
		std::cout << "\n  -- semiExpression --";
		temp = semi.show();
		std::cout << "\n" << temp << "\n";
	}
	// May have collected tokens, but reached end of stream before finding SemiExp terminator.
	if (semi.length() > 0)
	{
		std::string temp;
		std::cout << "\n  -- semiExpression --";
		temp = semi.show();
		std::cout << "\n" << temp << "\n";
	}
}

//Demonstrates Requirement 9 of Project1
void Req9()
{
	std::cout << "\n------------------------DEMONSTRATES REQUIREMENT 9------------------------\n";
	std::cout << "The SemiExp class implements the interface ITokenCollection with a declared method get()\n";
	std::cout << "\n---------------------------------------------------------------------------\n";
	std::vector<std::string> testVector = { "\n"," ","A1","B2","C3","D4","E5"," ","F6","G7","H8","I9","J10"," " };
	SemiExp test_iTokCollection;
	for (size_t i = 0; i < testVector.size(); i++)
	{
		test_iTokCollection.push_back(testVector[i]);
	}
	std::cout << "\n Length of vector using length(): "<< test_iTokCollection.length() << "\n";
	std::cout << "\n Displays original vector using show(): "<< test_iTokCollection.show(true) << "\n";
	std::cout << "\n Displays value at index 11 using operator[](11): " << test_iTokCollection.operator[](11) << "\n";
	std::cout << "\n Position of value A1 in vector using find(std::string): " << test_iTokCollection.find("A1") << "\n";
	std::cout << "\n Removes whitespace and newlines from front using trimFront(): \n";
	test_iTokCollection.trimFront();
	std::cout << "\n Length of vector after trimFront() using length(): "<< test_iTokCollection.length() << "\n";
	std::cout << "\n Removes value at position 5 from vector using remove(size_t i): " << test_iTokCollection.remove(5) << "\n";
	std::cout << "\n Removes value I9 from vector using remove(const std::string& tok): " << test_iTokCollection.remove("I9") << "\n";
	std::cout << "\n Converts to lower cases using toLower(): \n";
	test_iTokCollection.toLower();
	std::cout << "\n Displays modified vector using show(): " << test_iTokCollection.show(true) << "\n";	
}

//Demonstrates Requirement 10 of Project1
void Req10()
{
	std::cout << "\n------------------------DEMONSTRATES REQUIREMENT 10------------------------\n";
	std::cout << "This is automated unit test suite that exercises all of the special cases for these two packages\n";
	std::cout << "\n----------------------------------------------------------------------------\n";
}

void ReqSpecial(){
	std::cout << "\nWITHOUT SETTING setSpecialSingleChars(string) and setSpecialCharPairs(string)";
	std::cout << "\n----------------------------------------------------------------------------";
	std::string fileSpec = "TestReqSpecial.txt";
	std::ifstream in(fileSpec);
	bool test = true;
	if (test) {
		test = false;
		if (!in.good()){
			std::cout << "\n  can't open " << fileSpec << "\n\n";
			return;
		}
		Toker toker;
		toker.attach(&in);
		std::string tok;
		do{
			tok = toker.getTok();
			if (tok == "\n")
				tok = "newline";
			std::cout << "\n -- " << tok;
		} while (in.good());
		toker.reset();
		std::cout << "\n\n";
	}
	if(!test){
		std::cout << "\nAFTER SETTING setSpecialSingleChars(string) and setSpecialCharPairs(string)";
		std::cout << "\n -----\'\\t\':SpecialSingleChars---\"||\" and \"&&\":SpecialCharPairs-----";
		std::string fileSpec = "TestReqSpecial.txt";
		std::ifstream in(fileSpec);
		if (!in.good()){
			std::cout << "\n  can't open " << fileSpec << "\n\n";
			return;
		}
		Toker toker;
		std::string ssc = "\\t";
		toker.setSpecialCharPairs(ssc);
		std::string scp = "||,&&";
		toker.setSpecialCharPairs(scp);
		toker.attach(&in);
		std::string tok;
		do{
			tok = toker.getTok();
			if (tok == "\n")
				tok = "newline";
			std::cout << "\n -- " << tok;
		} while (in.good());
		toker.reset();
		std::cout << "\n";
	}
}

#ifdef TESTEXE
int main()
{
	Req3();
	Req4_5();
	Req6();
	Req7();
	Req8();
	Req9();
	Req10();
	ReqSpecial();
	std::cout << "\n--------------------------THIS IS END OF TEST SUITE-------------------------\n";
	return 0;
}
#endif