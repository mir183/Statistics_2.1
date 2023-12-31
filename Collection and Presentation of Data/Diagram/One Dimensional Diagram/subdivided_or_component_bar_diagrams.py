import matplotlib.pyplot as plt

print("Max 2 bars per category")

# Get input from the user
def get_user_input():
    models = input("Enter catagories separated by spaces: ").split(' ')
    fuel_capacity = [float(capacity) for capacity in input("Enter X-axis capacities separated by spaces: ").split(' ')]
    fuel_efficiency = [float(efficiency) for efficiency in input("Enter Y-axis efficiencies separated by spaces: ").split(' ')]
    
    x_label = ' '
    y_label = ' '
    title = "Subdivided or Component Bar Diagrams"
    
    return models, fuel_capacity, fuel_efficiency, x_label, y_label, title

models, fuel_capacity, fuel_efficiency, x_label, y_label, title = get_user_input()

fig, ax = plt.subplots(figsize=(10, 15))  # Swap width and height

# Use barh for vertical bars
bar1 = ax.bar(models, fuel_capacity, color='blue', width=0.5, label=' ')
bar2 = ax.bar(models, fuel_efficiency, bottom=fuel_capacity, color='red', width=0.5, label=' ')

ax.set_xlabel(x_label)
ax.set_ylabel(y_label)
ax.set_title(title)
ax.legend()

for bars in [bar1, bar2]:
    for bar in bars:
        height = bar.get_height()
        ax.annotate(f'{height}',
                    xy=(bar.get_x() + bar.get_width() / 2, height),
                    xytext=(0, 3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom')

plt.show()
