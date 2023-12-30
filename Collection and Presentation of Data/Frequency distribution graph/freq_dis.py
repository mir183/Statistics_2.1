import matplotlib.pyplot as plt
from collections import Counter

# Function to get user input for data
def get_user_input():
    data = []
    print("Enter values separated by spaces. Press Enter to finish.")
    input_str = input("Enter values: ")
    if input_str.strip():
        try:
            data = [int(value) for value in input_str.split()]
        except ValueError:
            print("Invalid input. Please enter numeric values separated by spaces.")

    return data

# Function to get user input for class interval
def get_class_interval():
    try:
        class_interval = int(input("Enter the class interval: "))
        if class_interval <= 0:
            print("Class interval must be a positive integer. Using default interval of 1.")
            class_interval = 1
    except ValueError:
        print("Invalid input. Class interval must be a positive integer. Using default interval of 1.")
        class_interval = 1

    return class_interval

# Get user input
user_data = get_user_input()

# Check if there is data entered
if not user_data:
    print("No data entered.")
else:
    # Get user input for class interval
    class_interval = get_class_interval()

    # Calculate frequencies with specified class interval
    frequency = Counter((value // class_interval) * class_interval for value in user_data)

    # Prepare data for plotting
    values, counts = zip(*frequency.items())

    # Plotting
    plt.bar(values, counts, align='center', alpha=0.7)
    plt.xlabel('Class Intervals')
    plt.ylabel('Frequency')
    plt.title('Frequency Distribution')
    plt.show()
