#include <stdio.h> //표준입출력 헤더 불러오기
#include <stdlib.h> //표준라이브러리 헤더 불러오기
#define MAX_SIZE 10 //배열 사이즈 미리 상수로 설정
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t)) // 값 교환 매크로 함수

int list[MAX_SIZE]; // 정수형 배열 list 선언, 사이즈는 10
int n; // 정수형 변수 n 선언 -> 배열 사이즈를 담아서 배열을 순회하기 위한 목적

// 선택 정렬 함수 정의
// 선택정렬이란? 가장 작은 수를 찾아서 앞쪽부터 정렬하는 알고리즘
void selection_sort(int list[], int n) {

	// i, j 배열 인덱스
	// least 배열 중 가장 작은 값의 인덱스
	// temp 임시값
	int i, j, least, temp;

	// i는 0부터 n-1(마지막 인덱스)까지 1씩 증가하며 배열의 값을 확인
	// n=10, n-1=9 -> 즉, i는 0~8까지

	// Q. 왜 i<n-1이고 j<n일까? 
	// => j값은 i+1이기 때문에, 만약 i=8이라면 j=9(마지막 인덱스)가 되어 뒤에 2자리만 교환하면 되기 때문에
	for (i = 0; i < n - 1; i++) {

		// 최솟값을 찾기위해 우선 i=0부터 least에 넣는다.
		least = i;
		
		// j는 i값의 다음부터 시작하여 n까지 증가하며 반복 -> 즉, j는 1~9까지
		for (j = i + 1; j < n; j++) {
			// 배열 list의 j번째의 실제 값과 least번째의 실제 값을 비교할 때, 
			// least의 값이 더 크다면, 인덱스를 교환한다 -> least가 최솟값을 가르키는 인덱스가 되도록
			if (list[j] < list[least]) least = j;
		}

		// 배열의 마지막까지 확인이 끝난 후 -> 최솟값의 인덱스가 결정된 후
		// 배열의 첫번째값부터(i번째) 최솟값과 교환한다.
		SWAP(list[i], list[least], temp);

		printf("%d번째 정렬 배열 : ", i);
		for (j = 0; j < n; j++) {
			printf("%d ", list[j]);
		}

		printf("\n\n");
	}
}

int main(void) {

	int i;

	// n에 MAX_SIZE의 값 10(배열 사이즈)을 넣는다.
	n = MAX_SIZE;

	// 난수 생성 초기화 함수 
	// -> 실행 할 때마다 매번 다른 난수를 생성하기 위해 현재시간(time(NULL))값으로 초기화한다.
	srand(time(NULL));
	
	// 배열 리스트에 rand()함수를 사용하여 난수 값을 넣는다.
	for (i = 0; i < n; i++) {
		// 0 ~ 99 사이의 난수 생성
		list[i] = rand() % 100;
	}

	// 선택 정렬 함수 호출
	selection_sort(list, n);

	// 정렬 결과 배열 출력
	printf("최종 정렬 배열 : ");
	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}