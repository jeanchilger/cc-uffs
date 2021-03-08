# Atividade 1 - Banco de Dados II

## Descrição da Atividade

Adaptado da tarefa original.

**Atividade 1**

Este trigger deve cuidar do armazenamento de lugares livre de  voos. O trigger é disparado quando ocorre uma inserção de um passageiro em um voo (Bookings). Os efeitos devem ser os seguintes: 
1.1 - Se o número de poltronas do voo é positiva (AvailableFlights), deve ser decrementado;
1.2 - Se não existir poltronas, a emissão do ticket falha;
1.3 - Se a emissão do ticket for ok, é necessário incrementar o preço da passagem em 50 reais para o próximo passageiro
OBS: para inserir uma linha no booking antes deve-se inserir o voo na tabela AvailableFlights

Esquema do banco: 

```
available_flights(
    num_flight int,
    date date,
    number_of_free_seats int,
    price float
)

bookings(
    num_flight int,
    date date,
    passenger int,
    price float
)
```

**Atividade 2**

A partir do banco de dados hw2 (que deve ser carregado do arquivo db.sql presente no moodle), construa gatilhos para as seguintes funcionalidades:
2.1 - se o produto em estoque chegar ao valor 0 (não tem mais o produto) então o mesmo deve ser removido das tabelas Product e Stock. Tem um esqueleto de exemplo. 

2.2 - Para evitar problemas com uso indevido de medicamentos controlados, crie uma tabela auxiliar de  controle para verificar quem está requisitando cada medicamento com a data e hora. 


## Solução A1

Os comandos são executados com o usuário padrão `postgres`, utilizando o banco `task_two`.

Para criar o banco excute o seguinte comando:

```
sudo -u postgres psql -f create-populate-table.sql
```
