#include <stdio.h>

int loadData(char* filename, float data[]);
int getCount(float list[], int size, float begin, float end);
int getMaxIndex(float list[], int size);
int getMinIndex(float list[], int size);
float getSum(float list[], int size);

int main(void) {
	int persons, count1, count2, count3;
	float degree[20]; // 최대 20명의 체온 
	float min, max, sum, avg;
	int min_i, max_i;
	persons = loadData("degree.txt", degree);

	count1 = getCount(degree, persons, 0.0, 35.0);
	count2 = getCount(degree, persons, 35.0, 37.5);
	count3 = getCount(degree, persons, 37.5, 100.0);
	max_i = getMaxIndex(degree, persons);
	min_i = getMinIndex(degree, persons);
	max = degree[max_i];
	min = degree[min_i];
	sum = getSum(degree, persons);
	avg=sum/persons;
	
	printf("정상체온 : %d명, 발열의심 : %d명, 저체온의심 : %d명\n", count2, count3, count1);
	printf("최고체온 : %.1f (%d번 분)\n", max, max_i+1);
	printf("최저체온 : %.1f (%d번 분)\n", min, min_i+1);
	printf("평균체온 : %.1f\n", avg);
	
  return 0;
}

int loadData(char* filename, float data[]){
  int count = 0;
  FILE* fp = NULL;
	
	// 파일 오픈
	fp = fopen(filename, "r");
	
	// eof나올 때까지 체온 받기
	while(!feof(fp)){
	  fscanf(fp, " %f", &data[count]);
	  if(data[count] == 0)  continue;
	  count++;
	}
	
	// 파일 닫기
	fclose(fp);
	
	printf("%d명의 체온을 읽었습니다.\n", count);
	
	// count 리턴
	return count;
}

// 목록갯수만큼의 값목록 배열을 찾아 구간시작값이상~구간끝값미만인 값이 몇개인지 세서 리턴
int getCount(float list[], int size, float begin, float end){
  int count = 0;
  
  for(int i=0; i<size; i++){
    if(list[i] >= begin && list[i] < end)  count++;
  }
	
	return count;
}

// 목록갯수만큼의 값목록 배열을 에서 최솟값 리턴
int getMaxIndex(float list[], int size){
  float max = 0;
  int max_index;
  
	for(int i=0; i<size; i++){
    if(list[i] > max){
      max = list[i];
      max_index = i;
    }  
  }
  
	return max_index;
}

// 목록갯수만큼의 값목록 배열을 에서 최솟값 리턴
int getMinIndex(float list[], int size){
	float min = 100;
	int min_index;
  
	for(int i=0; i<size; i++){
    if(list[i] < min){
      min = list[i];
      min_index = i;
    }  
  }
  
	return min_index;
}

// 배열 value의 합 리턴
float getSum(float list[], int size){
  float sum = 0;
  
  for(int i=0; i<size; i++){
    sum += list[i];
  }
	
	return sum;
}
