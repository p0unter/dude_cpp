#include "app.hpp"


#ifdef _WIN32

int WINAPI WinMain(HINSTANCE /*hInst*/, HINSTANCE /*hPrevInst*/,
    LPSTR /*lpCmdLine*/, int /*nCmdShow*/) {
  std::string url = lpCmdLine && strlen(lpCmdLine) > 0 ? lpCmdLine : "https://duckduckgo.com";
  std::string nurl = normalizeUrl(url);
  runWeb(nurl);
  return 0;
}
#else
int main(int argc, char** argv) {
  std::string url = (argc > 1) ? argv[1] : "https://duckduckgo.com";
  std::string nurl = normalizeUrl(url);
  runWeb(nurl); 
  
  return 0;
}
#endif

 
