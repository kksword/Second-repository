#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int questionnum = 1;      //题目数量初值为0
int symbolnum = 1;        //运算符种类数初值为0
char symboltype[4] = { 0 };    //运算符种类初值为空
int maxnum = 1;           //最大数初值为0
int bracket_exist = 0;             //是否存在括号（1表示有括号，0表示没有括号）,默认为0
int smallnumber_exist = 0;              //是否存在小数（1表示有小数，0表示没有小数）,默认为0
int printstyle = 0;          //用户选择输出方式（1表示输出到文件，0表示输出屏幕）,默认为0
float number[3] = { 0 };        //使用的数字数组初值为0
char symbol[4] = { 0 };         //使用的运算符初值为空

void Menu_start()//开始菜单界面
{
    printf("\n\n\n");
    printf("\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t    *       *       *                                  *       *       *\n");
    printf("\t\t   *       *       *                                    *       *       *\n");
    printf("\t\t  *       *       *     欢迎使用四则运算习题生成器       *       *       *\n");
    printf("\t\t   *       *       *                                    *       *       *\n");
    printf("\t\t    *       *       *                                  *       *       *\n");
    printf("\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n\n\n");
  
}

void Set_parameter(void)//设置用户需求参数
{
    printf("请设置题目数量，请输入正整数（例如想生成十道题，则输入10）\n");
    scanf("%d", &questionnum);
    if (questionnum <= 0)
    {
        printf("请重新设置题目数量（输入正整数）\n");
        scanf("%d", &questionnum);
    }
    printf("请设置要使用的运算符种类数，运算符包括“+”，“-”，“*”，“/”（例如想使用+-，则输入2）\n");
    scanf("%d", &symbolnum);
    if ((symbolnum < 1) || (symbolnum > 4))
    {
        printf("请重新设置运算符种类数，种类数为1-4\n");
        scanf("%d", &symbolnum);
    }
    printf("请输入要使用的运算符（在“+”，“-”，“*”，“/”中选择输入，符号连续输入）\n");
    scanf("%s", symboltype);
    printf("请设置最大数,请输入正整数（例如想控制在十以内，则输入10）\n");
    scanf("%d", &maxnum);
    if (maxnum <= 0)
    {
        printf("请重新设置最大数（输入正整数）\n");
        scanf("%d", &maxnum);
    }
    printf("请选择是否有小数（0表示没有小数，1表示有小数）\n");
    scanf("%d", &smallnumber_exist);
    printf("请选择是否有括号（0表示没有括号，1表示有括号）\n");
    scanf("%d", &bracket_exist);
   
    printf("请选择输出方式（0表示输出到屏幕，1表示输出到文件）\n");
    scanf("%d", &printstyle);
}

void Produce_random_number(void)//随机产生数字
{
    for (int i = 0; i < 3; i++)
    {
        if (smallnumber_exist == 0)//不存在小数
        {
            number[i] = rand() % (maxnum )+1;//控制生成1-100随机数
        }
        else//随机生成小数
        {
            number[i] = rand() % maxnum;
            number[i] = number[i] + rand() % 100 * 0.01;
        }
    }
}

void Produce_random_symbol(void)//随机产生符号
{
    for (int i = 0; i < 4; i++)
    {
        symbol[i] = symboltype[ rand() % symbolnum ];
    }
}

void Print(void)//输出函数
{
    int bracket_place;   //括号位置
    FILE* fp;             //文件指针
    fp = fopen("Four fundamental rules.txt", "w");//打开文件写操作
    for (int m = 0; m < questionnum; m++)
    {
        Produce_random_number();//随机产生数字
        Produce_random_symbol();//随机产生符号
        if (smallnumber_exist == 0)//算式中没有小数
        {
            if (printstyle == 0)//输出到屏幕
            {
                if (bracket_exist == 0)//算式中没有括号
                {
                    printf("\n%.0f %c %.0f %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                }
                else//算式中有括号
                {
                    bracket_place = rand() % 2;
                    if (bracket_place == 0)//括号在第一个数和第二个数上
                    {
                        printf("\n（ %.0f %c %.0f ） %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                    if (bracket_place == 1)//括号在第二个数和第三个数上
                    {
                        printf("\n%.0f %c ( %.0f %c %.0f ) =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                }
            }
            else//输出到文件
            {
                if (bracket_exist == 0)//算式中没有括号
                {
                    fprintf(fp, "%.0f %c %.0f %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                }
                else//算式中有括号
                {
                    bracket_place = rand() % 2;
                    if (bracket_place == 0)//括号在第一个数和第二个数上
                    {
                        fprintf(fp, "（ %.0f %c %.0f ） %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                    if (bracket_place == 1)//括号在第二个数和第三个数上
                    {
                        fprintf(fp, "%.0f %c ( %.0f %c %.0f ) =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                }
            }
        }
        else//是小数
        {
            if (printstyle == 0)//输出到屏幕
            {
                if (bracket_exist == 0)//算式中没有括号
                {
                    printf("\n%.2f %c %.2f %c %.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                }
                else//算式中有括号
                {
                    bracket_place = rand() % 2;
                    if (bracket_place == 0)//括号在第一个数和第二个数上
                    {
                        printf("\n（%.2f %c %.2f ） %c %.2f %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                    if (bracket_place == 1)//括号在第二个数和第三个数上
                    {
                        printf("\n%.2f %c ( %.2f %c %.2f ) %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                }
            }
            else//输出到文件
            {
                if (bracket_exist == 0)//算式中没有括号
                {
                    fprintf(fp, "%.2f %c %.2f %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                }
                else//有括号
                {
                    bracket_place = rand() % 2;
                    if (bracket_place == 0)//括号在第一个数和第二个数上
                    {
                        fprintf(fp, "（ %.2f %c %.2f ）%c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                    if (bracket_place == 1)//括号在第二个数和第三个数上
                    {
                        fprintf(fp, "%.2f %c ( %.2f %c %.2f ) %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                }
            }
        }
    }
    fclose(fp);//关闭文件
}

void Menu_end()//结束菜单界面
{
    printf("\n\n\n");
    printf("\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t    *       *       *                                  *       *       *\n");
    printf("\t\t   *       *       *                                     *       *       *\n");
    printf("\t\t  *       *       *             感谢使用!!!                *       *       *\n");
    printf("\t\t   *       *       *                                     *       *       *\n");
    printf("\t\t    *       *       *                                   *       *       *\n");
    printf("\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n\n\n");
}

int main()
{
    Menu_start();              //主菜单界面
    Set_parameter();         //参数设置
    srand((int)time(0)); //保证每次产生的随机数不同
    Print();  //输出函数
    Menu_end();
	system("pause");
    return 0;
}
