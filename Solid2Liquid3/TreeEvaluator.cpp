#include "TreeEvaluator.h"

double TreeEvaluator::Visit(NumericConstant num)
{
	return num.Num();
}

double TreeEvaluator::Visit(BinaryExpression bin)
{
	if (bin.op == Operator::PLUS)
	{
		return bin.left.Accept(*this) + bin.right.Accept(*this);
	}
	else if (bin.op == Operator::MUL)
	{
		return bin.left.Accept(*this) * bin.right.Accept(*this);
	}
	else if (bin.op == Operator::DIVIDE)
	{
		return bin.left.Accept(*this) / bin.right.Accept(*this);
	}
	else if (bin.op == Operator::MINUS)
	{
		return bin.left.Accept(*this) - bin.right.Accept(*this);
	}

	return 0.0;
}

double TreeEvaluator::Visit(UnaryExpression un)
{
	if (un.op == Operator::PLUS)
	{
		return +un.right.Accept(*this);
	}
	else if (un.op == Operator::MINUS)
	{
		return -un.right.Accept(*this);
	}

	return 0.0;
}