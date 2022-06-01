#ifndef EXPR_H
#define EXPR_H

class IExprVisitor;

class Expr
{
public:
	virtual double Accept(IExprVisitor &visitor) = 0;
	virtual ~Expr(){}
};

#endif
