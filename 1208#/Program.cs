using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1208_
{
    internal class Program
    {
        private static int N, maxTeams;

        private static void Solve(List<List<string>> input, Dictionary<string, bool> check, int forSwap)
        {
            List<List<string>> tempInput = new List<List<string>>(input);
            Dictionary<string, bool> tempDict = new Dictionary<string, bool>(check);
            (tempInput[0], tempInput[forSwap]) = (tempInput[forSwap], tempInput[0]);

            int maxTemp = 0;
            for (int i = 0; i < N; i++)
            {
                int cnt = 0;
                for (int j = 0; j < 3; j++)
                {
                    if (!tempDict[tempInput[i][j]]) cnt++;
                }
                if (cnt == 3)
                {
                    maxTemp++;
                    tempDict[tempInput[i][0]] = true;
                    tempDict[tempInput[i][1]] = true;
                    tempDict[tempInput[i][2]] = true;
                }
            }
            if (maxTemp > maxTeams)
            {
                maxTeams = maxTemp;
            }
        }

        static void Main(string[] args)
        {
            N = int.Parse(Console.ReadLine());
            List<List<string>> input = new List<List<string>>();
            Dictionary<string, bool> check = new Dictionary<string, bool>();
            for (int i = 0; i < N; i++)
            {
                List<string> row = new List<string>();
                string[] teamSplit = Console.ReadLine().Split();
                for (int j = 0; j < 3; j++)
                {
                    string member = teamSplit[j];
                    row.Add(member);
                    check[member] = false;
                }
                input.Add(row);
            }

            for (int i = 0; i < N; i++)
            {
                Solve(input, check, i);
            }

            Console.WriteLine(maxTeams);
        }
    }
}
