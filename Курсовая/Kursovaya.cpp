#include "StdAfx.h"
#include <stdlib.h>
#include "stdafx.h"
#include "locale.h"
#include "iostream"
#include <vector>
#include "time.h"
bool gen_create = false;
bool gen_init = false;
int metka = 0;
int size;
using namespace std;
vector<int> mt;
vector<vector<int>> graph;
vector<char> used(size);
FILE* READ;
FILE* WRITE;
int** create_mass(int size){
	
	//gen_create = true;
	int **n = (int**)malloc(sizeof(int*)*size);
	for(int i=0;i<size;i++){
		n[i] = (int*)malloc(sizeof(int)*size);
	}
	return n;
}

int** initializate(int** n, int size){
	//gen_init = true;
	srand(time(NULL));
	for(int i = 0; i < size; i++) {
 for (int j = 0; j < size; j++) {
   n[i][j] = rand()%2;
}
}

for(int i = 0; i < size; i++) {
 for (int j = 0; j < size; j++) {
  if(i == j){
   n[i][j] = 0;

}
 if(n[i][j] = n[j][i]){
  n[i][j] = n[j][i];
}
}
}
WRITE = fopen("Write_graph.txt", "w");
for(int i = 0; i < size; i++) {
 for (int j = 0; j < size; j++) {
  fprintf(WRITE, "%3d ", n[i][j]);
}
 fprintf(WRITE, "\n");
}
fclose(WRITE);
return n;
}
int ruchn_vvod(int** n, int size){
	gen_init = true;
	cout << "Введите граф размером " << size*size << " символов (только 0 и 1): \n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			 cin >>n[i][j];

		}
	}
	return 0;
}


int** file_vvod(int** n,int size){
	gen_init = true;
	READ = fopen("Read_graph.txt", "r");
	if(fopen("Read_graph.txt", "r")== NULL)
		cout <<"Файл не найден!";
	    
	else{
	fseek (READ, 0, SEEK_END);
		long size_file = ftell(READ);
	if(size_file/2 != size){
		cout <<"Размеры не совпадают!";
	return 0;
	}
	else{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			 fscanf(READ, "%d", &n[i][j]);

		}
	}
	}
	}
	fclose(READ);
	return n;
}
bool khun(int v){
	if (used[v]) 
		return false;
	used[v] = true;
	for (int i=0; i<graph[v].size(); ++i) {
		int to = graph[v][i];
		if (mt[to] == -1 || khun(mt[to])) {
			mt[to] = v;
			metka++;
			return true;
		}
	}
	
	return false;
}
int main()
{
	
	int **n;
	setlocale(LC_ALL, "");
	int k = 1;
    int k_new = 1;
	
	while (k)
	 {
     cout << "\n1 - задать двудольный граф размером NхN\n2 - заполнить граф автоматически\n3 - заполнить граф вручную(из файла или с кравиатуры)\n4 - вывод сгенерированного графа\n5 - проверка сгенерированного графа\n" << "0 - выход" << endl;
	 cin >> k; 
//----------------------------------------------------------------Создание (ввод количества вершин)
	  if(k==1){ 
	  cout << "Введите количество вершин (больше 2): ";
	  cin >> size;
	  if (size > 2){
	 n = create_mass(size);
	 if (n)
		  cout << "Граф создан!\n";
	 else
		  cout << "Ошибка распределения памяти!\n";
	  }
	  else
       cout << "Введите корректные данные!\n";
	  }
//---------------------------------------------------------Заполнение графа
	  if(k==2){
		 
		 initializate(n,size);
		 
          cout << "Граф заполнен и записан в файл!\n";
		 
	 
	  }
//--------------------------------------------------------------Ручной ввод
	  if(k==3){
		  cout << "\n1 - задать граф с клавиатуры\n2 - задать граф из файла в папке проекта\n";
		 cin >> k_new;
		 if((k_new > 2)||(k_new < 1))
          cout << "Введите корректные данные!\n";
		 else if (k_new == 1){
		 if(gen_create == true){
        ruchn_vvod(n,size);
		 }
		 else
			 cout << "Сгенерируйте граф!\n";
	  }
		 else if (k_new == 2){
         file_vvod(n,size);
	  }
	  }
//-------------------------------------------------------------Вывод графа
	  if(k==4){
		 
      cout << "Сгенерированный граф: \n";
		 
	for(int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%3d", n[i][j]);
     }
	cout <<"\n";
     }
	 
	  }
//------------------------------------------------------------Проверка графа
	 if (k == 5){
		 
		 for (size_t i = 0; i < size; ++i) {
            vector<int> row; // Создаём пустой текущий ряд
          for (size_t j = 0; j < size; ++j) {
           row.push_back(n[i][j]); // Кладём элемент в конец текущего ряда
           }
             graph.push_back(row); // Кладём заполненный текущий ряд в конец матрицы
             }
		 cout <<"\n";
		 for (size_t i = 0; i < graph.size(); ++i) {
           for (size_t j = 0; j < graph[i].size(); ++j)
           cout << graph[i][j] << ' ';
             cout << endl;
}
		 cout <<"\n";
		   


		 mt.assign (size, -1);
for (int v=0; v<size; ++v) {
		used.assign (size, false);
		khun(v);
	}
for (int i=0; i<size; ++i){
		if (mt[i] != -1)
			printf ("%d  %d\n", mt[i]+1, i+1);	 
}
printf("\n%d", metka);
		 
	 }
	
//--------------------------------------------------------
	 if(k==0)
      return 0;
	 }
	 system("pause");
	
}
	  
	
	


