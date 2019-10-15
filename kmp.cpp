// C program for implementation of KMP pattern searching 
// algorithm
#include<stdio.h>
#include <sys/time.h> 
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int match(char [], char []);
void computeLPSArray(char *pat, int M, int *lps);
int KMPSearch(char *, char *);
 
// Driver program to test above function
int main (int argc, char* argv[] )
{
	if(argc != 3)
	{
	    cout << "I am expecting 1 input argument. \n1.FILE WITH CHR_FILENAMES\n2.SUBSEQUENCE\n";
	    return -1;
    }
	struct timeval t1, t2;
    double elapsedTime;
	gettimeofday(&t1, NULL);
	FILE *file = fopen (argv[1], "r" );
	char all_lines[30][20]={{0}};
	if ( file == NULL )
	{
		printf("Error!! Cannot open file \n" );
		return -1;
	}
	else
	{
		char line [20]={0}; // or other suitable maximum line size 
		int l=0;
		
		while ( fgets ( line, sizeof line, file ) != NULL ) // read a line 
		{
			//cout << "line opener: ";	      	
			for(int k=0;line[k]!='\n';k++)
			{
			//	cout << line[k];
				all_lines[l][k] = line[k];	
			}
			//cout <<endl;
			l++;				 
		}
	   fclose ( file );
	}

	for(int l=0;l<30;l++)
	{
		//for(int k=0;k<20;k++)
		cout << all_lines[l];
		cout << endl;
 	}
				
	for(int l=0;all_lines[l][0]!=0;l++)
	{
		FILE* source = fopen(all_lines[l],"r"); // opens "chr.???" as input
		if(source == NULL)
		{
			printf("Error!! \n" );
			return -1;
		}
		else
		{	
		fseek(source, 0L, SEEK_END);
		long int size = ftell(source);
		fseek(source, 0L, SEEK_SET);
		char* txt = new char[size];
		long int i=0;
		
		for(int k=0;k<10;k++)
		cout << all_lines[l][k]; 
		printf(" opened successfully \n");
		while( !feof(source) )
		{
		//fscanf(fr,"%c",&txt[i]);
		fread(txt, 1,size, source);       
		}
		//***********after this I have got the text from a file. Now i will want to get the subsequence which i have to find.  
		char *subseq = argv[2];
		//**********there it is. Got the subsequence that easy********
		//cout << KMPSearch(subseq, txt)<<endl;
		cout << match(txt,subseq) << endl;
		}
		//printf("Got text successfully :) \n");
		fclose(source);

	}			

   	gettimeofday(&t2, NULL);
   	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    cout <<'\n'<< elapsedTime << " ms.\n";
			
   return 0;
   
}

int KMPSearch(char *pat, char *txt)
{
	int count =0;
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
      //  printf("Found pattern at index %d \n", i-j);
        count = count +1;
		j = lps[j-1];
      }
 
      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
    return count;
}

void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // length of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example 
           // AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
int match(char text[], char pattern[]) {
  int c, d, e, text_length, pattern_length, position = -1,count =0;
 
  text_length    = strlen(text);
  pattern_length = strlen(pattern);
 
  if (pattern_length > text_length) {
    return -1;
  }
 
  for (c = 0; c <= text_length - pattern_length; c++) {
    position = e = c;
 
    for (d = 0; d < pattern_length; d++) {
      if (pattern[d] == text[e]) {
        e++;
      }
      else {
        break;
      }
    }
    if (d == pattern_length) {
//      cout <<  position;
      count++;
    }
  }
 
  return count;
}
