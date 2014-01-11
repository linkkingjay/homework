a = []
16.times {a.push(rand(100))}

puts "with each:"
(0..3).each do |i|
    (0..3).each {|j| print "#{a[i*4+j]}\t"}
    puts
end

puts "with each_slice:"
a.each_slice(4) {|i| print i, "\n"}
