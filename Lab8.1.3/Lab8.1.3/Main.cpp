#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

bool SearchSign(const char* str, int& i1, int& i2)
{
	const char* res_str = strstr(str, "!!!");
	if (res_str != NULL)
	{
		i1 = res_str - str;
		i2 = i1 + 2;
		return true;
	}
	else 
		return false;
}

void ReplaceSigns(char* str)
{
	int i1 = 0, i2 = 0;
	while (SearchSign(str, i1, i2))
	{
		str[i1] = '\0';
		str = strcat(str, "**");
		str = strcat(str, str + i2 + 1);
	}
}

int main()
{
	char* str = new char[101];
	cin.getline(str, 100);
	int i1 = 0, i2 = 0;
	if (SearchSign(str, i1, i2))
		cout << "true\n";
	else cout << "false\n";

	ReplaceSigns(str);
	cout << str << endl;

}