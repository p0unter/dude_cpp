#pragma once

const char* HTML_CONTENT = R"HTML(<!DOCTYPE html>
<html>
<body style="font-family: sans-serif; padding: 20px;">
  <h1>Popo Browser</h1>
  <p>Enter URL or search term:</p>
  <input type="text" id="url" size="50" placeholder="google.com">
  <button onclick="go()">Go</button>
  <p id="status"></p>

  <script>
    function go() {
      var input = document.getElementById("url").value.trim();
      if (!input) return;

      var url = input;
      if (!input.startsWith("http://") && !input.startsWith("https://")) {
        if (input.includes(".") && !input.includes(" ")) {
          url = "https://" + input;
        } else {
          url = "https://www.google.com/search?q=" + encodeURIComponent(input);
        }
      }

      document.getElementById("status").innerText = "Loading: " + url;
      cppNavigate(url);
    }

    document.getElementById("url").addEventListener("keypress", function(e) {
        if (e.key === "Enter") go();
    });
        document.getElementById("url").focus();
        </script>
        </body>
        </html>)HTML";
