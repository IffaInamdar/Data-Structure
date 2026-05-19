#include <iostream>
#include <string>

using namespace std;

class stack
{
private:
	char *array;
	int top;
	int size;

public:
	stack(int size)
	{
		this->size = size;
		array = new char[size];
		top = -1;
	}

	bool isEmpty()
	{
		return top == -1;
	}


	void push(char op)
	{
		if (top == size - 1)
		{
			cout << "Stack overflow\n";
			return;
		}
		top++;
		array[top] = op;
	}

	char pop()
	{
		if (isEmpty())
		{
			cout << "Stack empty\n";
			
		}
		int poppedElement = array[top];
		top--;
		return poppedElement;
	}

	char peek()
	{
		if (isEmpty())
		{
			cout << "Stack is empty\n";
			
		}
		return array[top];
	}
};

int precedence(char op)
{
	if (op == '=')
		return 1;
	if (op == '+' || op == '-')
		return 2;
	if (op == '*' || op == '/')
		return 3;
	return 0;
}

bool isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=');
}

void infixToPostfix(string e)
{
	stack s(e.length());

	int i = 0;
	while (e[i] != '\0')
	{
		if (isOperator(e[i]))
		{
			while (!s.isEmpty() && precedence(s.peek()) >= precedence(e[i]))
			{
				cout << s.pop();
			}
			s.push(e[i]);
			i++;
		}
		else
		{
			cout << e[i];
			i++;
		}
	}

	while (!s.isEmpty())
	{
		cout << s.pop();
	}
}

int main()
{
	string expression;
	cout<<"Enter the Infix expression : "<<endl;
	cin>>expression;
	infixToPostfix(expression);
	cout << endl;
	return 0;
}