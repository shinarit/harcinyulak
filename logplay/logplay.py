# -*- coding: utf-8 -*-
#/bin/python

from Tkinter import *

class LogPlayer(Frame):
  def __init__(self, master, dimensions):
    Frame.__init__(self, master, width = dimensions[0], height = dimensions[1])

    self.currSize = dimensions

    self.cv = Canvas(self, bg="white")
    
    self.cv.bind("<Configure>", self.resize)
    
    self.pack_propagate(0)
    self.cv.pack(fill = BOTH, expand = YES)
    self.pack(fill = BOTH, expand = YES)

    self.cv.create_line(0, 0, currSize[0], currSize[1])
    self.cv.create_line(currSize[0], 0, 0, currSize[1])

  def resize(self, event):
    print "%d %d" % (event.width, self.currSize[0])
    print "%f %f" % (float(event.width) / self.currSize[0], float(event.height) / self.currSize[1])
    self.cv.scale("all", 0, 0, float(event.width) / self.currSize[0], float(event.height) / self.currSize[1])
    self.currSize = (event.width, event.height)


defaultSize = (800, 600)

tk = Tk()
tk.title("E!")

fr = LogPlayer(tk, defaultSize)

tk.mainloop()
