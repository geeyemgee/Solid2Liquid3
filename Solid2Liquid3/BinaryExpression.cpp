#include "BinaryExpression.h"

double BinaryExpression::Accept(IExprVisitor& visitor)
{
	return visitor.Visit(this);
}