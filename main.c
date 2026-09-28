#include"header.h"
int j=0;
//int c1=0;
FILE *fp,*dp,*hp;
char path[100]="/usr/include/";
char s1[10000];
void main(int argc,char **argv)
{
if(argc!=2)
{
printf("usage: ./a.out filename");
return;
}
char ipfile[100];
strcpy(ipfile,argv[1]);
fp=fopen(ipfile,"r");
char ch;
int c1=0,c=0,line=0;
/*char out_file[20],s1[10000];
strcpy(out_file,str);*/
char *p=strchr(ipfile,'.');
*(p+1)='i';
dp=fopen(ipfile,"w");
while((ch=fgetc(fp))!=EOF)
{
c++;
if(ch=='\n')
{
line++;
if(c>c1)
c1=c;
c=0;
}
}
rewind(fp);
char *s=malloc(c1+100);
while(fgets(s,c1+100,fp))
mac_cnt(s);
rewind(fp);

memory();

while(fgets(s,c1+100,fp))
macro(s);
rewind(fp);

while(fgets(s,c1+100,fp))
{
headerfile(s,ipfile);
sline(s);
dline(s);
replace(s);
}
fclose(fp);
fclose(dp);
}
