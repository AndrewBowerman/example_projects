#funky.rb
#exceptions in Ruby
#I learned these techniques from https://www.geeksforgeeks.org/ruby-exception-handling/
# and from https://www.honeybadger.io/blog/a-beginner-s-guide-to-exceptions-in-ruby/

begin
  # Any exceptions in here... 
  1/0
rescue ZeroDivisionError => e #stores Exception object inside of e
  puts "Exception Class: #{ e.class.name }"
  puts "Exception Message: #{ e.message }"
  puts "Exception Backtrace: #{ e.backtrace }"
end

