#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int questionnum = 1;      //��Ŀ������ֵΪ0
int symbolnum = 1;        //�������������ֵΪ0
char symboltype[4] = { 0 };    //����������ֵΪ��
int maxnum = 1;           //�������ֵΪ0
int bracket_exist = 0;             //�Ƿ�������ţ�1��ʾ�����ţ�0��ʾû�����ţ�,Ĭ��Ϊ0
int smallnumber_exist = 0;              //�Ƿ����С����1��ʾ��С����0��ʾû��С����,Ĭ��Ϊ0
int printstyle = 0;          //�û�ѡ�������ʽ��1��ʾ������ļ���0��ʾ�����Ļ��,Ĭ��Ϊ0
float number[3] = { 0 };        //ʹ�õ����������ֵΪ0
char symbol[4] = { 0 };         //ʹ�õ��������ֵΪ��

void Menu_start()//��ʼ�˵�����
{
    printf("\n\n\n");
    printf("\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t    *       *       *                                  *       *       *\n");
    printf("\t\t   *       *       *                                    *       *       *\n");
    printf("\t\t  *       *       *     ��ӭʹ����������ϰ��������       *       *       *\n");
    printf("\t\t   *       *       *                                    *       *       *\n");
    printf("\t\t    *       *       *                                  *       *       *\n");
    printf("\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n\n\n");
  
}

void Set_parameter(void)//�����û��������
{
    printf("��������Ŀ������������������������������ʮ���⣬������10��\n");
    scanf("%d", &questionnum);
    if (questionnum <= 0)
    {
        printf("������������Ŀ������������������\n");
        scanf("%d", &questionnum);
    }
    printf("������Ҫʹ�õ�������������������������+������-������*������/����������ʹ��+-��������2��\n");
    scanf("%d", &symbolnum);
    if ((symbolnum < 1) || (symbolnum > 4))
    {
        printf("�����������������������������Ϊ1-4\n");
        scanf("%d", &symbolnum);
    }
    printf("������Ҫʹ�õ���������ڡ�+������-������*������/����ѡ�����룬�����������룩\n");
    scanf("%s", symboltype);
    printf("�����������,�������������������������ʮ���ڣ�������10��\n");
    scanf("%d", &maxnum);
    if (maxnum <= 0)
    {
        printf("�����������������������������\n");
        scanf("%d", &maxnum);
    }
    printf("��ѡ���Ƿ���С����0��ʾû��С����1��ʾ��С����\n");
    scanf("%d", &smallnumber_exist);
    printf("��ѡ���Ƿ������ţ�0��ʾû�����ţ�1��ʾ�����ţ�\n");
    scanf("%d", &bracket_exist);
   
    printf("��ѡ�������ʽ��0��ʾ�������Ļ��1��ʾ������ļ���\n");
    scanf("%d", &printstyle);
}

void Produce_random_number(void)//�����������
{
    for (int i = 0; i < 3; i++)
    {
        if (smallnumber_exist == 0)//������С��
        {
            number[i] = rand() % (maxnum )+1;//��������1-100�����
        }
        else//�������С��
        {
            number[i] = rand() % maxnum;
            number[i] = number[i] + rand() % 100 * 0.01;
        }
    }
}

void Produce_random_symbol(void)//�����������
{
    for (int i = 0; i < 4; i++)
    {
        symbol[i] = symboltype[ rand() % symbolnum ];
    }
}

void Print(void)//�������
{
    int bracket_place;   //����λ��
    FILE* fp;             //�ļ�ָ��
    fp = fopen("Four fundamental rules.txt", "w");//���ļ�д����
    for (int m = 0; m < questionnum; m++)
    {
        Produce_random_number();//�����������
        Produce_random_symbol();//�����������
        if (smallnumber_exist == 0)//��ʽ��û��С��
        {
            if (printstyle == 0)//�������Ļ
            {
                if (bracket_exist == 0)//��ʽ��û������
                {
                    printf("\n%.0f %c %.0f %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                }
                else//��ʽ��������
                {
                    bracket_place = rand() % 2;
                    if (bracket_place == 0)//�����ڵ�һ�����͵ڶ�������
                    {
                        printf("\n�� %.0f %c %.0f �� %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                    if (bracket_place == 1)//�����ڵڶ������͵���������
                    {
                        printf("\n%.0f %c ( %.0f %c %.0f ) =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                }
            }
            else//������ļ�
            {
                if (bracket_exist == 0)//��ʽ��û������
                {
                    fprintf(fp, "%.0f %c %.0f %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                }
                else//��ʽ��������
                {
                    bracket_place = rand() % 2;
                    if (bracket_place == 0)//�����ڵ�һ�����͵ڶ�������
                    {
                        fprintf(fp, "�� %.0f %c %.0f �� %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                    if (bracket_place == 1)//�����ڵڶ������͵���������
                    {
                        fprintf(fp, "%.0f %c ( %.0f %c %.0f ) =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                }
            }
        }
        else//��С��
        {
            if (printstyle == 0)//�������Ļ
            {
                if (bracket_exist == 0)//��ʽ��û������
                {
                    printf("\n%.2f %c %.2f %c %.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                }
                else//��ʽ��������
                {
                    bracket_place = rand() % 2;
                    if (bracket_place == 0)//�����ڵ�һ�����͵ڶ�������
                    {
                        printf("\n��%.2f %c %.2f �� %c %.2f %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                    if (bracket_place == 1)//�����ڵڶ������͵���������
                    {
                        printf("\n%.2f %c ( %.2f %c %.2f ) %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                }
            }
            else//������ļ�
            {
                if (bracket_exist == 0)//��ʽ��û������
                {
                    fprintf(fp, "%.2f %c %.2f %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                }
                else//������
                {
                    bracket_place = rand() % 2;
                    if (bracket_place == 0)//�����ڵ�һ�����͵ڶ�������
                    {
                        fprintf(fp, "�� %.2f %c %.2f ��%c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                    if (bracket_place == 1)//�����ڵڶ������͵���������
                    {
                        fprintf(fp, "%.2f %c ( %.2f %c %.2f ) %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
                    }
                }
            }
        }
    }
    fclose(fp);//�ر��ļ�
}

void Menu_end()//�����˵�����
{
    printf("\n\n\n");
    printf("\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t    *       *       *                                  *       *       *\n");
    printf("\t\t   *       *       *                                     *       *       *\n");
    printf("\t\t  *       *       *             ��лʹ��!!!                *       *       *\n");
    printf("\t\t   *       *       *                                     *       *       *\n");
    printf("\t\t    *       *       *                                   *       *       *\n");
    printf("\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n\n\n");
}

int main()
{
    Menu_start();              //���˵�����
    Set_parameter();         //��������
    srand((int)time(0)); //��֤ÿ�β������������ͬ
    Print();  //�������
    Menu_end();
	system("pause");
    return 0;
}
