using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1523_
{
    internal class Program
    {
        static int[,] A = new int[11, 20001];
        static int[] input = new int[20001];
        static int n, k;
        const int mod = 1000000000;

        static int Sum(int length, int i)
        {
            int sum = 0;
            for (; i > 0; i -= i & -i)
            {
                sum = (sum + A[length, i]) % mod;
            }
            return sum;
        }

        static void Add(int length, int i, int prev)
        {
            for (; i <= n; i += i & -i)
            {
                A[length, i] = (A[length, i] + prev) % mod;
            }
        }

        static void Main(string[] args)
        {
            string[] inputLine = Console.ReadLine().Split(' ');
            n = int.Parse(inputLine[0]);
            k = int.Parse(inputLine[1]);

            input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

            for (int i = n - 1; i >= 0; i--)
            {
                int x = input[i];
                Add(1, x, 1);
                for (int l = 1; l < k; l++)
                {
                    Add(l + 1, x, Sum(l, x - 1));
                }
            }

            Console.WriteLine(Sum(k, n));
        }
    }
}
