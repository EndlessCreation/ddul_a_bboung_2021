#include <stdio.h>
#include <string>

using namespace std;

int best_str(int X, int Y, int begin, int end, char * str);

int main(void)
{
    int T, X, Y;
    scanf("%d", &T);
    
    for(int k = 1; k <= T; k++)
    {
    	char str[1002] = {0};
        scanf("%d %d %s", &X, &Y, str);
        
        //priority_check(X, Y);
        string s(str);
        
        int begin = 0, end = 0, leng = s.length(), answer = 0;
        char before = s[0];
        
        for(int i = 1; i < leng; i++)
        {
            if(s[i] == '?')
            {
                char buf = '?';
                begin = i - 1;
                while(buf == '?')
                {
                    if(i == leng - 1)
                        break;
                    i++;
                    buf = s[i];
                }
                end = i;
                
                answer += best_str(X, Y, begin, end, str);
            }
            else
            {
                if(before != s[i])
                {
                    answer += before == 'C' ? X : Y;
                }
            }
            before = s[i];
        }
        
        printf("Case #%d: %d\n", k, answer);
    }
}

int best_str(int X, int Y, int begin, int end, char * str)
{
	if(str[begin] == '?' || str[end] == '?')
		return 0;
    
    if(end - begin >= 2)
    {
        if(str[begin] == str[end])
            return 0;
        else
            return str[end] == 'J' ? X : Y;
    }
}