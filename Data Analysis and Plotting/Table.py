import pandas as pd
import matplotlib.pyplot as plt

plt.style.use('bmh')
data=pd.read_csv('uniform.csv')

summary_df = data.groupby('Algorithm').agg({
        'Comparisons': ['mean', 'min', 'max'],
        'Swaps': ['mean', 'min', 'max'],
        'Time(microseconds)': ['mean', 'min', 'max']
    })

summary_df.columns = ['Mean Comparisons', 'Min Comparisons', 'Max Comparisons',
                         'Mean Swaps', 'Min Swaps', 'Max Swaps',
                         'Mean Time', 'Min Time', 'Max Time']

summary_df.to_csv('sorting_summary.csv', index=True)
print(summary_df)

