import pandas as pd
import numpy as np

df=pd.read_csv('/home/hwaseop/ku_lhs2025/orange3/healthcare_dataset3.csv')
print(df.shape)


cols2=['gender_encoded','work_type_encoded','smoking_status_encoded']
df1=pd.get_dummies(df,columns=cols2)
df1.head(3)
print(df1.head(3))
print(df1.shape)
print(list[df1.columns])

cols3=['gender_encoded_0.0','work_type_encoded_1.0','smoking_status_encoded_2.0']
df1.drop(cols3,axis=1,inplace=True)
print(df1.shape)