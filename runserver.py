from flask import Flask, request, redirect, session, request, render_template, flash, redirect, url_for, g, jsonify
import twilio.twiml
import json
import os
from threading import Thread
import serial
import string
from time import sleep
 
app = Flask(__name__)
 
#mailjet_api = mailjet.Api(api_key='c66041761c6774515f8abcfbd50b5ed7', secret_key='22e83961c3180563dc1b7083c121a310')

@app.route("/", methods=['GET', 'POST'])
def hello_monkey():
    """Respond to incoming calls with a simple text message."""
 
    resp = twilio.twiml.Response()
    resp.message("Move your robot")
    return str(resp)

@app.route("/sms", methods=['GET', 'POST'])
def sms():
    ser = serial.Serial('COM6', 9600)
    body = request.values.get('Body', None).lower()
    wordsList = body.split()
    print str(wordsList)
    sleep(2)
    for word in wordsList:
        if "forward" in word:
            ser.write('0')
            sleep(1)
        elif "backward" in word:
            ser.write('1')
            sleep(1)
        elif "left" in word:
            ser.write('2')
            sleep(1)
        elif "right" in word:
            ser.write('3')
            sleep(1)
        elif "dance" in word:
            ser.write('4')
            sleep(1)
        else:
            # Bad command
            resp = twilio.twiml.Response()
            resp.message("Oops! Try saying forward, backward, left, or right :)")
            return str(resp)
    # Good command
    resp = twilio.twiml.Response()
    if len(wordsList) > 1: resp.message("Moved around!")
    elif len(wordsList) == 1: resp.message("Moved %s!" % body)
    return str(resp)

@app.route("/email", methods=['GET', 'POST'])
def email():
    #ser = serial.Serial('COM6', 9600)
    data = request.data
    dataDict = json.loads(data)
    body = dataDict['Subject']
    print(body)
    wordsList = body.split()
    print str(wordsList)
    sleep(2)
    return body

if __name__ == "__main__":
    app.run(debug=True)
