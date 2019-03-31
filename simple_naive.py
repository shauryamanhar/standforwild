# -*- coding: utf-8 -*-
"""
Created on Wed Dec  5 15:37:23 2018

@author: hp
"""

# -*- coding: utf-8 -*-
"""
Created on Wed Dec  5 14:55:06 2018

@author: hp
"""
# -*- coding: utf-8 -*-
"""
Created on Sat Mar 30 23:49:35 2019

@author: hp
"""

# -*- coding: utf-8 -*-
"""
Created on Wed Dec  5 15:37:23 2018

@author: hp
"""

# -*- coding: utf-8 -*-
"""
Created on Wed Dec  5 14:55:06 2018

@author: hp
"""
import pandas as pd
import numpy as np
# Importing the dataset
dataset = pd.read_csv('data.csv')
dataset.columns=['a','b','c','d']
X=np.array(dataset.iloc[:,:-1].values)
y=np.array(dataset.iloc[:, 3].values)




# Fitting Naive Bayes to the Training 
from sklearn.naive_bayes import GaussianNB
classifier = GaussianNB()
classifier.fit(X,y)

# Predicting the Test set results
y_pred = classifier.predict([[89,-100,560]])
print(y_pred)