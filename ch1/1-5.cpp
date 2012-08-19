// Time complexity O(n). Space complexity O(1)

#include "iostream"
using namespace std;

int GetWSNum(const char *str)
{
    int num = 0;
    for(int i = 0; i < strlen(str); i++)
        if(str[i] == ' ')
            ++num;
            
    return num;    
}

void PadStr(char *str)
{
     if(str == NULL)
        return;
        
     int len = strlen(str);
     if(len == 0)
        return;
        
     int wsNum = GetWSNum(str);        
     
     // add 2*wsNum more space
     str[len - 1 + wsNum * 2 + 1] = '\0';
     int tail = len - 1 +  wsNum * 2;
     for(int i = len - 1; i >= 0; i--)
     {
        if(str[i] != ' ')
            str[tail--] = str[i];
        else
        {
            str[tail--] = '0';
            str[tail--] = '2';
            str[tail--] = '%';    
        }          
     }
}

int main()
{
    string sArr[] = {"I'am fine, thank you.", "hello", "hi   hi ", "", "\0", "   "}; 
    
    for(int i = 0; i < sizeof(sArr) / sizeof(string *); i++)
    {
        if(sArr[i].c_str() == NULL) continue;
        cout << sArr[i] << " # ";
        PadStr((char *)sArr[i].c_str());
        cout << sArr[i] << endl;
    }   
    
    system("pause");
    return 0;
}
