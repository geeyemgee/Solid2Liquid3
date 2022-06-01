#ifndef STACK_EVALUATOR_H
#define STACK_EVALUATOR_H

#include<iostream>
#include<stack>
#include"NumericConstant.h"
#include"BinaryExpression.h"
#include"UnaryExpression.h"
#include"Operator.h"

class StackEvaluator : public IExprVisitor
{
private:
	std::stack<double> evalStack;

public:
	StackEvaluator()
	{
	}

	double GetValue();
	double Visit(NumericConstant num);
	double Visit(BinaryExpression bin);
	double Visit(UnaryExpression un);
};

#endif

