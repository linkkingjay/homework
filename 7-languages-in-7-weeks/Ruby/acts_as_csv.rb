class ActsAsCsv
    def self.acts_as_csv #宏

        define_method 'read' do
            file = File.new(self.class.to_s.downcase + '.txt')
            @headers = file.gets.chomp.split(', ')

            file.each do |row|
                @result << row.chomp.split(', ')
            end
        end

        define_method 'headers' do
        
            @headers
        end

        define_method 'result' do
            @result
        end

        define_method 'initialize' do
            @result = []
            read
        end
    end
end

class RubyCsv < ActsAsCsv
end

m = RubyCsv.new
puts m.headers.inspect
puts m.csv_contents.inspect
