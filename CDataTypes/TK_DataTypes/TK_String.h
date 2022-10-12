#ifndef __TK_STRING_H__
#define __TK_STRING_H__

#include "shared_dependencies.h"

#include "TK_DataTypeFactory.h"

bool TK_String_Create(void* obj);
bool TK_String_Destroy(void* obj);

char* TK_String_Get(void* inst);
bool TK_String_Set(void* inst, const char* string);

typedef struct TK_String
{
	void* inst;

	char* m_str;
	
	char* (*getString)(void* inst);
	bool (*setString)(void* inst, const char* string);
} TK_String;

#endif