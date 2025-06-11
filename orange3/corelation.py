import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

data=pd.read_csv("/home/hwaseop/ku_lhs2025/orange3/basket_analysis.csv")
corr = data.corr()
print(corr)

sns.heatmap(corr, annot=True, cmap="coolwarm", vmin=-1, vmax=1)
plt.show()

from Orange.data import Table

Table.to