// Time complexity O(n+m). Space complexity O(1)

#include "iostream"
using namespace std;

void ToLowerAndTrimAll(char *str)
{
    int tail = 0;
    for(int i = 0; i < strlen(str); i++)
    {        
        if(str[i] != ' ')
        {        
            if(str[i] >= 'A' && str[i] <= 'Z')    
                str[i] -= 'A' - 'a';  
            str[tail++] = str[i];    
        }   
                         
    } 
    
    // string null or empty do not need append '\0'
    if(strlen(str) > 0)
        str[tail] = '\0';   
}

bool IsAnagram(const char *str1, const char *str2)
{
    // string null
    if(str1 == NULL && str2 == NULL)
        return true;
    // string empty
    else if(str1 != NULL && strlen(str1) == 0
        && str2 != NULL && strlen(str2) == 0)
        return true;
    else
    {
        // Use NOR operator. str1 NOR str2 == 0 if they are anagram        
        int ires = (int)str1[0];
        for(int i = 1; i < strlen(str1); i++)            
            ires = ires ^ str1[i];
        for(int i = 0; i < strlen(str2); i++)             
            ires = ires ^ str2[i];
            
        if(ires != 0)
            return false;
        else
            return true;   
    }
}

int main()
{
    string strArr1[] = {"hell o", "George Bush", "William Shakespeare", "Tom Marvolo  Riddle!"};  
    string strArr2[] = {"very much", "He bugs Gore", " I am a weakish speller", "I Am Lord  !Voldemort"};      

    for(int i = 0; i < sizeof(strArr1) / sizeof(string *); i++)
    {
        cout << strArr1[i] << " # " << strArr2[i];
        ToLowerAndTrimAll((char *)strArr1[i].c_str());   
        ToLowerAndTrimAll((char *)strArr2[i].c_str()); 
        cout << " # " << IsAnagram(strArr1[i].c_str(), strArr2[i].c_str()) << endl;
    }
    
    system("pause");
    return 0;
}
