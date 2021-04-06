_ = gets.to_i
ary = gets.split.map(&:to_i)

max = ary.max
sum_of_the_others = ary.sum - max

puts max < sum_of_the_others ? 'Yes' : 'No'