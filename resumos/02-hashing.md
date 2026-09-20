# Hashing: funções hash criptográficas

> Fontes: [STA] §2.2, §3.2 · [BIS] §10.4, §13.2, §13.4 · [AND] §5.3.1.2, §5.6 · [AT03] (todas as questões)

## 1. Definição

- Uma **função hash** recebe uma mensagem **M de tamanho variável** e produz um **resumo (*message digest*) de tamanho fixo H(M)** [STA §2.2].
- Normalmente a mensagem recebe **padding** até um múltiplo de um tamanho fixo (ex.: 1024 bits), e o padding **inclui o tamanho original da mensagem**. Isso dificulta que o atacante produza outra mensagem com o mesmo hash [STA].
- **Propósito:** gerar uma **"impressão digital" (*fingerprint*)** de um arquivo, mensagem ou bloco de dados [STA].
- Bishop chama de **função de checksum criptográfico** (também *strong hash function* ou *strong one-way function*): gera um conjunto menor de *k* bits a partir de *n* bits originais. O resultado é o **checksum** ou **message digest** [BIS §10.4].
- **Diferente do MAC, a função hash NÃO recebe chave secreta** [STA].
- Bishop distingue ([BIS] Def. 10-6):
  - **Checksum criptográfico com chave (*keyed*)**: exige uma chave no cálculo (ex.: HMAC).
  - **Sem chave (*keyless*)**: MD4, MD5, RIPEMD-160, HAVAL, família SHA.

---

## 2. Propriedades exigidas ([STA] §2.2)

| # | Propriedade | Significado |
|---|---|---|
| 1 | Entrada de qualquer tamanho | H se aplica a um bloco de dados de **qualquer tamanho**. |
| 2 | Saída de tamanho fixo | H produz saída de **comprimento fixo**. |
| 3 | Eficiência | H(x) é **fácil de calcular** para qualquer x (viável em hardware e software). |
| 4 | **Resistência à pré-imagem (unidirecional / *one-way*)** | Dado um código h, é **computacionalmente inviável** achar x tal que H(x) = h. |
| 5 | **Resistência à segunda pré-imagem (resistência *fraca* a colisões)** | Dado um x, é **computacionalmente inviável** achar y ≠ x com H(y) = H(x). |
| 6 | **Resistência a colisões (resistência *forte* a colisões)** | É **computacionalmente inviável** achar **qualquer par** (x, y) com H(x) = H(y). |

- As propriedades **1 a 3** são requisitos para a **aplicação prática** do hash na autenticação de mensagens.
- Uma função que satisfaz **1 a 5** é um **hash fraco**. Se também satisfaz a **6**, é um **hash forte** [STA].
- **Por que a 4 importa:** no esquema com segredo, MD = H(K‖M‖K). Se o hash for inversível, o atacante que intercepta M e MD calcula H⁻¹(MD) = K‖M‖K e extrai **K** [STA].
- **Por que a 5 importa:** impede que, dada uma mensagem com hash cifrado, se gere **outra mensagem com o mesmo hash** (falsificação) [STA].
- **Por que a 6 importa (exemplo do vale/IOU):** Bob acha duas mensagens com o mesmo hash, uma com valor pequeno e outra com valor grande. Alice assina a pequena e Bob apresenta a grande como autêntica [STA]. A **assinatura digital assina o hash**, então a resistência a colisões é **requisito fundamental** para assinaturas [AT03 Q1.3].

