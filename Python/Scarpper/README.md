# Pyrebase4

A simple python wrapper for the [Firebase API](https://firebase.google.com).

## Installation

```python
pip install pyrebase4
```

## Getting Started

### Python Version

Pyrebase was written for python 3 and will not work correctly with python 2.

### Add Pyrebase to your application

For use with only user based authentication we can create the following configuration:

```python
import pyrebase
config = {
  "apiKey": "apiKey",
  "authDomain": "projectId.firebaseapp.com",
  "databaseURL": "https://databaseName.firebaseio.com",
  "storageBucket": "projectId.appspot.com"
}
firebase = pyrebase.initialize_app(config)
```

We can optionally add a [service account credential](https://firebase.google.com/docs/server/setup#prerequisites) to our
configuration that will allow our server to authenticate with Firebase as an admin and disregard any security rules.

```python
import pyrebase
config = {
  "apiKey": "apiKey",
  "authDomain": "projectId.firebaseapp.com",
  "databaseURL": "https://databaseName.firebaseio.com",
  "storageBucket": "projectId.appspot.com",
  "serviceAccount": "path/to/serviceAccountCredentials.json"
}
firebase = pyrebase.initialize_app(config)
```

Adding a service account will authenticate as an admin by default for all database queries, check out the
[Authentication documentation](#authentication) for how to authenticate users.

-----------------------------------------------------------------------------------------------------------\

# Python Requests Module

The requests module allows you to send HTTP requests using Python.
The HTTP request returns a Response Object with all the response data (content, encoding, status, etc).

### Navigate your command line to the location of PIP, and type the following:

C:\Users\Your Name\AppData\Local\Programs\Python\Python36-32\Scripts>pip install requests

### Make a request to a web page, and print the response text:

import requests
x = requests.get('https://sdgsd.com/python/demopage.htm')
print(x.text)
-----------------------------------------------------------------------------------------------------------\

# Python Beautiful Soup

Beautiful Soup is a Python library for pulling data out of HTML and XML files.

### Navigate your command line to the location of PIP, and type the following:

C:\Users\Your Name\AppData\Local\Programs\Python\Python36-32\Scripts>pip install beautifulsoup4

from bs4 import BeautifulSoup
with open("index.html") as fp:
soup = BeautifulSoup(fp, 'html.parser')

soup = BeautifulSoup("<html>a web page</html>", 'html.parser')
