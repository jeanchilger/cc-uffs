#!/bin/bash

irDiretorio(){
    cd testetset
}

irDiretorio 2>error.txt #erros da funcao vai pra error.txt e nao pra saida
#irDiretorio 0>arg.txt #argumentos vai pra arg.txt e nao pra func
#irDiretorio 1>ret.txt #retorno vai pra ret.txt e nao pra saida
