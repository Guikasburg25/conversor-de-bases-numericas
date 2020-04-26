#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void imprimeMenu();
void menu();
void voltaMenu();

void quebra(int);
void tabula(int);

void DecParaBin();
void BinParaDec();
void DecParaHex();
void HexParaDec();
void DecParaOct();
void OctParaDec();
void BinParaHex();
void HexParaBin();

void PedeNumero();
void PedeBinario();
void PedeHexa();
void PedeOctal();

char valor[50];

int main (void)
{
    menu();
    quebra(2);

    system ("pause");
    return 0;
}

void quebra (int n)
{

     for (int i=0; i<n;i++)
     {
         printf ("\n");
     }
}

void tabula (int n)
{

     for (int i=0; i<n;i++)
     {
         printf ("\t");
     }
}

void imprimeMenu(){
     printf ("Programa para conversão entre sistemas numéricos");quebra(2);
     printf ("Escolha a conversão:");quebra(2);tabula(1);
     printf ("1 - Decimal     -> Binário");quebra(1);tabula(1);
     printf ("2 - Binário     -> Decimal");quebra(1);tabula(1);
     printf ("3 - Decimal     -> Hexadecimal");quebra(1);tabula(1);
     printf ("4 - Hexadecimal -> Decimal");quebra(1);tabula(1);
     printf ("5 - Decimal     -> Octal");quebra(1);tabula(1);
     printf ("6 - Octal       -> Decimal");quebra(1);tabula(1);
     printf ("7 - Binário     -> Hexadecimal");quebra(1);tabula(1);
     printf ("8 - Hexadecimal -> Binário");quebra(1);tabula(1);
     printf ("9 - Sair"); quebra(2);
}

void menu()
{
     int opc;

     imprimeMenu();

     printf ("Opcao: ");
     opc = getche();
}
     switch (opc)
     {
            case '1':
                 DecParaBin();
                 voltaMenu(&opc);
                 break;
            case '2':
                 BinParaDec();
                 voltaMenu(&opc);
                 break;
            case '3':
                 DecParaHex();
                 voltaMenu(&opc);
                 break;
            case '4':
                 HexParaDec();
                 voltaMenu(&opc);
                 break;
            case '5':
                 DecParaOct();
                 voltaMenu(&opc);
                 break;
            case '6':
                 OctParaDec();
                 voltaMenu(&opc);
                 break;
            case '7':
                 BinParaHex();
                 voltaMenu(&opc);
                 break;
            case '8':
                 HexParaBin();
                 voltaMenu(&opc);
                 break;
            case '9':
                 exit(1);
            default:
                    system ("cls");
                    imprimeMenu();
                    printf("Opção inválida.\n");
                    system("pause");
                    system ("cls");
                    menu();

     }



void voltaMenu()
{
     char op = '0';
     quebra(2);
     printf ("Deseja retornar ao menu? [1] Sim | [2] Não "); // pergunta se o usuário deseja retornar ao menu
     op = getche();
     if (op=='1'){ // se "sim"
        system ("cls"); // limpa a tela
        menu(); // chama o menu
     }else if (op=='2'){ // se "não"
        printf("\nEncerrando...");
     }else{                     // Caso o usuário digite uma opção inválida, ele irá retornar ao menu após pressionar qualquer tecla.
        printf("\nOpção inválida. Retornando ao menu...\n");
        system("pause");
        system("cls");
        menu();
        }

     }
}

void DecParaBin()
{
     char binario[33];
     char buffer[33];

     int divisor = 2;

     int resto = 0;
     int quociente = 0;
     int temp = 0;

     quebra(2);
     printf ("Informe um numero inteiro para ser convertido: ");
     PedeNumero();

     quociente = atoi(valor);
     strcpy(binario, "");
     while (quociente >= divisor)
     {
           resto = quociente%divisor;
           temp = quociente/divisor;
           quociente = temp;
           sprintf (buffer, "%d", resto);
           strcat (binario, buffer);
     }
     sprintf (buffer, "%d", quociente);
     strcat (binario, buffer);

     quebra(2);
     printf ("Convertido em binario: %s", strrev(binario));
     quebra(2);
}

void BinParaDec()
{
     int tamanho = 0;
     int result = 0;
     int temp = 0;
     int i = 0;

     quebra(2);
     printf ("Informe um valor binario para ser convertido: ");
     PedeBinario();

     tamanho = strlen(valor);
     tamanho--;
     while (tamanho >= 0)
     {
           temp = pow (2, tamanho);
           result += ((valor[i] - 48) * temp);
           tamanho--;
           i++;
     }

     quebra(2);
     printf ("Convertido em decimal: %d", result);
     quebra(2);
}

void DecParaHex()
{
     char hexa[33];
     char* hexadecimais = "0123456789ABCDEF";

     int divisor = 16;

     int resto = 0;
     int quociente = 0;
     int temp = 0;
     char tmp[5];

     strcpy(hexa, "");

     quebra(2);
     printf ("Informe um numero inteiro para ser convertido: ");
     PedeNumero();

     quociente = atoi(valor);

     while (quociente >= divisor)
     {
           resto = quociente%divisor;
           temp = quociente/divisor;
           quociente = temp;

           sprintf (tmp, "%c", hexadecimais[resto]);
           strcat (hexa, tmp);
     }
     sprintf (tmp, "%c", hexadecimais[quociente]);
     strcat (hexa, tmp);

     quebra(2);
     printf ("Convertido em Hexadecimal: %s", strrev(hexa));
     quebra(2);
}

