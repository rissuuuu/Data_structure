#include <hoc.h>
#include "y.tab.h"
#include <math.h>

extern double Log(), Log10(), Exp(), Sqrt(), integer();
static struct{
	
	char *name;
	double cval;
	
} consts[]={
	"PI", 3.1415,
	"E", 2.71828,
	"GAMMA", 0.57721,
	"DEG", 57.29577,
	"PHI", 1.6180,
	0, 0
	};
static struct{
	char *name;
	double (*func)();
}builtins[]={
	"sin", sin,
	"cos", cos,
	"atan", atan,
	"log", Log,
	"log10",Log10,
	"exp", Exp,
	"sqrt", Sqrt,
	"int", integer,
	"abs", fabs,
	0,0
};

init(){
	int i;
	Symbol *s;
	
	for(i=0;consts[i].name;i++)
		install(consts[i].name, s,consts[i].cval);
	
	for(i=0;builtins[i].name;i++){
		
		s=install(builtins[i].name,BLTIN,0.0);
		s->u.ptr=builtins[i].func;
	}
	
	
	
	
}
	
}

	
	
	
	