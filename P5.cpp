using SplashKitSDK;
using System;
using static SplashKitSDK.SplashKit;

public
class Program
{
public
    static void Main()
    {
        double value;
        double total = 0;
        double min_value = 0;
        double max_value = 0;
        int count = 0;
        string choice;

        WriteLine("Welcome to the simple stats calculator:");

        do
        {
            Write("Enter value: ");
            value = Convert.ToDouble(ReadLine());

            count++;
            total += value;

            if (count == 1)
            {
                min_value = value;
                max_value = value;
            }
            else
            {
                if (value < min_value)
                    min_value = value;
                if (value > max_value)
                    max_value = value;
            }

            double average = total / count;

            WriteLine("Count: " + count);
            WriteLine("Total: " + total);
            WriteLine("Min: " + min_value);
            WriteLine("Max: " + max_value);
            WriteLine("Average: " + average);

            Write("Add another value? [y/n] ");
            choice = ReadLine() ?.ToLower();

        } while (choice == "y");

        WriteLine("I hope you got the information you are after!");
    }
}
