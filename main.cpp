/*
what command line parameter format is supported:
1. simple flag (no value assigned), for example "-g"
2. parameter without separator (written together), for example "-O2", where 2 is the value of the -O parameter
3. parameter with a value and a separator, for example "-I ../include", where the value is "../include", and the separator can be a space (often also = or a colon is used)
*/

#include <iostream>
#include "clparser.h"

int main(int argc, char* argv[])
{
	using namespace std;

	clparser cmd;
	cmd.add_param("-a", " :=", "\\S+");
	cmd.add_param("-b");
	cmd.add_param("-x", "", "\\d+");
	cmd.add_param("-xyz", "", "\\d+");

	/*char* argv[] = { "clparser.exe", "-a", "123", "-b", "-x3", "-xyz5" };
	int argc = sizeof(argv)/sizeof(char*);*/

	if (!cmd.parse(argc, argv))
		cout << "Error in command line!" << endl;
	else
	{
		for (size_t i = 0, count = cmd.get_options_count(); i < count; ++i)
		{
			cout << cmd.get_name(i);
			std::string value = cmd.get_value(i);
			if (!value.empty())
				cout << " = " << value;
			cout << endl;
		}
	}
	return 0;
}
