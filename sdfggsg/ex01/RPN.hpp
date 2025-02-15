#pragma once
#include <iostream>
#include <stack>
#include <cstdlib>

int		is_operator(char a);
void	start(std::stack<int> &stack, std::string input);
void	operation(std::stack<int> &stack, char op);
int		is_valid(const char *s, int i);