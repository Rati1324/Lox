#ifndef LOX_H
#define LOX_H

#include <iostream>
#include <string>

extern bool hadError;

void error(int line, std::string message);

void report(int line, std::string where, std::string message);

#endif