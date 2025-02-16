import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

data = pd.read_csv('box.csv')

# Create a box plot for execution times
plt.figure(figsize=(10, 6))
sns.boxplot(x='Algorithm', y='Time(microseconds)', data=data)
plt.xlabel('Algorithm')
plt.ylabel('Execution Time (microseconds)')
plt.title('Distribution of Execution Times for Sorting Algorithms')
plt.show()