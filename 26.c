#include<stdio.h>
#include<malloc.h>
#include<string.h>
char* output[100];
int binaryadd(int);
void bleak(int input1[]);

main()
{
	int input[20],i,size;
	printf("Enter the size\n");
	scanf("%d",&size);
	printf("\nInput the numbers\n");
 	for(i=0;i<size;i++)
 		scanf("%d",&input[i]);
	bleak(input);
}

void bleak(int input1[])
{
	int i,j,size=0;
	size=(sizeof(input1))/(sizeof(int));
	for(i=0;i<size;i++)
	{
		output[i]=(char*)malloc(sizeof(char));
		for(j=1;j<=input1[i];j++)
		{
			if(input1[i]==binaryadd(j))
			{
			//output[i]="SUPPORTED";			
			strcpy(output[i],"SUPPORTED\0");
			break;
			}
			else
			//output[i]="BLEAK";			
			strcpy(output[i],"BLEAK\0");
		}
		
	}
for(i=0;i<size;i++)
printf("%s\n",output[i]);
}

int binaryadd(int n)
{
	int temp=n,sum=0;
	while(n!=0)
	{
	sum+=n%2;
	n=n/2;
	}
//printf("The sum is %d",sum);
return (temp+sum);
}
