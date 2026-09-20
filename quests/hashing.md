# Questões: Hashing

> [!info] Como usar
> Escreva sua resposta no espaço **Sua resposta**. O gabarito fica **oculto**: clique em **Gabarito** para expandir **só depois de responder**. Depois peça ao agente para corrigir.
> Resumo de apoio: [[02-hashing]]

---

## Questão 1 (Discursiva)
Defina **função hash** e explique a diferença entre uma função hash e um **código de autenticação de mensagem (MAC)**.

**Sua resposta:**


> [!success]- Gabarito
> Uma função hash recebe uma mensagem M de **tamanho variável** e produz um **resumo (digest) de tamanho fixo** H(M), uma "impressão digital" dos dados. Diferente do MAC, **a função hash não recebe chave secreta**. O MAC é calculado como F(K_AB, M), com uma chave compartilhada entre as partes.
> 📚 *Fonte: [STA] §2.2*

---

## Questão 2 (Discursiva)
Liste as **seis propriedades** que Stallings exige de uma função hash segura e diga o que é um hash **fraco** e um hash **forte**.

**Sua resposta:**


> [!success]- Gabarito
> 1. Pode ser aplicada a blocos de **qualquer tamanho**.
> 2. Produz saída de **tamanho fixo**.
> 3. H(x) é **fácil de calcular**.
> 4. **Resistência à pré-imagem (unidirecional):** dado h, é computacionalmente inviável achar x com H(x) = h.
> 5. **Resistência à 2ª pré-imagem (resistência fraca a colisões):** dado x, é inviável achar y ≠ x com H(y) = H(x).
> 6. **Resistência a colisões (resistência forte):** é inviável achar qualquer par (x, y) com H(x) = H(y).
>
> **Hash fraco:** satisfaz 1 a 5. **Hash forte:** satisfaz também a 6.
> 📚 *Fonte: [STA] §2.2*

---

## Questão 3 (Discursiva, base na Atividade 03)
Explique o conceito de **colisão** em funções hash. Por que colisões **necessariamente existem**?

**Sua resposta:**


> [!success]- Gabarito
> Colisão é um par de entradas diferentes x ≠ x' com **o mesmo hash**, h(x) = h(x'). Elas **sempre existem** pelo **princípio da casa dos pombos**: há mais entradas possíveis do que saídas (a saída tem tamanho fixo). Ex. de Bishop: um hash de 3 bits tem 2³ = 8 valores; para 2⁵ = 32 arquivos de 5 bits, **pelo menos 4 arquivos** compartilham o mesmo hash. Por isso a segurança exige que seja **computacionalmente inviável encontrar** colisões, não que elas não existam.
> 📚 *Fonte: [BIS] §10.4 · [AT03] Q1*

---

## Questão 4 (Múltipla escolha)
Para um hash de **n bits**, o esforço de força bruta para encontrar uma **colisão** é da ordem de:

a) 2ⁿ
b) n²
c) 2ⁿᐟ²
d) 2²ⁿ
e) n/2

**Sua resposta:**


> [!success]- Gabarito
> **c) 2ⁿᐟ²**, pelo **paradoxo do aniversário**: com cerca de √N amostras já se espera uma coincidência (23 alunos bastam para passar de 50% de chance de aniversários iguais). Pré-imagem e 2ª pré-imagem custam **2ⁿ**.
> 📚 *Fonte: [STA] §2.2 · [AND] §5.3.1.2*

---

## Questão 5 (Discursiva, base na Atividade 03)
Discuta por que a **resistência a colisões** é crítica para **assinaturas digitais**. Use o exemplo do vale (IOU) de Stallings.

**Sua resposta:**


> [!success]- Gabarito
> A assinatura digital **não assina a mensagem inteira, assina o hash** dela. Se o hash não for resistente a colisões, o atacante acha duas mensagens x1 ≠ x2 com H(x1) = H(x2), e a assinatura de uma vale para a outra.
> **Exemplo do vale:** Alice aceita assinar um vale de valor pequeno enviado por Bob. Bob encontrou duas mensagens com o mesmo hash, uma com valor pequeno e outra com valor grande. Alice assina a primeira, e Bob apresenta a segunda como autêntica. Por isso assinaturas exigem um **hash forte**.
> 📚 *Fonte: [STA] §2.2 · [AT03] Q1.3*

---

## Questão 6 (Discursiva, base na Atividade 03)
Compare funções hash com algoritmos de criptografia reversível (AES, RSA) quanto à **direção**, ao **uso de chave** e aos **casos de uso**. Por que o hash **não pode** ser usado para comunicação secreta?

**Sua resposta:**


