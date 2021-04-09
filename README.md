# Marchesa Bot (or the boring name of CockatriceTournamentBot)
(Linux only)

## Interfacing with it 
The bot will host an https server (with self signed keys probably) and apps that
interface with the bot will use that to connect and send commands which will then
get a response (see src/helppage.gen.html for details). Sample implementation is
in python called `tricebot.py`

## Config file
The file (config.conf) should be in this format:

```yaml
username=cockatrice username
password=cockatrice password
serveraddress=ws://server.cockatrice.us:4748
authtoken=auth token for the interfacing with this bot
certfile=server.pem
certkeyfile=server-key.pem
bindAddr=https://127.0.0.1:8000
clientID=what servertrice sees as your client id
roomName=Magic
authRequired=1
```

Change the data for what you want. (is whitespace sensitive)
For duplicate property tags, the last line of the tag is used i.e:

```yaml
username=not this
username=this is used

```

## certfile and certkeyfile
Generate some ssl keys and slap them in the folder with the executable and then
change the config file to have the correct names.

## Help it is borked
compile with `make build-debug` and then run it with a debugger and get the full
backtrace of the program.

## TODO:
make it make a log or something idk
