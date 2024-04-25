using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1838_
{
    internal class Program
    {
        static int[] arr = new int[100000];

        static int Clamp(int input, int bound)
        {
            return Math.Min(bound, Math.Max(input, 0));
        }

        static void Main(string[] args)
        {
            string[] inputSize = Console.ReadLine().Split(' ');
            int l = int.Parse(inputSize[0]), n = int.Parse(inputSize[1]), answer = 0;
            string[] inputSplit = Console.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                arr[i] = int.Parse(inputSplit[i]);
            }

            answer = arr[0] + l - arr[n - 1];

            for (int i = 0; i < n - 1; i++)
            {
                int width = arr[i + 1] - arr[i];
                int L = Math.Max(Clamp(2 * arr[i + 1] - l - arr[i], width), Clamp(arr[0] * 2 - arr[i], width)); // L = I1 + I2 = (p1 = l1 < r1 <= p2) + (p1 = l2 < r2 <= p2) против часовой
                int R = Math.Max(Clamp(arr[i + 1] - 2 * arr[i], width), Clamp(arr[i + 1] + l - 2 * arr[n - 1], width)); // R = I3 + I4 = (p1 <= l3 < r3 = p2) + (p1 <= l4 < r4 = p2) по часовой
                answer += Math.Min(width, L + R);
            }

            Console.WriteLine(answer);
        }
    }
}
