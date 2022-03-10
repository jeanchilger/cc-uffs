-------------------------------------------------------
-- 1
-------------------------------------------------------
salarioLiquido :: Double -> Double
salarioLiquido2 :: Double -> Double

salarioLiquido sal = let acc = sal * 0.10
                         dec = sal * 0.07
                      in sal + acc - dec

salarioLiquido2 sal = sal + acc - dec
    where
        acc = sal * 0.10
        dec = sal * 0.07

-------------------------------------------------------
-- 2
-------------------------------------------------------
isTriagle :: Double -> Double -> Double -> Bool
isTriagle a b c = mid + low > high
    where
        high = max a (max b c)
        low = min a (min b c)
        mid = a + b + c - high - low

-------------------------------------------------------
-- 3
-------------------------------------------------------
weightedAvg :: Double -> Double -> Double -> Char
weightedAvg a b c = concept
    where
        avg = (a * 2 + b * 3 + c * 5) / (2 + 3 + 5)
        concept
          | avg >= 8 && avg <= 10 = 'A'
          | avg >= 7 && avg < 8 = 'B'
          | avg >= 6 && avg < 7 = 'C'
          | avg >= 5 && avg < 6 = 'D'
          | avg >= 0 && avg < 5 = 'E'
          | otherwise = 'N'

-------------------------------------------------------
-- 4
-------------------------------------------------------
framePrice :: Integer -> String -> Double
framePrice nPeople weekDay = basePrice + acc
    where
        basePrice
          | nPeople == 1 = 100
          | nPeople == 2 = 130
          | nPeople == 3 = 150
          | nPeople == 4 = 165
          | nPeople == 5 = 175
          | nPeople == 6 = 180
          | nPeople >= 7 = 185
          | otherwise = 0

        acc = if weekDay `elem` ["sábado", "domingo"]
            then basePrice * 0.2
            else basePrice * 0

-------------------------------------------------------
-- 5
-------------------------------------------------------
prod3 :: Double -> Double -> Double -> Double
prod3 a b c = a * b * c

-------------------------------------------------------
-- 5
-------------------------------------------------------
idealHeight :: Double -> Char -> Double
idealHeight height sex = if sex == 'm'
    then 72.7 * height - 58
    else 62.1 * height - 44.7