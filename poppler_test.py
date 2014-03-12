import sys
import json
from popplerExtension import *

def poppler_parse(pdf):
    f = fopen(pdf, 'rb')
    P = PopplerParser(f)
    results = P.Parse()

    parseResults = []
    results = results.split("\n");
    for word in results:
        if word:
            word = json.loads(word)
            parseResults.append(word)
    #print [x['word'] for x in parseResults]
    return parseResults

if __name__=="__main__":
    poppler_parse(sys.argv[1])
