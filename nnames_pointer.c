
...//read and print n namesusing single pointer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main()
{
	int count,counter,length=30;
	printf("Enter how many names you to read and print\n");
	scanf("%d",&count);
	char names[count][length];
	char *ptr_names;
	ptr_names=&names[0][0];
	for(counter=0;counter<count;counter++)
	{
		printf("Enter the name %d of %d : \n",counter+1,count);
		fgets(names+counter*length,length,stdin);

	}
	for(counter=0;counter<count;counter++)
	{
		printf("the name %d of %d : %s\n",counter+1,count,names+counter*length);

	}
}