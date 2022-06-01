#ifndef IEXPR_VISITOR_H
#define IEXPR_VISITOR_H

class NumericConstant;
class BinaryExpression;
class UnaryExpression;

class IExprVisitor
{
public:
	virtual double Visit(NumericConstant *num) = 0;
	virtual double Visit(BinaryExpression *bin) = 0;
	virtual double Visit(UnaryExpression *un) = 0;

	virtual ~IExprVisitor() {}
};

#endif
