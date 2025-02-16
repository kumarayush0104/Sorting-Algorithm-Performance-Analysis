import pandas as pd
import matplotlib.pyplot as plt

# Load the data from the CSV file
data = pd.read_csv('Varying.csv')

# Assuming 'Size' is a constant value (e.g., 10000) for all rows in your data
 # Replace with the actual size if it varies

# Define a dictionary to map algorithms to marker styles and colors
algorithm_markers = {
    'Bubble Sort': 'o',  # circle marker
    'Insertion Sort': 's',  # square marker
    'Selection Sort': '^',  # triangle marker
    'Merge Sort': 'p',  # pentagon marker
    'Quick Sort': 'h',  # hexagon marker
    'Heap Sort': 'D'  # diamond marker
}
algorithm_colors = {
    'Bubble Sort': 'blue',
    'Insertion Sort': 'green',
    'Selection Sort': 'red',
    'Merge Sort': 'purple',
    'Quick Sort': 'orange',
    'Heap Sort': 'brown'
}

# Create scatter plots for Comparisons and Swaps
plt.figure(figsize=(12, 6))

# Comparisons
plt.subplot(1, 2, 1)
for algorithm in data['Algorithm'].unique():
    algorithm_data = data[data['Algorithm'] == algorithm]
    marker = algorithm_markers[algorithm]
    color = algorithm_colors[algorithm]
    plt.scatter(algorithm_data['Size'], algorithm_data['Comparisons'],
                label=algorithm, alpha=0.7, marker=marker, c=color)
plt.xlabel('Array Size')
plt.ylabel('Number of Comparisons')
plt.title('Comparisons vs. Array Size')
plt.legend()

# Swaps
plt.subplot(1, 2, 2)
for algorithm in data['Algorithm'].unique():
    algorithm_data = data[data['Algorithm'] == algorithm]
    marker = algorithm_markers[algorithm]
    color = algorithm_colors[algorithm]
    plt.scatter(algorithm_data['Size'], algorithm_data['Swaps'],
                label=algorithm, alpha=0.7, marker=marker, c=color)
plt.xlabel('Array Size')
plt.ylabel('Number of Swaps')
plt.title('Swaps vs. Array Size')
plt.legend()

plt.tight_layout()
plt.show()