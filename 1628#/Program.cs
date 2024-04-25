using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1628_
{
    internal class Program
    {
        public static int CompareX((int, int) a, (int, int) b)
        {
            if (a.Item1 != b.Item1) return a.Item1.CompareTo(b.Item1);
            return a.Item2.CompareTo(b.Item2);
        }

        public static int CompareY((int, int) a, (int, int) b)
        {
            if (a.Item2 != b.Item2) return a.Item2.CompareTo(b.Item2);
            return a.Item1.CompareTo(b.Item1);
        }

        static void Main(string[] args)
        {
            int rows, cols, unluckyDays, result = 0;
            string[] input = Console.ReadLine().Split(' ');
            rows = int.Parse(input[0]);
            cols = int.Parse(input[1]);
            unluckyDays = int.Parse(input[2]);

            List<(int, int)> uDays = new List<(int, int)>();
            HashSet<(int, int)> reCheck = new HashSet<(int, int)>();

            for (int i = 0; i < unluckyDays; i++)
            {
                input = Console.ReadLine().Split(' ');
                int week = int.Parse(input[0]);
                int day = int.Parse(input[1]);
                uDays.Add((week, day));
            }

            for (int i = 1; i <= cols; i++)
            {
                uDays.Add((0, i));
                uDays.Add((rows + 1, i));
            }
            for (int i = 1; i <= rows; i++)
            {
                uDays.Add((i, 0));
                uDays.Add((i, cols + 1));
            }

            unluckyDays += (rows + cols) * 2;

            uDays.Sort(CompareX);
            for (int i = 0; i < unluckyDays - 1; i++)
            {
                int space = uDays[i + 1].Item2 - uDays[i].Item2;
                if (space == 2) reCheck.Add((uDays[i].Item1, uDays[i].Item2 + 1));
                else if (uDays[i].Item1 == uDays[i + 1].Item1 && space > 2) result++;
            }

            uDays.Sort(CompareY);
            for (int i = 0; i < unluckyDays - 1; i++)
            {
                int space = uDays[i + 1].Item1 - uDays[i].Item1;
                if (space == 2 && reCheck.Contains((uDays[i].Item1 + 1, uDays[i].Item2))) result++;
                else if (uDays[i].Item2 == uDays[i + 1].Item2 && space > 2) result++;
            }

            Console.WriteLine(result);
        }
    }
}
