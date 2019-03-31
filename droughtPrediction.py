import pandas as pd
import numpy as np
# Importing the dataset
dataset = pd.read_csv('datasetDry.csv')
dataset.columns=['a','b','c','d']
X=np.array(dataset.iloc[:,:-1].values)
y=np.array(dataset.iloc[:, 3].values)




# Fitting Naive Bayes to the Training 
from sklearn.naive_bayes import GaussianNB
classifier = GaussianNB()
classifier.fit(X,y)

# Predicting the Test set results
y_pred = classifier.predict([[60	,-30	,350]])
try:
	fd = open("droughtResult.txt",'w')
	fd.write("[60	,-30	,350 ]")
	fd.write(str(y_pred))
except IOError as e:
	print("file not found ")
else :
	fd.close()
print("[60	-30	350]")
print(y_pred)