int len(char* str)
{
    int l = 0 ;
    while(str[l] != '\0')
    l++;
    return l;
}

void Entirereverse(char* s, int start, int end)
{
    while(start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}
char* finalreversed(char* s)
{
    int n = len(s);
    Entirereverse(s, 0, n-1);
        
    int start = 0;
    for(int i = 0; i <= n; i++)
    {
        if(i == n || s[i] == ' ')
        {
            Entirereverse(s, start, i-1);
            start = i+1;
        }
    }

    int temp = 0;
    for ( int j = 0; j < n; j++)
    {
        if(s[j] != ' ')
        {
            if(temp > 0)
            {
            s[temp] = ' ';
            temp++;
            }

            while(j < n && s[j] != ' ')
            {
                s[temp] = s[j];
                j++;
                temp++;
            }
        }
    }
    s[temp] = '\0';
    return s;
}
char* reverseWords(char* s) {
    return finalreversed(s);
}