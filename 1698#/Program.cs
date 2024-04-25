using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1698_
{
    internal class Program
    {
        static int n, answer;
        static int[] a = new int[2000];
        static int[] b = new int[2000];

        static bool Check(int k)
        {
            b[k] = 0;

            for (int i = 0; i <= k; ++i)
            {
                b[k] += a[i] * a[k - i];
            }

            if (k != 0) b[k] += b[k - 1] / 10;

            return b[k] % 10 == a[k];
        }

        static void Dfs(int k)
        {
            if (k >= n) return;

            for (int i = 9; i >= 0; --i)
            {
                a[k] = i;
                if (Check(k))
                {
                    if (a[k] != 0) answer++;
                    Dfs(k + 1);
                }
            }
        }

        static void Main(string[] args)
        {
            n = int.Parse(Console.ReadLine());
            Dfs(0);
            Console.WriteLine(answer);
            Console.ReadLine();
        }
    }
}
