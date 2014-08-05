#!/usr/bin/env python3

import threading

class HelloThr (threading.Thread):
    """ Une classe pour dire bonjour """
    def __init__(self, tid):
        super(HelloThr, self).__init__(group=None)
        self.tid = tid
    def hello(self):
        print("Hello world! de ", self.tid)
    def run(self):
        self.hello()

threads=[]
for i in range(2):
    threads.append( HelloThr(i) )

[t.start() for t in threads]


















