/* 
 * !! 일반적으로 소스 파일의 가장 윗부분에는 소스 파일에 대한 간략한 정보를 제공하는 것이 관례입니다.
 * 프로젝트 명칭 : {프로젝트 혹은 어플리케이션 명칭을 기록}
 * 파일 명칭 : {현재 파일의 명칭, 일반적으로 최초에 작성한 파일 명칭을 사용하나 복사/수정하는 과정에서 수정될 수 있으니 단순히 최초 명칭을 기록으로 남기는 용도로 생각하면 됨}
 * 작성자 : {코드의 작성자 성명 혹은 닉네임}
 * 작성 일자 : {최초 작성일자를 적어두는 것도 추후 기억을 되살리거나, 코드의 변화 이력을 추정하는데 도움이 됩니다}
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
 * !! 구조체 선언에서 job 이라는 단어를 사용했는데, 무슨 의미인지 어떤 데이터를 포함하는 것인지 의미 파악이 매우 힘듭니다.
 */ 
struct job{
    int start;
    int end;
};

/*
 * !! jobs는 그렇다 쳐도, jobV는 대체 무슨 의도일까? 전혀 가늠이 가지 않는 생뚱맞는 long 타입 포인터 변수를 선언했는데,
 *    어떤 의도인지 변수 명칭으로 추정할 수 있도록 직관적인 명칭을 사용하거나, 아니면 로직을 주석으로 작성해두는 게 좋지 않을까?
 */
struct job *jobs;
long *jobV;

/*
 * !! 언듯 함수 명칭을 보아서는 quick 정렬을 구현한 함수 같은데 정말 맞는지 의문의 듭니다.
 *    게다가 재귀 함수를 사용했는데, recursive 함수는 특별한 경우 아니면 권장되지 않습니다.
 */
void qsort(int start, int end)
{
	long p=jobV[(start + end)>>1];
	int s=start;
	int e=end;

	while(s<=e)
	{
		while(jobV[s] < p && s <= e) s++;
		while(jobV[e] > p && s <= e) e--;

		if(s<=e)
		{
			long tmp = jobV[s];
			jobV[s] = jobV[e];
			jobV[e] = tmp;
			s++; e--;
		}
	}

	if(start<e) qsort(start,e);
	if(s<end) qsort(s, end);
}

/* !! C 언어에서 메인 함수의 반환 값을 int 타입으로 선언한 경우에는
 * main() 함수의 종료 시점에서 return 0; 코드를 추가하는 것이 바람직 합니다.
 * return 0; 코드가 없으면 컴파일러가 보이지 않는 return 0 코드를 삽입해 줍니다.
 * (작성해도 안해도 상관 없는 코드라도 간혹 부작용이나, 어이 없는 버그를 유발할 수 있으므로, 내가 무얼 생략했는가는 명확히 알고 있어야 합니다.)
 */
int main(void)
{
  /* !! 정수형 변수 T를 선언했는데, 최근 거의 프로그래밍 언어들의 변수 명칭 지정 규범(variable naming rule)은 
   * 소문자로 변수 명칭을 시작하는 겁니다. 상수(constant) 명칭은 대문자로 시작하는 것이 일반적입니다.
   * 만일 프로그램이 길어지고, 긴 소스를 스크롤하면서 조회하는 와중에 T라는 명칭을 접하면, 다수의 개발자들은 T를 상수로 착각하기 쉽습니다.
   *
   * 그리고, T라는 변수 명칭은 지나치게 모호합니다. 아래의 코드들에서 빈번하게 사용되는 변수인데 그 의미를 추정(추론)하기가 어렵습니다.
   * 가급적 변수 명칭을 선언할 때, 간단하더라고 최소한의 의미가 통하는 명칭을 사용하는 것이 적절합니다.
   * (프로그래머 자신이 시간이 지난 후에 자신의 코드와 논리를 다시 기억해 내는데도 유리할 뿐더러, 다른 팀원을 위한 배려입니다.)
   */
  int T, end, count=1;
  
  /* !! scanf에서 수치 값을 입력 받도록 했는데, 과연 프로그램이 실행되고 아무 메시지도 없이 커서만 깜박인다면, 사용자가 당황하지 않을까요?
   * "숫자를 입력해주세요. Please input number (for array size) : " 이런 문구를 printf로 먼저 출력해주는 건 어떨까요?
   * !! 아울러 만일 사용자가 숫자가 아니라 'a' 같은 문자를 입력하면 어떤 문제가 발생할까요?
   */
  scanf("%d", &T);
  jobs = (struct job *)malloc(sizeof(struct job) * T);
  
  /* !! jobV 변수는 long 타입의 포인터이고, jobs는 job 구조체 배열의 시작 위치인데, 
   * jobs 주소를 주소를 jobV에 할당하는지 아래의 코드를 보면 직관적으로 이해할 수 없습니다.
   *
   * 평범한 개발자는 컴퓨터가 이해하는 코드를 작성하지만, 훌륭한 개발자는 사람이 이해하는 코드를 작성합니다.
   * 타인이 코드를 이해 못한다고 무시하거나, 어차피 잘 동작하는 코드니까 상관 없다고 넘어갈수도 있지만,
   * 타인을 불편하게 만드는 개발자는 아무리 유능해도 개발자 집단에서 환영 받기 어렵습니다. 
   */
  jobV = (long *)jobs;

  /* !! 앞서 작성한 scanf에서도 무엇을 입력 받는지 알 수 없었지만, 아래의 루프에서도 마찬가지 입니다.
   * 숫자 두 개를 입력하라는 가이드 문구를 출력해주는 건 어떨런지?
   */
  for( int i=0; i<T; i++ )
     scanf("%d %d", &jobs[i].start, &jobs[i].end);

	qsort(0, T-1);
  
  /* !! 간단한 문제이지만 대입문(=) 앞뒤의 수식 사이에 공백을 쓰기도 하고 안쓰기도 하는데,
   *  for 루프 내의 변수 할당 (int i=0) 같은 관습적으로 붙여쓰는 경우 외에는 모두 띄어쓰기 하는 것이 타인을 위한 배려 입니다.
   */
	end=jobs[0].end;
  for( int i=1; i<T; i++ ) 
  {
      if(end < jobs[i].start) 
      {
          end = jobs[i].end;
          count++;
      }
  }

  /* !! 최종적으로 출력되는 count라는 변수가 출력하는 값이 무얼 의미하는지 직관적으로 이해하기 어렵습니다.
   * 적어도 아래와 같이 구현하는게 최소한의 예의라고나 할까?
   * printf("final result : %d", count);
   */
  printf("%d", count);
}
