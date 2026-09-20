**1\. Explique o conceito de colisão em funções hash criptográficas.**


R: Colisão é a possibilidade de duas entradas terem o mesmo valor do hash.Elas ocorrem quando existem mais entradas possíveis do que saídas possíveis,fazendo com que obrigatoriamente que duas entradas diferentes tenham a mesma saída.Por exemplo,mepeando  um arquivo de 1M e outro 1GB para um valor de hash 256 bits,vai inevitavelmente gerar sobreposição no valor de saída,e consequentemente colisão.Isso ocorre por que existem mais 

1) **escreva um cenário prático onde colisões podem comprometer a segurança de um sistema**  
   Hash são muito utilizados em em checksums para verificar a integridade durante uma transmissão de dados,uma colisão poderia comprometer a integridade da verificação,permitindo  arquivos maliciosos passarem de forma despercebida.A criptografia também pode sofrer com colisões,já que uma colisão nesses funções ( como por exemplo SHA-256 E SHA-3) pode permitir criminosos a forjarem assinaturas digitais.  
2) **pesquise como colisões foram exploradas em algoritmos como SHA-1**  
   O algoritmo SHA-1 foi introduzido em 1995,sendo oficialmente quebrado em  2017,22 anos depois.Contudo,antes mesmo da quebra do algoritmo,já haviam quebras teóricas do mesmo,na ordem de 2⁶⁹ operações.Então em 2017,foi possível criar dois arquivos diferentes com o mesmo SHA-1.Mas,não foi simples computacionalmente realizar a quebra,foi necessário uma quantidade de recursos bastante onerosa.  
   Cerca de nove quintilhões  de cálculos SHA1 no total,6.500 anos de computação de CPU para completar a primeira fase do ataque e 110 anos de GPU para completar a segunda fase.Contudo,somente em 2020 foi possível obter a quebra com dois prefixos diferentes para os arquivos em questão,que anteriormente não permitiam.Isso é algo ainda mais problemático,já que o atacante possui muito mais controle sobre o conteúdo que precede a parte da colisão  
 


3) **Discuta por que a resistência a colisões é crítica para assinaturas digitais.**

       A resistência a colisões,é a propriedade da criptografia de funções hash.Uma hash function têm resistência a colisões se é difícil encontrar duas entradas que resultem na mesma saída.Como  as assinaturas digitais não assinam a mensagem inteira diretamente,elas assinam o hash da mensagem,a resistência a colisões um requisito de segurança fundamental.Pois,se uma função hash não é resistente a colisões,um atacante consegue encontrar dois inputs diferentes x1 e x2,tais que H(x1)= H(x2).

**2\) Compare funções hash com algoritmos de criptografia reversível, como AES e RSA.**

1) **diferenças conceituais (função unidirecional ou bidirecional)**

	Hash é unidirecional por construção, não por dificuldade.SHA-256 recebe um input de tamanho arbitrário,1 byte ou 10 GB e devolve sempre 256 bits.A consequência é forte,não existe função inversa de hash, nem em teoria.

Cifra é bidirecional.Para uma chave k fixa, E\_k é uma permutação: cada plaintext mapeia para exatamente um ciphertext, e existe D\_k tal que D\_k(E\_k(m)) \= m. Nada se perde. O ciphertext de 10 KB contém os mesmos 10 KB de informação, apenas embaralhados.A segurança não vem de destruir dados,vem de tornar a permutação indistinguível de uma permutação aleatória para quem não conhece k.

hash é projeção; cifra é codificação com segredo.

2) **casos de uso distintos**  
   **Hash**:Armazenar senha,verificar integridade de arquivo/build/artefato,digest para assinatura digital  
   **Cifra**: dados sensíveis no banco (PII, CPF, endereço),token de API de terceiro armazenado,número de cartão  
3) **por que funções hash não podem ser utilizadas para comunicação secreta direta.**

O que define um canal secreto é uma assimetria: o destinatário legítimo lê, o adversário não. Essa assimetria vem do segredo compartilhado ou da chave privada.

Hash não tem chave. É uma função pública, determinística, irreversível para todos igualmente,inclusive para o destinatário pretendido

**3\) Descreva os principais tipos de ataques contra hashes de senha:**

1) **força bruta**  
   testar exaustivamente todas as combinações possíveis de caracteres, calculando o hash de cada uma e comparando com o alvo.  
     
   Como funciona: o atacante define um alfabeto e um comprimento máximo, e itera. a, b, aa, ab,e assim por diante. Não precisa de conhecimento prévio sobre a senha.Cresce exponencialmente com o tamanho. Com 95 caracteres imprimíveis  
2) **ataque de dicionário**

	Testa apenas senhas prováveis. Listas de   senhas reais vazadas, palavras de idioma, nomes, times, datas.O atacante usa wordlists (RockYou com \~14 milhões de entradas, listas do HaveIBeenPwned com bilhões) e aplica regras de mangling por cima.

