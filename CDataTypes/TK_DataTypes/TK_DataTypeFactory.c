#include "TK_DataTypeFactory.h"

bool TK_FactoryCreate(void* obj, enum TK_DataTypes type)
{
	switch (type)
	{
		case TK_STRING:
			return TK_String_Create(obj);
			break;
		case 2:
			printf("Lol");
			break;
		default:
			return false;
			break;
	}
}

bool TK_FactoryDestroy(void* obj, enum TK_DataTypes type)
{
	switch (type)
	{
	case TK_STRING:
		return TK_String_Destroy(obj);
		break;
	default:
		return false;
		break;
	}
}