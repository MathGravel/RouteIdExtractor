#ifndef ___PARSER_H___
#define ___PARSER_H___
#include <locale>

struct Parser : std::ctype<char> {
  Parser() : std::ctype<char>(get_table()) {}
  static mask const* get_table()
  {
    static mask rc[table_size];
    rc[','] = std::ctype_base::space;
    rc['\n'] = std::ctype_base::space;
    rc['\\'] = std::ctype_base::blank;
    rc[':'] = std::ctype_base::blank;
    rc['/'] = std::ctype_base::blank;
    rc[' '] = std::ctype_base::blank;
    return &rc[0];
  }
};

struct ParserDesc : std::ctype<char> {
  ParserDesc() : std::ctype<char>(get_table()) {}
  static mask const* get_table()
  {
    static mask rc[table_size];
    rc['"'] = std::ctype_base::space;
    rc['\n'] = std::ctype_base::space;
    rc[' '] = std::ctype_base::blank;
    return &rc[0];
  }
};


#endif