> [!success]- Gabarito
> - **Hash:** unidirecional, **sem chave**, saída de tamanho fixo (perde informação). Usos: armazenar senhas, verificar integridade, digest para assinatura.
> - **Cifra:** bidirecional; para uma chave k fixa existe D_k com **D_k(E_k(m)) = m**, e nada se perde. Usos: dados que precisam ser lidos de volta (CPF, cartão, tokens de terceiros).
> - **Comunicação secreta** exige **assimetria** entre o destinatário legítimo (lê) e o adversário (não lê), e essa assimetria vem de um **segredo (chave)**. O hash é **público, determinístico e irreversível para todos, inclusive para o destinatário**. Bishop confirma que hashes sem chave "não podem ser usados para esconder informação".
> 📚 *Fonte: [AT03] Q2 · [BIS] §10.2, §10.4.1*

---

## Questão 7 (Múltipla escolha)
Sobre o **salt** no armazenamento de senhas, é **incorreto** afirmar:

a) Faz com que dois usuários com a mesma senha tenham hashes diferentes.
b) Aumenta a dificuldade de ataques de dicionário offline.
c) Deve ser mantido secreto e nunca armazenado junto ao hash.
d) Dificulta descobrir se a mesma pessoa usou a mesma senha em sistemas diferentes.
e) Com salt de b bits, o número de possibilidades para o atacante cresce por um fator de 2ᵇ.

**Sua resposta:**


> [!success]- Gabarito
> **c)** está incorreta. O salt é armazenado **em texto claro** junto do hash no arquivo de senhas. O sistema precisa dele para recalcular o hash no login. As demais alternativas são as três funções do salt descritas por Stallings.
> 📚 *Fonte: [STA] §3.2*

---

## Questão 8 (Discursiva, base na Atividade 03)
Descreva os três principais tipos de ataque contra hashes de senha: **força bruta**, **dicionário** e **rainbow tables**.

**Sua resposta:**


> [!success]- Gabarito
> - **Força bruta:** testa **exaustivamente todas as combinações** de um alfabeto até um tamanho máximo, calculando o hash de cada uma e comparando. Cresce exponencialmente com o tamanho [AT03].
> - **Dicionário:** adivinhação por tentativa e erro repetida, usando uma lista ("dicionário") de senhas prováveis, geralmente em ordem decrescente de probabilidade [BIS Def. 13-7], com variações (inverter, trocar "o" por "0", maiúsculas) [STA]. Pode ser **offline** (com o arquivo de hashes) ou **online** (pela tela de login) [BIS].
> - **Rainbow table:** **pré-computação** que troca espaço por tempo: calcula os hashes de senhas prováveis (para cada salt) e depois só consulta. Ex.: 1,4 GB quebrou 99,9% dos hashes alfanuméricos do Windows em 13,8 s. **Contramedida:** salt grande e hash longo [STA].
> 📚 *Fonte: [STA] §3.2 · [BIS] §13.4 · [AT03] Q3*

---

## Questão 9 (Discursiva, base na Atividade 03)
Explique como o **salt** e algoritmos lentos como **bcrypt/Argon2** reduzem a eficácia dos ataques. Considere custo computacional e tempo.

**Sua resposta:**


> [!success]- Gabarito
> - **Salt:** valor aleatório por usuário, guardado em claro. Cada hash vira um **problema independente**: o atacante só conhece o salt após o vazamento, então **não há o que pré-computar** (rainbow tables perdem o efeito). Testar uma palavra contra n usuários exige **n cálculos**, então o salt aumenta o trabalho **na ordem do número de usuários** [BIS][AT03].
> - **Hash lento:** o algoritmo é "projetado para ser lento" [STA]. O **bcrypt** tem uma **variável de custo** configurável (mais custo, mais tempo por hash) [STA]. O **Argon2** também exige muita **memória** residente (ex.: 64 MB) com dependências pseudoaleatórias, o que encarece ataques paralelos em hardware [AT03].
> - **Efeito:** para o usuário legítimo, um hash lento custa milissegundos num login; para o atacante, que testa bilhões de palpites, o custo total explode.
> 📚 *Fonte: [STA] §3.2 · [BIS] §13.4.1 · [AT03] Q4*

---

## Questão 10 (Discursiva)
Explique o que é o **HMAC** e por que ele surgiu. De que depende sua segurança?

**Sua resposta:**


> [!success]- Gabarito
> HMAC é o termo genérico para um algoritmo que usa uma **função hash sem chave + uma chave criptográfica** para produzir um **hash com chave (MAC)**: HMAC-h(k, m) = h(k' ⊕ opad ‖ h(k' ⊕ ipad ‖ m)). Ele surgiu porque muitos países restringiam a exportação de software de cifragem, mas **não** de hash sem chave (que não esconde informação); o HMAC permite construir um hash com chave a partir de um hash sem chave. Sua **força depende da força do hash h** usado.
> 📚 *Fonte: [BIS] §10.4.1 · [AND] §5.6.2 (FIPS 198-1)*

