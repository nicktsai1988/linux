#include<stdio.h>
#include<stdlib.h>
int main()
{
char* str[]=
{
"Hello world",
"I love you",
"my love",
NULL
};
char **index=str;
while(*index)
{
printf("%s\n",*index);
index++;
}
exit(0);
}
