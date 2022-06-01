#include<iostream>
#include "Lexer.h"

Token Lexer::GetToken()
{
	Token tok = Token::ILLEGAL_TOKEN;
	std::string str;

	while (index < length &&
		IExpr[index] == ' ' ||
		IExpr[index] == '\t')
	{
		index++;
	}

	if (index == length)
	{
		return Token::TOK_NULL;
	}

	switch (IExpr[index])
	{
	case '+':
		tok = Token::TOK_PLUS;
		index++;
		break;

	case '-':
		tok = Token::TOK_SUB;
		index++;
		break;

	case '/':
		tok = Token::TOK_DIV;
		index++;
		break;

	case '*':
		tok = Token::TOK_MUL;
		index++;
		break;

	case '(':
		tok = Token::TOK_OPAREN;
		index++;
		break;

	case ')':
		tok = Token::TOK_CPAREN;
		index++;
		break;

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		while (index < length &&
			(IExpr[index] == '0' ||
			IExpr[index] == '1' ||
			IExpr[index] == '2' ||
			IExpr[index] == '3' ||
			IExpr[index] == '4' ||
			IExpr[index] == '5' ||
			IExpr[index] == '6' ||
			IExpr[index] == '7' ||
			IExpr[index] == '8' ||
			IExpr[index] == '9'))
		{
			str += IExpr[index];
			index++;
		}

		number = atoi(str.c_str());
		tok = Token::TOK_DOUBLE;

		break;

	default:
		std::cerr << "Error while analyzing tokens!";
		return Token::ILLEGAL_TOKEN;
	}

	return tok;
}