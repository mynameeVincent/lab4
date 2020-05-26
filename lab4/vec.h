#pragma once
#include<vector>
#include<algorithm>

namespace PseStl
{
	template<class T>
	class vector
	{
	protected:
		std::vector<T> *vec;

		void merge(T arr[], int beg, int mid, int end);

		void merge_sort(T arr[], int beg, int end);

	public:

		//constr
		vector(int N = 0)
		{
			vec = new std::vector<T>(N);
		}

		//copy constr
		vector(const vector<T>& opa)
		{
			vec = new vector<T>(opa.vec->size());
			for (auto f = opa.vec.begin(), ff = this->vec.begin(); f != opa.vec.end(); f++, ff++)
				*ff = *f;
		}

		//[]
		T& operator[](int N)
		{
			return vec->at(N);
		}

		//n
		int size()
		{
			return vec->size();
		}

		//N
		int capacity()
		{
			return vec->capacity();
		}

		//SORT
		void Marge_Sort();

		//push back
		void push_back(T z = 0)
		{
			vec->push_back(z);
		}
	
		~vector()
		{
			delete vec;
			vec = nullptr;
		}
	};

	template <class  T>
	void vector<T>::Marge_Sort()
	{
		this->merge_sort(&this->vec->at(0), 0, this->size() - 1);
	}

	template <class  T>
	void vector<T>::merge(T arr[], int beg, int mid, int end)
	{
		int left = mid - beg + 1;
		int right = end - mid;

		T* Left_arr = new T[left];
		T* Right_arr = new T[right];

		for (int i = 0; i < left; ++i)
			Left_arr[i] = arr[beg + i];

		for (int j = 0; j < right; ++j)
			Right_arr[j] = arr[mid + 1 + j];

		int i = 0, j = 0;
		int k = beg;
		while (i < left && j < right) {
			if (Left_arr[i] <= Right_arr[j]) {
				arr[k] = Left_arr[i];
				i++;
			}
			else {
				arr[k] = Right_arr[j];
				j++;
			}
			k++;
		}
		while (i < left) {
			arr[k] = Left_arr[i];
			i++; k++;
		}
		while (j < right) {
			arr[k] = Right_arr[j];
			j++; k++;
		}
	}
	
	template <class  T>
	void vector<T>::merge_sort(T arr[], int beg, int end)
	{

		if (beg < end)
		{
			int mid = (beg + end) / 2;
			merge_sort(arr, beg, mid);
			merge_sort(arr, mid + 1, end);
			merge(arr, beg, mid, end);
		}

	}

}