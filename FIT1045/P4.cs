using static SplashKitSDK.SplashKitSDK;
using static System.Convert;

class Program
{
    static void Main()
    {
        double value;
        double total = 0;
        double min = 0;
        double max = 0;
        int count = 0;
        string choice;

        Write("Welcome to the simple stats calculator:\n");

        do
        {
            Write("Enter value: ");
            value = ToDouble(ReadLine());

            count++;
            total += value;

            if (count == 1)
            {
                min = value;
                max = value;
            }
            else
            {
                if (value < min) min = value;
                if (value > max) max = value;
            }

            double average = total / count;

            Write("Count: " + count + "\n");
            Write("Total: " + total + "\n");
            Write("Min: " + min + "\n");
            Write("Max: " + max + "\n");
            Write("Average: " + average + "\n");

            Write("Add another value? [y/n] ");
            choice = ReadLine().ToLower();

        } while (choice == "y");

        Write("I hope you got the information you are after!\n");
    }
}
