#define TXT 1024
#define WORD 30
#include <stdio.h>
#include <string.h>
int size_word = 0;
char ans[WORD];
int n=0;
void geomatry(char word[WORD], char text[WORD + TXT + 1]);
void Atbash(char word[WORD], char text[WORD + TXT + 1]);
int valueOfChar(char c);
void changeValue(char c[WORD]);
///////////////////////////////////////////////////////////////////////////
int valueOfChar(char c)
{
    if (c == NULL)
        return -1;
    if ((c >= 65 && c <= 90))
        return (c - 64);
    if (c >= 97 && c <= 122)
        return c - 96;
    return 0;
}
void changeValue(char c[WORD])
{
    char a1[26];
    char a2[26];
    for (int i = 26; i >= 0; i--)
    {
        a1[26 - i] = (char)(i + 97);
    }
    for (int i = 26; i >= 0; i--)
    {
        a2[26 - i] = (char)(i + 65);
    }
    memset(ans, NULL, WORD);
    for (int i = 0; i < size_word && c[i] != NULL; i++)
    {
        if ((c[i] >= 65 && c[i] <= 90))
            ans[i] = a2[valueOfChar(c[i])];
        if (c[i] >= 97 && c[i] <= 122)
            ans[i] = a1[valueOfChar(c[i])];
    }
}
void geomatry(char word[WORD], char text[WORD + TXT + 1])
{
    char value[WORD + TXT + 1];
    int value_word = 0, counter = 0;
    memset(value, NULL, WORD + TXT + 1);
    for (int i = 0; i < WORD + TXT + 1; i++)
    {
        if (text[i] != NULL)
        {
            if (!((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)))
                value[i] = 0;
            if ((text[i] >= 65 && text[i] <= 90))
                value[i] = value[i] - 64;
            if ((text[i] >= 97 && text[i] <= 122))
                value[i] = value[i] - 97;
        }
    }
    for (int i = 0; i < WORD; i++)
    {
        if ((word[i] >= 65 && word[i] <= 90))
            value_word = value_word + word[i] - 64;
        if ((word[i] >= 97 && word[i] <= 122))
        {
            value_word = value_word + word[i] - 96;
        }
    }
    for (int k = 0; valueOfChar(text[k]) != -1; k++)
    {
        if (valueOfChar(text[k]) != 0)
        {
            int sum = 0;
            for (int i = 0; value_word > sum; i++)
            {
                sum = sum + valueOfChar(text[i + k]);
                if (value_word == sum)
                {
                    if (counter != 0)
                        printf("~");
                    counter++;
                    for (int j = 0; j <= i; j++)
                    {
                        char flag = text[j + k];
                        printf("%c", text[j + k]);
                    }
                }
            }
        }
    }
}
void Atbash(char word[WORD], char text[WORD + TXT + 1])
{
    changeValue(word);
    for (int k = 0; valueOfChar(text[k]) != -1; k++)
    {
        int flag=1;
        int counter1=0,counter2=0;
        if (valueOfChar(text[k]) != 0)
        {
            for (int i = 0;i<WORD&&ans[i]!=NULL; i++)
            {
                if (valueOfChar(text[k + i]) != 0)
                {
                    if (text[k + i-counter1] != ans[i])
                        flag=0;
                }
                else
                    counter1++; 
                counter2++; 
            }
            if(flag==1){
                n++;
                for(int i=0;i<counter2;i++){
                    printf("%c", text[k+i]);
                }
                if(n!=0)
                    printf("~");
            }
        }
    }
}
int main()
{

    char input[TXT + WORD + 1], word[WORD], text[TXT + WORD + 1];
    // for(int i=0;i<WORD;i++)
    // {
    //     word[i]=NULL;
    // }
    memset(word, NULL, WORD);
    memset(text, NULL, TXT + WORD + 1);
    memset(input, NULL, TXT + WORD + 1);
    int flag2 = 1;
    for (int i = 0; i < WORD + TXT + 1 && flag2 == 1; i++)
    {
        scanf("%c", &input[i]);
        if (input[i] == '~')
        {
            flag2 = 0;
        }
    }

    //get array with only the input(word)
    int flag = 0;
    for (int i = 0; i < WORD && flag == 0; i++)
    {
        if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
        {
            word[i] = input[i];
            size_word++;
        }
        else
            flag = 1;
    }
    //get string without the word
    for (int i = size_word; i < TXT + WORD + 1 && input[i + 1] != '~'; i++)
    {
        text[i - size_word] = input[i + 1];
    }
    char op[WORD];
    for (int i = 0; i < size_word; i++)
    {
        op[i]=word[size_word-i-1];
    }
    Atbash(word,text);
    if(n!=0)
        printf("~");
    Atbash(op,text);
    

    // printf("Gematria Sequences: ");
    // geomatry(word, text);
    // printf("\nAtbash Sequences: ");
    // printf("\nAnagram Sequences: ");
    // printf("-  %s\n", word);
    // printf("-- %s\n", input);
    // printf("---%s\n", text);
}
