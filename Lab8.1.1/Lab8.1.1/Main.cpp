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
	while (SearchSign(str, i1, i2) && str != nullptr) {
		if (i1 != 0) {
			str[i1 - 1] = '*';
			if (i1 - 1 != 0)
				str[i1 - 2] = '*';
		}
		if (str[i2 + 1] != '\0') {
			str[i2 + 1] = '*';
			if (str[i2 + 2] != '\0')
				str[i2 + 2] = '*';
		}
	}
}

int main()
{
	char* str = new char[101];
	cin.getline(str, 100);
	int i1 = 0, i2 = 0;
	if (SearchSign(str, i1, i2))
		cout << i1 << " " << i2 << " " << "true\n";
	else cout << "false\n";

	ReplaceSigns(str);
	cout << str << endl;

}