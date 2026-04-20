class UserAccount:
    """UserAccount class to represent a simple user login system."""

    def __init__(self, username, password):
        """Initialize account with username and password (password kept private)."""
        self.username = username
        self.__password = password   # private attribute

    def test_login(self, username, password):
        """Return True if username and password match, otherwise False."""
        return self.username == username and self.__password == password

    def change_password(self, current_password, new_password):
        """
        Change the password only if:
        - current password matches
        - new password is different from the old one
        """
        if current_password == self.__password and new_password != self.__password:
            self.__password = new_password
            return True
        else:
            return False

    def __str__(self):
        """Return string representation (username only, password hidden)."""
        return f"UserAccount(username={self.username})"


# Example usage
user = UserAccount("Glory", "123Er")

# Test login
print("Login success?", user.test_login("Glory", "123Er"))   # True
print("Login success?", user.test_login("Glory", "abc"))     # False

# Change password
print("Password changed?", user.change_password("123Er", "abc123"))  # True
print("Password changed?", user.change_password("abc123", "123Er"))  # False (reuse not allowed)
