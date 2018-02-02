from flask import Flask, redirect, render_template, request, url_for

import helpers
import sys
from analyzer import Analyzer

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "")
    if not screen_name:
        return redirect(url_for("index"))

    # get screen_name's tweets
    tweets = helpers.get_user_timeline(screen_name, 100)
    if tweets == None:
        return redirect(url_for("index"))

    anal = Analyzer("positive-words.txt", "negative-words.txt")

    positive, negative, neutral = 0, 0, 0
    for tweet in tweets:
        score = anal.analyze(tweet)
        if score == 0:
            neutral+=1

        elif score > 0:
            positive+=1

        elif score < 0:
            negative+=1


    length = len(tweets)
    positive = positive/length*100
    negative = negative/length*100
    neutral = neutral/length*100

    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
