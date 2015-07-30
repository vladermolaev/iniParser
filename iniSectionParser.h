#pragma once
#include <string>
#include <vector>
#include <utility>

typedef std::pair<std::string, std::string> NameValuePair;

void ParseIniSection(const char* buf, int bufSz,
                     std::vector<NameValuePair>& nameValuePairs);
