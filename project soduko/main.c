#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int c=0;
int flag=0;
char check[9][9];

char sudoku[9][9]={{' ','9','3','8','4',' ',' ','5','2'},{' ',' ','8','3',' ','1','6',' ','9'},{' ','2',' ','5',' ','7','3','8','4'},{'9','3','5','1',' ',' ','7',' ','6'},{' ','6',' ','9','7','5','8','3','1'},{'8','1','7','4','6','3',' ',' ',' '},{' ','8','9','6','1',' ','5',' ','7'},{'6','4','2','7','5',' ','9',' ','3'},{'5',' ','1',' ','3',' ',' ',' ','8'}};
void copysudoku(void)
{
int i,j;
if(flag==0)
{


    for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                check[i][j]=sudoku[i][j];

            }
        }

flag=1;

}
}
char check[9][9]={0};
int check_original(int x,int y)
{   int i,j;


    if(check[x][y]!=' ')
    {
        return -1;
    }
    else
        {return 0;}

return 0;
}


int check_edit(int x,int y,char value,char (*p)[9])
{
    int i,j;
if(value<48||value>57)
{
    return -1;
}
    for(i=x;i==x;i++)
        {
            for(j=0;j<9;j++)
            {
               if( p[i][j]==value)
               {    if(i==x&&j==y)
               {
                  continue;
               }
                   return -1;

               }

            }

        }

         for(j=y;j==y;j++)
        {
            for(i=0;i<9;i++)
            {
               if( p[i][j]==value)
               {
                    if(i==x&&j==y)
               {
                  continue;
               }
                   return -1;

               }

            }

        }



        return 0;
}


void print_sudoku(char(*sod)[9],int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {  //printf("\033[1;33m");
            if(check_original(i,j)==0&&c!=0)
            {
                  printf("\033[0;31m");
                   printf("%2c ",sod[i][j]);
            }
        else
            {   if(c!=0)
            {
                printf("\033[0;37m");
            }

             printf("%2c ",sod[i][j]);
            }



        }
printf("\n");
//printf("\n_____________________________\n");
    }



}


void insertvalue(int *x,int*y,char*value,char (*p)[9],int *user)
{ int i,j;

    printf("please insert the row and column ");
    fflush(stdin);
    scanf("%d%d",x,y);
    fflush(stdin);
    if(*user!=2)
    {
         printf("please enter the value ");
         fflush(stdin);
    scanf("%c",value);
    }






}
void deletevalue(int x,int y)
{
    sudoku[x][y]=' ';

}

int finish(char (*p)[9])
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
           if( p[i][j]==' ')
           {
               return -1;
           }
        }

    }
    return 0;
}





int main()
{
    int finish_game=1;
//char sudoku[9][9]={{' ','9','3','8','4',' ',' ','5','2'},{' ',' ','8','3',' ','1','6',' ','9'},{' ','2',' ','5',' ','7','3','8','4'},{'9','3','5','1',' ',' ','7',' ','6'},{' ','6',' ','9','7','5','8','3','1'},{'8','1','7','4','6','3',' ',' ',' '},{' ','8','9','6','1',' ','5',' ','7'},{'6','4','2','7','5',' ','9',' ','3'},{'5',' ','1',' ','3',' ',' ',' ','8'}};
//char s[2][9]={{' ','9','3','8','4',' ',' ','5','2'}};
//print_sudoku(sudoku,9);
int x,y,value;
copysudoku();
print_sudoku(sudoku,9);
while (1)
{

    int user_enter;
printf("for edit value enter 1\nfor delete value enter 2 ");
scanf("%d",&user_enter);
if(user_enter!=1&&user_enter!=2)
{   printf("wrong,please enter 1 or 2\n");
    continue;
}

insertvalue(&x,&y,&value,sudoku,&user_enter);

system("cls");

//printf("%c",check[x][y]);


printf("\n");

int checkOrignal=check_original(x,y);
if(checkOrignal==-1)
{
  printf("wrong cant edit the orignal\n");

}

int checkedit= check_edit(x,y,value,sudoku);
if(checkedit==-1)
{
  printf("wrong there is a vlaue equivlant at row or coloumn \n");

}
if((checkOrignal!=-1)&&(checkedit!=-1))
{
   sudoku[x][y]=value;
   finish_game=finish(sudoku);
}
if (user_enter==2&&checkOrignal!=-1)
{
    deletevalue(x,y);
}
if(finish_game==0)
{
    printf("congrates,you win");
    return 0;
}

print_sudoku(sudoku,9);
c++;
}
}
