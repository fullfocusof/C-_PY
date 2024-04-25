using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1033_
{
    internal class Program
    {
        public static char[,] maze = new char[35, 35];
        public static bool[,] mazeCheck = new bool[35, 35];

        public static int S1 = 9;
        public static int cnt;

        public static void CheckMaze(int size, int x, int y, char[,] maze, bool[,] mazeCheck)
        {
            mazeCheck[x, y] = true;

            if (x + 1 <= size && maze[x + 1, y] != '#' && !mazeCheck[x + 1, y])
                CheckMaze(size, x + 1, y, maze, mazeCheck);

            if (x - 1 >= 1 && maze[x - 1, y] != '#' && !mazeCheck[x - 1, y])
                CheckMaze(size, x - 1, y, maze, mazeCheck);

            if (y + 1 <= size && maze[x, y + 1] != '#' && !mazeCheck[x, y + 1])
                CheckMaze(size, x, y + 1, maze, mazeCheck);

            if (y - 1 >= 1 && maze[x, y - 1] != '#' && !mazeCheck[x, y - 1])
                CheckMaze(size, x, y - 1, maze, mazeCheck);

            return;
        }


        static void Main(string[] args)
        {
            int size = int.Parse(Console.ReadLine());

            for (int i = 1; i <= size; i++)
            {
                string row = Console.ReadLine();
                for (int j = 1; j <= size; j++)
                {
                    maze[i, j] = row[j - 1];
                }
            }

            CheckMaze(size, 1, 1, maze, mazeCheck);
            CheckMaze(size, size, size, maze, mazeCheck);

            for (int i = 1; i <= size; i++)
            {
                for (int j = 1; j <= size; j++)
                {
                    if (mazeCheck[i, j])
                    {
                        if (i + 1 > size || !mazeCheck[i + 1, j]) cnt++;
                        if (i - 1 < 1 || !mazeCheck[i - 1, j]) cnt++;
                        if (j + 1 > size || !mazeCheck[i, j + 1]) cnt++;
                        if (j - 1 < 1 || !mazeCheck[i, j - 1]) cnt++;
                    }
                }
            }

            cnt -= 4;

            Console.WriteLine(cnt * S1);
        }
    }
}