void HexParaDec()
{
    int tamanho = 0;
    int result = 0;
    int temp = 0;
    int i = 0;

    quebra(2);
    printf ("Informe um valor hexadecimal para ser convertido: ");
    PedeHexa();

    tamanho = strlen(valor);
    tamanho--;
    while (tamanho >= 0)
    {
          temp = pow (16, tamanho);
          if ((valor[i] - 48) >= 17 && (valor[i] - 48) <=22)
          {
             result += ((valor[i]-55) * temp);
          }else{
                result += ((valor[i] - 48) * temp);
          }
          tamanho--;
          i++;
    }

    quebra(2);
    printf ("Convertido em decimal: %d", result);
    quebra(2);
}

void DecParaOct()
{
    char octal[33];
    char buffer[33];

    int divisor = 8;

    int resto = 0;
    int quociente = 0;
    int temp = 0;

    quebra(2);
    printf ("Informe um numero inteiro para ser convertido: ");
    PedeNumero();

    quociente = atoi(valor);
    strcpy(octal, "");

    while (quociente >= divisor)
    {
          resto = quociente%divisor;
          temp = quociente/divisor;
          quociente = temp;
          sprintf (buffer, "%d", resto);
          strcat (octal, buffer);
    }
    sprintf (buffer, "%d", quociente);
    strcat (octal, buffer);

    quebra(2);
    printf ("Convertido em octal: %s", strrev(octal));
    quebra(2);
}

void OctParaDec()
{
    int tamanho = 0;
    int result = 0;
    int temp = 0;
    int i = 0;

    quebra(2);
    printf ("Informe um valor octal para ser convertido: ");
    PedeOctal();

    tamanho = strlen(valor);
    tamanho--;
    while (tamanho >= 0)
    {
          temp = pow (8, tamanho);
          result += ((valor[i] - 48) * temp);
          tamanho--;
          i++;
    }

    quebra(2);
    printf ("Convertido em decimal: %d", result);
    quebra(2);
}

void BinParaHex()
{
    char hexa[33];
    char temp[33];
    char *p;
    char Hexas[16][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A",
    "B", "C", "D", "E", "F"};
    char Binarios[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101",
    "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110",
    "1111"};

    int tamanho = 0;
    int i;

    quebra(2);
    printf ("Informe um valor binario: ");
    PedeBinario();

    tamanho = strlen(valor);
    strcpy(hexa, "");
    strcpy(temp, "");

    if (tamanho%4==1){
        strcpy(temp, "000");
        tamanho+=3;
        strcat(temp, valor);
        strcpy(valor, temp);
    }else if (tamanho%4==2){
          strcpy(temp, "00");
          tamanho+=2;
          strcat(temp, valor);
          strcpy(valor, temp);
    }else if (tamanho%4==3){
          strcpy(temp, "0");
          tamanho+=1;
          strcat(temp, valor);
          strcpy(valor, temp);
    }

    p = valor;

    while (*p != '\0'){
          for (i=0;i<16;i++){
              if (strncmp(p, Binarios[i], 4) == 0){
                 strcat (hexa, Hexas[i]);
                 i = 16;
              }
          }
          p += 4;
    }

    quebra(2);
    printf ("Convertido em hexadecimal: %s", hexa);
    quebra(2);
}

void HexParaBin()
{
    char binario[33];
    char Binarios[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101",
    "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110",
    "1111"};
    char Binarios2[16][5] = {"", "1", "10", "11", "100", "101", "110", "111",
    "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

    int tamanho = 0;
    int i;
    int result;
    int zero=0;

    quebra(2);
    printf ("Informe um valor hexadecimal: ");
    PedeHexa();

    tamanho = strlen(valor);
    strcpy(binario, "");

    for (i=0;i<tamanho;i++)
    {
          if ((valor[i] - 48) >= 17 && (valor[i] - 48) <= 22)
          {
             result = ((valor[i] - 55));
             strcat(binario, Binarios[result]);
          }else{
                result = ((valor[i] - 48));
                if (result==0 && i==0){
                   strcpy(binario, "");
                   zero++;
                }else if (result == 0){
                      zero++;
                }
                if (i==0 || zero != 0){
                   strcat(binario, Binarios2[result]);
                }else{
                      strcat(binario, Binarios[result]);
                }
          }
    }

    if (zero == tamanho){
       strcpy(binario, "0");
    }

    quebra(2);
    printf ("Convertido em binario: %s", binario);
    quebra(2);
}

void PedeNumero()
{
     char c;
     int i;

         i=0;
         do
         {
       c=getch();
           if (isdigit(c)!=0)
           {
          valor[i] = c;
          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
          valor[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

    valor[i]='\0';
}

void PedeBinario()
{
     char c;
     int i;

         i=0;
         do
         {
       c=getch();
           if (c=='0' || c=='1')
           {
          valor[i] = c;
          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
          valor[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

    valor[i]='\0';
}

void PedeHexa()
{
     char c;
     int i;

         i=0;
         do
         {
       c=getch();
           if ((c>=48 && c<=57) || (c>=65 && c<=70))
           {
          valor[i] = c;
          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
          valor[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

    valor[i]='\0';
}

void PedeOctal()
{
     char c;
     int i;

         i=0;
         do
         {
       c=getch();
           if ((c>=48 && c<=55))
           {
          valor[i] = c;
          i++;
          printf ("%c", c);
       }
       else if(c==8&&i)
       {
          valor[i]='\0';
          i--;
          printf("\b \b");
       }
    }while(c!=13);

    valor[i]='\0';
}
