#!/usr/bin/python3

import sys, os
sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))
from util import util
import cgi, cgitb, os, sys

cgitb.enable()

form = cgi.FieldStorage()
fileName = form.getvalue('file')
filePath = '/var/www/uploaded' + '/' + fileName

try:
    if os.path.isfile(filePath):
        mimeType = util.getMIMEType(fileName)
        if mimeType is None:
            mimeType = 'application/octet-stream'
        
        sys.stdout.buffer.write(f"Content-Type: {mimeType}\r\n\r\n".encode('utf-8'))
        with open(filePath, 'rb') as file:
            sys.stdout.flush()
            while True:
                chunk = file.read(10000)
                if not chunk:
                    break
                sys.stdout.buffer.write(chunk)
                sys.stdout.flush()
    else:
        print("Content-Type: text/html\n")
        print("File not found.: {}".format(filePath))
except Exception as e:
    print("Content-Type: text/html\n")
    print(f"Error: {str(e)}")
