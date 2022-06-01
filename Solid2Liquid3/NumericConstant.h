#ifndef NUMERIC_CONSTANT_H
#define NUMERIC_CONSTANT_H

#include"Expr.h"
#include"IExprVisitor.h"

class NumericConstant: public Expr
{
private:
	double value;
public:
	NumericConstant(double _value)
	{
		this->value = _value;
	}

	double Accept(IExprVisitor &visitor) override;
	
	double Num()
	{
		return this->value;
	}
};

#endif

