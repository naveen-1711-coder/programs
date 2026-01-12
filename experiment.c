//print a given name using a pointer

#include<stdio.h>
#include<stdlib.h>

void main()
{
	printf("enter name :");
	int length=10;
	char *name=(char*)malloc(length);
	scanf("%s",name);
	printf("hi %s !",name);
}