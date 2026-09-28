#include"header.h"
extern int c1;
extern FILE *fp,*dp;
FILE *hp;
void headerfile(char *s,char *ipfile)
{
char path[100]="/usr/include/";
char out_file[20],s1[10000];
//strcpy(out_file,"inputfile.c");
/*char *p=strchr(ipfile,'.');
*(p+1)='i';
dp=fopen(ipfile,"w");*/
if(strstr(s,"#include"))
{
int i=0;
char file[100];
char *q=strchr(s,'<');
q++;
while((*q)!='>')
file[i++]=*q++;
file[i]='\0';
strcat(path,file);
hp=fopen(path,"r");
while(fgets(s1,c1+100,hp))
fprintf(dp,"%s",s1);
}
}
