import Data.Text.Internal.Fusion.Common (findBy)
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
-- 6
-------------------------------------------------------
idealHeight :: Double -> Char -> Double
idealHeight height sex = if sex == 'm'
    then 72.7 * height - 58
    else 62.1 * height - 44.7

-------------------------------------------------------
-- 21
-------------------------------------------------------
and' :: Bool -> Bool -> Bool
and' False _ = False
and' _ False = False
and' True True = True

-------------------------------------------------------
-- 24
-------------------------------------------------------
findByName :: [(String, String)] -> String -> [(String, String)]
findByName list name = filter (\tuple -> fst tuple == name) list


-------------------------------------------------------
data Cliente =
    OrgGov String
    | Empresa String Integer String String
    | Individuo Pessoa' Bool
    deriving Show

data Pessoa' =
    Pessoa' String String
    deriving Show

getNameCliente :: Cliente -> String
getNameCliente (OrgGov name) = name
getNameCliente (Empresa name _ _ _) = name
getNameCliente (Individuo (Pessoa' name _) _) = name
-------------------------------------------------------
-------------------------------------------------------
fat :: Integer -> Integer
fat n
    | n == 0 = 1
    | n > 0 = n * fat (n - 1)
-------------------------------------------------------
-------------------------------------------------------
divide :: Integer -> Integer -> Integer
divide a b
    | a >= b = 1 + divide (a - b) b
    | a < b = 0
-------------------------------------------------------
-------------------------------------------------------
len :: [Integer] -> Integer
len list
    | null list = 0
    | otherwise = 1 + len (tail list)

len' :: [Integer] -> Integer
len' [] = 0
len' (x:xs) = 1 + len' xs

get :: Integer -> [Integer] -> Integer
get 0 (x:xs) = x
get nth (x:xs) = get (nth - 1) xs

cat :: [Integer] -> [Integer] -> [Integer]
cat xs b = foldr (:) b xs
-------------------------------------------------------
-------------------------------------------------------
data Pessoa = Pessoa String String Integer
    deriving Show

data Estudante =
    EstudanteMedio Pessoa [Double]
    | EstudanteSuperior Pessoa Integer [Double]
    | EstudanteMestrado Pessoa String [Double]
    deriving Show

--

getNome :: Estudante -> String
getNome (EstudanteMedio (Pessoa nome sobrenome _) _) = nome ++ " " ++ sobrenome
getNome (EstudanteSuperior (Pessoa nome sobrenome _) _ _) = nome ++ " " ++ sobrenome
getNome (EstudanteMestrado (Pessoa nome sobrenome _) _ _) = nome ++ " " ++ sobrenome

getTemaDissertacao :: Estudante -> String
getTemaDissertacao (EstudanteMestrado _ tema _) = tema
getTemaDissertacao (EstudanteMedio _ _) = ""
getTemaDissertacao (EstudanteSuperior {}) = ""

getNotas :: Estudante -> [Double]
getNotas (EstudanteMedio _ notas) = notas
getNotas (EstudanteSuperior _ _ notas) = notas
getNotas (EstudanteMestrado _ _ notas) = notas

--
data Data = Data Integer Integer Integer
    deriving Show

addDay :: Data -> Data
addDay (Data d m y)
    | d + 1 > 30 = addDay (Data 0 (m + 1) y)
    | m > 12 = addDay (Data d 1 (y + 1))
    | otherwise = Data (d + 1) m y

-------------------------------------------------------
-------------------------------------------------------

