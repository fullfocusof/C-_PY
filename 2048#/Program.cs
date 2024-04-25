using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.XPath;

namespace _2048_
{
    internal class Program
    {
        static int[] result = new int[13];
        static int[] m = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        static void PrintResult()
        {
            for (int i = 0; i < 13; i++)
            {
                Console.WriteLine($"{i}: {result[i]}");
            }
        }

        static bool IsLeap(int n)
        {
            return (n % 4 == 0 && (n % 400 == 0 || n % 100 != 0));
        }

        static void AddToResult(int firstDay, int y)
        {
            m[1] = IsLeap(y) ? 29 : 28;
            int n = 0;
            for (int i = 0; i < 12; i++)
            {
                if (firstDay == 6)
                    n++;
                firstDay = (firstDay + m[i]) % 7;
            }
            result[n]++;
        }

        static void Main(string[] args)
        {
            string[] inputSplit = Console.ReadLine().Split();
            int y1, y2;
            y1 = int.Parse(inputSplit[0]);
            y2 = int.Parse(inputSplit[1]);

            int firstDay = 1;
            int y = 1918 + 400 * ((y1 - 1 - 1918) / 400);
            for (++y; y < y1; y++)
            {
                firstDay = (firstDay + 365 + (IsLeap(y - 1) ? 1 : 0)) % 7;
            }

            if (y1 + 400 < y2)
            {
                for (y = y1; y < y1 + 400; y++)
                {
                    firstDay = (firstDay + 365 + (IsLeap(y - 1) ? 1 : 0)) % 7;
                    AddToResult(firstDay, y);
                }
                y = y1 + 400;
            }
            else y = y1;

            for (int i = 0; i < 13; i++)
            {
                result[i] += result[i] * ((y2 - 1 - y) / 400);
            }

            y += 400 * ((y2 - 1 - y) / 400);

            for (; y <= y2; y++)
            {
                firstDay = (firstDay + 365 + (IsLeap(y - 1) ? 1 : 0)) % 7;
                AddToResult(firstDay, y);
            }

            PrintResult();
        }
    }
}
