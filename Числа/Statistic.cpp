#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Statistic.h"
using namespace std;

template <class T>
Statistic<T>::Statistic() {
	vector<T> numbers;
	max_num = 0;
	min_num = 0;
	avg = 0;
	my_size = 0;
	};

template <class T>
Statistic<T>::~Statistic() {}


template <class T>
void Statistic<T>::AddNum(const T num)
	{
		if (my_size == 0)
		{
			numbers.insert(numbers.end(), num);
			my_size++;
			max_num = num;
			min_num = num;
			avg = num;
		}
		else
		{
			int i;
			numbers.insert(numbers.end(), 0);
			for (i = 0; ((num < numbers[i]) && (i < my_size)); i++) {};
			for (int j = my_size; j > i; j--)
				numbers[j] = numbers[j - 1];
			numbers[i] = num;
			avg = (avg * my_size + num) / (my_size + 1);
			my_size++;
			if (num > max_num)
				max_num = num;
			if (num < min_num)
				min_num = num;

		}
	}


template <class T>
void Statistic<T>::AddNum(const vector<T> numbers) {
	for (int i = 0; i < numbers.size(); i++)
		AddNum(numbers[i]);
}

template <class T>
void Statistic<T>::AddNumsFromFile(const string filename) {	ifstream my_file;
	my_file.open(filename);
	string this_str;
	char buf[100] = "";
	while (my_file.getline(buf, 100))
	{
		this_str = string(buf);		int this_num = stoi(this_str);		AddNum(this_num);	}}template <class T>void Statistic<T>::AddNum(Statistic numbers_set) {	for (int i = 0; i < numbers_set.my_size; i++)		AddNum(numbers_set.numbers[i]);}
template <class T>
T Statistic<T>::GetMax() const
	{
		return max_num;
	}

template <class T>
T Statistic<T>::GetMin() const
	{
		return min_num;
	}

template <class T>
float Statistic<T>::GetAvg() const
	{
		return avg;
	}

template <class T>
int Statistic<T>::GetCountUnder(T threshold) const
	{
		int i = numbers.size() - 1;
		while ((numbers[i] < threshold) && (i > 0))
		{
			i--;
		}
		return my_size - i - 1;
	}

template <class T>
int Statistic<T>::GetCountAbove(T threshold) const 
	{
		int i = numbers.size() - 1;
		while ((numbers[i] < threshold) && (i > 0))
		{
			i--;
		}
		return i + 1;
	}


