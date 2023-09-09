#include <iostream>
#include "matrix.h"

void clearn(Matrix &matr)
{
	if(matr.lines != nullptr)
	{
		delete[] matr.lines;
		matr.lines = nullptr;
		matr.m = 0;
		matr.n = 0;
		matr.size = 0;
	}
}

void proverka(Matrix &matr)
{
	if(matr.size > matr.n * matr.m / 2)
	{
		clearn(matr);
		throw std::runtime_error("This is not matrix for my sent\n");
	}
}

Matrix input()
{
	Matrix matr;
	try
	{
		matr.lines = nullptr;
		std::cout << "Input number of line (m):" << std::endl;
		int m = getNum <int>(0);
		std::cout << "Input number of items in line(n):" << std::endl;
		int n = getNum <int>(0);
		matr.n = n;
		matr.m = m;
		matr.lines = new Line[5]();
		matr.size = 5;
		int count = 0;
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				std::cout << "Input data:" << std::endl;
				int data = getNum <int> (0);
				if(data == 0)
				{
					continue;
				}
				if(count < matr.size)
				{
					matr.lines[count].x = i;
					matr.lines[count].y = j;
					matr.lines[count].data = data;
					count++;
					continue;
				}
				matr.size *= 2;
				Line* l = new Line[matr.size];
				std::copy(matr.lines, matr.lines + matr.size / 2, l);
				delete[] matr.lines;
				matr.lines = l;
				matr.lines[count].x = i;
				matr.lines[count].y = j;
				matr.lines[count].data = data;
				count++;
			}
		}

	}
	catch(...)
	{
		clearn(matr);
		throw;
	}
	return matr;
}

int find(const Matrix &matr, int i, int j)
{
	for(int k = 0; k < matr.size; k++)
	{
		if(matr.lines[k].x == i && matr.lines[k].y == j)
		{
			return k;
		}
	}
	return -1;
}

void output(const Matrix &matr)
{
	for(int i = 0; i < matr.m; i++)
	{
		for(int j = 0; j < matr.n; j++)
		{
			int index = find(matr, i, j);
			if(index != -1)
			{
				std::cout << matr.lines[index].data << " ";
				continue;
			}
			std::cout << 0 << " ";
		}
		std::cout << std::endl;
	}
}

int f(int dat)
{
	int sum = 0;
	int data = fabs(dat);
	while(data != 0)
	{
		sum += data % 10;
		data /= 10;
	}
	return sum;
}

Matrix function(Matrix &matr)
{
	Matrix m;
	m.lines = nullptr;
	for(int i = 0; i < matr.m; i++)
	{
		int index = find(matr, i, matr.n - 1);
		if(index == -1)
		{
			continue;
		}
		int res = f(matr.lines[index].data);
		int in = index;
		while(in >= 0)
		{
			int p = f(matr.lines[in].data);
			if(matr.lines[in].x != i)
			{
				break;
			}
			if(p == res)
			{
				m.size++;
				Line* l = new Line[m.size];
				std::copy(m.lines, m.lines + m.size - 1, l);
				delete[] m.lines;
				m.lines = l;
				m.lines[m.size - 1].x = i;
				m.lines[m.size - 1].y = matr.lines[in].y;
				m.lines[m.size - 1].data = matr.lines[in].data;
			}
			in--;
		}
	}
	m.n = matr.n;
	m.m = matr.m;
	return m;
}
