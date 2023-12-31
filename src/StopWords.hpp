#ifndef __STOP_WORDS_HPP__
#define __STOP_WORDS_HPP__

#include <unordered_set>
#include <string>

struct StopWords {
  std::unordered_set<std::string> mp;
  StopWords(const std::locale &loc);
  bool isStopWord(const std::string &word);
};

#endif
