#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>


void moving_character_signboard(char file_name[], int line_horizontality);
void gotoxy(int x, int y);
void draw_rectangle(int c, int r);

void gotoxy(int x, int y)
{
    COORD Pos = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
}

void flash(char *str){
 	char str2[30];
 	strcpy(str2,str); 
 	gotoxy(10,10);
 	printf("%20s"," ");
 	Sleep(50);
 	gotoxy(10,10);
 	printf("%s",str2);
 	Sleep(50);
}


void start(char *str){
 	char str2[30];
	strcpy(str2, str);
	 while(true)
 	{
  		flash(str2);
  		Sleep(10);
	}
}

int main(void)
{
		char str2[30]= "★이상입니다.★ ";
        char file_name[20];
        int line_horizontality, repeat;
        int ch;
        printf("★움직이는 글자 광고판★\n\n");
        printf("불러올 광고 txt파일입력-> ");
        scanf("%s", file_name);
        printf("광고판크기 입력 -> ");
        scanf("%d", &line_horizontality);
		do
        {
               printf("반복 횟수 입력(1번 이상) >");
               scanf("%d", &repeat);
        } while (repeat < 1);
        for(int i=0; i<repeat; i++)
               moving_character_signboard(file_name, line_horizontality);
     		
	 start(str2);
	 return 0;
}

void moving_character_signboard(char file_name[], int line_horizontality)
{
        char *ptr, chr[121];
        int i, j, horizontality, count = 0, countx;
        FILE *fp;
        ptr = (char*)malloc(line_horizontality);
        gotoxy(1, 9);
        draw_rectangle(line_horizontality+2, 1);
        fp = fopen(file_name, "r");
        if (fp == NULL)
        {
               printf("file open error!");
               exit(1);
        }
        while (!feof(fp))
        {
               fgets(chr, 120, fp);
               horizontality = strlen(chr); 
               ptr[line_horizontality] = '\0';
               for (j = 0; j < line_horizontality; j++) 
               {
                       count = 0;
                       for (i = 0; i < line_horizontality - j - 1; i++)  
                              ptr[i] = ' ';
                       for (i = line_horizontality - j - 1; i < line_horizontality; i++) 
                       {
                              ptr[i] = chr[count];
                              count++;
                       }
                       gotoxy(3, 10);
                       Sleep(200); 
                       printf("%s", ptr);
               }
               count = 1;
               for (j = line_horizontality - 2;j < horizontality; j++)
               {
                       countx = 0;
                       for (i = count; i < count + line_horizontality; i++)
                       {
                              ptr[countx] = chr[i];
                              countx++;
                       }
                       count++;
                       if ((horizontality - line_horizontality) <= count) 
                              break;
                       gotoxy(3, 10);
                       Sleep(200);
                       printf("%s", ptr);
               }
               for (j = 0; j < line_horizontality; j++) 
               {
                       for (i = 0; i < line_horizontality - j - 1; i++) 
                              ptr[i] = ptr[i + 1];
                       for (i = line_horizontality - j - 1; i < line_horizontality; i++) 
                              ptr[i] = ' ';
                       gotoxy(3, 10);
                       Sleep(200);
                       printf("%s", ptr);
               }
        }
        gotoxy(1, 12);
        fclose(fp);
}

void draw_rectangle(int c, int r)
{
	int i, j;
	unsigned char a=0xa6;
	unsigned char b[7]; 
	for(i=1;i<7;i++)
		b[i]=0xa0+i;
		printf("%c%c",a, b[3]);
	for(i=0;i<c;i++)
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[4]);
		printf("\n");
	for(i=0;i<r;i++)
	{
		printf("%c%c", a, b[2]);
		for(j=0;j<c;j++)
			printf(" ");
			printf("%c%c",a, b[2]);
			printf("\n");
	}
	printf("%c%c", a, b[6]);
	for(i=0;i<c;i++)
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[5]);
		printf("\n");
}
