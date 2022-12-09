#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

//char words[30][30];
char words[][20] = {"mobile","samsung","mango","icecream","and","go","i","like","swim","play","park","water","hello","hi"};


int *memory;
int size = 10000;

int check(char word[]){
//    printf("Checking %s\n",word);
    for(int i=0;i<13;i++){
        if(!strcmp(words[i],word)){
            return 1;
        }
    }
    return 0;
}

char* slice(char s[],int start,int stop){
    char *s2;
    s2 = malloc(size*sizeof(char));
    int k=0;
    for(int i=start;i<stop;i++)
        s2[k++] = s[i];
    return s2;
}


int wordbreak(char word[]){
    int l = strlen(word);
    if(l==0) return 1;
    for(int i=0;i<l;i++)
    {
        char *s,*s2;
        s = slice(word,0,i+1);
        if(memory[i] == 0 && check(s))
            memory[i] = 1;
        if(memory[i] == 1){
            if(i==l-1) return 1;

            for(int j=i+1;j<l;j++){
                s2 = slice(word,i+1,j+1);
                if(memory[j] == 0 && check(s2))
                    memory[j] = 1;
                
                if(j==l-1 && memory[j] == 1)
                    return 1;

            }
        }

    }
    return 0;
}

int main()
{


    char s[size];

    FILE *f = fopen("words.txt","r");
    fscanf(f,"%s",s);
    fclose(f);
    printf("%s\n",s);


    memory = (int *) calloc(strlen(s),sizeof(int));
    clock_t start = clock();
    if(wordbreak(s))
        printf("Word can be broken");
    else
        printf("Word cannot be broken");
    clock_t stop = clock();
    double time = (double) (stop-start)/CLOCKS_PER_SEC;
    printf("\nExecution time is %f",time);

    return 0;
}

