# digital_security


Implementar um programa em
C que aplique a cifra de César a uma mensagem

predefinida, utilizando um deslocamento informado
pelo usuário.





Descrição:



No código do programa, uma mensagem (string) deve
estar definida como uma

constante (hard coded). Exemplo:



char mensagem[] = "Hello, World!";





O programa deve:





1.    Exibir a mensagem original.





2.    Solicitar ao usuário
que digite um valor inteiro positivo diferente de zero que

representará o deslocamento na cifra.





3.    Gerar e exibir a mensagem
cifrada, aplicando o deslocamento a cada caractere alfabético, podem

padronizar a caixa do software em maiuscula ou minuscula para facilitar.


 


4 Caracteres não
alfabéticos (espaços, pontuações, etc.) devem permanecer

inalterados.



5 O deslocamento deve ser cíclico: ao
ultrapassar 'z' ou 'Z', retorna-se

ao início do alfabeto (ex.: 'z' com deslocamento 1
→ 'a').





Requisitos:





· Utilizar apenas conceitos básicos da linguagem C
(vetores de caracteres,

laços, condicionais, entrada/saída padrão).





·  O programa deve tratar corretamente o wrap-around (volta ao início/fim do alfabeto)
para qualquer valor de deslocamento.





· Não é permitido o uso de funções prontas de
criptografia; a lógica deve

ser implementada manualmente.





· Considere que o usuário pode fornecer valores
grandes  ex.: 100;

negativos; ou zero o programa deve tratar esses
casos.





· Teste seu programa com diferentes valores de
deslocamento para garantir

que o comportamento cíclico está correto.