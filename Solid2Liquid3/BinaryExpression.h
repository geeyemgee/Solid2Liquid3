#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H

#include"Expr.h"
#include"IExprVisitor.h"
#include"Operator.h"

class BinaryExpression : public Expr
{
public:
	Expr &left;
	Expr &right;
	Operator op;
	BinaryExpression(Expr& l, Expr& r, Operator _op)
		: left(l), right(r)
	{
		this->op = _op;
	}

	double Accept(IExprVisitor &visitor) override;
};

#endif

