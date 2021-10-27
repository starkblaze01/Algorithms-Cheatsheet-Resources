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
