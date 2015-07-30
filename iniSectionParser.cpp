#include "iniSectionParser.h"

void ParseIniSection(const char* buf, int bufSz,
                     std::vector<NameValuePair>& nameValuePairs) {
  int keyStart = 0, valueStart = -1;
  for (int i = 0; i < bufSz; ++i) {
    if (keyStart > valueStart) {  // parse key
      if (buf[i] == '=') valueStart = i + 1;
    } else {  // parse value
      if (buf[i] == 0) {
        std::string key(buf + keyStart, buf + valueStart - 1);
        std::string value(buf + valueStart, buf + i);
        nameValuePairs.emplace_back(
            NameValuePair(std::move(key), std::move(value)));
        keyStart = i + 1;
      }
    }
  }
  /*const char* p = buf;
  while (p <= buf + bufSz && *p) {
    const char* pos = strchr(p, '=');
    if (!pos) return;
    std::string key(p, pos - p);
    p = pos + 1;
    std::string value(p);
    p += value.size() + 1;
    nameValuePairs.push_back(NameValuePair(key, value));
  }*/
}
