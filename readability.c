#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float conta_letras(string txt);
float conta_palavras(string txt);
float conta_frases(string txt);

int main(void)
{
    //Entrade de dados e declaracao de variaveis
    string texto = get_string("Texto: ");
    float letras = conta_letras(texto);
    float palavras = conta_palavras(texto);
    float frases = conta_frases(texto);
    //Transformando letras e frases na media por 100 palavras
    letras = letras / palavras * 100;
    frases = frases / palavras * 100;
    //Indice de Coleman Liau
    int grade = round(0.0588 * letras - 0.296 * frases - 15.8);
    //Saida de dados
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}
// funcoes
float conta_letras(string txt)
{
    int ponteiro, cont = 0;
    for (int i = 0, len = strlen(txt); i < len; i++)
    {
        ponteiro = toupper(txt[i]);
        if (ponteiro > 64 && ponteiro < 91)
        {
            cont++;
        }
    }
    return cont;
}

float conta_palavras(string txt)
{
    int cont = 0;
    for (int i = 0, len = strlen(txt); i < len; i++)
    {
        if (isspace(txt[i]))
        {
            cont++;
        }
    }
    return cont + 1;
}

float conta_frases(string txt)
{
    int ponteiro, cont = 0;
    for (int i = 0, len = strlen(txt); i < len; i++)
    {
        ponteiro = txt[i];
        if (ponteiro == 33 || ponteiro == 46 || ponteiro == 63)
        {
            cont++;
        }
    }
    return cont;
}