#include "NumericConstant.h"

double NumericConstant::Accept(IExprVisitor &visitor)
{
	return visitor.Visit(this);
}