#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

void Decrypt( char* alph_2, char* string_2, int rot_type_2, int cs_2);
void Encrypt( char* alph, char* string, int rot_type, int cs);
void TolowerArr(char *str, int cs);

int main(void)
{
    short i_1, F;
    int counter = 0, i_2;
    char f_name[25], *cpy_str, alphabet[26] ={"abcdefghijklmnopqrstuvwxyz"};

    printf("\n-----------------------| Programa Hosgeldiniz |-------------------------------\n\n");
    printf("# Islem Tipinizi Seciniz :\n\n");
    printf(" 1-) Rot Sifreleme\n");
    printf(" 2-) Rot Sifre Cozme\n\n==> ");
    scanf("%hi",&i_1);
    printf("\n------------------------------------------------------------------------------\n\n");
    if(i_1 == 1)
    {
        printf("# ROT-? Sifreleme Turunu Giriniz [1-25] :\n\n==> ");
        scanf("%d", &i_2);
        printf("\n------------------------------------------------------------------------------\n\n");
        printf("# Sifreleme Yapilacak Dosyanin Adini Giriniz :\n\n==>");
        scanf("%s", f_name);
        printf("\n------------------------------------------------------------------------------\n\n");
        F = 1;
    }
    else if(i_1 == 2)
    {
        printf("# Sifreyi Cozmek Icin ROT-? Tipini Giriniz :\n\n==> ");
        scanf("%d", &i_2);
        printf("\n------------------------------------------------------------------------------\n\n");
        printf("Sifre Cozumu Yapilacak Dosyanin Adini Giriniz :\n\n==> ");
        scanf("%s", f_name);
        printf("\n------------------------------------------------------------------------------\n\n");
        F = 0;
    }
    else
    {
        printf("HATA!! Yanlis Tuslama Yaptiniz...");
        exit(1);
    }


    FILE *fp = fopen( f_name, "r+");
    if(fp == NULL)
    {
        printf("HATA!! Dosya Acilamadi...");
        exit(1);
    }

    while( !feof(fp))
    {
        if(fgetc(fp) == EOF) break;
        counter++ ;
    }

    cpy_str = (char *) malloc( sizeof(char) * (counter+1) );

    if(cpy_str == NULL)
    {
        printf("HATA !!! BELLEKTEN YER AYRILAMADI..");
        exit(1);
    }

    cpy_str[counter] = '\0' ;

    rewind(fp);
    for(int i = 0; i < counter; ++i)
    {
        *(cpy_str + i ) = fgetc(fp);
    }

    printf("# Orjinal Metniniz :\n\n==> ");
    puts(cpy_str);
    printf("------------------------------------------------------------------------------\n\n");
    TolowerArr(cpy_str, counter);

    if(F == 1)
    {
        Encrypt(alphabet, cpy_str, i_2, counter);
        printf("# Sifrelenmis Hali :\n\n==> ");
        puts(cpy_str);
        printf("------------------------------------------------------------------------------\n\n");
        printf("\n[==============/// ISLEM BASARIYLA TAMAMLANDI \\\=================]");

    }
    else if(F == 0)
    {
        Decrypt(alphabet, cpy_str, i_2, counter);
        printf("# Sifre Cozulmus Hali :\n\n==> ");
        puts(cpy_str);
        printf("------------------------------------------------------------------------------\n\n");
        printf("\n\n[==============/// ISLEM BASARIYLA TAMAMLANDI \\\=================]\n\n");

    }
    else
    {
        printf("HATA !!!");
        exit(1);
    }

    rewind(fp);
    for(int i = 0; i < strlen(cpy_str); i++)
    {
        fputc(cpy_str[i], fp);
    }

    printf("counter %d", counter);
    free(cpy_str);
    fclose(fp);
    return 0 ;
}


void TolowerArr(char *str, int cs)
{
   for(int i = 0; i < cs; ++i)
    {
        str[i] = tolower(str[i]);
    }
}

void Encrypt( char* alph, char* string, int rot_type, int cs)
{
    int loc, ctrl ;
    for(int i = 0; i < cs; ++i)
    {
        ctrl = 0;
        for(int j = 0; j < 26; ++j)
        {
            if(string[i] == alph[j])
            {
                loc = j ;
                ctrl = 1;
                break;
            }
        }

        if(ctrl != 1)
        {
            continue;
        }

        loc = ((loc + rot_type) % 26) ;
        string[i] = alph[loc];
    }
}

void Decrypt( char* alph_2, char* string_2, int rot_type_2, int cs_2)
{
    int loc_2, ctrl_2 ;
    for( int i = 0; i < cs_2; ++i)
    {
        ctrl_2 = 0;
        for(int j = 0; j < 26; ++j)
        {
            if(string_2[i] == alph_2[j])
            {
                loc_2 = j ;
                ctrl_2 = 1 ;
                break;
            }
        }

        if(ctrl_2 != 1)
        {
            continue;
        }

        loc_2 = ( loc_2 - rot_type_2);
        if(loc_2 < 0)
        {
            loc_2 = loc_2 + 26 ;
        }
        string_2[i] = alph_2[loc_2];

    }
}
