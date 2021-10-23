#Amazon web scraping
#website selected = Amazon

#Scraps a page from Amazon website and collects all the product related information from the website and store them in a data frame.

import pandas as pd
import numpy as np
import re
from urllib.request import urlopen
from bs4 import BeautifulSoup
import requests


no_pages = 1

def get_data(pageNo):  
    
    r = requests.get('https://www.amazon.in/gp/bestsellers/dvd/21360334031/ref=zg_bs_pg_?'+str(pageNo)+'ie=UTF8&pg='+str(pageNo))
    content = r.content
    soup = BeautifulSoup(content)
    
    alls = []
    for d in soup.findAll('div', attrs={'class':'a-section a-spacing-none aok-relative'}):
 
        name = d.find('a', attrs={'class':'a-link-normal'})
        n = name.find_all('img', alt=True)
        
        userRatings = d.find('span', attrs={'class':'zg-badge-text'})
        
        stars = d.find('span', attrs={'class':'a-icon-alt'})
        
        NoOfRatings = d.find('a', attrs={'class':'a-size-small a-link-normal'})
        
        all1=[]

        if name is not None:
            #print(n[0]['alt'])
            all1.append(n[0]['alt'])
        else:
            all1.append("Movie name cannot be found")
            
        if userRatings is not None:
            #print(rating.text)
            all1.append(userRatings.text)
        else:
            all1.append('0')
            
        if stars is not None:
            #print(rating.text)
            all1.append(stars.text)
        else:
            all1.append('0')
            
        if NoOfRatings is not None:
            all1.append(NoOfRatings.text)
        else:
            all1.append('0')
            
       
        alls.append(all1)    
    return alls




results = []
for i in range(1, no_pages+1):
    results.append(get_data(i))
flatten = lambda l: [item for sublist in l for item in sublist]
df = pd.DataFrame(flatten(results),columns=['Movie Name', 'User Rating', 'Stars', 'No of User Ratings'])
df.to_csv('actionMovies.csv', index=False, encoding='utf-8')

df = pd.read_csv("actionMovies.csv")


df.head(5)
