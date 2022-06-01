#ifndef TREE_EVALUATOR_H
#define TREE_EVALUATOR_H

#include"Expr.h"
#include"IExprVisitor.h"
#include"NumericConstant.h"
#include"BinaryExpression.h"
#include"UnaryExpression.h"

class TreeEvaluator : public IExprVisitor
{
public:
	double Visit(NumericConstant num);
	double Visit(BinaryExpression bin);
	double Visit(UnaryExpression un);
};

#endif