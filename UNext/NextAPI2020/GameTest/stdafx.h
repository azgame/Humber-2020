// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here





#define SAFE_DELETE(x) if (x) delete x; x = nullptr;
#define SAFE_DELETE_ARRAY(x) if (x) delete [] x; x = nullptr;