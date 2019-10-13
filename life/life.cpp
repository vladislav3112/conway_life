#include<iostream>
using namespace std;

int main() {
	const int SIZE = 8;// ����������� ������ �� 2 ������, �.�. ������� ������ ����� �������������
	char c;
	int count = 0;
	int gen_count = 1;
	short array[SIZE][SIZE];
	short niegh_count[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			array[i][j] = 0;
			niegh_count[i][j] = 0;
		}
	}
	
	setlocale(LC_ALL, "Russian");
	cout << "������� ������� " << SIZE - 2 << " * " << SIZE - 2 << endl;
	cout << "������ '.' -����������� ������;" << endl;
	cout << "������ '#' - ������������� ������." << endl;

	for (int i = 1; i < SIZE - 1; i++)
	{
		for (int j = 1; j < SIZE - 1; j++)
		{
			cin.get(c);
			if (c == '.')
				array[i][j] = 1;
			else if (c != '#') {
				cout << "�������� ������, ������� �������" << endl;
				return -1;
			}
			
		}
		cin.get(c);
	}
	cout << "������ ����, ������� q ��� ������, ������ ������ ��� �����������" << endl;
	while (cin.get(c))
	{
		if (c == 'q')break;
		cin.get(c);
		cout << "��������� "<<gen_count<<"  :"<< endl;
		for (int i = 1; i < SIZE - 1; i++)
		{
			for (int j = 1; j < SIZE - 1; j++)
			{
				count = array[i][j - 1] + array[i][j + 1]
					+ array[i + 1][j - 1] + array[i + 1][j] + array[i + 1][j + 1]
					+ array[i - 1][j - 1] + array[i - 1][j] + array[i - 1][j + 1];

				niegh_count[i][j] = count;
			}
		}

		for (int i = 1; i < SIZE - 1; i++)
		{
			for (int j = 1; j < SIZE - 1; j++)
			{
				if (( (niegh_count[i][j] == 3) & (array[i][j] == 0)  )|
					( ((niegh_count[i][j] == 3) | (niegh_count[i][j] == 2))&(array[i][j] == 1))  )array[i][j] = 1;
				else array[i][j] = 0;
			}
		}

		for (int i = 1; i < SIZE - 1; i++)
		{
			for (int j = 1; j < SIZE - 1; j++)
			{
				if (array[i][j] == 1)cout << ".";
				else cout << "#";
			}
			cout << '\n';
		}
		cout << "������� q ��� ������, ������ ������ ��� �����������" << endl;
		gen_count++;
	}
		return 0;
}