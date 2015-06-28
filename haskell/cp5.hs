compareWithHundred :: Int -> Ordering
compareWithHundred x = compare 100 x

divideByTen :: (Floating a) => a -> a
divideByTen = (/10)

applyTwice :: (a -> a) -> a -> a
applyTwice f x = f (f x)

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys

flip' :: (a -> b -> c) -> (b -> a -> c)
flip' f y x = f x y

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = 
    let
        smallerOrEqual = filter (<=x) xs
        larger = filter (>x) xs
    in
        quicksort smallerOrEqual ++ [x] ++ quicksort larger

chain :: Integer -> [Integer]
chain 1 = [1]
chain n
    | even n = n:chain (n `div` 2)
    | odd n = n:chain(n * 3 + 1)

numLongChains :: Int
numLongChains = length (filter(\xs -> length xs > 15) (map chain [1..100]))

longNum :: [[Integer]]
longNum = filter isLong (map chain [1..100])
    where isLong xs = length xs > 50000

maxLength :: Int
maxLength = maximum (map length (map chain [1..100]))

fib :: Int -> Int
fib 0 = 1
fib 1 = 1
fib n = fib (n - 1) + fib (n - 2)
