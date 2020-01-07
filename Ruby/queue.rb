class Q
  def initialize
    @a=Array.new #queue uses Array
  end
  def enqueue(val)
    puts "Queueing #{val}..."
    @a[@a.length]=val 
    #place value at a new, higher index
  end
  def dequeue
    puts "Attempting dequeue..."
    if @a.length>0
      a=@a.pop
      puts "Removed: #{a}"
    else
      puts "Queue is already empty."
    end
  end
  def print
    puts "Current queue:"
    for i in @a do
      puts i
    end
  end
end #END Q
#BEGIN DRIVER
q = Q.new
q.enqueue(78)
q.enqueue(35)
q.enqueue(12)
q.enqueue(24)
q.enqueue(53)
q.print
q.dequeue
q.dequeue
q.dequeue
q.print
q.dequeue
q.dequeue
q.dequeue
q.print