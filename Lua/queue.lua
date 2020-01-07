Queue = {}

table.insert(Queue,1)
table.insert(Queue,3)
table.insert(Queue,4)
table.insert(Queue,6)
table.insert(Queue,8)

print("Queue: "..table.concat(Queue,", "))

--remove(name, x)
--approximates a dequeue of first element
print("Dequeue "..table.remove(Queue, 1))
print("Dequeue "..table.remove(Queue, 1))
print("Dequeue "..table.remove(Queue, 1))

print(table.concat(Queue,", "))

print("Dequeue "..table.remove(Queue, 1))
print("Dequeue "..table.remove(Queue, 1))
print("Dequeue ")
table.remove(Queue, 1)

print("Queue: "..table.concat(Queue,", "))