3) **rainbow tables**

Ataque de pré-computação com troca tempo–espaço. O atacante calcula os hashes uma vez, armazena, e depois quebra qualquer hash daquele conjunto por simples lookup.

**4\) Explique como técnicas como e algoritmos como Argon2 reduzem a eficácia desses ataques. Inclua uma análise sobre custo computacional e tempo de processamento.**

**Salt**: Valor aleatório único por usuário, gerado no cadastro, armazenado em texto claro junto ao hash.Com salt, cada hash é um problema independente. O atacante só descobre o salt depois que o banco vazou, então não há nada para pré-computar. Atacar 1 milhão de contas custa 1 milhão de vezes mais que atacar uma.

**Argon2:** Aloca um bloco grande de memória (ex. 64 MB) e o preenche com dependências pseudoaleatórias entre posições — para calcular o bloco i, você precisa de blocos anteriores escolhidos de forma imprevisível. Não dá para recomputar sob demanda nem processar em streaming: a memória inteira precisa estar residente durante todo o cálculo.

**5\) Pesquise como sistemas distribuídos utilizam hashing para organização de dados.**  
:

1) **o conceito de hashing em estruturas como tabelas hash**

   Ideia: índice \= H(chave) mod tamanho. Transforma busca O(n) em O(1).Colisões: duas chaves no mesmo bucket. Resolve-se com encadeamento (lista/árvore no bucket ,o HashMap do Java vira árvore rubro-negra após 8 elementos) ou endereçamento aberto (procura o próximo slot livre).Quando elementos/buckets passam de \~0,75, a tabela dobra e reindexa tudo ,porque o módulo mudou.

2) **como ferramentas como Git utilizam hashes para versionamento e integridade**  
   Git é um content-addressable store: o endereço de um objeto é o hash do seu conteúdo.Contém blob que é o conteudo do arquivo,tree que contém nomes \+ hashes de blobs e subtrees,commit hash da tree raiz mais ash dos commits pais,autor e mensagem e por fim tag,hash do objeto apontado \+ assintatura.Cada objeto referencia filhos pelo hash, então o hash do pai depende de tudo abaixo dele  
3) **vantagens e limitações do uso de hash nesse contexto.**  
* **Sem coordenação**: Qualquer nó calcula o destino da chave sozinho, sem consultar um master  
* **Distribuição uniforme:** Sem conhecer os dados de antemão  
* **Integridade verificável** : Content addressing detecta corrupção automaticamente  
* **Deduplicação grátis** : Conteudo igual, endereço igual  
* **Escala horizontal previsível:**  Com consistent hashing




**6\) Explique o conceito de Proof of Work (PoW) no contexto do Bitcoin.**

1) **como o algoritmo SHA-256 é utilizado na mineração**  
   O minerador monta um cabeçalho de bloco de 80 bytes com seis campos,Version,Previous block hash,Merkle root,Timestamp,Bits,Nonce  
   Aplica-se então double SHA-256.O resultado é um número de 256 bits. A regra é: o hash precisa ser numericamente menor que o alvo (target).SHA-256 é resistente a pré-imagem  
   Não existe forma de calcular "qual entrada produz um hash abaixo de X",a  única estratégia é gerar candidatos e testar.   
   É o oposto de um problema com atalho matemático. A mineração é, funciona como uma loteria de força bruta.O campo Merkle root conecta o PoW ao conteúdo do bloco. Todas as transações são hasteadas em pares, subindo até uma raiz única de 32 bytes. Alterar qualquer transação muda a raiz, muda o cabeçalho, muda o hash, e invalida o PoW. O trabalho está criptograficamente amarrado ao conteúdo exato.  
2) **o papel do “nonce” no processo**  
   O nonce é o único campo que o minerador pode variar livremente e barato.Os outros são fixos por contexto: o hash anterior vem da cadeia, a Merkle root vem das transações escolhidas, o timestamp tem tolerância limitada.Cada valor de nonce produz um resultado que é, para todos os efeitos, um sorteio independente e uniforme.  
3) **por que o custo computacional elevado contribui para a segurança da rede.**  
   Cada bloco contém o hash do anterior. Alterar uma transação no bloco N invalida o PoW do bloco N e o de todos os subsequentes, porque o campo previous block hash de cada um deixa de bater.  
   Para o ataque funcionar, o adversário precisa refazer todo o trabalho de N até a ponta da cadeia, e ainda superar a rede honesta, que continua estendendo a cadeia legítima enquanto ele minera.  
   Se um atacante controla menos de 50% do hashrate, a cadeia honesta cresce mais rápido que a dele e ele nunca alcança, a probabilidade de sucesso tende a zero com o tempo.PoW protege ordenação e histórico, não propriedade.  
   

