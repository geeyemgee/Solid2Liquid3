#include "UnaryExpression.h"

double UnaryExpression::Accept(IExprVisitor& visitor)
{
	return visitor.Visit(this);
}