#ifndef _matrix_h
#define _matrix_h

#include <iostream>
#include <cstring>
#include <cmath>

struct Line
{
	int x = -1;
	int y = -1;
	int data = 0;
};

struct Matrix
{
	int size = 0;
	Line* lines = nullptr;
	int m = 0;
	int n = 0;
};

template <class T>
T getNum(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()) 
{
        T a;
        while(true)
       	{
            std::cin >> a;
            if(std::cin.eof()) // обнаружен конец файла
	    {
                throw std::runtime_error("Failed to read number: EOF");
	    }
            else if(std::cin.bad()) // обнаружена невосстановимая ошибка входного потока
	    {
                throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
	    }
            else if(std::cin.fail()) //прочие ошибки (неправильный формат ввода)
	    {
                std::cin.clear(); // очищаем флаги состояния потока
                // игнорируем все символы до конца строки
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "You are wrong; repeat please!" << std::endl;
            }
          //  else if(a >= min && a <= max) // если число входит в заданный диапазон
                return a;
        }
}

Matrix input();

void output(const Matrix &matr);

void clearn(Matrix &matr);

Matrix function(Matrix &matr);

#endif 
