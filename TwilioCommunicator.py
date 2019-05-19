from twilioKeys import getKeys
from twilio.rest import Client

keys = getKeys()
account_sid = keys['account_sid']
auth_token = keys['auth_token']
twilio_number = keys['twilio_number']
my_number = keys['my_number']
client = Client(account_sid, auth_token)

def send_message(response,
                 sender = keys['twilio_number'],
                 reciever = keys['my_number']):
    message = client.messages \
                    .create(
                         body = response,
                         from_= sender,
                         to = reciever)

def make_phonecall(url = 'https://handler.twilio.com/twiml/EHbd05de33bed6e27c29bf7e1db4e9548f', sender = keys['twilio_number'], reciever = keys['my_number']):

    call = client.calls.create(
        url = url,
        to = reciever,
        from_ = sender
    )

def executeTwilio():
    make_phonecall()
    send_message('There is a fire detected at 1336 Brittmoore Rd, Houston, TX 77043')



