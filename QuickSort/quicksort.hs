partition :: (a -> Bool) -> [a] -> ([a], [a])
partition p xs = (filter p xs, filter (not . p) xs) 

qsort :: Ord a => [a] -> [a]
qsort []     = []
qsort (x:xs) = 
  let (lower, upper) = partition (<x) xs
  in qsort lower ++ [x] ++ qsort upper 
  
main :: IO ()
main = 
  print $ qsort [5,4,62,4,7,1,3]
