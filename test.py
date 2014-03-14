import json
from popplerExtension import *
import sys

#if sys.argv[1]:
f = fopen('MyMedicalRecord.pdf', 'rb')
#else:
#	f = fopen("brian_test.pdf", "rb")

#karthik pdf decrypt password
karthik_password =  "KH3348"

owner_password = ""

P = PopplerParser(f, owner_password, karthik_password )
#P = PopplerParser("brian_test-2013-03-08.pdf")
#print 'Number of pages ', P.getPages()
print "-"*1 
print "Starting Parse " 
results = P.Parse()
print "#"*1
print "FunctionResults"
#print results

parseResults = []
results = results.split("\n");
for word in results:
    if word:
        word = json.loads(word)
        parseResults.append(word)
print "#"* 1
print "done"
print parseResults
