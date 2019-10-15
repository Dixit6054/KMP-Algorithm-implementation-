// C program for implementation of KMP pattern searching 
// algorithm
#include<stdio.h>
#include <sys/time.h> 
#include<string.h>
#include<stdlib.h>
#include<iostream>

// for mmap:
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

const char* map_file(const char* fname, size_t& length);
using namespace std;
int match(char [], char []);
void computeLPSArray(char *pat, int M, int *lps);
int KMPSearch(char *, char *);
 
// Driver program to test above function
int main (int argc, char* argv[] )
{
	if(argc != 3)
    {
        cout << "I am expecting 1 input argument. \n1.CHR_FILE\n2.SUBSEQUENCE\n";
        return -1;
    }
	struct timeval t1, t2;
    double elapsedTime;
	gettimeofday(&t1, NULL);
	
 	size_t length;
    auto f = map_file("chr01.pfa", length);
    auto l = f + length;
    
    uintmax_t m_numLines = 0;
    while (f && f!=l)
        if ((f = static_cast<const char*>(memchr(f, '\n', l-f))))
            m_numLines++, f++;

    std::cout << "m_numLines = " << m_numLines << "\n";
 	
 	
 	
 	
 	
 	
 	
 	
 	
gettimeofday(&t2, NULL);   
	
//***********after this I have got the text from a file. Now i will want to get the subsequence which i have to find.  
	   char *subseq = argv[2];
//**********there it is. Got the subsequence that easy********
	
	cout << KMPSearch(subseq, txt);

//gettimeofday(&t2, NULL);
elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
cout <<'\n'<< elapsedTime << " ms.\n";
   
return 0;
	   
}

void handle_error(const char* msg) {
    perror(msg); 
    exit(255);
}

const char* map_file(const char* fname, size_t& length)
{
    int fd = open(fname, O_RDONLY);
    if (fd == -1)
        handle_error("open");

    // obtain file size
    struct stat sb;
    if (fstat(fd, &sb) == -1)
        handle_error("fstat");

    length = sb.st_size;

    const char* addr = static_cast<const char*>(mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, 0u));
    if (addr == MAP_FAILED)
        handle_error("mmap");

    // TODO close fd at some point in time, call munmap(...)
    return addr;
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
        printf("Found pattern at index %d \n", i-j);
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
 //     cout <<  position;
      count++;
    }
  }
 
  return count;
}
