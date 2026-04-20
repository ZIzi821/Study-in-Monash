import csv
import unittest

def read_numbers_from_csv(path):
    """
    Read integers from a CSV file (one number per line).
    Returns a list of integers.
    """
    numbers = []
    with open(path, newline='', encoding='utf-8') as f:
        reader = csv.reader(f)
        for row in reader:
            if row:  # skip empty rows
                numbers.append(int(row[0]))
    return numbers

def filter_even_numbers(nums):
    """
    Return a list containing only the even numbers.
    """
    return [n for n in nums if n % 2 == 0]

def format_table(nums):
    """
    Format a list of numbers into a right-aligned table string.
    """
    return "\n".join(f"{i:>5}" for i in nums)

# Example usage
if __name__ == "__main__":
    # Make sure numbers.csv exists in the same directory
    nums = read_numbers_from_csv("numbers.csv")
    evens = filter_even_numbers(nums)
    print("Even numbers from CSV:")
    print(format_table(evens))

# Unit test class
class TestKnowledge(unittest.TestCase):
    def test_filter_even_numbers(self):
        data = [1, 2, 3, 4, 5, 6]
        self.assertEqual(filter_even_numbers(data), [2, 4, 6])

    def test_format_table(self):
        data = [10, 20]
        formatted = format_table(data)
        self.assertIn("   10", formatted)
        self.assertIn("   20", formatted)

if __name__ == "__main__":
    unittest.main(exit=False)
