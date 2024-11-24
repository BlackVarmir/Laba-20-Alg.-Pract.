#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace ns1
{
    int i, n;

	void v(vector<double>& array, double a, double b)
	{
		srand(time(0));
		for (i = 0; i < n - 1; ++i)
		{
			array[i] = a + static_cast<double>(rand()) / RAND_MAX * (b - a);
		}
	}

	double min(const vector<double>& array)
	{
		double minimum = array[0];
		for (i = 1; i < n; ++i)
		{
			if (array[i] < minimum)
			{
				minimum = array[i];
			}
		}
		return minimum;
	}

	void del(vector<double>& array, int index)
	{
		if (index >= 0 && index < n)
		{
			array.erase(array.begin() + index);
			--n;
		}
	}
}

namespace ns2
{
	int i;
	double s;

	void v(const vector<double>& array, double a, double b) {
		cout << "Елементи масиву [" << a << "; " << b << "]: ";
		for (i = 0; i < array.size(); ++i) {
			cout << fixed << setprecision(1) << array[i] << " ";
		}
		cout << endl;
	}

	double max(const vector<double>& array) {
		double maximum = array[0];
		for (i = 1; i < array.size(); ++i) {
			if (array[i] > maximum) {
				maximum = array[i];
			}
		}
		return maximum;
	}

	void del(vector<double>& array, double value) {
		array.erase(remove(array.begin(), array.end(), value), array.end());
	}
}

int main()
{
	int in;

	vector<double> A;
	ns1::n = 9;
	A.resize(ns1::n);

	vector<double> sums;
	double maxSum;

	while (true) {
		cout << "Меню:" << endl;
		cout << "1. Заповнити масив випадковими числами з відрізка [-10; 10]" << endl;
		cout << "2. Знаходження суми кожних трьох елементів і максимального значення" << endl;
		cout << "3. Сортування масиву за зростанням" << endl;
		cout << "4. Вивід масиву" << endl;
		cout << "5. Видалення елемента за індексом (ns1) і за значенням (ns2)" << endl;
		cout << "0. Вихід" << endl;
		cout << "Виберіть пункт меню: ";
		cin >> in;

		switch (in)
		{
		case 1:
			ns1::v(A, -10.0, 10.0);
			cout << "Масив після заповнення: " << endl;
			A.push_back(-5.0);
			ns2::v(A, -10.0, 10.0);
			cout << endl;
			break;
		case 2:
			for (int i = 0; i < ns1::n; i += 3) {
				ns2::s = A[i] + A[i + 1] + A[i + 2];
				sums.push_back(ns2::s);
			}
			maxSum = ns2::max(sums);
			cout << "Максимальна сума трьох елементів: " << maxSum << endl;
			cout << endl;
			break;
		case 3:
			cout << "Масив після сортування: ";
			for (ns1::i = 0; ns1::i < ns1::n; ++ns1::i)
			{
				for (ns2::i = 0; ns2::i < ns1::n - ns1::i - 1; ++ns2::i)
				{
					if (A[ns2::i] > A[ns2::i + 1])
					{
						swap(A[ns2::i], A[ns2::i + 1]);
					}
				}	
			}
			ns2::v(A, -10.0, 10.0);
			cout << endl;
			break;
		case 4:
			ns2::v(A, -10.0, 10.0);
			cout << endl;
			break;
		case 5:
			cout << "Видалення елемента з індексом 2 (ns1):" << endl;
			ns1::del(A, 2);
			ns2::v(A, -10.0, 10.0);

			cout << "Видалення елемента зі значенням -5.0 (ns2):" << endl;
			ns2::del(A, -5.0);
			ns2::v(A, -10.0, 10.0);
			cout << endl;
			break;
		case 0:
			return 0;
		default:
			cout << "Невірний пункт меню" << endl;
			break;
		}
	}
}


