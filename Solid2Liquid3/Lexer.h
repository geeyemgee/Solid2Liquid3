#ifndef LEXER_H
#define LEXER_H

#include<string>
#include"Token.h"

class Lexer
{
public:
	std::string IExpr;
	int index;
	long int length;
	double number;

	Lexer(std::string exp)
		:IExpr(exp)
	{
		length = IExpr.size();
		index = 0;
	}

	Token GetToken();
	
	double GetNumber()
	{
		return number;
	}
};

#endif