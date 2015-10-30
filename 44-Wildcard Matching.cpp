/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/
//20ms
class Solution {
public:

    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int sAnchor = -1, pAnchor = -1;

        while(i < s.length() && j < p.length())
        {
            if(p[j] == '*')
            {
                pAnchor = j;
                // look for the next non-'*' char
                j++;
                bool hasQ = false;
                while(j < p.length())
                {
                    if(p[j] == '*')
                        j++;
                    else if(p[j] == '?')
                    {
                        if(!hasQ) sAnchor = i;
                        hasQ = true;
                        i++; j++;
                    }
                    else break; // get a non-'*'&'?' char
                }
                if(i > s.length()) return false;
                if(j == p.length()) return true;

                while(i < s.length())
                {
                    if(s[i] == p[j])
                    {
                        if (!hasQ) sAnchor = i;
                        i++; j++;
                        break;
                    }
                    else
                    {
                        i++;
                    }
                }
            }

            else if(p[j] != '?')
            {
                if(s[i] != p[j])
                {
                    if(pAnchor >= 0)
                    {
                        i = sAnchor; sAnchor = -1;
                        j = pAnchor; pAnchor = -1;
                        i++;
                    }
                    else return false;
                }
                else // (s[i] == p[j])
                {
                    i++; j++;
                }
            }

            else // p[j] == '?'
            {
                i++; j++;
            }

            if(i < s.length() && j == p.length())
                if(pAnchor >= 0)
                {
                    i = sAnchor; sAnchor = -1;
                    j = pAnchor; pAnchor = -1;
                    i++;
                }
        }

        if(i == s.length())
        {
            while (j < p.length() && p[j] == '*')
                j++;
            return j == p.length();
        }

        return false;
    }
};

//16ms 20ms,52.84
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s == p) return true;
        int m = s.size();
        int n = p.size();
        int posS = 0;
        int posP = 0;
        int posStar = -1;
        int posOfS  = -1;
        while(posS<m){
            if(posP<n && (s[posS] == p[posP]||p[posP]=='?')){
                ++posS;
                ++posP;
            }else if(posP<n && p[posP] == '*'){
                posStar = posP;
                posOfS  = posS;
                ++posP;
                continue;
            }
            else if(posStar != -1){
                posS = posOfS;
                posP = posStar + 1;
                ++ posOfS;
            }else{
                return false;
            }
        }
        while(posP<n && p[posP] == '*'){
            ++posP;
        }
        return posS == m && posP == n; 
    }
};