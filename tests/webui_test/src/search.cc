bool isUrl(const std::string& input) {
    return input.find("http://") == 0 || 
           input.find("https://") == 0 || 
           input.find("file://") == 0 ||
           (input.find(".") != std::string::npos && 
            input.find(" ") == std::string::npos);
}

std::string normalizeUrl(const std::string& input) {
  if (isUrl(input)) {
    return input;
  }
  return "https://www.duckduckgo.com/search?q=" + input;
}
