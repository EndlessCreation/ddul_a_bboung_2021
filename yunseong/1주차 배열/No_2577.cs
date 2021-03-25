using System;

namespace No_2577
{
    class No_2577
    {
        static void Main(string[] args)
        {
            int num = 1;
            int[] check = new int[10]; //0~9의 갯수를 나타내는 배열

            for(int i = 0; i < 3; i++ )
            {
                int input = Convert.ToInt32(Console.ReadLine());    //A,B,C 입력
                num *= input;                                       //A*B*C 저장
            }

            for( ; num>0; num/=10)
            {
                check[num % 10]++; //오른쪽 자리수부터 배열에 저장
            }

            for (int i = 0; i < check.Length; i++) //결과 출력
            {
                Console.WriteLine(check[i]);
            }
            

        }
    }
}