**Definição de Bishop (Def. 10-4)**: h: A → B é checksum criptográfico se
1. h(x) é fácil de calcular;
2. dado y ∈ B, é inviável achar x com h(x) = y;
3. é inviável achar x ≠ x' com h(x) = h(x'). **Esse par é uma colisão.**
   - 3'. Variante: dado **um x específico**, é inviável achar x' ≠ x com h(x) = h(x').
   - **Achar x' que atenda a 3' é bem mais difícil do que achar um par qualquer que atenda a 3.**

---

## 3. Por que colisões SEMPRE existem

- **Princípio da casa dos pombos** ([BIS] Def. 10-5): se há *n* casas para *n+1* pombos, pelo menos uma casa tem dois pombos.
- Ex. de Bishop: hash de **3 bits** (2³ = 8 valores) para arquivos de **5 bits** (2⁵ = 32 arquivos). Pelo menos **4 arquivos diferentes** caem no mesmo hash.
- [AT03 Q1]: há mais entradas possíveis do que saídas. Mapear arquivos de 1 MB e de 1 GB para 256 bits **inevitavelmente** gera sobreposição.
- Por isso a exigência nunca é "não existir colisão", e sim que seja **computacionalmente inviável ENCONTRAR** uma. Na nota do MAC, Stallings diz: como a entrada é arbitrária e a saída é pequena, **teoricamente muitas mensagens têm o mesmo código**, mas deve ser inviável achá-las (**resistência a colisões**).
- Um bom checksum criptográfico **se comporta como uma função aleatória**: hashes distribuídos uniformemente, e o valor só pode ser conhecido calculando-o [BIS].

---

## 4. Segurança: ataques e esforço

Como na cifragem simétrica, há **dois tipos de ataque** [STA]:
- **Criptoanálise**: explora fraquezas lógicas do algoritmo.
- **Força bruta**: a resistência depende **só do tamanho *n* do hash**.

| Propriedade | Esforço de força bruta (hash de n bits) |
|---|---|
| Resistência à pré-imagem | **2ⁿ** |
| Resistência à 2ª pré-imagem | **2ⁿ** |
| Resistência a colisões | **2ⁿᐟ²** |

- **Por que 2ⁿᐟ²?** É o **paradoxo do aniversário**: numa turma, a chance de dois alunos fazerem aniversário no mesmo dia passa de **50% com apenas 23 alunos**. Com ~√N amostras já se espera uma coincidência [AND §5.3.1.2].
- Bishop: com hash de **128 bits**, a probabilidade de achar uma mensagem para um hash dado é **2⁻¹²⁸**, mas a de achar duas mensagens com o mesmo hash é **2⁻⁶⁴**.
- **MD5 (128 bits)**: uma máquina de US$ 10 milhões acharia colisão em **24 dias** (van Oorschot e Wiener), então 128 bits é **inadequado**. **160 bits** já é **suspeito** [STA].

---

## 5. Algoritmos e histórico de quebras

| Algoritmo | Saída | Situação |
|---|---|---|
| **MD4** (Rivest) | 128 bits | Colisão em **1998** (Dobbertin) [AND] |
| **MD5** (Rivest) | 128 bits | Colisão em **2004** (Wang et al.). Hoje colisões são fáceis, inclusive em formatos de **certificados digitais** [AND] |
| **SHA-0** | — | Colisões (Wang e Yu) [BIS] |
| **SHA-1** (FIPS 180-1, **1995**) | **160 bits** | Colisão publicada em **fev/2017** (Amsterdã + Google); ataque de **prefixo escolhido** em **2020**, permitindo **forjar certificados** [AND] |
| **SHA-2** (FIPS 180-2, **2002**) | 256, 384, 512 (SHA-256/384/512) | Mesma estrutura do SHA-1 [STA] |
| **SHA-3** (Keccak) | — | Selecionado pelo NIST em **2012** [BIS], publicado/padronizado em **2015** [STA][AND]. Estrutura **muito diferente** do SHA-2 |

- O SHA original foi publicado pelo NIST como **FIPS 180 em 1993** [STA].
- O NIST criou o SHA-3 porque o SHA-2 é **estruturalmente parecido com o SHA-1** [STA].
- [AT03 Q1.2] sobre o SHA-1: quebras teóricas na ordem de **2⁶⁹ operações** antes de 2017. O ataque de 2017 custou cerca de **9 quintilhões de cálculos SHA-1**, **6.500 anos de CPU** (fase 1) e **110 anos de GPU** (fase 2). Em 2020 veio a colisão com **prefixos diferentes (*chosen-prefix*)**, mais perigosa porque o atacante controla o conteúdo que antecede a colisão.
- Anderson: mesmo quando a colisão não gera um ataque prático, ela gera uma **ameaça "certificacional"**. Em 2005, um motorista em Sydney foi **absolvido** porque ninguém testemunhou que o MD5 era seguro para garantir que a foto não tinha sido alterada.

---

## 6. Aplicações do hash

### 6.1 Autenticação de mensagem ([STA] Fig. 2.5)
1. **Hash cifrado com chave simétrica**: se só emissor e receptor têm a chave, a autenticidade está garantida.
2. **Hash cifrado com a chave privada** (chave pública): gera **assinatura digital** e autenticação, **sem precisar distribuir chaves**.
3. **Hash com chave, sem cifragem (*keyed hash MAC*)**: MD = **H(K‖M‖K)**. Envia-se M‖MD, e a chave nunca é enviada. Usar K só como prefixo ou só como sufixo é **menos seguro**.

- As opções 1 e 2 exigem **menos computação** do que cifrar a mensagem inteira. A opção 3 evita cifragem porque cifrar é lento, o hardware tem custo, é otimizado para dados grandes e o algoritmo pode ter patente [STA].

### 6.2 HMAC
- Termo genérico para algoritmo que usa um **hash sem chave + uma chave criptográfica** para gerar um **hash com chave** [BIS §10.4.1].
- **HMAC-h(k, m) = h( k' ⊕ opad ‖ h( k' ⊕ ipad ‖ m ) )**, com ipad = 0x36 repetido e opad = 0x5C repetido [BIS][AND]. É padrão **FIPS 198-1** [AND].
- A **força do HMAC depende da força do hash h** (Bellare, Canetti e Krawczyk) [BIS].
- Motivo histórico: países restringiam a exportação de software de cifragem, mas **não de hash sem chave**, porque ele **não serve para esconder informação** [BIS].

