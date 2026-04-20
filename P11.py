from abc import ABC, abstractmethod

# -------------------------
# Abstract Base Class
# -------------------------
class UserAction(ABC):
    @abstractmethod
    def show(self, index):
        """Display the menu option with its index."""
        pass

    @abstractmethod
    def run(self):
        """Perform the action when selected."""
        pass


# -------------------------
# Say Hello Action
# -------------------------
class SayHelloAction(UserAction):
    def show(self, index):
        print(f"{index}: Say Hello")

    def run(self):
        name = input("Enter your name: ")
        print(f"Hello, {name}! Nice to meet you.")


# -------------------------
# Simple Math Action
# -------------------------
class SimpleMathAction(UserAction):
    def show(self, index):
        print(f"{index}: Simple Math Test")

    def run(self):
        answer = input("What is 2 + 3? ")
        if answer.strip() == "5":
            print("Correct!")
        else:
            print("Oops, the answer is 5.")


# -------------------------
# Extra Action (Guess Game)
# -------------------------
class GuessNumberAction(UserAction):
    def show(self, index):
        print(f"{index}: Guess the Number")

    def run(self):
        import random
        target = random.randint(1, 6)
        guess = int(input("Guess a number between 1 and 6: "))
        if guess == target:
            print("You guessed it!")
        else:
            print(f"Sorry, the number was {target}.")


# -------------------------
# Menu Runner
# -------------------------
def choose_and_run(actions):
    while True:
        print("\n--- Menu ---")
        for i, action in enumerate(actions, start=1):
            action.show(i)
        print("0: Quit")

        choice = input("Option: ")
        if choice == "0":
            print("Exiting menu...")
            break
        elif choice.isdigit() and 1 <= int(choice) <= len(actions):
            actions[int(choice) - 1].run()
        else:
            print("Invalid choice, try again.")


# -------------------------
# Main
# -------------------------
if __name__ == "__main__":
    actions = [SayHelloAction(), SimpleMathAction(), GuessNumberAction()]
    choose_and_run(actions)
