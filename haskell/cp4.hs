maximum' :: (Ord a) => [a] -> a
maximum' [] = error "Maximum of an empty list"
maximum' [x] = x
maximum' (x:xs) = max x (maximum' xs)

replicate' :: Int -> a -> [a]
replicate' n x
    | n <= 0 = []
    | otherwise = x:replicate' (n - 1) x

take' :: (Ord a) => Int -> [a] -> [a]
take' n _
    | n <= 0 = []
take' _ []   = []
take' n (x:xs) = x : take' (n - 1) xs

qsort :: (Ord a) => [a] -> [a]
qsort [] = []
qsort (x:xs) = 
    let smallerOrEqual = [a | a <- xs, a <= x]
        larger = [a | a <- xs, a > x]
    in
        (qsort smallerOrEqual) ++ [x] ++ (qsort larger)