### 6.3 Outras aplicações
| Aplicação | Como usa o hash | Propriedade exigida |
|---|---|---|
| **Assinatura digital** | assina-se o **hash** da mensagem | resistência a colisões |
| **Armazenamento de senhas** | guarda-se H(senha), não a senha [STA] | pré-imagem (e talvez 2ª pré-imagem) |
| **Detecção de intrusão** | guarda-se H(F) de cada arquivo em mídia protegida e depois recalcula [STA] | 2ª pré-imagem (fraca) |
| **Integridade contra erros** | funciona como *frame check sequence*: se um bit muda por acidente, o digest não bate [STA] | — |
| **Compromisso/carimbo de tempo** | publica-se o hash de um documento para provar autoria depois [AND] | pré-imagem |
| **Árvores de Merkle** | folhas = hashes; cada nó = hash dos filhos; a raiz resume tudo (assinatura de código, blockchain) [AND] | — |
| **Atualização de chave** | K(i+1) = h(K(i)): quem rouba a chave atual não decifra o tráfego antigo (**segurança para trás**) [AND] | unidirecionalidade |
| **Autochaveamento** | chave atualizada com hash das mensagens trocadas (**segurança para frente**) [AND] | unidirecionalidade |
| **Tabelas hash** | índice = H(chave) mod tamanho, busca O(1) [AT03 Q5] | — |
| **Git** | armazenamento endereçado por conteúdo (blob, tree, commit, tag) [AT03 Q5] | — |
| **Proof of Work (Bitcoin)** | double SHA-256 do cabeçalho < alvo; varia-se o **nonce** [AT03 Q6] | pré-imagem |

---

## 7. Hash × cifra reversível (AES, RSA), [AT03 Q2] + [STA]/[BIS]

| | **Hash** | **Cifra** |
|---|---|---|
| Direção | **Unidirecional** | **Bidirecional**: D_k(E_k(m)) = m |
| Chave | **Não tem** (exceto variantes com chave, como o HMAC) | **Tem** chave |
| Saída | Tamanho **fixo**, perde informação | Proporcional à entrada, **nada se perde** |
| Uso típico | senhas, integridade de arquivos, digest para assinatura | dados sensíveis que precisam ser lidos de volta (CPF, cartão, tokens) |
| Resumo [AT03] | "hash é **projeção**" | "cifra é **codificação com segredo**" |

- **Por que hash não serve para comunicação secreta:** um canal secreto exige **assimetria**: o destinatário legítimo lê e o adversário não. Essa assimetria vem de um segredo (chave). O hash **não tem chave**, é **público e determinístico**, e é irreversível **para todos igualmente, inclusive para o destinatário** [AT03 Q2.3]. Bishop confirma que hashes sem chave *"não podem ser usados para esconder informação"*.

> ⚠️ **Atenção à definição dos livros:** a [AT03] diz que o hash é unidirecional "por construção, não por dificuldade". **Nos livros, a unidirecionalidade é definida em termos de dificuldade computacional**: *"para qualquer h, é **computacionalmente inviável** achar x tal que H(x) = h"* [STA][BIS]. Pré-imagens **existem** (casa dos pombos); o que se garante é que **encontrá-las** é inviável. Na prova, use a definição dos livros.

---

## 8. Hash de senhas e o salt ([STA] §3.2 · [BIS] §13.2, §13.4)

### Esquema (UNIX)
1. **Cadastro:** senha + **salt** (valor de tamanho fixo; antigamente ligado ao horário, hoje **aleatório ou pseudoaleatório**) → algoritmo de hash **propositalmente lento** → guarda-se **hash + salt em texto claro** no arquivo de senhas.
2. **Login:** o sistema usa o ID para achar o salt e o hash armazenados, recalcula H(salt, senha digitada) e compara.

