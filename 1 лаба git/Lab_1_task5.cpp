#include "stdafx.h"
#include "locale.h"
#include <iostream>
#include <string>
using namespace std;
    int size = 3;
	int search=0;
	int i,metka;
	struct student
	{
		char famil[200];
		char name[200], facult[200];
		int Nomzach;
	} stud[3];
int   main()
{
	setlocale(LC_ALL, "Russian");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	for (i = 0; i < size; i++) {
        printf("������� ������� �������� ");
        scanf("%s", &stud[i].famil);

        printf("������� ��� �������� ");
        scanf("%s", &stud[i].name);

        printf("������� �������� ���������� �������� %s %s ",stud[i].famil,stud[i].name);
        scanf("%s", &stud[i].facult);

        printf("������� ����� �������� ������ �������� %s %s ",stud[i].famil,stud[i].name);
        scanf("%d", &stud[i].Nomzach);
		printf("\n");
	}
	for(i=0;i<size;i++)
		{
			printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n",stud[i].famil,stud[i].name,
					stud[i].facult,stud[i].Nomzach);
		}
	printf("�� ������ ������ ����� �� �������� ����������? 1/0 ");
	scanf("%d",&metka);
	if (metka == 1){
	cout << "�������� ����� �� ������� ��������: "<< std::endl;
	cout << "1.������� "<< std::endl;
	cout << "2.��� "<< std::endl;
	cout << "3.��������� "<< std::endl;
	
	
	do {
        std::cin >> search;
    } while ((search < 1) && (search > 4));
	
	switch (search){
	
	case 1:
		{
	string userFam;
    cout << "������� ������� ��� ������: ";
	cin.sync();
    getline(std::cin, userFam);
	cout << "���������� ������ \"" << userFam << "\": " << std::endl;
	for (int i = 0; i < size; i++) {
		if (stud[i].famil == userFam){
        cout << "2.��� "<< stud[i].name << std::endl;
	    cout << "3.��������� "<< stud[i].facult << std::endl;
	    cout << "4.����� �������� ������ "<< stud[i].Nomzach << std::endl;
		}
	}
	break;
		}
	case 2:
		{
	string userFam;
    cout << "������� ��� ��� ������: ";
	cin.sync();
    getline(std::cin, userFam);
	cout << "���������� ������ \"" << userFam << "\": " << std::endl;
	for (int i = 0; i < size; i++) {
		if (stud[i].name == userFam){
        cout << "1.������� "<< stud[i].famil << std::endl;
	    cout << "3.��������� "<< stud[i].facult << std::endl;
	    cout << "4.����� �������� ������ "<< stud[i].Nomzach << std::endl;
		}
	}
	break;
	}
		case 3:
		{
	string userFam;
    cout << "������� ��������� ��� ������: ";
	cin.sync();
    getline(std::cin, userFam);
	std::cout << "���������� ������ \"" << userFam << "\": " << std::endl;
	for (int i = 0; i < size; i++) {
		if (stud[i].facult == userFam){
        cout << "1.������� "<< stud[i].famil << std::endl;
	    cout << "2.��� "<< stud[i].name << std::endl;
	    cout << "4.����� �������� ������ "<< stud[i].Nomzach << std::endl;
		}
	}
	break;
	}
		
	}
	}
	else
		return 0;
	getchar();
	return 0;
}

	


