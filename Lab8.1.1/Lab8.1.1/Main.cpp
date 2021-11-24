#include <iostream>
using namespace std;

bool SearchSign(const char* str, int &i1, int &i2)
{
	for (int i = i2; str[i] != '\0'; i++)
		if (str[i] == '!' &&
			str[i + 1] == '!' && str[i + 1] != '\0' &&
			str[i + 2] == '!' && str[i + 2] != '\0')
		{
			i1 = i;
			i2 = i + 2;
			return true;
		}
	return false;
}

void ReplaceSigns(char* str)
{
	int i1 = 0, i2 = 0;

	while (SearchSign(str, i1, i2)) 
	{	
		str[i1] = '*';
		str[i1+1] = '*';
		for (int i = i2; str[i] != '\0'; i++)
		{
			str[i] = str[i + 1];
		}
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