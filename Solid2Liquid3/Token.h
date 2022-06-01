#ifndef TOKEN_H
#define TOKEN_H

enum Token{
	ILLEGAL_TOKEN = -1,
	TOK_PLUS = 1,
	TOK_MUL,
	TOK_DIV,
	TOK_SUB,
	TOK_OPAREN,
	TOK_CPAREN,
	TOK_DOUBLE,
	TOK_NULL //end of string
};

#endif
