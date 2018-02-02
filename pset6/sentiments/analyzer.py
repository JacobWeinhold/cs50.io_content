import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        self.tokenizer = nltk.tokenize.TweetTokenizer()

        self.positives = set()
        self.negatives = set()
        positiveFile = open(positives, "r")
        negativeFile = open (negatives, "r")

        for line in positiveFile:
            if not line.startswith(';'):
                self.positives.add((line.rstrip("\n").strip(' ')))

        for line in negativeFile:
            if not line.startswith(';'):
                self.negatives.add((line.rstrip("\n").strip(' ')))


    def analyze(self, text):
        score = 0
        tokens = self.tokenizer.tokenize(text)
        for token in tokens:
            if token.lower() in self.positives:
                score+=1
            elif token.lower() in self.negatives:
                score-=1

        return score
