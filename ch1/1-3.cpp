// Time complexity O(n^2). Space complexity O(1)

#include "iostream"
using namespace std;

void RemoveDup(char *str)
{
    int len = strlen(str);
        
    // set to null if found duplicate characters
	for(int i = 0; i < len; i ++)
		for(int j = i + 1; j < len; j++)
        {
		  if(str[j] != '\0' && str[i] == str[j])
		      str[j] = '\0';
        }

    // remove null characters within the original string
    for(int i = 0; i < len; i++)
    {
	   if(str[i] == '\0')
        {
	       int idxNotNull = i;
           while(idxNotNull < len && str[++idxNotNull] == '\0');
	       str[i] = str[idxNotNull];
	       str[idxNotNull] = '\0';
        }
    }    
}

int main()
{
	string strArr[] = {"abccba", "abcdbefacghi", "abc@er@ag!g",
                    "a bs  bs f$ % ' \"\"", "", "\0", "aaa"};
	for(int i = 0; i < sizeof(strArr) / sizeof(string *); i++)
    {
		cout << strArr[i] << "\t";
		RemoveDup((char *)strArr[i].c_str());
        cout << strArr[i] << endl;
    }

	system("pause");
    return 0;
}
