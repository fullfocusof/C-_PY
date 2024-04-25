using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1593_
{
    internal class Program
    {
        static bool IsPerfectSquareRoot(ulong num)
        {
            ulong temp = (ulong)Math.Floor(Math.Sqrt(num));
            if (temp * temp == num)
                return true;
            else
                return false;
        }

        static bool IsSumOfFourSquares(ulong num)
        {
            ulong temp = num;
            while (temp % 4 == 0)
            {
                temp /= 4;
            }
            if (temp % 8 == 7)
                return true;
            else
                return false;
        }

        static void Main(string[] args)
        {
            ulong input;
            input = ulong.Parse(Console.ReadLine());

            List<bool> result = new List<bool>();

            for (int i = 0; i < 5; i++)
            {
                result.Add(false);
            }

            for (ulong i = 1; i * i <= input / 2; i++)
            {
                if (IsPerfectSquareRoot(input - i * i))
                {
                    result[2] = true;
                }
            }

            if (IsPerfectSquareRoot(input))
            {
                result[1] = true;
            }
            else if (IsSumOfFourSquares(input))
            {
                result[4] = true;
            }
            else if (!result[2])
            {
                result[3] = true;
            }

            for (int i = 0; i < result.Count; i++)
            {
                if (result[i])
                {
                    Console.WriteLine(i);
                    break;
                }
            }
        }
    }
}
