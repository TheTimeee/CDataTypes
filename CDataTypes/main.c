#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "./Tk_DataTypes/TK_DataTypes.h"

int main(void)
{
	TK_String str;
	TK_FactoryCreate(&str, TK_STRING);

	str.setString(str.inst, "Foo1\n");
	printf(str.getString(str.inst));

	str.setString(str.inst, "Foo2\n");
	printf(str.getString(str.inst));

	str.setString(str.inst, "!!!\n");
	printf(str.getString(str.inst));

	TK_FactoryDestroy(&str, TK_STRING);
	
	return 0;
}