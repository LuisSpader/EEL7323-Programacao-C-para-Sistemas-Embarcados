06/02/2022
O que fiz:
Alterei o nó para possuir
ID
temperatura
se a alteração foi automatica ou não (bool)
ponteiro para próximo nodo

O que devo fazer:
Criação Fila no embarcado:
Classe nó deve automaticamente gerar/pegar todos os dados internos (temperatura, ID, automatico_ou_botao, data_hora): - ID: não sei como será gerado ou pego este valor - Temperatura + automatico_ou_botao: - classes de leitura da temperatura: classe Sensor_Temperatura_DHT11 - Classe botões >> Node::Node(int new_ID=??, int new_temp = (List obj.getLastTemp + 1), bool new_automatico_ou_botao = 0, Node *nxt) ---> assim a temperatura_atual = (temp_antiga + 1) - Criar função 'getLastTemp()' na classe 'List' - Classe Tensorflow >> Node::Node(int new_ID=??, int new_temp =tf.temp, bool new_automatico_ou_botao = 1, Node *nxt)
Recebimento fila no computador:

---

PERGUNTAS PARA SE FAZER AO PROFESSOR
2- Como funcionará o ID?
como será gerado?
como faremos a 'troca' no controle, para alterar a temperatura de 1 dispositivo e não do outro
3- Tensorflow
a - já armazena variável de temperatura atual?
b - já possui sistema de controle?
4- Como fazer a classe 'Node' pegar as variáveis de um objeto do tipo ClockCalendar que seria único e que estaria no 'main' ou em outra classe. Ex:
Classe controle{
ClockCalendar data_horario;
friend class Node;
}
Classe Node{ string Node::friend_getClockCalendar() #acessa horario}

==================================================
XX/02/2022
O que fiz:
O que devo fazer:
==================================================
Log de operações
a) Ler ID e registrar com o log
b) Data e hora (Clock Calendar)
? Como será sincronizada a hora? de onde pegaríamos a informação
Poderia haver um 'setClock' manual

==================================================
Classe controle
a) irá ter objeto ClockCalendar único -> dentro do OS do controlador em alguma classe... - Nó terá construtor que ao ser inicializada acessará as variáveis de ClockCalendar e atribuirá à apena 1 variável do tipo 'string' com todas as informações necessárias do ClockCalendar (do nó). Assim cada nó terá suas variáveis internas de hora,minuto,segundo, data .. - Para o nó acessar os métodos ele será 'friend' de ClockCalendar, assim cada vez que for criado um objeto do tipo nó, NÃO SERÁ CRIADO NENHUM OBJETO NOVO DE ClockCalendar (o que aconteceria caso fosse utilizada herança ou polimorfismo)

    ST placas com RTC Real Time Clock (sistema de relógio)

==================================================
[Markdown Tutorial.](https://www.markdowntutorial.com/lesson/3/)

# Nó:

- temp externa fixa - OK
- nova temperatura: ? - OK
  Fila:
- função Liga (nó com temp específica) - OK
- função Desliga (nó com temp específica) - OK
- função para pegar lista inteira e apagá-la - OK (desconstrutor)
- função tempo ligado

# Log: - OK

- listar todos os eventos ocorridos em um determinado intervalo de datas; -> PROBLEMA: intervalo hora está paralelo ao intervalo data (devem agir juntos) - OK

- obter o tempo total (em horas e minutos) que o sistema manteve o ar-condicionado alimentado, em um determinado intervalo de datas. - OK \*_operador (-, +) -> data_
  Data1 = 01/01/2020; Hora1 = 10:00:00 -> Início
  Data2 = 02/01/2020; Hora2 = 08:00:00 -> Fim
  <!-- Intervalo_horas = ((Data2 - Data1) * 24) + (Hora2 - Hora1) =
  \_\_[(ano2 - ano1)x365 + (mes2 - mes1)x30 + (dia2 - dia1)]*24\_\_ + (Hora2 - Hora1) -->
  - fazer interface -> inserir logs manualmente -> opção Node iniciar com hora como parametro

# Serial:

# Embarcado:
- Botões temperatura


# Interface PC:

- inserção de 'nós' -> 'List' - OK
- solicitação do log: pega de 'List'
- Serial UART recebimento: como será feito o teste??

# ClockCalendar:

- Sobrecarga de operadores:
  - Data1 > data2 & ... - OK
  - Hora1 > hora2 & ... - OK

# Documentação:
