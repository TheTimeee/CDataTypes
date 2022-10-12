#include "TK_String.h"

char* TK_String_Get(void* inst)
{
	TK_String* str = (TK_String*)inst;

	if (str == NULL)
	{
		return "";
	}

	return str->m_str;
}

bool TK_String_Set(void* inst, const char* string)
{
	TK_String* str = (TK_String*)inst;
	
	if (str != NULL)
	{
		if (str->m_str != NULL)
		{
			//free allocated memory
			free(str->m_str);

			//const char* are always null terminated, therefore we can iterate trough the primitive and stop when we found it.
			int i = 0;
			while (string[i] != '\0')
			{
				i++;
			}

			//allocate memory and copy contents
			str->m_str = (char*)calloc(i + 1, sizeof(char));
			memcpy(str->m_str, string, i + 1);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	
	return true;
}

bool TK_String_Create(void* obj)
{
	TK_String* str = (TK_String*) obj;

	if (str != NULL)
	{
		str->inst = obj;

		//initialize memory
		str->m_str = (char*) calloc(1, sizeof(char));
		if (str->m_str != NULL)
		{
			str->m_str[0] = '\0';

			//initialize methods
			str->getString = &TK_String_Get;
			str->setString = &TK_String_Set;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	return true;
}

bool TK_String_Destroy(void* obj)
{
	TK_String* str = (TK_String*)obj;

	if (str != NULL)
	{
		//destroy instance by nulling all members and freeing allocated memory
		if (str->inst != NULL) str->inst = NULL;

		if (str->m_str != NULL) free(str->m_str);

		if (str->getString != NULL) str->getString = NULL;
		if (str->setString != NULL) str->setString = NULL;
	}
	else
	{
		return false;
	}

	return true;
}