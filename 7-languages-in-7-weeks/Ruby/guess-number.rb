num = rand(1024)
puts "guess the number(0 < n < 1024):"
while (n = gets().to_i)
    if n == num
        puts "you are right"
        break
    end
    if n > num
        puts "the right number is less than #{n}"
    else 
        puts "the right number is greater than #{n}"
    end
end
