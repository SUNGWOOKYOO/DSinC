// [Chap1]  foundation ; search algorithm, time complexity analysis, big oh concept(upper bound) 

//simple 한 Linaer search algorithm
#if 0
#include <stdio.h>

int LSearch(int ar[], int len, int target)
{
	int i;
	for (i = 0; i<len; i++)
	{
		if (ar[i] == target)
			return i;    // 찾은 대상의 인덱스 값 반환
	}
	return -1;    // 찾지 못했음을 의미하는 값 반환
}

int main(void)
{
	int arr[] = { 3, 5, 2, 4, 9 };
	int idx;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4); //4를 찾아라! -> index 3번에 있다 
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7); //7을 찾아라! 
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return 0;
}
#endif 

//simple 한 Binary search algorithm 
#if 0
#include <stdio.h>
// 기본가정 : ar[]는 low ~ high order순으로 이미 sorted 되어있다. 
int BSearch(int ar[], int len, int target)
{
	int first = 0;   // 탐색 대상의 시작 인덱스 값
	int last = len - 1;   // 탐색 대상의 마지막 인덱스 값
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;   // 탐색 대상의 중앙을 찾는다. 

		if (target == ar[mid])   // 중앙에 저장된 것이 타겟이라면
		{
			return mid;
		}
		else    // 타겟이 아니라면 
		{
			if (target<ar[mid])
				last = mid - 1;   // 뒷부분을 탐색 대상에서 제외
			else
				first = mid + 1;   // 앞부분을 탐색 대상에서 제외
		}
	}
	return -1;   // 찾지 못했을 때 반환되는 값 -1
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7); // 7값은 index = 3에 있다. 
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return 0;
}
#endif 

//Binary search worst case에 대해서 연산수를 print 해보았다
#if 0
#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;
	int opCount = 0;   // 비교연산의 횟수를 기록

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
		opCount += 1;   // 비교연산의 횟수 1 증가
	}
	printf("비교연산 횟수: %d \n", opCount);  // 탐색 실패 시 연산횟수 출력
	return -1;
}

int main(void)
{
	int arr1[500] = { 0, };    // 모든 요소 0으로 초기화
	int arr2[5000] = { 0, };    // 모든 요소 0으로 초기화
	int arr3[50000] = { 0, };    // 모든 요소 0으로 초기화
	int idx;

	// 저장되지 않은 정수 1을 찾으라고 명령
	idx = BSearch(arr1, sizeof(arr1) / sizeof(int), 1);
	if (idx == -1)
		printf("탐색 실패 \n\n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	// 저장되지 않은 정수 2를 찾으라고 명령
	idx = BSearch(arr2, sizeof(arr2) / sizeof(int), 2);
	if (idx == -1)
		printf("탐색 실패 \n\n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	// 저장되지 않은 정수 3을 찾으라고 명령
	idx = BSearch(arr3, sizeof(arr3) / sizeof(int), 3);
	if (idx == -1)
		printf("탐색 실패 \n\n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return 0;
}
#endif


// [Chap 2] ; recursive algorithm 에 대한 이해와 구현 

//recursive 함수; 복사되어 실행되는데 탈출 조건이 필요하다! if(num<=0) return; 
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

//ex1; n! 구현 
#if 0
#include <stdio.h>

int Factorial(int n)
{
	if (n == 0)
		return 1; //마지막 조건 bound condition 
	else
		return n * Factorial(n - 1); // recurrence ; 점화식 
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

//ex2; fibonacci sequence 구현 
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
	for (i = 1; i<15; i++)  // 1~ 14번째 항까지 구해봄 
		printf("%d ", Fibo(i));

	return 0;
}
#endif

//fibonacci 구현에서 recursive call의 호출순서 분석 
#if 0
#include <stdio.h>

int Fibo(int n)
{
	printf("func call param %d  \n", n); //n 번째 재귀함수 호출시 print 됨 

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

//ex3; Chap1에서의 Binary search를 recursive 로 구현  
#if 0
#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;    // -1의 반환은 탐색의 실패를 의미
	mid = (first + last) / 2;    // 탐색대상의 중앙을 찾는다.

	if (ar[mid] == target)
		return mid;    // 검색된 타겟의 인덱스 값 반환
	else if (target < ar[mid])
		return BSearchRecur(ar, first, mid - 1, target);
	else
		return BSearchRecur(ar, mid + 1, last, target);
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7); // 7을 찾아라! (0 1 2 )3번째! 
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 2); // 2를 찾아라! 없는수 ; first> last가 되어 -1 반환 
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return 0;
}
#endif


//ex4 HoanoiTowerMove
#if 0
#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to) // num개의 원반을 from위치로부터 by를 거쳐 to위치로 이동 
{
	if (num == 1)    // 이동할 원반의 수가 1개라면
	{
		printf("원반1을 %c에서 %c로 이동 \n", from, to);
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);    // 3단계 중 1단계
		printf("원반%d을(를) %c에서 %c로 이동 \n", num, from, to);  // 3단계 중 2단계
		HanoiTowerMove(num - 1, by, from, to);    // 3단계 중 3단계
	}
}


int main(void)
{
	// 막대A의 원반 6개를 막대B를 경유하여 막대C로 옮기기
	HanoiTowerMove(6, 'A', 'B', 'C');
	return 0;
}
#endif