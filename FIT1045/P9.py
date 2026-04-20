# Student Grade Analyser
# This program allows the user to enter up to 20 grades (integers).
# It then calculates the average grade, pass rate, and number of high distinctions.

def analyse_grades(grades):
    """Return average, pass rate, and high distinction count."""
    if not grades:
        return 0, 0, 0
    average = sum(grades) / len(grades)
    pass_rate = (len([g for g in grades if g >= 50]) / len(grades)) * 100
    high_distinctions = len([g for g in grades if g >= 80])
    return average, pass_rate, high_distinctions

def main():
    grades = []
    print("Enter up to 20 student grades (0–100). Type -1 to finish.")
    while len(grades) < 20:
        try:
            g = int(input(f"Enter grade {len(grades)+1}: "))
            if g == -1:
                break
            if 0 <= g <= 100:
                grades.append(g)
            else:
                print("Grade must be between 0 and 100.")
        except ValueError:
            print("Please enter a valid integer.")

    average, pass_rate, high_distinctions = analyse_grades(grades)
    print("\n--- Results ---")
    print("Grades entered:", grades)
    print(f"Average grade: {average:.2f}")
    print(f"Pass rate: {pass_rate:.1f}%")
    print(f"High distinctions (>=80): {high_distinctions}")

if __name__ == "__main__":
    main()
