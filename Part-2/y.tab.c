#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20121003

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
	#include <stdio.h>
	#include <stdlib.h>
	int yylex(void);
	void yyerror (char const *s) {
   		fprintf (stderr, "%s\n", s);
 	}
#line 26 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ADD_ASSIGN 257
#define SUB_ASSIGN 258
#define MUL_ASSIGN 259
#define DIV_ASSIGN 260
#define MOD_ASSIGN 261
#define AND_ASSIGN 262
#define XOR_ASSIGN 263
#define OR_ASSIGN 264
#define RIGHT_OP 265
#define LEFT_OP 266
#define INC_OP 267
#define DEC_OP 268
#define PTR_OP 269
#define AND_OP 270
#define OR_OP 271
#define LE_OP 272
#define GE_OP 273
#define EQ_OP 274
#define NE_OP 275
#define ID 276
#define DATA_TYPE 277
#define IF 278
#define ELSE 279
#define WHILE 280
#define FOR 281
#define DO 282
#define CONTINUE 283
#define BREAK 284
#define RETURN 285
#define NUM 286
#define INTEGER 287
#define CHAR_LIT 288
#define STRING 289
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    1,    3,    3,    3,    5,    5,    2,
    6,    6,    6,    8,    8,    8,    7,    7,    9,    9,
   10,   10,   10,   10,   10,   10,   11,   11,   12,   12,
   12,   13,   13,   13,   13,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   16,   16,   16,   16,   17,   17,
   17,   14,   14,   14,   14,   14,
};
static const short yylen[] = {                            2,
    0,    2,    1,    1,    3,    5,    6,    1,    2,    6,
    0,    2,    4,    0,    1,    3,    2,    3,    0,    2,
    1,    1,    1,    1,    1,    2,    5,    7,    5,    7,
    9,    2,    2,    2,    3,    1,    1,    3,    3,    3,
    3,    3,    3,    3,    4,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    3,    4,    0,    2,    5,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   50,   51,   47,
   48,   49,   52,   53,   54,   60,   61,   57,   58,   46,
    0,   55,   56,   59,   62,   63,   64,   65,   66,    0,
    0,    0,    0,    0,    0,    0,    6,    0,    0,    0,
    0,    0,   39,   40,   42,   44,   38,   41,   43,    7,
    0,    0,   10,    0,   45,   13,    0,    0,    0,    0,
    0,    0,    0,    0,   17,    0,    0,   21,   22,    0,
    0,   23,   24,   25,   16,    0,    0,    0,    0,    0,
   32,   33,   34,    0,    9,   26,   18,   20,    0,    0,
    0,    0,   35,    0,    0,    0,    0,    0,   29,    0,
    0,    0,    0,    0,   28,    0,   30,    0,   31,
};
static const short yydgoto[] = {                          2,
    3,    4,   76,   77,   78,   17,   79,   52,   80,   81,
   82,   83,   84,   40,   41,   42,   43,
};
static const short yysindex[] = {                      -275,
 -268,    0, -275,    0,    0,   -7,    0,    0, -233, -261,
 -258,  -33,  -22,  -28,  -56, -225,   16,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -218,    0,    0,    0,    0,    0,    0,    0,    0, -233,
 -233, -233, -233, -233, -233, -233,    0,    1,   15,  -62,
   18,   23,    0,    0,    0,    0,    0,    0,    0,    0,
 -258, -122,    0, -218,    0,    0, -211,   27,   28,   30,
  -82,   12,   13,  -54,    0, -204,   17,    0,    0,  -51,
  -82,    0,    0,    0,    0,  -25, -233, -233, -233, -205,
    0,    0,    0,   20,    0,    0,    0,    0,   36,   40,
   21,   42,    0,  -82,  -82, -233, -233, -196,    0,   26,
   45,  -82, -233,   29,    0,   46,    0,  -82,    0,
};
static const short yyrindex[] = {                        89,
    0,    0,   89,    0,    0,    0,    0,    0,    0,    0,
   49,  -35,  -24,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   53,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   54,    0,
   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   49,    0,    0,   53,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -107,    0,    0,    0,    0,
  -27,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -93,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                        94,
    0,    0,   39,    4,   24,   38,   51,   41,   22,  -49,
    0,    0,    0,   91,    0,   93,   95,
};
#define YYTABLESIZE 251
static const short yytable[] = {                         34,
   62,    1,   75,   39,   93,   37,   31,    6,   37,   35,
   34,   36,   14,   38,   39,    8,   36,    8,   16,   37,
   35,   90,   36,   37,   38,   15,   32,   30,   33,   27,
   47,   27,   11,    8,   36,    9,   48,   32,    5,   33,
   62,    5,   12,   53,   54,   55,   56,   57,   58,   59,
   49,    8,   13,    9,  108,  109,   50,   51,   61,   60,
   62,   64,  115,   65,   86,   10,   87,   88,  119,   89,
   91,   92,   67,   97,  102,   96,  104,   94,  103,  106,
  105,  107,  112,   10,  113,  114,  118,  117,    1,   11,
   99,  100,  101,   14,   12,   15,    7,   19,   66,   95,
   63,    0,   98,   44,   85,   45,    0,   46,    0,  110,
  111,    0,    0,    0,    0,    0,  116,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   12,   67,   68,    0,   69,   70,   71,
   72,   73,   74,   13,    0,    0,    0,    0,    8,    0,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    0,
    0,    0,   27,   27,   27,    0,   27,   27,   27,   27,
   27,   27,   27,   12,   67,   68,    0,   69,   70,   71,
   72,   73,   74,   13,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   12,    0,   18,   19,   20,   21,   22,   23,   24,
   25,   13,    0,    0,    0,    0,   26,   27,   28,   29,
    0,    0,    0,    0,    0,    0,    0,   26,   27,   28,
   29,
};
static const short yycheck[] = {                         33,
  123,  277,  125,   37,   59,   41,   40,  276,   42,   43,
   33,   45,    9,   47,   37,  123,   41,  125,  277,   42,
   43,   71,   45,   59,   47,  287,   60,   61,   62,  123,
   59,  125,   40,   59,   59,   61,   93,   60,    0,   62,
  123,    3,  276,   40,   41,   42,   43,   44,   45,   46,
  276,   59,  286,   61,  104,  105,   41,  276,   44,   59,
  123,   44,  112,   41,  276,   91,   40,   40,  118,   40,
   59,   59,  277,  125,  280,   59,   41,   74,   59,   59,
   41,   40,  279,   91,   59,   41,   41,   59,    0,   41,
   87,   88,   89,   41,   41,   41,    3,  125,   61,   76,
   50,   -1,   81,   13,   64,   13,   -1,   13,   -1,  106,
  107,   -1,   -1,   -1,   -1,   -1,  113,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  276,  277,  278,   -1,  280,  281,  282,
  283,  284,  285,  286,   -1,   -1,   -1,   -1,  276,   -1,
  278,  279,  280,  281,  282,  283,  284,  285,  286,   -1,
   -1,   -1,  276,  277,  278,   -1,  280,  281,  282,  283,
  284,  285,  286,  276,  277,  278,   -1,  280,  281,  282,
  283,  284,  285,  286,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  276,   -1,  257,  258,  259,  260,  261,  262,  263,
  264,  286,   -1,   -1,   -1,   -1,  270,  271,  272,  273,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,
  273,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 289
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ADD_ASSIGN","SUB_ASSIGN","MUL_ASSIGN",
"DIV_ASSIGN","MOD_ASSIGN","AND_ASSIGN","XOR_ASSIGN","OR_ASSIGN","RIGHT_OP",
"LEFT_OP","INC_OP","DEC_OP","PTR_OP","AND_OP","OR_OP","LE_OP","GE_OP","EQ_OP",
"NE_OP","ID","DATA_TYPE","IF","ELSE","WHILE","FOR","DO","CONTINUE","BREAK",
"RETURN","NUM","INTEGER","CHAR_LIT","STRING",
};
static const char *yyrule[] = {
"$accept : strt",
"strt :",
"strt : external_declaration strt",
"external_declaration : function_definition",
"external_declaration : declaration",
"declaration : DATA_TYPE ID ';'",
"declaration : DATA_TYPE ID '=' expr ';'",
"declaration : DATA_TYPE ID '[' INTEGER ']' ';'",
"declaration_list : declaration",
"declaration_list : declaration declaration_list",
"function_definition : DATA_TYPE ID '(' arg_list ')' compound_stmts",
"arg_list :",
"arg_list : DATA_TYPE ID",
"arg_list : DATA_TYPE ID ',' arg_list",
"param_list :",
"param_list : ID",
"param_list : ID ',' param_list",
"compound_stmts : '{' '}'",
"compound_stmts : '{' stmt_list '}'",
"stmt_list :",
"stmt_list : stmt stmt_list",
"stmt : declaration_list",
"stmt : compound_stmts",
"stmt : conditional_stmt",
"stmt : iteration_stmt",
"stmt : jump_stmt",
"stmt : expr ';'",
"conditional_stmt : IF '(' expr ')' stmt",
"conditional_stmt : IF '(' expr ')' stmt ELSE stmt",
"iteration_stmt : WHILE '(' expr ')' stmt",
"iteration_stmt : DO stmt WHILE '(' expr ')' ';'",
"iteration_stmt : FOR '(' expr ';' expr ';' expr ')' stmt",
"jump_stmt : CONTINUE ';'",
"jump_stmt : BREAK ';'",
"jump_stmt : RETURN ';'",
"jump_stmt : RETURN expr ';'",
"expr : NUM",
"expr : ID",
"expr : NUM binary_op expr",
"expr : ID binary_op expr",
"expr : ID assignment_op expr",
"expr : NUM relational_op expr",
"expr : ID relational_op expr",
"expr : NUM logical_op expr",
"expr : ID logical_op expr",
"expr : ID '(' param_list ')'",
"assignment_op : '='",
"assignment_op : MUL_ASSIGN",
"assignment_op : DIV_ASSIGN",
"assignment_op : MOD_ASSIGN",
"assignment_op : ADD_ASSIGN",
"assignment_op : SUB_ASSIGN",
"assignment_op : AND_ASSIGN",
"assignment_op : XOR_ASSIGN",
"assignment_op : OR_ASSIGN",
"relational_op : '<'",
"relational_op : '>'",
"relational_op : LE_OP",
"relational_op : GE_OP",
"logical_op : '!'",
"logical_op : AND_OP",
"logical_op : OR_OP",
"binary_op : '+'",
"binary_op : '-'",
"binary_op : '*'",
"binary_op : '/'",
"binary_op : '%'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 124 "parser.y"

int main(){
	yyparse();
	return 0 ;
}

#line 355 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
