#include<iostream>
#include "RDParser.h"
#include"BinaryExpression.h"
#include"NumericConstant.h"
#include"UnaryExpression.h"

Expr& RDParser::CallExpr()
{
	CurrentToken = GetToken();
	return Expression();
}

Expr& RDParser::Expression()
{
	Token lToken;
	Expr& retVal = Term();

	while (CurrentToken == Token::TOK_PLUS ||
		CurrentToken == Token::TOK_SUB)
	{
		lToken = CurrentToken;
		CurrentToken = GetToken();
		Expr& e1 = Expression();
		retVal = BinaryExpression(retVal, e1,
			lToken == Token::TOK_PLUS ? Operator::PLUS : Operator::MINUS);
	}
	return retVal;
}

Expr& RDParser::Term()
{
	Token lToken;
	Expr& retVal = Factor();

	while (CurrentToken == Token::TOK_MUL ||
		CurrentToken == Token::TOK_DIV)
	{
		lToken = CurrentToken;
		CurrentToken = GetToken();

		Expr& e1 = Term();
		retVal = BinaryExpression(retVal, e1,
			lToken == Token::TOK_MUL ? Operator::MUL : Operator::DIVIDE);
	}

	return retVal;
}

Expr& RDParser::Factor()
{
	Token lToken;
	Expr& retVal = NULL;

	if (CurrentToken == Token::TOK_DOUBLE)
	{
		retVal = NumericConstant(GetNumber());
	}
	else if (CurrentToken == Token::TOK_OPAREN)
	{
		CurrentToken = GetToken();
		retVal = Expression();
		if (CurrentToken != Token::TOK_CPAREN)
		{
			std::cerr << "Error: Missing closing parenthesis";
		}
		else
		{
			CurrentToken = GetToken();
		}
	}
	else if (CurrentToken == Token::TOK_PLUS ||
		CurrentToken == Token::TOK_SUB)
	{
		lToken = CurrentToken;
		CurrentToken = GetToken();
		retVal = Factor();

		retVal = UnaryExpression(retVal,
			lToken == Token::TOK_PLUS ? Operator::PLUS : Operator::MINUS);
	}
	else
	{
		std::cerr << "Error: Illegal Token!";
	}

	return retVal;
}