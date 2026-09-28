#include"header.h"
extern int j;
extern FILE *dp;
void sline(char *s)
{
int i=0;
while(s[i]!='\0')
{
if(strncmp(s+i,"//",2)==0) 
{
while(s[i]!='\n'&&s[i]!='\0')
{
s[i]=' ';
i++;
}
}
i++;
}
}
void dline(char *s)
{
int i=0;
while(s[i]!='\0')
{
if(strncmp(s+i,"/*",2)==0)
{
j=1;
}
if(j==1)
{
while(strncmp(s+i,"*/",2)!=0)
{
if(s[i]=='\0')
return;
s[i]=' ';
i++;
}
s[i++]=' ';
s[i]=' ';
j=0;
}
i++;
} 
}


