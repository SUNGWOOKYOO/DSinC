// [Chap1]  foundation ; search algorithm, time complexity analysis, big oh concept(upper bound) 

//simple �� Linaer search algorithm
#if 0
#include <stdio.h>

int LSearch(int ar[], int len, int target)
{
	int i;
	for (i = 0; i<len; i++)
	{
		if (ar[i] == target)
			return i;    // ã�� ����� �ε��� �� ��ȯ
	}
	return -1;    // ã�� �������� �ǹ��ϴ� �� ��ȯ
}

int main(void)
{
	int arr[] = { 3, 5, 2, 4, 9 };
	int idx;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4); //4�� ã�ƶ�! -> index 3���� �ִ� 
	if (idx == -1)
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7); //7�� ã�ƶ�! 
	if (idx == -1)
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	return 0;
}
#endif 

//simple �� Binary search algorithm 
#if 0
#include <stdio.h>
// �⺻���� : ar[]�� low ~ high order������ �̹� sorted �Ǿ��ִ�. 
int BSearch(int ar[], int len, int target)
{
	int first = 0;   // Ž�� ����� ���� �ε��� ��
	int last = len - 1;   // Ž�� ����� ������ �ε��� ��
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;   // Ž�� ����� �߾��� ã�´�. 

		if (target == ar[mid])   // �߾ӿ� ����� ���� Ÿ���̶��
		{
			return mid;
		}
		else    // Ÿ���� �ƴ϶�� 
		{
			if (target<ar[mid])
				last = mid - 1;   // �޺κ��� Ž�� ��󿡼� ����
			else
				first = mid + 1;   // �պκ��� Ž�� ��󿡼� ����
		}
	}
	return -1;   // ã�� ������ �� ��ȯ�Ǵ� �� -1
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7); // 7���� index = 3�� �ִ�. 
	if (idx == -1)
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	return 0;
}
#endif 

//Binary search worst case�� ���ؼ� ������� print �غ��Ҵ�
#if 0
#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;
	int opCount = 0;   // �񱳿����� Ƚ���� ���

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (target == ar[mid])
		{
			return mid;
		}
		else
		{
			if (target<ar[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
		opCount += 1;   // �񱳿����� Ƚ�� 1 ����
	}
	printf("�񱳿��� Ƚ��: %d \n", opCount);  // Ž�� ���� �� ����Ƚ�� ���
	return -1;
}

int main(void)
{
	int arr1[500] = { 0, };    // ��� ��� 0���� �ʱ�ȭ
	int arr2[5000] = { 0, };    // ��� ��� 0���� �ʱ�ȭ
	int arr3[50000] = { 0, };    // ��� ��� 0���� �ʱ�ȭ
	int idx;

	// ������� ���� ���� 1�� ã����� ���
	idx = BSearch(arr1, sizeof(arr1) / sizeof(int), 1);
	if (idx == -1)
		printf("Ž�� ���� \n\n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	// ������� ���� ���� 2�� ã����� ���
	idx = BSearch(arr2, sizeof(arr2) / sizeof(int), 2);
	if (idx == -1)
		printf("Ž�� ���� \n\n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	// ������� ���� ���� 3�� ã����� ���
	idx = BSearch(arr3, sizeof(arr3) / sizeof(int), 3);
	if (idx == -1)
		printf("Ž�� ���� \n\n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	return 0;
}
#endif


// [Chap 2] ; recursive algorithm �� ���� ���ؿ� ���� 

//recursive �Լ�; ����Ǿ� ����Ǵµ� Ż�� ������ �ʿ��ϴ�! if(num<=0) return; 
#if 0
#include <stdio.h>

void Recursive(int num)
{
	if (num <= 0)
		return;

	printf("Recursive call! %d \n", num);
	Recursive(num - 1);
}

int main(void)
{
	Recursive(3);
	return 0;
}
#endif

//ex1; n! ���� 
#if 0
#include <stdio.h>

int Factorial(int n)
{
	if (n == 0)
		return 1; //������ ���� bound condition 
	else
		return n * Factorial(n - 1); // recurrence ; ��ȭ�� 
}

int main(void)
{
	printf("1! = %d \n", Factorial(1));
	printf("2! = %d \n", Factorial(2));
	printf("3! = %d \n", Factorial(3));
	printf("4! = %d \n", Factorial(4));
	printf("9! = %d \n", Factorial(9));
	return 0;
}
#endif

//ex2; fibonacci sequence ���� 
#if 0
#include <stdio.h>

int Fibo(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

int main(void)
{
	int i;
	for (i = 1; i<15; i++)  // 1~ 14��° �ױ��� ���غ� 
		printf("%d ", Fibo(i));

	return 0;
}
#endif

//fibonacci �������� recursive call�� ȣ����� �м� 
#if 0
#include <stdio.h>

int Fibo(int n)
{
	printf("func call param %d  \n", n); //n ��° ����Լ� ȣ��� print �� 

	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

int main(void)
{
	Fibo(7);
	return 0;
}
#endif

//ex3; Chap1������ Binary search�� recursive �� ����  
#if 0
#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;    // -1�� ��ȯ�� Ž���� ���и� �ǹ�
	mid = (first + last) / 2;    // Ž������� �߾��� ã�´�.

	if (ar[mid] == target)
		return mid;    // �˻��� Ÿ���� �ε��� �� ��ȯ
	else if (target < ar[mid])
		return BSearchRecur(ar, first, mid - 1, target);
	else
		return BSearchRecur(ar, mid + 1, last, target);
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7); // 7�� ã�ƶ�! (0 1 2 )3��°! 
	if (idx == -1)
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 2); // 2�� ã�ƶ�! ���¼� ; first> last�� �Ǿ� -1 ��ȯ 
	if (idx == -1)
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	return 0;
}
#endif


//ex4 HoanoiTowerMove
#if 0
#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to) // num���� ������ from��ġ�κ��� by�� ���� to��ġ�� �̵� 
{
	if (num == 1)    // �̵��� ������ ���� 1�����
	{
		printf("����1�� %c���� %c�� �̵� \n", from, to);
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);    // 3�ܰ� �� 1�ܰ�
		printf("����%d��(��) %c���� %c�� �̵� \n", num, from, to);  // 3�ܰ� �� 2�ܰ�
		HanoiTowerMove(num - 1, by, from, to);    // 3�ܰ� �� 3�ܰ�
	}
}


int main(void)
{
	// ����A�� ���� 6���� ����B�� �����Ͽ� ����C�� �ű��
	HanoiTowerMove(6, 'A', 'B', 'C');
	return 0;
}
#endif