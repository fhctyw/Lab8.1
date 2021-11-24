#include <iostream>
using namespace std;

bool SearchSign(const char* str, int i, int& i1, int& i2)
{
	if (str[i] != '\0')
	{
		if (str[i] == '!' &&
			str[i + 1] == '!' && str[i + 1] != '\0' &&
			str[i + 2] == '!' && str[i + 2] != '\0')
		{
			i1 = i;
			i2 = i + 2;
			return true;
		}
		SearchSign(str, i + 1, i1, i2);
	}
	else 
		return false;
}

void IterStr(char* str, int i)
{
	if (str[i] != '\0')
	{
		str[i] = str[i + 1];
		IterStr(str, i + 1);
	}
}

void ReplaceSigns(char* str, int i, int&i1, int&i2)
{
	if (SearchSign(str, i2, i1, i2))
	{
		str[i1] = '*';
		str[i1 + 1] = '*';
		IterStr(str, i2);
		ReplaceSigns(str, i + 1, i1, i2);
	}
}

int main()
{
	char* str = new char[101];
	cin.getline(str, 100);
	int i1 = 0, i2 = 0;
	if (SearchSign(str, 0, i1, i2))
		cout << "true\n";
	else cout << "false\n";

	i1 = i2 = 0;
	ReplaceSigns(str, 0, i1, i2);
	cout << str << endl;

}