#include "RPN.hpp"

int is_operator(char a)
{
	const char *symbols = "+-/*";
	int i = -1;
	while (symbols[++i])
		if (symbols[i] == a)
			return (1);
	return (0);
}

int is_valid(const char *s, int i)
{
	while(s[i])
	{
		if (is_operator(s[i]))
			return (1);
		i++;
	}
	return (0);
}

void operation(std::stack<int> &stack, char op)
{
	int nbr;

	if (stack.size() < 2)
	{
		std::cout << "Error!" << std::endl;
		exit(1);
	}
	if(op == '+')
	{
		nbr = stack.top();
		stack.pop();
		nbr = nbr + stack.top();
		stack.pop();
		stack.push(nbr);
	}
	else if(op == '-')
	{
		nbr = stack.top();
		stack.pop();
		nbr = stack.top() - nbr;
		stack.pop();
		stack.push(nbr);
	}
	else if(op == '*')
	{
		nbr = stack.top();
		stack.pop();
		nbr = nbr * stack.top();
		stack.pop();
		stack.push(nbr);
	}
	else if(op == '/')
	{
		nbr = stack.top();
		stack.pop();
		nbr = stack.top() / nbr;
		stack.pop();
		stack.push(nbr);
	}
}

void start(std::stack<int> &stack, std::string input)
{
	int i = -1;
	int nbr;
	int count = 0;
	(void)count;

	while (input[++i])
	{
		if (input[i] == ' ')
			continue;
		else if (is_operator(input[i]))
		{
			operation(stack, input[i]);
		}
		else if (input[i] >= '0' && input[i] <= '9')
		{
			nbr = input[i] - '0';
			stack.push(nbr);
			if (stack.size() == 2 && !is_valid(input.c_str(), i))
			{
				std::cout << "Error" << std::endl;
				exit(1);
			}
		}
		else
		{
			std::cout << "Error" << std::endl;
			exit(1);
		}
	}
	std::cout << "Result: " << stack.top() << std::endl;
}



