#include<iostream>
#include<exception>
#include"Operator.h"
#include"RuntimeContext.h"
#include"Expr.h"
#include"RDParser.h"
#include"StackEvaluator.h"
#include"TreeEvaluator.h"

using namespace std;


int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		cout << "Usage: Expr \"<expression>\" \n";
		cout << "Eg: Expr \"2*3+4\" \n";
		return -1;
	}

	try
	{
		RDParser parser(argv[1]);
		Expr& nd = parser.CallExpr();

		//cout << "The evaluated value is: " << nd << endl;

		IExprVisitor *s;
		StackEvaluator *st = StackEvaluator();
		s = &st;
		nd.Accept(s);
	}
	catch(exception e)
	{

	}

	return 0;
}