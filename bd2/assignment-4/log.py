import re;
arquivo = open('teste03', 'r')
arquivolist = list(arquivo)     #cria uma lista com o .txt
REDO = []                       #salva quem vai ser feito REDO

#Variaveis p/ identificar se existe no .txt
checkvalue = re.compile(r'T[0-9]*,', re.IGNORECASE) #re.IGNORECASE -> ignorar se maiuscula ou minuscula
commit = re.compile(r'commit', re.IGNORECASE) #re.IGNORECASE -> ignorar se maiuscula ou minuscula
extracT = re.compile(r'(?!commit\b)(?!CKPT\b)(?!Start\b)\b\w+', re.IGNORECASE) #Ignora as palavras descritas e coloca as demais em uma lista com .findall
words = re.compile(r'\w+', re.IGNORECASE)   #Utilizado p/ pegar o valor das variaveis

valores = words.findall(arquivolist[0])
variaveis = {}
for i in range(0,len(valores),2): #Iniciar primeiros valores das variáveis (A B C...)
    variaveis[valores[i]]= valores[i+1]
del valores
print("", variaveis)
end = 0

for linha in reversed(arquivolist): #Verificar os casos e criar as listas de REDO
    if commit.search(linha):  #Procura commit
        REDO.append(extracT.findall(linha)[0])
    


print("Aplicado REDO:", REDO, "\n")

for j in range(1,len(arquivolist)-1,1):
    linha = arquivolist[j]    
    if (checkvalue.search(linha)):
        if(extracT.findall(linha)[0] in REDO):           
            variaveis[words.findall(linha)[1]] = words.findall(linha)[2]
   

print("Resultado:", variaveis)
arquivo.close()
