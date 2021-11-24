#include <iostream>
#include <string>
using namespace std;

bool SearchSign(string str)
{
	return str.find("!!!") != string::npos;
}

void ReplaceSigns(string &str)
{
	while (SearchSign(str))
	{
		size_t i_first = str.find("!!!");
		str = str.replace(i_first, 2, "**");
		str.erase(i_first + 2, 1);
	}
}

int main()
{
	string str;
	getline(cin, str);
	int i1 = 0, i2 = 0;
	if (SearchSign(str))
		cout << "true\n";
	else cout << "false\n";

	ReplaceSigns(str);
	cout << str << endl;

}