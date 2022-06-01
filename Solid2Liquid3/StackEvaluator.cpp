#include "StackEvaluator.h"

double StackEvaluator::GetValue()
{
	double retVal = evalStack.top();
	evalStack.pop();
	return retVal;
}

double StackEvaluator::Visit(NumericConstant num)
{
	evalStack.push(num.Num());
	return 0.0;
}

double StackEvaluator::Visit(BinaryExpression bin)
{
	bin.left.Accept(*this);
	bin.right.Accept(*this);

	double op1, op2;
	op1 = evalStack.top();
	evalStack.pop();
	op2 = evalStack.top();
	evalStack.pop();

	if (bin.op == Operator::PLUS)
	{
		evalStack.push(op1 + op2);
	}
	else if (bin.op == Operator::MUL)
	{
		evalStack.push(op1 * op2);
	}
	else if (bin.op == Operator::DIVIDE)
	{
		evalStack.push(op1 / op2);
	}
	else if (bin.op == Operator::MINUS)
	{
		evalStack.push(op1 - op2);
	}

	return 0.0;
}

double StackEvaluator::Visit(UnaryExpression un)
{
	un.right.Accept(*this);

	double op;

	if (un.op == Operator::PLUS)
	{
		op = evalStack.top();
		evalStack.pop();
		evalStack.push(op);
	}
	else if (un.op == Operator::MINUS)
	{
		op = evalStack.top();
		evalStack.pop();
		evalStack.push(-op);
	}

	return 0.0;
}