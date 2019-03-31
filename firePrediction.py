import pandas as pd
import numpy as np
from collections import deque
import csv
# Importing the dataset
dataset = pd.read_csv('data.csv')
dataset.columns=['a','b','c','d']
X=np.array(dataset.iloc[:,:-1].values)
y=np.array(dataset.iloc[:, 3].values)

def get_last_row(csv_filename):
    with open(csv_filename, 'r') as f:
        return deque(csv.reader(f), 1)[0]


# Fitting Naive Bayes to the Training 
from sklearn.naive_bayes import GaussianNB
classifier = GaussianNB()
classifier.fit(X,y)

# Predicting the Test set results
try:
    
        lastline = ', '.join(get_last_row('final_data1.csv'))
        values = lastline.split("\t")
        print (values[0])   
        list1 = values[0].split(",")   
        print(list1)
        y_pred = classifier.predict([[int(list1[1]),int(list1[2]),int(list1[0])]])
        fd = open("fireResult.txt",'w')
        # fd.write(values[1])
        # fd.write(values[2])
        # fd.write(values[0])
       	fd.write(str(y_pred))
except IOError as e:
	print("file not found ")
else :
	fd.close()

print(list1)
print(y_pred)