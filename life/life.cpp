#include<iostream>
using namespace std;

int main() {
	int size;// фактический размер на 2 меньше, т.о. крайние случаи легче рассматривать
	char c;
	int count = 0;
	int gen_count = 1;

	setlocale(LC_ALL, "Russian");
	cout << "Введите размер таблицы" << endl;
	cin >> size;
	size += 2;
	short** array = new short*[size];
	short** niegh_count = new short*[size];
		for (int i = 0; i < size;i++) array[i] = new short[size];
		for (int i = 0; i < size; i++) niegh_count[i] = new short[size];
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			array[i][j] = 0;
			niegh_count[i][j] = 0;
		}
	}
	
	cout << "введите таблицу " << size - 2 << " * " << size - 2 << endl;
	cout << "символ '.' -заполненная клетка;" << endl;
	cout << "символ '#' - незаполненная клетка." << endl;
	

	for (int i = 1; i < size - 1; i++)
	{
		for (int j = 1; j < size - 1; j++)
		{
			cin>>c;
			if (c == '.')
				array[i][j] = 1;
			else if (c != '#') {
				cout << "Неверный символ, начните сначала" << endl;
				return -1;
			}
			
		}
		cin.get(c);
	}
	cout << "Запуск игры, нажмите q для выхода, другой символ для продолжения" << endl;
	while (cin.get(c))
	{
		if (c == 'q')break;
		cin.get(c);
		cout << "поколение "<<gen_count<<"  :"<< endl;
		for (int i = 1; i < size - 1; i++)
		{
			for (int j = 1; j < size - 1; j++)
			{
				count = array[i][j - 1] + array[i][j + 1]
					+ array[i + 1][j - 1] + array[i + 1][j] + array[i + 1][j + 1]
					+ array[i - 1][j - 1] + array[i - 1][j] + array[i - 1][j + 1];

				niegh_count[i][j] = count;
			}
		}

		for (int i = 1; i < size - 1; i++)
		{
			for (int j = 1; j < size - 1; j++)
			{
				if (( (niegh_count[i][j] == 3) & (array[i][j] == 0)  )|
					( ((niegh_count[i][j] == 3) | (niegh_count[i][j] == 2))&(array[i][j] == 1))  )array[i][j] = 1;
				else array[i][j] = 0;
			}
		}

		for (int i = 1; i < size - 1; i++)
		{
			for (int j = 1; j < size - 1; j++)
			{
				if (array[i][j] == 1)cout << ".";
				else cout << "#";
			}
			cout << '\n';
		}
		cout << "нажмите q для выхода, другой символ для продолжения" << endl;
		gen_count++;
	}
		return 0;
}