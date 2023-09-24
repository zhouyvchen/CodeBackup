void cn(char s[])
{
    char c;
    int i;
    for(c='A';c<='Z';c++)
    {
        for(i=0;s[i]!='\0';i++)
        {
            if(c==s[i])
            {
                num1++;
            }
        }
    }
}