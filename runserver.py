from flask import Flask, request, redirect
import twilio.twiml
import serial
import string
from time import sleep
 
app = Flask(__name__)
 
@app.route("/", methods=['GET', 'POST'])
def hello_monkey():
    """Respond to incoming calls with a simple text message."""
 
    resp = twilio.twiml.Response()
    resp.message("Move your robot ")
    return str(resp)

@app.route("/sms", methods=['GET', 'POST'])
def serialTest():
    ser = serial.Serial('COM6', 9600)
    body = request.values.get('Body', None).lower()
    print str(body)
    sleep(4)
    if body == "forward":
        ser.write('0')
    elif body == "backward":
        ser.write('1')
    elif body == "left":
        ser.write('2')
    elif body == "right":
        ser.write('3')
    else:
        # Bad command
        resp = twilio.twiml.Response()
        resp.message("Oops! Try saying forward, backward, left, or right :)")
        return str(resp)
    # Good command
    resp = twilio.twiml.Response()
    resp.message("Moved %s!" % body)
    return str(resp)

if __name__ == "__main__":
    app.run(debug=True)