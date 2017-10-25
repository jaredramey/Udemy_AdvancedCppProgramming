#include <iostream>

//Example function throwing an error higher up the stack
void MightGoWrong();
//Example function showing that thrown error can be caught anywhere up the call stack
void Use_MightGoWrong();

int main()
{
	//Try the example function
	try
	{
		Use_MightGoWrong();
	}
	//Catch an int error
	catch (int e)
	{
		std::cout << "Error Code: " << e << std::endl;
	}
	//Catch a char
	catch (char const *e)
	{
		std::cout << "Error Message: " << e << std::endl;
	}
	//Catch a string
	catch (std::string *e)
	{
		std::cout << "String error message: " << e << std::endl;
		delete e;
	}

	//Show that the program is still running
	std::cout << "Program still running." << std::endl;

	getchar();
	return 0;
}

void Use_MightGoWrong()
{
	MightGoWrong();
}

void MightGoWrong()
{
	bool error = false;
	bool error2 = true;

	if (error)
	{
		throw "Something went wrong...";
	}
	if (error2)
	{
		throw new std::string("Something else went wrong...");
	}
}