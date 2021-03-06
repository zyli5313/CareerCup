#include "iostream"
using namespace std;

void ReverseStr(char *str)
{
    if( strlen( str ) > 0 ) {
        char* first = &str[ 0 ];
        char* last = &str[ strlen( str ) - 1 ];
        while( first < last ) {
            char tmp = *first;
            *first = *last;
            *last = tmp;
            ++first;
            --last;
        }
    }
}

int main()
{
    // !!!!!!char *str, defines a constant string!!!!
	char str[] = "onetwothree!@#$";
	ReverseStr(str);
	cout << str;
	
	system("pause");
	return 0;
}
