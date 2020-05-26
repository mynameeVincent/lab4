#pragma once

namespace HMStl
{
	template<class vec_T>
	class vector
	{
	protected:

		//vector's size is n
		unsigned int n;

		//full vector's size is N
		unsigned int N;

		//vector's array
		vec_T* vec_arr;

		//SWAP
		void SWAP(int a, int b);

		void merge(vec_T arr[], int beg, int mid, int end);

		void merge_sort(int arr[], int beg, int end);

	public:

		class iterator;

		//constr
		vector(int N = 0);

		//copy constr
		vector(const vector<vec_T>& opa);

		~vector()
		{
			n = 0;
			N = 0;
			delete[] vec_arr;
			vec_arr = nullptr;
		}

		//[]
		vec_T& operator[](int N);

		//begin
		iterator begin()
		{
			return vec_arr;
		}

		//end
		iterator end()
		{
			return vec_arr + n;
		}

		//n
		int size();

		//N
		int capacity();

		//SORT
		void Marge_Sort();

		//push back
		void push_back(vec_T z = 0);

		class iterator
		{
		private:
			vec_T* poin;
		public:
			iterator (vec_T* now):poin(now)		{	}

			bool operator == (const iterator& now)
			{
				return now.poin != poin;
			}
			bool operator != (const iterator& now)
			{
				return now.poin != poin;
			}
			bool operator >  (const iterator& now)
			{
				return now.poin != poin;
			}
			bool operator <  (const iterator& now)
			{
				return now.poin != poin;
			}
			bool operator >= (const iterator& now)
			{
				return now.poin != poin;
			}
			bool operator <= (const iterator& now)
			{
				return now.poin != poin;
			}

			vec_T& operator + (const int now)
			{
				return *(this->poin + now);
			}
			vec_T& operator - (const int now)
			{
				return *(this->poin - now);
			}

			vec_T& operator ++ (const int now)
			{
				return *poin++;
			}
			vec_T& operator -- (const int now)
			{
				return *poin--;
			}
			vec_T& operator -- ()
			{
				return *--poin;
			}
			vec_T& operator ++ ()
			{
				return *++poin;
			}
		
			vec_T& operator [] (int op)
			{
				return poin[op];
			}
			vec_T operator *()
			{
				return *poin;
			}
		};
	};

	template <class  vec_T>
	vector<vec_T>::vector(int N)
	{
		this->N = N;
		this->n = N;
		this->vec_arr = new vec_T[N]{};
	}

	template <class  vec_T>
	vector<vec_T>::vector(const vector<vec_T>& opa)
	{
		this->N = opa.N;
		this->n = opa.n;
		this->vec_arr = new vec_T[N];
		for (int f = 0; f < N; f++)
		{
			this->vec_arr[f] = opa.vec_arr[f];
		}
	}

	template <class  vec_T>
	vec_T& vector<vec_T>::operator[](int N)
	{
		return vec_arr[N];
	}

	template <class  vec_T>
	int vector<vec_T>::size()
	{
		return n;
	}

	template <class  vec_T>
	int vector<vec_T>::capacity()
	{
		return N;
	}

	template <class  vec_T>
	void vector<vec_T>::SWAP(int a, int b)
	{
		vec_T zz = this->vec_arr[a];
		this->vec_arr[a] = this->vec_arr[b];
		this->vec_arr[b] = zz;
	}

	//chec me please
	template <class  vec_T>
	void vector<vec_T>::merge_sort(int arr[], int beg, int end) 
	{
		if (beg < end) {
			int mid = (beg + end) / 2;
			merge_sort(arr, beg, mid);
			merge_sort(arr, mid + 1, end);
			merge(arr, beg, mid, end);
		}
	}

	template <class  vec_T>
	void vector<vec_T>::Marge_Sort()
	{
		this->merge_sort(this->vec_arr, 0, this->size() - 1);
	}

	template <class  vec_T>
	void vector<vec_T>::merge(vec_T arr[], int beg, int mid, int end)
	{
		int left = mid - beg + 1;
		int right = end - mid;

		vec_T *Left_arr = new vec_T[left];
		vec_T *Right_arr = new vec_T[right];

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

	template <class  vec_T>
	void vector<vec_T>::push_back(vec_T z)
	{
		if (n < N)
		{
			vec_arr[n] = z;
			n++;
		}
		else
		{
			N += int(N / 3) + 1;
			vec_T* ss = new vec_T[N]{};
			for (unsigned int f = 0; f < n; f++)
				ss[f] = vec_arr[f];
			ss[n] = z;
			n++;
			delete vec_arr;
			vec_arr = ss;
			ss = nullptr;
		}
	}
}
