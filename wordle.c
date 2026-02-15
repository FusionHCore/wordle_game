#include<stdio.h>
#include<string.h>
#include<math.h>
#define max_words 2
#define max_length 20
#define cupr(c) ((c)>='a' && (c)<='z'? (c)-32: (c)) //macro to capitalize a character

void print_progress(char s[max_length+1],int pos[max_length], int wordlen); //max_length+1 for s to give space for \0

struct word_data
{
	int word_length;
	char word[max_length],user_word[max_length];
};

int main()
{
	struct word_data w[max_words];
	int i=0,j,correct=0,temp1_counter=0,pos[max_length],underscores[max_length];//underscores for printing underscores only
	char user_input[max_length],s[max_length];
	FILE *fp;
	fp = fopen("words.txt","r"); //File should only contain capitalized words
	if(fp==NULL)
	{
		perror("File didnt open.");
		return 1;
	}
	while(i<max_words && fgets(w[i].word,max_length,fp)!=NULL)
	{
		w[i].word[strcspn(w[i].word,"\n")]='\0';
		w[i].word_length=strlen(w[i].word);
		i++;
	}
	fclose(fp);
	//underscores can never print character
	for(i=0;i<max_length;i++)
	{
		underscores[i]=-1;
	}
	//Main game loop
	for(i=0;i<max_words;i++)
	{
		printf("Enter word %d:\n",i+1);
		print_progress("0",underscores,w[i].word_length);
		while(correct!=1)
		{
			temp1_counter=0;
			scanf("%19s",user_input);
			if(strcmp(w[i].word,strupr(user_input))==0)
			{
				correct = 1;
				continue;
			}
			//compile the chars and its position into in 2 arrays
			for(j=0;j<w[i].word_length;j++)
			{
				if(w[i].word[j]==cupr(user_input[j]))
				{
					s[temp1_counter]=w[i].word[j];
					pos[temp1_counter]=j;
					temp1_counter++;
				}
			}
			s[temp1_counter]='\0';   //needed for manual string creation
			print_progress(s,pos,w[i].word_length);  //send the two arrays to print_progress
		}
		if(i=max_words-2)
		    printf("\nYou got the word correct!!\nLast one:");
		else
			printf("\nYou got the word correct!!\nNext one:");
		correct=0;
	}
}

void print_progress(char s[max_length+1], int pos[max_length], int wordlen)
{
	int i,j=0;
	for(i=0;i<wordlen;i++)
	{
		if(pos[j]==i)
		{
			printf("%c",s[j]);
			j++;
		}
		else
			printf("_");
	}
	printf("\n");
}
