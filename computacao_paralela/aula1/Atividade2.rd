# Resumo — Criação de N processos com fork() em C
##1️⃣ Objetivo

Criar N processos filhos a partir de um processo pai usando a chamada de sistema fork().

##2️⃣ Como fork() funciona

fork() cria uma cópia do processo atual.

Depois da chamada existem dois processos executando o mesmo código:

Processo	Valor retornado por fork()
Pai	PID do filho criado
Filho	0

Exemplo:

pid_t pid = fork();

if(pid == 0){
    // código do filho
}else{
    // código do pai
}
## 3️⃣ Criando vários filhos

Cada chamada de fork() cria apenas um filho.

Para criar N filhos, usamos um loop:

for(int i = 0; i < n; i++){
    fork();
}

Assim, cada iteração cria um novo processo filho.

## 4️⃣ Evitando que filhos criem mais filhos

Após executar seu código, o filho deve terminar:

return 0;

Se isso não for feito, o filho continua executando o loop e pode criar novos processos, gerando uma explosão de processos.

## 5️⃣ Esperando os filhos terminarem (wait())

Quando um filho termina, ele vira um processo zumbi até que o pai execute wait().

Para limpar esses processos da tabela do sistema, o pai deve chamar:

wait(NULL);
## 6️⃣ Por que o pai usa um loop separado para wait()

Se foram criados N filhos, o pai precisa chamar wait() N vezes, porque:

Cada wait() coleta o término de um filho

Se existirem vários filhos terminados, cada um precisa ser tratado.

Por isso usamos:

for(int i = 0; i < n; i++){
    wait(NULL);
}

Esse loop garante que todos os filhos sejam aguardados e removidos da tabela de processos.

## 7️⃣ Por que não colocar wait() no loop de criação

Se wait() estiver dentro do loop que cria os filhos:

for(int i = 0; i < n; i++){
    fork();
    wait(NULL);
}

O pai irá:

Criar um filho

Esperar ele terminar

Criar o próximo

Isso faz com que os processos executem um por vez (sequencialmente).

Separar os loops permite que todos os filhos executem concorrentemente.

## 8️⃣ Estrutura típica do programa

Ler quantos filhos criar.

Criar os filhos usando fork() em um loop.

Cada filho executa seu código e termina.

O pai espera todos os filhos usando wait().

## 9️⃣ Regras importantes

 1 chamada de fork() → cria 1 filho

 N filhos → N chamadas de fork()

 N filhos → N chamadas de wait()