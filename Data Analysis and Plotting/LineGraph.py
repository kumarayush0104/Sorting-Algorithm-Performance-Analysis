import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('Varying.csv')

# Group by Algorithm and Array Size (assuming you have an 'Array Size' column)
grouped_data = data.groupby(['Algorithm', 'Size'])

# Calculate mean values for each metric
mean_comparisons = grouped_data['Comparisons'].mean().reset_index()
mean_swaps = grouped_data['Swaps'].mean().reset_index()
mean_times = grouped_data['Time(microseconds)'].mean().reset_index()

# Create line graphs
plt.figure(figsize=(12, 6))

# Comparisons
plt.subplot(1, 3, 1)
for algorithm in mean_comparisons['Algorithm'].unique():
    algorithm_data = mean_comparisons[mean_comparisons['Algorithm'] == algorithm]
    plt.plot(algorithm_data['Size'], algorithm_data['Comparisons'], label=algorithm)
plt.xlabel('Array Size')
plt.ylabel('Number of Comparisons')
plt.title('Comparisons vs. Array Size')
plt.legend()

# Swaps
plt.subplot(1, 3, 2)
for algorithm in mean_swaps['Algorithm'].unique():
    algorithm_data = mean_swaps[mean_swaps['Algorithm'] == algorithm]
    plt.plot(algorithm_data['Size'], algorithm_data['Swaps'], label=algorithm)
plt.xlabel('Array Size')
plt.ylabel('Number of Swaps')
plt.title('Swaps vs. Array Size')
plt.legend()

# Execution Times
plt.subplot(1, 3, 3)
for algorithm in mean_times['Algorithm'].unique():
    algorithm_data = mean_times[mean_times['Algorithm'] == algorithm]
    plt.plot(algorithm_data['Size'], algorithm_data['Time(microseconds)'], label=algorithm)
plt.xlabel('Array Size')
plt.ylabel('Execution Time (microseconds)')
plt.title('Execution Time vs. Array Size')
plt.legend()

plt.tight_layout()
plt.show()

