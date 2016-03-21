#include "my_printf.h"
#include <stdarg.h>

int base_converter(int convert, int basee)
{
  char base_digits[16] =
    {'0', '1', '2', '3', '4', '5', '6', '7',
     '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
  
  int converted_number[64];
  long int number_to_convert = convert;
  int base;
  int index=0;
  base = basee;
  while (number_to_convert != 0)
    {
      converted_number[index] = number_to_convert % base;
      number_to_convert = number_to_convert / base;
      ++index;
    }
  
  --index;  /* back up to last entry in the array */
  while(index >= 0)
    {  
      ft_putchar(base_digits[converted_number[index]]);
      index--;
    }
  return (0);
}

int base_converter_upper(int convert, int basee)
{
  char base_digits[16] =
    {'0', '1', '2', '3', '4', '5', '6', '7',
     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  int converted_number[64];
  long int number_to_convert = convert;
  int base;
  int index=0;
  base = basee;
  while (number_to_convert != 0)
    {
      converted_number[index] = number_to_convert % base;
      number_to_convert = number_to_convert / base;
      ++index;
    }

  --index;  /* back up to last entry in the array */
  while(index >= 0)
    {
      ft_putchar(base_digits[converted_number[index]]);
      index--;
    }
  return (0);
}

int manage_arg(t_main *main, va_list *myva)
{
  int nb;
  char *chaine;
  unsigned int number;
  int c;
  void *adress;

  main->i++;
  if(main->chaine[main->i] == 'd' || main->chaine[main->i] == 'i')
    {
      nb = va_arg(*myva, int);
      ft_putnbr(nb);
    }
  else if(main->chaine[main->i] == 's')
    {
      chaine = va_arg(*myva, char *);
      ft_putstr(chaine);
    }
  else if(main->chaine[main->i] == 'u')
    {
      number = va_arg(*myva, unsigned int);
      ft_putnbr(number);
    }
  else if(main->chaine[main->i] == 'c')
    {
      c = va_arg(*myva, int);
      ft_putchar(c);
    }
  else if(main->chaine[main->i] == '%')
    ft_putchar('%');
  else if(main->chaine[main->i] == 'p')
    {
      adress = va_arg(*myva, void *);
      ft_putstr("0x");
      //gerer le debut de l'adresse
      base_converter((int)adress, 16);
    }
  else if(main->chaine[main->i] == 'x')
    {
      number = va_arg(*myva, unsigned int);
      base_converter(number, 16);
    }
  else if(main->chaine[main->i] == 'X')
    {
      number = va_arg(*myva, unsigned int);
      base_converter_upper(number, 16);
    }
  return (1);
}

int ft_printf(const char *format, ...)
{
  va_list myva;
  t_main *main;

  main = (t_main *)malloc(sizeof(t_main) * 1); 
  main->i = 0;
  main->chaine = format;
  //initializzzzzze VA  
  va_start(myva, format); 
  while(format[main->i] != '\0')
    {
      if(format[main->i] != '%')
	{
	  ft_putchar(format[main->i]);
	  //  main->i++;
	}      
      else
	manage_arg(main, &myva);
      main->i++;
    }
  //END de mon VA
  va_end(myva); 
 return (1);
}

//SpdDoOuUxXcC
int main()
{
  unsigned int a = -3;
  char *b = "salut";
  unsigned int c = 934549;

  printf("VRAI PRINTF : \n");
  printf("lol %X\n",c);
  printf("MON PRINTF : \n");
  ft_printf("lol %X\n",c);
  return (0);
}
