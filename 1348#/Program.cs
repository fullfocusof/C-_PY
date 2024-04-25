using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1348_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            System.Globalization.CultureInfo.DefaultThreadCurrentCulture = System.Globalization.CultureInfo.InvariantCulture;

            double aX, aY, bX, bY, kX, kY, ropeLength;
            string[] inputCords = Console.ReadLine().Split(' ');
            aX = double.Parse(inputCords[0]);
            aY = double.Parse(inputCords[1]);
            bX = double.Parse(inputCords[2]);
            bY = double.Parse(inputCords[3]);

            string[] inputCordsLength = Console.ReadLine().Split(' ');
            kX = double.Parse(inputCordsLength[0]);
            kY = double.Parse(inputCordsLength[1]);
            ropeLength = double.Parse(inputCordsLength[2]);

            double akLength = Math.Sqrt(Math.Pow(aX - kX, 2) + Math.Pow(aY - kY, 2));
            double bkLength = Math.Sqrt(Math.Pow(bX - kX, 2) + Math.Pow(bY - kY, 2));

            double second = Math.Max(akLength, bkLength);
            if (second > ropeLength) second -= ropeLength;
            else second = 0;

            double first = Math.Min(akLength, bkLength);
            if (first <= ropeLength) first = 0;
            else if (Math.Abs(akLength - bkLength) < 0.001)
            {
                aX = (aX + bX) / 2;
                aY = (aY + bY) / 2;
                first = Math.Sqrt(Math.Pow(aX - kX, 2) + Math.Pow(aY - kY, 2));

                if (first <= ropeLength) first = 0;
                else first -= ropeLength;
            }
            else
            {
                while (Math.Abs(akLength - bkLength) > 0.001)
                {
                    if (akLength < bkLength)
                    {
                        bX = (aX + bX) / 2;
                        bY = (aY + bY) / 2;
                        bkLength = Math.Sqrt(Math.Pow(bX - kX, 2) + Math.Pow(bY - kY, 2));
                    }
                    else
                    {
                        aX = (aX + bX) / 2;
                        aY = (aY + bY) / 2;
                        akLength = Math.Sqrt(Math.Pow(aX - kX, 2) + Math.Pow(aY - kY, 2));
                    }
                }

                first = Math.Min(akLength, bkLength);
                if (first <= ropeLength) first = 0;
                else first -= ropeLength;
            }

            Console.WriteLine(string.Format("{0:F2}", first));
            Console.WriteLine(string.Format("{0:F2}", second));
        }
    }
}