Bishop: a solução para arquivos de senha expostos por acidente é usar uma **função hash unidirecional** para transformar a senha em um **complemento**. **Arquivos *shadow*** (legíveis só pelo root) escondem o complemento.

### As 3 funções do salt ([STA])
1. **Impede que senhas iguais apareçam iguais** no arquivo: dois usuários com a mesma senha recebem salts diferentes e, portanto, hashes diferentes.
2. **Dificulta muito o ataque de dicionário offline**: com salt de *b* bits, o número de senhas possíveis cresce por um fator de **2ᵇ**.
3. Torna quase impossível descobrir se uma pessoa **usou a mesma senha em vários sistemas**.

- Bishop: o salt torna a função de complementação dependente de um dado aleatório. Para testar se uma string é a senha de **qualquer um de n usuários**, o atacante precisa de **n cálculos**. **O salt aumenta o trabalho na ordem do número de usuários.**
- [AT03 Q4]: com salt, **cada hash é um problema independente**. O atacante só descobre o salt depois do vazamento, então **não há o que pré-computar**. Atacar 1 milhão de contas custa 1 milhão de vezes mais do que atacar uma.

### Implementações ([STA])
| Esquema | Detalhes |
|---|---|
| **crypt(3)** (UNIX antigo) | Baseado em **DES**, senha de até 8 caracteres, **salt de 12 bits**, **25 cifragens**. Hoje é "lamentavelmente inadequado" |
| **MD5 crypt** | Salt de até 48 bits, senha sem limite, hash de 128 bits, **1000 iterações** |
| **Bcrypt** (OpenBSD) | Baseado em **Blowfish**, senhas de até 55 caracteres, **salt de 128 bits**, hash de 192 bits, **variável de custo configurável** (mais custo para usuários privilegiados) |
| **Argon2** [AT03 Q4] | **Usa muita memória** (ex.: 64 MB) com dependências pseudoaleatórias. A memória inteira precisa ficar residente durante o cálculo, o que encarece ataques em hardware |

### Ataques a hashes de senha
| Ataque | Descrição |
|---|---|
| **Força bruta** | Testa **exaustivamente todas as combinações** de um alfabeto. Cresce exponencialmente com o tamanho [AT03 Q3] |
| **Dicionário** | "Adivinhar a senha por tentativa e erro repetida" [BIS Def. 13-7], com listas de senhas prováveis mais variações (inverter, trocar "o" por "0", maiúsculas) [STA] |
| **Dicionário offline** | O atacante **tem o arquivo de hashes** e as funções, calcula f(g) para cada palpite g e compara [BIS Def. 13-8][STA] |
| **Dicionário online** | O atacante **só tem acesso à função de autenticação** (tela de login) [BIS Def. 13-9] |
| **Rainbow table** | **Troca espaço por tempo**: pré-computa hashes para cada senha e salt. Ex.: **1,4 GB** quebrou **99,9%** dos hashes alfanuméricos do Windows em **13,8 s**. **Contramedida: salt grande e hash longo** [STA]. Bishop: usa **várias funções de redução** para permitir colisões sem fundir cadeias |

- Estudo de Klein (~14.000 senhas UNIX): **quase ¼ adivinhadas** com cerca de 3 milhões de palavras [STA].
- Análise de 70 milhões de senhas do Yahoo!: **< 10 bits** de segurança contra ataque online e **≈ 20 bits** contra dicionário offline ótimo [STA].

---

## ⚠️ Pegadinhas de prova
- **Hash ≠ criptografia reversível.** Não existe "descriptografar" hash.
- **Hash ≠ MAC**: o MAC usa **chave secreta**, o hash puro não [STA].
- **Colisões sempre existem** (casa dos pombos). Segurança significa ser **inviável encontrá-las**.
- **Colisão: 2ⁿᐟ²**, não 2ⁿ (aniversário).
- **Fraca** = 2ª pré-imagem (x é dado). **Forte** = colisão (qualquer par).
- **Salt não é secreto**: é guardado **em texto claro** junto do hash [STA].
- **Salt não impede** ataque a **uma** senha fraca específica. Ele multiplica o custo por usuário e inviabiliza a **pré-computação** (rainbow).
- O hash sozinho protege contra **alteração acidental**. Contra um atacante ativo, ele pode **alterar a mensagem E recalcular o checksum** [BIS §10.4], por isso é preciso chave (MAC/HMAC) ou assinatura.
