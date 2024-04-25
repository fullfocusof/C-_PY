using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1138_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] inputSplit = input.Split(' ');
            int lastSalary = int.Parse(inputSplit[0]), firstSalary = int.Parse(inputSplit[1]), maxCnt = 0;

            if (lastSalary == firstSalary)
            {
                maxCnt = 1;
                Console.WriteLine(maxCnt);
            }
            else
            {
                int[] cnts = new int[lastSalary + 1];
                cnts[firstSalary] = 1;

                for (int i = firstSalary; i <= lastSalary; i++)
                {
                    if (cnts[i] > 0)
                    {
                        int k;
                        if (lastSalary > 2 * i)
                        {
                            k = 2 * i;
                        }
                        else
                        {
                            k = lastSalary;
                        }

                        for (int j = i + 1; j <= k; j++)
                        {
                            if ((cnts[j] < cnts[i] + 1) && (j * 100 % i == 0))
                            {
                                cnts[j] = cnts[i] + 1;
                            }
                        }
                    }

                    if (cnts[i] > maxCnt)
                    {
                        maxCnt = cnts[i];
                    }
                }

                Console.WriteLine(maxCnt);
            }
        }
    }
}
