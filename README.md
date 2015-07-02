# drive-a-robot
Control a robot with SMS and email. It's like Twitch Plays Pokemon, but with a robot!

Commands are sent via Twilio and Mailjet to a Flask server.
The server sends the commands to an Arduino Uno via USB.
The Uno drives the robot's motors to navigate it through a course of cones.

Many users can send commands at once, making this an exciting collaborative game.
