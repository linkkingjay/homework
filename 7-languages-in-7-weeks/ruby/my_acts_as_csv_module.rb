module ActsAsCsv

    def self.included(base)
        base.extend ClassMethods
    end

    module ClassMethods
        def acts_as_csv
            include InstanceMethods
        end
    end

    module InstanceMethods

        def read
            @csv_contents = []
            file = File.new(self.class.to_s.downcase + '.txt')
            @headers = file.gets.chomp.split(', ')

            file.each do |row|
                @row_contents = {}
                @headers.each_with_index do |x, i|
                    @row_contents[x] = row.chomp.split(',')[i]
                end
                @csv_contents.push(@row_contents)
            end
        end

        attr_accessor :headers, :csv_contents

        def initialize
            read
        end

        def each
            @csv_contents.each {|x|yield x}
        end

    end
end

class Hash
    def method_missing name, *args
        self[name.to_s]
    end
end

class RubyCsv
    include ActsAsCsv
    acts_as_csv
end

csv = RubyCsv.new
csv.each {|x| puts x.name}
