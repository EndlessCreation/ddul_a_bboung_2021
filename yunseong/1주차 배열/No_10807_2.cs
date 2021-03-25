using System;

namespace No_10807
{
    class No_10807
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            string[] input = Console.ReadLine().Split();
            string v = Console.ReadLine();

            int count = 0;

            for(int i = 0; i < n; i++)
            {
                if (input[i] == v)
                    count++;
            }

            Console.WriteLine(count);
        }
    }
}
