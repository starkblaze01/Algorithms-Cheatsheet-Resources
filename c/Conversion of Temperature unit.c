#include <stdio.h>

int main(void)
{
  float temp_fah, temp_c;
  printf("Enter temperature of a city in fahrenhite: ");
  scanf("%f" , &temp_fah);

  temp_c = (temp_fah-32)/1.8;

  printf("The temperature of the city in degree celsius is: %f " , temp_c);
}
