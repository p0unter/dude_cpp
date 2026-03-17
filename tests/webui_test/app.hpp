#ifndef APP_HPP
#define APP_HPP

#include "webview/core/include/webview.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

#include "src/run.cc"
#include "src/search.cc"

// run
extern void runWeb(const std::string& url);

// search
extern bool isUrl(const std::string& input);
extern std::string normalizeUrl(const std::string& input);

#endif // APP_HPP
