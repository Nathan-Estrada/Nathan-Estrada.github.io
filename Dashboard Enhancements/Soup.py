from bs4 import BeautifulSoup
import requests, csv
import pandas as pd
import re

r = range(1,28)
pages = list(r)

fragranceNames = []
fragrancePrices = []
fragrancePricesAveraged = []
fragranceBrands = []
fragrances = []

for i in pages:
    website = f'https://perfumania.com/collections/mens-colognes?page={i}'
    result = requests.get(website)
    content = result.text
    soup = BeautifulSoup(content,features="html.parser")
    
    frags = soup.find_all('div', class_= 'grid-item col-6 col-md-4 col-lg-3')
    for frag in frags:
        fragrances.append(frag.text.strip())

        prices = frag.find('div', class_= 'priceRange').find('span', {'aria-hidden': 'true'})
        for price in prices:
            fragrancePrices.append(price.text.strip())

        brands = frag.find('div', {'class': 'product-bottom'}).find('div', {'class': 'product-vendor'}).find('span', {'class': 'visually-hidden'})
        for brand in brands:
            fragranceBrands.append(brand.text.strip())

        names = frag.find('a', class_= 'product-title title_ellipse').find('span')
        for name in names:
            fragranceNames.append(name.text.strip())

for i in fragrancePrices:
    if '-' in i:
        startingPoint = i.index('-')
        firstNumber, secondNumber = [], []
        firstNumberString, secondNumberString = '', ''
        #Get the second number in price range
        for char in i[(startingPoint+2):]:
            if char != '$':
                secondNumber.append(char)
        #Get the first number in price range
        for char in i[:(startingPoint-1)]:
            if char != '$':
                firstNumber.append(char)      
        firstNumberString = firstNumberString.join(firstNumber)
        secondNumberString = secondNumberString.join(secondNumber)

        firstNumberFloat = float(firstNumberString)
        secondNumberFloat = float(secondNumberString)

        averagePrice = ((firstNumberFloat + secondNumberFloat)/2)
        fragrancePricesAveraged.append(averagePrice)
    else:
        cleanedPrice = i.replace("$", "")
        cleanedPrice = float(cleanedPrice)
        fragrancePricesAveraged.append(cleanedPrice)

for i,j in enumerate(fragrancePricesAveraged):
    fragrancePricesAveraged[i] = round(j, 2)


print(len(frags))
print(len(fragranceBrands))
print(len(fragrancePricesAveraged))
print(len(fragranceNames))
df = pd.DataFrame({"Brand": fragranceBrands, "Name": fragranceNames, "Price": fragrancePricesAveraged})
print(df)
df.to_csv("Perfumania_Fragrances.csv", index=False)