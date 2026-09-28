#include"header.h"
extern FILE *dp;
int c1=1000;
int cnt=0,t=0;
char **p,**q;
void replace(char *s)
{
int i=0,j=0,l1,k=0,m=0;
extern FILE *dp;
char t[c1];
if(strstr(s,"#include"))
return;
if(strncmp(s,"#define",7)==0)
return;
while(s[m]!='\0')
{
for(i=0;i<cnt;i++)
{
l1=strlen(p[i]);
if((strncmp(s+m,p[i],l1)==0)&&(!(s[m+l1+1]>='a'&&s[m+l1+1]<='z'))&&(!(s[m+l1+1]>='A'&&s[m+l1+1]<='Z'))&&((s+m==s)||((!(s[m-1]>='a'&&s[m-1]<='z'))&&(!(s[m-1]>='A'&&s[m-1]<='Z')))))
{
k=0;
while(q[i][k]!='\0')
t[j++]=q[i][k++];
m=m+l1;
}
}
t[j++]=s[m++];
}
t[j]='\0';
fprintf(dp,"%s",t);
}
void macro(char *s)
{
int l;
if(strncmp(s,"#define",7)==0)
{
copy(s+8,p[t]);
l=strlen(p[t]);
copy(s+8+l+1,q[t]);
t++;
}
}
void memory(void)
{
int a;
p=malloc(sizeof(char *)*cnt);
q=malloc(sizeof(char *)*cnt);
for(a=0;a<cnt;a++)
{
p[a]=malloc(c1);
q[a]=malloc(c1);
}
}
void copy(char *s1,char *s2)
{
int m=0;
while(s1[m]!='\0'&&s1[m]!=' '&&s1[m]!='\n')
{
s2[m]=s1[m];
m++;
}
s2[m]='\0';
}
void mac_cnt(char*s)
{
if(strncmp(s,"#define",7)==0)
cnt++;
}
