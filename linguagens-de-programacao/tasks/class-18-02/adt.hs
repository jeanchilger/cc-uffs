
data Cliente = Org String
             | Empresa Integer Integer String String
             | Individuo Pessoa Bool
             deriving Show

data Pessoa = Pessoa String String
            deriving Show