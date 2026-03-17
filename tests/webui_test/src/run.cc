#include "../html_content.hpp"

void windowsChecks(int* width, int* height);

void runWeb(const std::string& url) {
  try {
    webview::webview w(false, nullptr);
    w.set_title("Popo Browser");

    int width = 0, height = 0;
    windowsChecks(&width, &height);
    w.set_size(width, height, WEBVIEW_HINT_NONE);

    /*w.bind("cppNavigate", [&](const std::string& req) -> std::string {
      std::string url;
      size_t first = req.find('"');
      size_t last = req.rfind('"');
      if (first != std::string::npos && last != std::string::npos && last > first) {
        url = req.substr(first + 1, last - first - 1);
      }

      w.dispatch([&, url]() {
        w.navigate(url);
      });
      return "\"ok\"";
    });*/

    printf("[INFO] opening: %s\n", url.c_str());
    w.navigate(url);

    //w.set_html(HTML_CONTENT);

    printf("[INFO] Popo Browser started at %dx%d\n", width, height);
    w.run();

  } catch (const webview::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

void windowsChecks(int* width, int* height) {
  #ifdef _WIN32
  *width = GetSystemMetrics(SM_CXSCREEN);
  *height = GetSystemMetrics(SM_CYSCREEN);
  #else
  *width = 1920;
  *height = 1080;
  #endif
}

/*GET FROM FILE (before w.set_html)
    std::string htmlContent;  
    if (setHtmlContent(&htmlContent)) {
      w.set_html(htmlContent);
    } else {
      w.set_html("Something went wrong.");
    }

bool setHtmlContent(std::string *htmlContent) {
  std::ifstream file("~/dude_cpp/tests/webui_test/index.html");
  if (!file.is_open()) {
    std::perror("[ERR] File opening failed.");
    return false;
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  *htmlContent = buffer.str();

  return true;
}*/
