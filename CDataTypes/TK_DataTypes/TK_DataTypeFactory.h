#ifndef __TK_FACTORY_H__
#define __TK_FACTORY_H__

#include "shared_dependencies.h"

#include "TK_Datatypes.h"

bool TK_FactoryCreate(void* obj, enum TK_DataTypes type);
bool TK_FactoryDestroy(void* obj, enum TK_DataTypes type);

#endif