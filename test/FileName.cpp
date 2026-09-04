#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char s1[] = "Happy Birthday to You";
	char s2[25], s3[15];

	cout << "строка1: " << s1 << endl;
	strcpy_s(s2, s1);
	cout << "строка2: " << s2 << endl;
	strncpy_s(s3, s1, 14);
	s3[14] = '\0';
	cout << "строка3: " << s3 << endl;

	return 0;
}
