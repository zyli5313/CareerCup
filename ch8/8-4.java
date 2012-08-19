/*
 * Careercup 8-4
 * Author: zy li
 */

import java.util.*;
import java.lang.Object;
import java.io.*;

public class Perm {
    private String m_str;
    private int m_len;

    public List<String> GetPermStr(int idx) {
        List<String> strPermList;
        if(idx == m_len) {
            strPermList = new ArrayList<String>();
        }
        else {
            strPermList = GetPermStr(idx + 1);
            // basic case
            if(strPermList.size() == 0) {
                strPermList.add(m_str.substring(idx, idx+1));
                return strPermList;
            }

            char curch = m_str.charAt(idx);
            List<String> newPermList = new ArrayList<String>();

            for(String str : strPermList) {
                for(int i = 0; i <= str.length(); i++) {
                    int cnt = 0;
                    StringBuffer sb = new StringBuffer();
                    
                    for(char ch : str.toCharArray()) {
                        if(cnt++ != i)
                            sb.append(ch);
                        else {
                            sb.append(curch);
                            sb.append(ch);
                        }
                    }
                    // put curch in the back of the str
                    if(cnt == i)
                        sb.append(curch);
                   
                    newPermList.add(sb.toString());
                }
            }

            strPermList.addAll(newPermList);
        }

        return strPermList;
    }
    
    public Perm(String str) {
        m_str = str;
        m_len = str.length();
    }

    public void PrintPermStr(List<String> permList) {
        for(String str : permList)
            if(str.length() == m_len)
                System.out.println(str);
    }

    public static void main(String args[]) {
       Perm perm = new Perm("happy");
       List<String> permList = perm.GetPermStr(0);
       perm.PrintPermStr(permList);
    }
}
