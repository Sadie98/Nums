#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

template<class T>
class Statistic {
private:
	vector<T> numbers;
	T max_num;
	T min_num;
	double avg;
	int my_size;

public:
	Statistic();

	~Statistic();

	void AddNum(const T num);

	void AddNum(const vector<T> numbers);

	void AddNumsFromFile(const string filename);

	void AddNum(Statistic numbers_set);
	
	T GetMax() const;
	
	T GetMin() const;
	
	float GetAvg() const;
	
	int GetCountUnder(T threshold) const;
	
	int GetCountAbove(T threshold) const;
	
};
