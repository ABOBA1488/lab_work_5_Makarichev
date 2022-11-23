/******************************************************************************
��������� ���� ������������
����1-2
������������ ������ �5 �����������
������� � 4
�������: ��������   ���������,   �������   ����������   �   ����������  �  ����  ���������  ��������  ���������   ��������   �������.
� ��������  �����������  �����  ���������  ������������  ������ ���������. 
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <locale>
#include <Windows.h>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

struct FootBall_command
{
    string name;
    string city;
    string coach_LastName;
    int players_count = 11;
    int games_count=0;
    int points_count=0;//�� ����� ��������� ����� ����������� ����������
};

typedef FootBall_command* P_command; //������ ��������

void Sort�ommand(P_command p[], int n)// ����� �
{
    P_command temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 2; j >= i; j--)
        {
            if (p[j + 1]->points_count < p[j]->points_count)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void resize(int& n, FootBall_command*& arr)//���������� ����������� ������� ��������
{
    int newSize = n + 1;
    FootBall_command* newArr = new FootBall_command[newSize];

    copy(arr, arr + n, newArr);

    n = newSize;
    
    arr = newArr;
}
void Search(P_command p[], int n)// ����� �
{   
    cout << "������� ��� ������� ��� ������" << endl;
    string Name;
    cin >> Name;
    bool U = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i]->name == Name)
        {
            cout << "�� ������ ������� ������� �������" << endl;
            cout << "�������� ������� " << p[i]->name << ".���������� ������� " << p[i]->players_count << ".������� ������� " <<
                p[i]->coach_LastName << ".����� " << p[i]->city << ".���������� ��� " << p[i]->games_count << ".���������� ����� "
                << p[i]->points_count << " " << endl;
            U = 1;
        }
    }
    if (U == 0) 
    {
        cout << "������ 322 ������� �� �������"<<endl;
    }
}
int main()
{
    int N = 3;
    string question;
    system("chcp 1251");
    setlocale(LC_ALL, "russian");
    ofstream fout("F1.txt");
    FootBall_command* F =new FootBall_command[N];//�������� ������
    P_command* p = new P_command[N];//�������� ������
    //��������� ���������
    cout << "***********************************************************************************************************************" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "������� ��� �������" << endl;
        cin >> F[i].name;
        cout << "������� ������� �������" << endl;
        cin >> F[i].coach_LastName;
        cout << "����� �������" << endl;
        cin >> F[i].city;
        cout << "���������� ���" << endl;
        cin >> F[i].games_count;
        cout << "���������� �����" << endl;
        cin >> F[i].points_count;
        cout << endl;
    }
    for (int i = 0; i < N; i++)
    {
        p[i] = &F[i];//������ ������
    }
    
    cout << "***********************************************************************************************************************" << endl;
    cout << "�� ������ ����� �����-�� ������� ? (��/���)" << endl;
    cin >> question;
    if (question == "��")
    {
        FootBall_command* P = new FootBall_command[N ];
        for (int i = 0; i < N; i++)
        {
            p[i] = &F[i];//������ ������
        }
        Search(p, N);
    }
    else {}
    cout << "***********************************************************************************************************************" << endl;
    cout << "�� ������ �������� ������� ? (��, ���)"<<endl;
    cin >> question;
    int G;
    if (question == "yes" || question == "��") 
    {
        cout << "������� ������ �� ������� �������� ?" << endl;
        cin >> G;
        int u = 0;
        for (int i = 3;u!=G; i++) 
        {
            resize(N, F);
            cout << "������� ��� �������" << endl;
            cin >>F[i].name;
            cout << "������� ������� �������" << endl;
            cin >>F[i].coach_LastName;
            cout << "����� �������" << endl;
            cin >> F[i].city;
            cout << "���������� ���" << endl;
            cin >>F[i].games_count;
            cout << "���������� �����" << endl;
            cin >> F[i].points_count;
            cout << endl;
            u++;
        }
        cout << "***********************************************************************************************************************" << endl;
    }
    else
    {
        cout << "***********************************************************************************************************************" << endl;
        
    }
    for (int i = 0; i < N; i++)//����� �
    {
        fout << "�������� ������� " << F[i].name << ".���������� ������� " << F[i].players_count << ".������� ������� " <<
            F[i].coach_LastName << ".����� " << F[i].city << ".���������� ��� " << F[i].games_count << ".���������� ����� "
            << F[i].points_count << " " << endl;
    }
    fout << endl;
    P_command* P = new P_command[N];//�������� ������
    for (int i = 0; i < N; i++)
    {
        P[i] = &F[i];//������ ������
    }
    Sort�ommand(P, N);// ����� �
    for (int i = 0; i < N; i++)//����� �
    {
        fout << "�������� ������� " << P[i]->name << ".���������� ������� " << P[i]->players_count << ".������� ������� " <<
            P[i]->coach_LastName << ".����� " << P[i]->city << ".���������� ��� " << P[i]->games_count << ".���������� ����� "
            << P[i]->points_count << " " <<endl;
    }
    //������� ������
    delete[]F;
    delete[]p;
    fout.close();
    return 0;
}