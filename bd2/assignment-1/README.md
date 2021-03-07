# Atividade 1 - Banco de Dados II

## Descrição da Atividade

Adaptado da tarefa original.

> Crie uma tabela com a assinatura “employee (id int, name varchar(50), birthData int, salary float)”. 

> Insira 5 tuplas.

> A - Faça uma função capaz de aplicar um aumento de 10% em todos os funcionários;

> B - Faça uma função capaz de aplicar um aumento de X% nos funcionários com id maior que N. Importante: X e N serão passados por argumento;

> C - Faça uma função capaz de remover os funcionar com salário acima da média;

> D - Crie uma função que armazene o usuário corrente e a data atual ao adicionar uma nova tupla na tabela. Ex: insereDados( 10,’joao’,’xx’, ‘j’,’1’);

## Solução

Os comandos são executados com o usuário padrão `postgres`, utilizando o banco `task_one`. Todos os arquivos das tarefas irão mostrar a tabela (`SELECT * FROM employees`) antes e depois de alterá-la.

Para criar a tabela e populá-la excute o seguinte comando:

```
sudo -u postgres psql -f create-populate-table.sql
```

O esquema criado será:

```sql
employees (
    id INT PRIMARY KEY NOT NULL,
    name VARCHAR(50) NOT NULL,
    birth_date DATE NOT NULL,
    wage FLOAT NOT NULL
)
```

### Tarefa A

**Arquivo:** `task-a.sql`;
**Comando:** `sudo -u postgres psql -f task-a.sql`;


### Tarefa B

**Arquivo:** `task-b.sql`;
**Comando:** `sudo -u postgres psql -f task-b.sql`;

### Tarefa C

**Arquivo:** `task-c.sql`;
**Comando:** `sudo -u postgres psql -f task-c.sql`;

### Tarefa D

**Arquivo:** `task-d.sql`;
**Comando:** `sudo -u postgres psql -f task-d.sql`;