#AUTHOR : ARUN KRISHNAN(AM.EN.U4CSE22004)

import os
import telebot
import requests
import json
import csv

#The api is stored as an environment varaible in my host machine(TO DO: 1.1)
BOT_API_KEY = os.getenv("API_KEY")
arun_movie_bot = telebot.TeleBot(BOT_API_KEY)


global arun_bot_running
arun_bot_running = False


#Greeting and info about the bot
@arun_movie_bot.message_handler(commands=["hello", "hi", "Hello", "Hi"])
def bot_greet(message):
    global arun_bot_running
    arun_bot_running = True
    arun_movie_bot.reply_to(message, "Hi there👋 , i'm a movie bot and i can get you info about all the movies also i'll export it to a CSV file type 'help' to see more commands")


#To display help commands
@arun_movie_bot.message_handler(commands=["help"])
def bot_help(message):
    global arun_bot_running
    if arun_bot_running != True:
        arun_movie_bot.reply_to(message,"Please start the bot by typing '/hi' or '/hello'")
    else:
        arun_movie_bot.reply_to(message,"These are the list of commands you can use:")
        arun_movie_bot.reply_to(message,"Type '/hi' or '/hello' to start the bot")
        arun_movie_bot.reply_to(message,"Type '/film [MOVIE_NAME]' to get the info about the movie")
        arun_movie_bot.reply_to(message,"Type '/export' to dump the movie info to a csv file and then it'll be available as a downloadable format in the Telegram chat")


#Getting the movie info
@arun_movie_bot.message_handler(commands=["film"])
def bot_find_film(message):
    global arun_bot_running
    if arun_bot_running != True:
        arun_movie_bot.reply_to(message,"Please start the bot by typing '/hi' or '/hello'")
    else:
        #Getting the movie name
        trimmed_msg = list(message.text.replace(" ",""))
        movie_name = "".join(trimmed_msg[5:])

        #Using the OMDB api to get movie info(TO DO: 1.2)
        movie_info_json = requests.get(f"http://www.omdbapi.com/?apikey=e6e95ac1&t={movie_name}")
        global movie_info;
        movie_info =  json.loads(movie_info_json.text)
        try:
            #Showing movie date to chat screen TO DO 1.3
            arun_movie_bot.reply_to(message,f"""
            Bot by Arun Krishnan
            Movie Name : {movie_info["Title"]}
            Year of Release : {movie_info["Year"]}
            Date of Release : {movie_info["Released"]}
            IMDB rating     : {movie_info["imdbRating"]}
            {movie_info["Poster"]}
            """)
        except:
            arun_movie_bot.reply_to(message,"Some error occured")


#TO DO 2.1
#Create a Csv file and put movie info in it
@arun_movie_bot.message_handler(commands=["export"])
def bot_dump_csv(message):
    global movie_info
    if arun_bot_running != True:
        arun_movie_bot.reply_to(message,"Please start the bot by typing '/hi' or '/hello'")
    required_movie_info = [movie_info["Title"],movie_info["Year"],movie_info["Released"],movie_info["imdbRating"]]
    with open("movie_info.csv","w",encoding='UTF8') as f:
        writer = csv.writer(f)
        writer.writerow(required_movie_info)

    #TO DO 2.2,Sending csv file to telegram chat
    #arun_movie_bot.send_document(chat_id,"movie_info.csv")
    chat_id = message.chat.id
    movie_csv = open('movie_info.csv', 'rb')
    arun_movie_bot.send_document(chat_id,movie_csv)


#To end the conversation
@arun_movie_bot.message_handler(commands=["halt","full_stop"])
def bot_goodbye(message):
    global arun_bot_running
    arun_bot_running = False
    arun_movie_bot.reply_to(message,"Hope you liked my service 😄")


arun_movie_bot.polling()