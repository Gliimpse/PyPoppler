from popplerExtension import *
P = PopplerParser("brian_test.pdf")
#print 'Number of pages ', P.getPages()
print "-"*100 
print "Starting Parse"
results = P.Parse()
print "#"*100
print "FunctionResults"
print results

parseResults = []
results = results.split("\n");
for word in results:
	word = word.split(",")
	if len(word) > 0:
		keys = []
		vals = []
		t = {}
		for k in range(0, len(word), 2):
			keys.append(word[k])
		for v in range(1, len(word), 2):
			vals.append(word[v])

		for k, v  in zip(keys, vals):
			print k, ' -> ',v
			t[k] = v

		print
		parseResults.append(t)
print "#"* 100
print "done"
print parseResults
