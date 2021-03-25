using System;

namespace No_10807
{
    class No_10807
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            string[] input = Console.ReadLine().Split();
            int v = Convert.ToInt32(Console.ReadLine());

            int[] arr = new int[n];
            int count = 0;

            for (int i = 0; i < n; i++)
            {
                arr[i] = Convert.ToInt32(input[i]);
                if (arr[i] == v)
                    count++;
            }

            Console.WriteLine(count);
        }
    }
}