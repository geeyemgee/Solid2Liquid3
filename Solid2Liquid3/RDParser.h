#ifndef RD_PARSER_H
#define RD_PARSER_H

#include"Expr.h"
#include"Lexer.h"

class RDParser : public Lexer
{
public:
	Token CurrentToken;

	RDParser(std::string str)
		: Lexer(str)
	{

	}

	Expr& CallExpr();
	Expr& Expression();
	Expr& Term();
	Expr& Factor();
};

#endif