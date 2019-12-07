#include<stdio.h>

#include<string.h>

#include<stdlib.h>


void main()

{
	int i,j,ch,ascii,k,f=0,c,n=0,m,index,count=0;

	char str[100],word[25],*a[26];
	
printf("Enter the text: ");
	
gets(str);
	
for(i=0;i<26;i++)

		a[i] = malloc(25);
	
while(str[n++]!='\0');
	
do
	
{
		m=0;
		
count++;
		
for(i=0;i<26;i++)
			
strcpy(a[i],"\0");
		
printf("\nMenu\n1.Linear Probing\n2.Quadratic Probing\n3.Exit\nEnter your choice:");
		
scanf("%d",&ch);
		
if(ch==3)

		{
			exit(0);
		
}        
		
for(i=0;i<n;i++)
		
{
			if((str[i]==' ')||(str[i]=='\0'))
			
{
				strcpy(word,"");
				
ascii=0;
				
index=0;

				for(j=m;j<i;j++)
				
{
					word[index++]=str[j];
					
ascii+=str[j];

				}
				
word[index]='\0';
				
m=i+1;
				
printf("\nASCII Value:%d  Word:%s",ascii,word);

				k=0;                
				
if(ch==1)

				{
					j=(ascii%26+k)%26;
					
while(strcmp(*(a+j),"\0")!=0)

					{
						k++;
						
j=(ascii%26+k)%26;

					}
					
strcpy(*(a+j),word);
			        
}

				if(ch==2)

				{
					j=(ascii%26+k*k)%26;
					
while(strcmp(*(a+j),"\0")!=0)

					{
						k++;

						j=(ascii%26+k*k)%26;

					}

					strcpy(*(a+j),word);
                   		
}

			} 

		}

		printf("\nFinal Hash Table:");
		
for(i=0;i<26;i++)

			printf("\nElement at index %d:%s",i,*(a+i));            

		printf("\nEnter the search keyword: ");

		scanf("%s",word);

		ascii=0;

		for(i=0;word[i]!='\0';i++)

			ascii+=word[i];

		k=0;
		
c=0;
		
if(ch==1)

		{
			do
			
{
				c++;
				
j=(ascii%26+k)%26;
				
k++;
				
if(strcmp(*(a+j),word)==0)

				{
					f=1;
					
break;

				}

				if(strcmp(*(a+j),"\0")==0)

					break;

			}while(c<=27);

			if((c<27)&&(f==1))

				printf("\nNumber of key comparisons for successful search of %s:%d\n",word,c);

		}

		if(ch==2)

		{
			do

			{
				c++;
				
j=(ascii%26+k*k)%26;
				
k++;                

				if(strcmp(*(a+j),word)==0)

				{
					f=1;

					break;

				}

				if(strcmp(*(a+j),"\0")==0)

					break;

			}while(c<=51);

			if((c<51)&&(f==1))

				printf("\nNumber of key comparisons for successful search of %s:%d\n",word,c);       

		}

		if(f==1)

			printf("\n%s found at index %d",word,j);

		else

			printf("\n%s not found!",word);

	}while(count>=1);

}

