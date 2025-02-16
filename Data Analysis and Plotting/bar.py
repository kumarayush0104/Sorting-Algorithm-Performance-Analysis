import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('uniform.csv')

# Calculate total operations (comparisons + swaps) for each algorithm
data['Total_Operations'] = data['Comparisons'] + data['Swaps']
total_operations = data.groupby('Algorithm')['Total_Operations'].mean()

# Create the bar chart
plt.figure(figsize=(10, 6))
plt.bar(total_operations.index, total_operations.values)
plt.xlabel('Sorting Algorithm')
plt.ylabel('Total Number of Operations')
plt.title('Comparison of Total Operations (Comparisons + Swaps)')
#plt.xticks(rotation=45)
#plt.grid(True)
plt.show()
