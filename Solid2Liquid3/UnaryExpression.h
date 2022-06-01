#ifndef UNARY_EXPRESSION_H
#define UNARY_EXPRESSION_H

#include"Expr.h"
#include"IExprVisitor.h"
#include"Operator.h"

class UnaryExpression : public Expr
{
public:
	Expr& right;
	Operator op;
	
	UnaryExpression(Expr& _exp, Operator _op) 
		: right(_exp), op(_op)
	{
	}

	double Accept(IExprVisitor& visitor) override;
};

#endif

