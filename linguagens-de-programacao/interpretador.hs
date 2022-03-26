data Expr = BTrue
    | BFalse
    | Num Int
    | Add Expr Expr
    | And Expr Expr
    | If Expr Expr Expr
    deriving Show


step :: Expr -> Maybe Expr

--------------------------------------------------------------------
-- EXPRESSIONS
--------------------------------------------------------------------

-- ADD
step (Add (Num n1) (Num n2)) = Just (Num (n1 + n2))
step (Add (Num n1) e2) = case (step e2) of
    Just e2' -> Just (Add (Num n1) e2')
    Nothing -> Nothing
step (Add e1 e2) = case (step e1) of
    Just e1' -> Just (Add e1' e2)
    Nothing -> Nothing

-- AND
step (And BTrue e2) = Just e2
step (And BFalse _) = Just BFalse
step (And e1 e2) = case (step e1) of
    Just e1' -> Just (And e1' e2)
    Nothing -> Nothing

-- IF
step (If BTrue e2 e3) = Just e2
step (If BFalse e2 e3) = Just e3
step (If e1 e2 e3) = case (step e1) of
    Just e1' -> Just (If e1' e2 e3)
    Nothing -> Nothing

step e = Just e


--------------------------------------------------------------------
-- TYPE SYSTEM
--------------------------------------------------------------------

data Ty = TBool
    | TNum
    deriving Show


typeof :: Expr -> Maybe Ty
typeof BTrue = Just TBool
typeof BFalse = Just TBool
typeof (Num _) = Just TNum
typeof (Add e1 e2) = case (typeof e1, typeof e2) of 
        (Just TNum, Just TNum) -> Just TNum
        _ -> Nothing
typeof (And e1 e2) = case (typeof e1, typeof e2) of 
        (Just TBool, Just TBool) -> Just TBool
        _ -> Nothing
    
