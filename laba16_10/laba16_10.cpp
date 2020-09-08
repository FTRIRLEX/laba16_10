//#include <iostream>
//#include <locale>
//#include <iomanip>
//#include <math.h>
//#include <iostream>
//#include <locale>
//#include <iomanip>
//#include <math.h>
//using namespace std;
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//
//	int const n = 3;
//	int m[n][n];
//
//	cout << "Введите матрицу: \n";
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << "Введите элемент[" << i + 1 << "][" << j + 1 << "]: ";
//			cin >> m[i][j];
//		}
//	}
//
//	cout << "\n";
//
//	cout << "Исходная матрица: \n";
//	for (int i = 0; i < n; i++)
//	{
//		cout << endl;
//		cout << "\t";
//		for (int j = 0; j < n; j++)
//		{
//			cout << setw(3) << setiosflags(ios::left) << m[i][j] << " ";
//		}
//	}
//
//	cout << "\n\n";
//
//	/*1)Максимальное, которое встречается более одного раза*/
//
//	int t = 0, t1 = 0, r = 0, t2 = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			t2 = m[i][j];
//			m[i][j] = 0;
//
//			for (int k = 0; k < n; k++)
//			{
//				for (int f = 0; f < n; f++)
//				{
//					if (t2 == m[k][f])
//					{
//						t = m[k][f];
//					}
//					else
//						r++;
//				}
//
//				if (t1 > t)
//					t = t1;
//			}
//
//			t1 = t;
//			m[i][j] = t2;
//
//		}
//	}
//
//	double kof;
//	kof = pow((double)n, 4);
//
//	if (r == kof)
//		cout << "Однинаковых элементов нет!";
//	else
//		cout << "Максимальное из встречающихся более 1 раза: " << t;
//
//	cout << "\n\n";
//
//
//
//}




#include <stdio.h>
#include <string.h>

char s[255], t[255], c1[255], c2[255];
bool c1b = true, c2b = false;
int pn = 0, l = 0;

void asort(bool end)
{
	if ((unsigned char)c1[0] > (unsigned char)c2[0])
	{
		strcat_s(t, c2);
		strcat_s(t, " ");
		pn++;
		if (end)
			strcat_s(t, c1);
	}
	else
	{
		strcat_s(t, c1);
		strcat_s(t, " ");
		if (end)
			strcat_s(t, c2);
		else
			memcpy(c1, c2, 255);
	}
	if (end)
		memset(c1, (char)0, sizeof(c1));
	memset(c2, (char)0, sizeof(c2));
	if (end)
	{
		c1b = true;
		c2b = false;
	}
	else c2b = true;
}

int main()
{
	printf("Enter string:");
	gets_s(s);
	do
	{
		l = strlen(s);
		pn = 0;
		for (int n = 0; n < l; n++)
		{
			if (s[n] != ' ' && c1b)
			{
				strncat_s(c1, &s[n], 1); 
			}
			else if (s[n] == ' ' && s[n + 1] != ' ' && c1[0] != 0 && c1b)
			{
				c1b = false;
				c2b = true;
				continue;
			}
			else if (s[n] != ' ' && c2b)
			{
				strncat_s(c2, &s[n], 1);
			}
			else if (s[n] == ' ' && s[n + 1] != ' ' && c2b)
			{
				c2b = false;
			}
			if ((!c1b && !c2b) || (n == l - 1))
			{
				if (n == l - 1)
					asort(1);
				else asort(0);
			}
		}
		memcpy(s, t, 255);
		memset(t, (char)0, sizeof(t));
	} while (pn != 0);
	printf("After sort:%s", s);
	return 0;
}