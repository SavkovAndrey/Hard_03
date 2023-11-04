#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//--------------------�������----------------------------------------------------
/*
����������� ��������� ��� ��������� ������.
��������� ������ ��������� ��������� �������� :
�����,
���������,
��������� ���� ������.
������� ������ ��������� � ���� ������ ������.
�� ����, ��� ������� ���������, ���������� ������� �� ������ ��� ������� � ��� ����� ����� ����������� ����������.
��������� ������� �� �����.
*/
//---------------------������� � ���������---------------------------------------





//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------���� �����-------------------------------------

	int col1 = 1, col2 = 1, row1 = 1, row2 = 1;


	string in1, in2;   // ���������� ��� �������� ������ � �������� ���������

	char ch1 = '\0';
	char ch2 = '\0';

	cout << "������� ��� ����� � ������ ��������: ";
	//cin >> in1;
	in1 = "m1.txt";

	cout << "������� ��� ����� �� ������ ��������: ";
	//cin >> in2;
	in2 = "m2.txt";

	ifstream fin1;

	fin1.open(in1);

	if (!fin1.is_open())
	{
		cout << "������ �������� ����� � ������ ��������!" << endl;
	}
	else
	{
		cout << "���� � ������ �������� ������ ���������!" << endl;

		while (!fin1.eof())
		{
			ch1 = '\0';
			fin1.get(ch1);

			cout << ch1;                                                             // �������

			//-----������� ����� � �������� -------------
			if (ch1 == '\n')
			{
				row1++;
			}

			if (ch1 == ' ' && row1 == 1)
			{
				col1++;
			}


			//------------------------------ --------------

		}

		cout << endl << endl << "row = " << row1 << "col = " << col1 << endl;         // �������

	}

		//-------�������� ������������� �������--------------------------

		int** arr1 = new int* [row1];
		for (int i = 0; i < row1; i++)
		{
			arr1[i] = new int[col1];                  
		}

		//-----------���������� ������������� ������� �� �����-------------

		string buff = "";
		int i1 = 0, j1 = 0;

		cout << endl << "����� ������� ( ��� �������� ������ �� ����� � ������):" << endl;

		fin1.clear();
		fin1.seekg(0);
		
		while (!fin1.eof())
		{
			ch1 = '\0';
			fin1.get(ch1);

			cout << ch1;                                                             // �������

			
			if (ch1 == ' ')
			{
				arr1[i1][j1] = stoi(buff);
				buff = "";
				j1++;
			}
			else if (ch1 == '\n')
			{
				arr1[i1][j1] = stoi(buff);
				buff = "";
				i1++;
				j1 = 0;
			}
			else if (ch1 == '\0')
			{
				arr1[i1][j1] = stoi(buff);
				buff = "";
			}
			else
			{
				buff = buff + ch1;
			}

		}

		cout << endl << "����� ������������� ������� ������ �������: " << endl;

		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				cout << arr1[i][j] << "\t";
			}
			cout << endl;
		}


	cout << endl;
	fin1.close();

	
	//-----------------------------------------------------------------------------------------------------------
	ifstream fin2;

	fin2.open(in2);

	if (!fin2.is_open())
	{
		cout << "������ �������� ����� �� ������ ��������!" << endl;
	}
	else
	{
		cout << "���� �� ������ �������� ������ ���������!" << endl;


		while (!fin2.eof())
		{
			ch2 = '\0';
			fin2.get(ch2);

			cout << ch2;                                                        // �������
			
			if (ch2 == '\n')
			{
				row2++;
			}

			if (ch2 == ' ' && row2 == 1)
			{
				col2++;
			}


		}
		cout << endl << endl << "row = " << row2 << "col = " << col2 << endl;         // �������

	}
	cout << endl;
	//----�������� ����
	int** arr2 = new int* [row2];
	for (int i = 0; i < row2; i++)
	{
		arr2[i] = new int[col2];
	}
	//-----

	string buff2 = "";
	int i2 = 0, j2 = 0;

	cout << endl << "����� ������� ( ��� �������� ������ �� ����� � ������):" << endl;

	fin2.clear();
	fin2.seekg(0);

	while (!fin2.eof())
	{
		ch2 = '\0';
		fin2.get(ch2);

		cout << ch2;                                                             // �������


		if (ch2 == ' ')
		{
			arr2[i2][j2] = stoi(buff2);
			buff2 = "";
			j2++;
		}
		else if (ch2 == '\n')
		{
			arr2[i2][j2] = stoi(buff2);
			buff2 = "";
			i2++;
			j2 = 0;
		}
		else if (ch2 == '\0')
		{
			arr2[i2][j2] = stoi(buff2);
			buff2 = "";
		}
		else
		{
			buff2 = buff2 + ch2;
		}

	}

	cout << endl << "����� ������������� ������� ������ �������: " << endl;

	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			cout << arr2[i][j] << "\t";
		}
		cout << endl;
	}


	cout << endl;

	fin2.close();

	//---------------------------------!!!!  ������  !!!!---------------------------------------------------
	//---------------------------------    ��������      ------------------------------------------
	cout << endl << endl << "�������� ������: " << endl << endl;

	if (row1 == row2 && col1 == col2)
	{
		//--�������� �������.
		int** result_sum = new int* [row1];
		for (int i = 0; i < row1; i++)
		{
			result_sum[i] = new int[col1];
		}
		//--���������� ���. � ����� ���.

		cout << endl << "�������������� �������: " << endl;
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				result_sum[i][j] = arr1[i][j] + arr2[i][j];
				cout << setw(4) << result_sum[i][j];
			}
			cout << endl;
		}

		//--�������� �������.
		for (int i = 0; i < row1; i++)
		{
			delete[] result_sum[i];
		}
		delete[] result_sum;

	}
	else
	{
		cout << "�������� �� ��������, ������� ����� ������ �����������!!";
	}
	cout << endl;

	//---------------------------------    ���������    ----------------------------------------------------

	cout << endl << endl << "��������� ������: " << endl << endl;

	if (row1 == row2 && col1 == col2)
	{
		//--�������� �������.
		int** result_sum = new int* [row1];
		for (int i = 0; i < row1; i++)
		{
			result_sum[i] = new int[col1];
		}
		//--���������� ���. � ����� ���.

		cout << endl << "�������������� �������: " << endl;
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				result_sum[i][j] = arr1[i][j] - arr2[i][j];
				cout << setw(4) << result_sum[i][j];
			}
			cout << endl;
		}

		//--�������� �������.
		for (int i = 0; i < row1; i++)
		{
			delete[] result_sum[i];
		}
		delete[] result_sum;

	}
	else
	{
		cout << "��������� �� ��������, ������� ����� ������ �����������!!";
	}
	cout << endl;

	//---------------------------------    ���������    ----------------------------------------------------

	cout << endl << endl << "��������� ������: " << endl << endl;

	if (col1 == row2)
	{
		//--�������� �������.
		int** result = new int* [row1];
		for (int i = 0; i < row1; i++)
		{
			result[i] = new int[col2];
		}

		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				result[i][j] = 0;
			}
		}
		//--���������� ���. � ����� ���.

		cout << endl << "�������������� �������: " << endl;
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				//--

				for (int k = 0; k < row2; k++)
				{
					result[i][j] += arr1[i][k] * arr2[k][j];
				}
			
				//--
				cout << setw(4) << result[i][j];
			}
			cout << endl;
		}

		//--�������� �������.
		for (int i = 0; i < row1; i++)
		{
			delete[] result[i];
		}
		delete[] result;

	}
	else
	{
		cout << "��������� �� ��������, ������� �� ������������!!";
	}
	cout << endl;

	//-----�������� ��������---------------------------------------------------

	for (int i = 0; i < row1; i++)
	{
		delete[] arr1[i];    
	}
	delete[] arr1;

	for (int i = 0; i < row2; i++)
	{
		delete[] arr2[i];
	}
	delete[] arr2;

	system("pause");
	return 0;
}
