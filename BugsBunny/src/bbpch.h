/*Precompiled headers are files that are compiled once and stored in a binary format. This makes them
compile faster.
They are used for two reasons:
	* compilation time reduces
	* more convenient, as not every include has to be added manually to every cpp file
Only NOT frequently used files should be included in the pch, as every time something gets changed
in the included file, the pch needs to get recompiled. If frequently files in the pch are changed, this
could even slow down the compilation time.
*/

#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include"BugsBunny/Log.h"

#ifdef BB_PLATFORM_WINDOWS
#include <Windows.h>
#endif