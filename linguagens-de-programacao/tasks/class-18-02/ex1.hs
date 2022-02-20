calcKiloWatts :: Double -> Double -> Double
calcKiloWatts wage kwAmount = kwAmount * t * discountPercent
    where 
        discountPercent = (1 - 0.15)
        t = wage / 5

fourTimeDouble :: Integer -> Integer
fourTimeDouble x = let y = 2 * x
                    in 4 * y