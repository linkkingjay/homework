import Data.List
import Data.Char
import qualified Data.Map as Map

import qualified Geometry.Sphere as Sphere
import qualified Geometry.Cuboid as Cuboid
import qualified Geometry.Cube as Cube

numUniques :: (Eq a) => [a] -> Int
numUniques = length . nub

wordNums :: String -> [(String, Int)]
wordNums = map (\ws -> (head ws, length ws)) . group . sort . words

isIn :: (Eq a) => [a] -> [a] -> Bool
needle `isIn` haystack = any (needle `isPrefixOf`) (tails haystack)

encode :: Int -> String -> String
encode offset msg = map (\c -> chr $ ord c + offset) msg

decode :: Int -> String -> String
decode shift msg = map (\c -> chr $ ord c - shift) msg

digitSum :: Int -> Int
digitSum = sum . map digitToInt . show
firstTo :: Int -> Maybe Int
firstTo n = find (\x -> digitSum x == n) [1..]