---

## Questão 11 (Múltipla escolha)
Assinale a alternativa **correta** sobre algoritmos de hash:

a) SHA-1 produz hash de 256 bits e nunca teve colisão publicada.
b) MD5 produz hash de 128 bits e já teve colisões encontradas.
c) SHA-3 tem a mesma estrutura interna do SHA-2.
d) SHA-2 foi publicado em 1993 como FIPS 180.
e) Um hash de 128 bits é considerado adequado contra colisões hoje.

**Sua resposta:**


> [!success]- Gabarito
> **b)** O MD5 tem **128 bits** e colisões foram encontradas em **2004** (Wang e colegas).
> - a) O SHA-1 tem **160 bits** e teve colisão publicada em **2017**.
> - c) O SHA-3 (Keccak) tem estrutura **muito diferente** do SHA-2.
> - d) O FIPS 180 (1993) é o SHA original; o SHA-2 é de **2002** (FIPS 180-2).
> - e) 128 bits é **inadequado** (uma máquina de US$ 10 milhões acharia colisão de MD5 em 24 dias).
> 📚 *Fonte: [STA] §2.2 · [AND] §5.6.1*

---

## Questão 12 (Discursiva)
Cite **duas aplicações** de hash além da autenticação de mensagens e diga qual propriedade cada uma exige.

**Sua resposta:**


> [!success]- Gabarito
> Quaisquer duas, por exemplo:
> - **Armazenamento de senhas:** guarda-se o hash, não a senha. Exige **resistência à pré-imagem** (e talvez à 2ª pré-imagem) [STA].
> - **Detecção de intrusão:** guarda-se H(F) de cada arquivo em mídia protegida e depois recalcula para detectar alterações. Exige **resistência à 2ª pré-imagem** [STA].
> - **Assinatura digital:** assina-se o hash. Exige **resistência a colisões** [STA].
> - **Compromisso/carimbo de tempo:** publica-se o hash de um documento para provar autoria depois [AND].
> - **Atualização de chave:** K(i+1) = h(K(i)) garante segurança para trás pela unidirecionalidade [AND].
> 📚 *Fonte: [STA] §2.2 · [AND] §5.6.2*

---

## Questão 13 (Discursiva)
Por que um checksum sem chave **não protege** contra um adversário ativo? Como resolver?

**Sua resposta:**


> [!success]- Gabarito
> Porque o adversário pode **alterar a mensagem e recalcular o checksum** para corresponder à mensagem alterada, e o receptor não percebe. O hash sozinho só detecta **alterações acidentais** (como um *frame check sequence*). **Soluções:** usar um segredo, com **MAC/HMAC** (hash com chave), **cifrar o hash** com chave simétrica, ou **assinar o hash** com a chave privada (assinatura digital).
> 📚 *Fonte: [BIS] §10.4 · [STA] §2.2 (Fig. 2.5)*

---

## Questão 14 (Discursiva)
Diferencie **ataque de dicionário offline** e **online** (Bishop) e cite a contramedida clássica para o ataque a uma conta específica.

**Sua resposta:**


> [!success]- Gabarito
> - **Offline:** o atacante conhece as funções de complementação F e a informação complementar C (ex.: obteve o arquivo de senhas). Ele calcula f(g) para cada palpite g e compara, **na própria máquina**, sem interagir com o sistema.
> - **Online:** F ou C não estão disponíveis, então o atacante usa a **função de autenticação** (login) com cada palpite.
> - **Contramedida para ataque a conta específica:** **bloqueio de conta** após algumas tentativas falhas (tipicamente **no máximo cinco**).
> 📚 *Fonte: [BIS] §13.4.1, §13.4.2 · [STA] §3.2*

---

## Questão 15 (Discursiva, base na Atividade 03)
Explique como o **SHA-256** é usado no **Proof of Work** do Bitcoin e qual o papel do **nonce**.

**Sua resposta:**


> [!success]- Gabarito
> O minerador monta um cabeçalho de bloco de 80 bytes (versão, hash do bloco anterior, raiz de Merkle, timestamp, bits, **nonce**) e aplica **double SHA-256**. O resultado precisa ser **numericamente menor que um alvo**. Como o SHA-256 é **resistente à pré-imagem**, não há atalho para achar uma entrada com hash abaixo do alvo: a única estratégia é **testar candidatos** (força bruta). O **nonce** é o campo que o minerador pode variar livremente e barato; cada valor funciona como um **sorteio independente**. Como cada bloco contém o hash do anterior, alterar um bloco exige **refazer o trabalho** de todos os seguintes.
> 📚 *Fonte: [AT03] Q6 · [AND] §5.6.2 (blockchain como árvore de Merkle)*
