#include <stdio.h>

int main()
{
	char string[20];
	char c;
	
	printf("¹®ÀÚ¿­ ÀÔ·Â : ");
	scanf("%s", string);
	c = getchar();
	printf("¹®ÀÚ ÀÔ·Â : "); 
	scanf("%c", &c);
	
	printf("%s\n", string);
	
	printf("!!%c!!\n" , c);
	
	return 0;
}

