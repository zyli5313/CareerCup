#include "iostream"
#include "string"
using namespace std;

#define BITSPERINT 32
int g_bitmap[4] = {0};    // store the bitmap of 128 characters (to indicate if the character has appeared 

bool Test(char ch)
{
	int quo = (int)ch / BITSPERINT;
	int rem = (int)ch % BITSPERINT;
	int itest = g_bitmap[quo];
	itest >>= rem - 1;

	// reset all bits to 0 except the bit of "ch" and test if it appears
	return itest & 1;
}

void Set(char ch)
{
	int quo = (int)ch / BITSPERINT;
	int rem = (int)ch % BITSPERINT;
	int ior = 1;
	ior = ior << rem - 1;

	// set the bit of "ch" in global bitmap
	g_bitmap[quo] |= ior;
}

bool IsStrUnique(const char *str, int len)
{
	bool result = true;
	for(int i = 0; i < len; i++)
	{
		// if str[i] has appear, return not unique. Otherwise set its corresponding bit to 1
		if(Test(str[i]))
		{
			result = false;
			break;    
		}    
		else
			Set(str[i]);
	}    

	return result;
}

int main()
{
	//char strArr[][] = {"append", "once", "string", "abccba"};
	string strArr[] = {"append", "once", "string", "abccba", "@!#ad@es"};
	

	for(int i = 0; i < sizeof(strArr) / sizeof(string *); i++)
	{
		cout << strArr[i] << " " << IsStrUnique(strArr[i].c_str(), strArr[i].length()) << endl;
		g_bitmap[0] = g_bitmap[1] = g_bitmap[2] = g_bitmap[3] = 0;
	}
	system("pause");
	return 0;
}
