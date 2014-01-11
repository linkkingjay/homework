def grep(pattern, file)
    f = File.open(file)
    f.each_with_index do |l, i|
        if (pattern =~ l) != nil
            puts "#{i}:#{l}"
        end
    end
end

grep(/puts/i, 'each.rb')
