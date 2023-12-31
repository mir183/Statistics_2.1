import matplotlib.pyplot as plt

# Function to get user input for categories and values
def get_user_input():
    categories = input("Enter categories separated by spaces: ").split()
    values = [float(value) for value in input("Enter corresponding values separated by spaces: ").split()]
    return categories, values

# Get user input
user_categories, user_values = get_user_input()

# Create a simple bar diagram
plt.bar(user_categories, user_values, color='blue')
plt.xlabel('Categories')
plt.ylabel('Values')
plt.title('Simple Bar Diagram')
plt.show()
