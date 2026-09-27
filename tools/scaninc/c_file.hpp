// Copyright(c) 2017 YamaArashi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef C_FILE_H
#define C_FILE_H

#include <memory>
#include <set>
#include <string>

#include "scaninc.hpp"

class CFile {
 public:
  CFile(std::string path);
  ~CFile();
  void FindIncDirectives();
  const std::set<std::string>& GetIncbins() { return m_incbins; }
  const std::set<std::string>& GetIncludes() { return m_includes; }
  const std::set<std::string>& GetInccodes() { return m_inccodes; }

 private:
  char* m_buffer;
  int m_pos;
  int m_size;
  int m_lineNum;
  std::string m_path;
  std::set<std::string> m_incbins;   // INCBIN_XX files
  std::set<std::string> m_includes;  // #include files
  std::set<std::string> m_inccodes;  // INCASM and INCFUNC files

  bool ConsumeHorizontalWhitespace();
  bool ConsumeNewline();
  bool ConsumeComment();
  void SkipWhitespace();
  bool CheckIdentifier(const std::string& ident);
  void CheckInclude();
  void CheckIncbin();
  void CheckIncCode();
  std::string ReadPath();
};

#endif  // C_FILE_H
