#define TXT 1024
#define WORD 30
#include <stdio.h>
#include <string.h>
int size_word = 0;
int size_text = 0;
char ans[WORD];
void geomatry(char word[WORD], char text[TXT]);
void Atbash2(char word[WORD], char text[TXT]);
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
    for (int i = 0; i < size_word; i++)
    {
        if ((c[i] >= 65 && c[i] <= 90))
            ans[i] = a2[valueOfChar(c[i])];
        if (c[i] >= 97 && c[i] <= 122)
            ans[i] = a1[valueOfChar(c[i])];
    }
}
void geomatry(char word[WORD], char text[WORD + TXT + 1])
{
    char value[TXT];
    int value_word = 0, counter = 0;
    memset(value, NULL, TXT);
    for (int i = 0; i < size_text; i++)
    {
        if (!((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)))
            value[i] = 0;
        if ((text[i] >= 65 && text[i] <= 90))
            value[i] = value[i] - 64;
        if ((text[i] >= 97 && text[i] <= 122))
            value[i] = value[i] - 97;
    }
    for (int i = 0; i < size_word; i++)
    {
        if ((word[i] >= 65 && word[i] <= 90))
            value_word = value_word + word[i] - 64;
        if ((word[i] >= 97 && word[i] <= 122))
        {
            value_word = value_word + word[i] - 96;
        }
    }
    for (int k = 0; k < size_text; k++)
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
void Atbash2(char word[WORD], char text[TXT])
{
    int test1=0,test2=0;
    memset(ans, NULL, WORD);
    changeValue(word);
    char op[WORD];
    memset(op, NULL, WORD);
    for (int i = 0; i < size_word; i++)
    {
        op[i] = ans[size_word - i - 1];
    }
    for (int i = 0; i < size_text; i++)
    {
        int flag1 = 1,flag2=0,flag3=1;
        int counter1 = 0, counter2 = 0;
        int counter3=0 , counter4=0;
        if ((text[i] != ' ' && text[i] != '\t' && text[i] != '\n'))
        {
            for (int j = 0; ans[j] != NULL && flag1 == 1; j++)
            {
                if (ans[j] != text[i + j])
                {
                    if ((text[i + j] == ' ' || text[i + j] == '\t' || text[i + j] == '\n'))
                        counter1++;
                    else
                        flag1 = 0;
                }
                else
                    counter2++;
            }
            if (flag1 == 1)
            {
                test1=1;
                if(test2==1){
                    printf("~");
                    test2=0;
                    }

                flag2++;
                if(flag2>1)
                    printf("~");
                for (int k = 0; k < counter1 + counter2; k++)
                {
                    printf("%c", text[i+k]);
                }
            }


            for (int j = 0; op[j] != NULL && flag3 == 1; j++)
            {
                if (op[j] != text[i + j])
                {
                    if ((text[i + j] == ' ' || text[i + j] == '\t' || text[i + j] == '\n'))
                        counter3++;
                    else
                        flag3 = 0;
                }
                else
                    counter4++;
            }
            if (flag3 == 1)
            {
                test2=1;
                if(test1==1){
                    printf("~");
                    test1=0;
                }
                flag2++;
                if(flag2>1)
                    printf("~");
                for (int k = 0; k < counter3 + counter4; k++)
                {
                    printf("%c", text[i+k]);
                }
            }
        }
    }
}
void appears(char word[WORD], char text[TXT])
{
    char save_word[WORD];
    int flag1 = 0;
    memset(save_word, NULL, WORD);
    for (int i = 0; i < size_text; i++)
    {
        int counter1 = 0;
        int counter2 = 0;
        int flag2 = 1;
        strcpy(save_word, word);
        if ((text[i] != ' ' && text[i] != '\t' && text[i] != '\n') && text[i + size_word - 1] != NULL)
        {
            for (int k = 0; counter2 < size_word && flag2 == 1; k++)
            {
                if (text[i + k] != ' ' && text[i + k] != '\t' && text[i + k] != '\n')
                {
                    int flag3 = 0;
                    for (int u = 0; u < size_word; u++)
                    {
                        if (text[i + k] == save_word[u] && flag3 != 1)
                        {
                            flag3 = 1;
                            save_word[u] = NULL;
                            counter2++;
                        }
                    }
                    if (flag3 == 0)
                        flag2 = 0;
                }
                else
                    counter1++;
            }
            if (text[i + size_word - 1 + counter1] == NULL)
                flag2 = 0;
            if (flag2 == 1)
            {
                flag1++;
                if (flag1 > 1)
                    printf("~");
                for (int j = 0; j < counter1 + counter2; j++)
                {
                    printf("%c", text[j + i]);
                }
            }
        }
    }
}

int main()
{

    char word[WORD], text[TXT];
    memset(word, NULL, WORD);
    memset(text, NULL, TXT);
    int flag1 = 1;
    for (int i = 0; i < WORD && flag1 == 1; i++)
    {
        scanf("%c", &word[i]);
        if (word[i] == ' ' || word[i] == '\t' || word[i] == '\n')
        {
            word[i] = NULL;
            flag1 = 0;
        }
    }
    int flag2 = 1;
    for (int i = 0; i < TXT && flag2 == 1; i++)
    {
        scanf("%c", &text[i]);
        if (text[i] == '~')
        {
            text[i] = NULL;
            flag2 = 0;
        }
    }
    for (int i = 0; i < WORD && word[i] != NULL; i++)
    {
        size_word++;
    }
    for (int i = 0; i < TXT && text[i] != NULL; i++)
    {
        size_text++;
    }
    printf("Gematria Sequences: ");
    geomatry(word, text);
    printf("\nAtbash Sequences: ");
    Atbash2(word,text);
    printf("\nAnagram Sequences: ");
    appears(word, text);
    return 0;
}
