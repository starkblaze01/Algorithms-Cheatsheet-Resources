# A simple python wrapper for the [Firebase API](https://firebase.google.com).

## Installation

```python
pip install -r requirements.txt
```

## Getting Started


### Change the following in the config variable of your python script

```python
config = {
  "apiKey": "apiKey",
  "authDomain": "projectId.firebaseapp.com",
  "databaseURL": "https://databaseName.firebaseio.com",
  "storageBucket": "projectId.appspot.com"
}
```

You can generate these values after setting up your own firebase account from [here](https://console.firebase.google.com/).


### Data details
```
data = {"newslink":all_news_data[i][0],
            "imagelink":all_news_data[i][1],
            "head":all_news_data[i][2],
            "title":all_news_data[i][3],
            "desc":all_news_data[i][4]}

    result = firebaseconn.patch("/News/%s"%i,data)

"newslink" : extracts url of the webpage
"imagelink" : extracts url of the image
"head" : extracts url of the image referenced or quotes 
"title" : extracts url of the headline of the news
"desc" : extracts url of the first paragraph of the article
result : Updating Data with PATCH to firebase database
```

### Dependency details

#### Python Requests Module

The requests module allows you to send HTTP requests using Python.
The HTTP request returns a Response Object with all the response data (content, encoding, status, etc).

#### For e.g. Make a request to a web page, and print the response text:

```
import requests
x = requests.get('https://sdgsd.com/python/demopage.htm')
print(x.text)
```
-----

#### Python Beautiful Soup

Beautiful Soup is a Python library for pulling data out of HTML and XML files.

#### Sample Usage

```
from bs4 import BeautifulSoup
with open("index.html") as fp:
soup = BeautifulSoup(fp, 'html.parser')

soup = BeautifulSoup("<html>a web page</html>", 'html.parser')
```
