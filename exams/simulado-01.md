# Simulado 01: Segurança Digital

> [!info] Instruções
> - **10 questões**: teóricas, com duas de prática da cifra de César.
> - **Conteúdo:** Tríade CIA · Princípios da criptografia · Hashing · Cifra de César · Identificação, autenticação e autorização · Não repúdio · Certificados digitais.
> - **Tempo sugerido:** 100 minutos. **Não consulte** resumos nem flashcards.
> - Responda em **Sua resposta**. O **gabarito fica oculto**: só abra depois de terminar **todas** as questões. Depois peça ao agente para corrigir.
> - **Pontuação sugerida:** 1,0 ponto por questão (total 10,0).
>
> **Convenção para César:** A = 0 … Z = 25, sem acentos/Ç, espaços mantidos. Cifrar: c = (m + k) mod 26. Decifrar: m = (c − k) mod 26.

| A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 |

---

## Questão 1 (Tríade CIA, discursiva)
Em um hospital ocorreram três incidentes:
- **(a)** Um funcionário **sem autorização** contornou o controle de acesso e **leu prontuários** de pacientes.
- **(b)** Uma enfermeira **autorizada** a atualizar os dados **falsificou deliberadamente** as informações de alergia de um paciente.
- **(c)** O **serviço de autenticação** do hospital saiu do ar porque foi **sobrecarregado** com um volume enorme de requisições.

Para cada incidente, indique: **(i)** o pilar da tríade CIA violado; **(ii)** a **consequência de ameaça** da RFC 4949 (divulgação não autorizada, engano, interrupção ou usurpação); **(iii)** a **ação de ameaça** correspondente. Por fim, **defina** o pilar violado em (b) segundo a FIPS 199.

**Sua resposta:**


> [!success]- Gabarito
> | Incidente | Pilar | Consequência (RFC 4949) | Ação de ameaça |
> |---|---|---|---|
> | (a) | **Confidencialidade** | **Divulgação não autorizada** | **Intrusão** (contornar as proteções do sistema para acessar dados sensíveis) |
> | (b) | **Integridade** | **Engano** | **Falsificação** (alterar ou substituir dados válidos) |
> | (c) | **Disponibilidade** | **Interrupção** | **Obstrução** (sobrecarregar o tráfego ou o processamento) |
>
> **Integridade (FIPS 199):** proteger contra **modificação ou destruição imprópria** da informação, incluindo garantir o **não repúdio** e a **autenticidade**. A **perda de integridade** é a modificação ou destruição não autorizada da informação.
> Observação: (b) é o exemplo de Stallings de requisito **alto** de integridade. Deve ser possível restaurar os dados e **rastrear o responsável**. É também o caso de Bishop de alguém **autorizado** que altera dados **de maneira não autorizada**, que exige controles além da autenticação.
>
> **Critério:** 0,2 por linha correta da tabela (0,6) + 0,4 pela definição.
> 📚 *Fonte: [STA] §1.1 e Tab. 1.2 · [BIS] §1.1.2*

---

## Questão 2 (Princípios da criptografia, múltipla escolha)
Assinale a alternativa **correta**:

a) Pelo princípio de Kerckhoffs, a segurança de um criptossistema depende de manter o algoritmo em segredo.
b) Na criptografia de chave pública, cifrar uma mensagem com a **chave pública do destinatário** fornece confidencialidade, pois só ele tem a chave privada correspondente.
c) A criptografia de chave pública é, por natureza, mais resistente à criptoanálise do que a simétrica e tornou a simétrica obsoleta.
d) Em um ataque de texto claro conhecido, o adversário pode escolher quais textos claros serão cifrados.
e) Uma cifra de transposição altera as letras do texto claro, mas preserva a sua ordem.

**Sua resposta:**


> [!success]- Gabarito
> **b)** Bob cifra com a **chave pública de Alice**, e só Alice, dona da **chave privada**, decifra [STA §2.3].
> - a) Errada: Kerckhoffs diz que a segurança **não pode depender** de o adversário desconhecer o algoritmo; só a **chave** é secreta [BIS §10.1.1].
> - c) Errada: são dois **equívocos** listados por Stallings. A resistência depende do tamanho da chave e do trabalho computacional, e a simétrica continua em uso pelo custo da assimétrica [STA §2.3].
> - d) Errada: isso descreve o ataque de **texto claro escolhido** [BIS §10.1.1].
> - e) Errada: a transposição **reordena** os caracteres **sem alterá-los** [BIS §10.2.1].
> 📚 *Fonte: [STA] §2.3 · [BIS] §10.1.1, §10.2.1*

---

## Questão 3 (Hashing, discursiva)
**(a)** Defina função hash e explique por que colisões **necessariamente existem**.
**(b)** Diferencie **resistência à pré-imagem**, **à segunda pré-imagem** e **a colisões**, indicando o esforço de força bruta de cada uma para um hash de *n* bits.
**(c)** Qual dessas propriedades é **crítica para assinaturas digitais**, e por quê?

**Sua resposta:**


> [!success]- Gabarito
> **(a)** A função hash recebe uma mensagem de **tamanho variável** e produz um **resumo de tamanho fixo** (impressão digital), **sem chave secreta** [STA]. Colisões existem pelo **princípio da casa dos pombos**: há mais entradas possíveis do que saídas (ex.: 32 arquivos de 5 bits para 8 hashes de 3 bits → pelo menos 4 arquivos por hash) [BIS]. A segurança exige que seja **inviável encontrá-las**.
>
> **(b)**
> | Propriedade | Definição | Esforço |
> |---|---|---|
> | Pré-imagem (unidirecional) | dado h, inviável achar x com H(x) = h | **2ⁿ** |
> | 2ª pré-imagem (colisão fraca) | dado **x**, inviável achar y ≠ x com H(y) = H(x) | **2ⁿ** |
> | Colisão (colisão forte) | inviável achar **qualquer par** x ≠ y com H(x) = H(y) | **2ⁿᐟ²** (paradoxo do aniversário) |
>
> **(c)** A **resistência a colisões**. A assinatura digital **assina o hash**, não a mensagem. Se for possível achar duas mensagens com o mesmo hash, a assinatura de uma vale para a outra. Exemplo do vale: Bob prepara duas versões (valor pequeno e valor grande) com o mesmo hash, Alice assina a pequena e Bob apresenta a grande [STA][AT03].
>
> **Critério:** (a) 0,3 · (b) 0,4 · (c) 0,3.
> 📚 *Fonte: [STA] §2.2 · [BIS] §10.4 · [AND] §5.3.1.2 · [AT03] Q1*

---

## Questão 4 (Hashing de senhas, discursiva)
Descreva como um sistema armazena e verifica senhas usando **hash e salt**. Explique as **três funções do salt** e por que ele torna as **rainbow tables** ineficazes. O salt precisa ser secreto?

**Sua resposta:**


> [!success]- Gabarito
> **Armazenamento:** a senha é combinada com um **salt** (valor aleatório ou pseudoaleatório de tamanho fixo) e passa por um hash **propositalmente lento**. Guarda-se o **hash + o salt em texto claro** no arquivo de senhas, junto do ID. **Login:** o sistema usa o ID para achar o salt e o hash, recalcula H(salt, senha digitada) e compara [STA].
>
> **Funções do salt:**
> 1. Senhas **iguais** geram **hashes diferentes** no arquivo.
> 2. **Encarece o ataque de dicionário offline**: com salt de b bits, as possibilidades crescem por um fator de **2ᵇ**; Bishop diz que o trabalho cresce **na ordem do número de usuários**.
> 3. Esconde se a pessoa **reutilizou a mesma senha** em vários sistemas.
>
> **Rainbow tables** são tabelas **pré-computadas** de hashes. Com salt grande e único por usuário, seria preciso pré-computar para **cada salt possível**, e o salt só é conhecido após o vazamento: **não há o que pré-computar**. A contramedida citada por Stallings é **salt grande e hash longo**.
>
> **O salt não é secreto**: fica em texto claro, porque o sistema precisa dele para verificar a senha.
>
> **Critério:** esquema 0,3 · três funções 0,4 · rainbow 0,2 · sigilo do salt 0,1.
> 📚 *Fonte: [STA] §3.2 · [BIS] §13.4.1 · [AT03] Q4*

---

## Questão 5 (Cifra de César, prática: cifrar e decifrar)
**(a)** Cifre a mensagem **`NAO REPUDIO`** com a chave de **Júlio César**.
**(b)** Decifre **`XJLWJIT LZFWIFIT`**, sabendo que **k = 5**.
**(c)** Qual chave, aplicada **somando** (como se fosse cifrar), recupera a mensagem do item (b)? Justifique.

**Sua resposta:**


> [!success]- Gabarito
> **(a)** Chave de Júlio César: **k = 3** ('D' no lugar de 'A').
> N(13)→16 Q · A(0)→3 D · O(14)→17 R · R(17)→20 U · E(4)→7 H · P(15)→18 S · U(20)→23 X · D(3)→6 G · I(8)→11 L · O(14)→17 R
> **→ `QDR UHSXGLR`**
>
> **(b)** Subtraindo 5 (somando 26 quando negativo):
> X(23)→18 S · J(9)→4 E · L(11)→6 G · W(22)→17 R · J→E · I(8)→3 D · T(19)→14 O · L→G · Z(25)→20 U · F(5)→0 A · W→R · I→D · F→A · I→D · T→O
> **→ `SEGREDO GUARDADO`**
>
> **(c)** **k' = 26 − 5 = 21.** Somar 21 equivale a subtrair 5 (mod 26), porque 21 ≡ −5. Ex.: X(23) + 21 = 44 → 44 − 26 = 18 = S ✓.
>
> **Critério:** (a) 0,4 · (b) 0,4 · (c) 0,2.
> 📚 *Fonte: [BIS] §10.1 e §10.9 · [AND] §5.2*

---

## Questão 6 (Cifra de César, criptoanálise e teoria)
Você interceptou a mensagem **`TYRMV GIZMRUR`**, cifrada com uma cifra de César de chave desconhecida. Um informante revelou que a **primeira palavra é `CHAVE`**.
**(a)** Descubra a chave e decifre a mensagem.
**(b)** Que **tipo de ataque** você realizou (classificação de Bishop)?
**(c)** Se você **não** soubesse a primeira palavra, qual seria o **número máximo** de chaves a testar por força bruta, e quantas em média?
**(d)** Classifique a César (simétrica/assimétrica; substituição/transposição; mono/polialfabética) e explique por que ela é vulnerável à **análise de frequência**.

**Sua resposta:**


> [!success]- Gabarito
> **(a)** C(2) → T(19): k = 19 − 2 = **17**. Conferindo: H(7) → Y(24), 24 − 7 = 17 ✓.
> Decifrando com k = 17 (T19−17 = 2 C, Y24−17 = 7 H, R17−17 = 0 A, M12−17 = −5+26 = 21 V, V21−17 = 4 E, G6−17 = −11+26 = 15 P, I8−17 = −9+26 = 17 R, Z25−17 = 8 I, M→V, R→A, U20−17 = 3 D, R→A):
> **→ `CHAVE PRIVADA`**
>
> **(b)** Ataque de **texto claro conhecido**: o adversário tem o texto cifrado e (parte do) texto claro correspondente, e quer a chave [BIS].
>
> **(c)** Há **26 chaves** (0 a 25), então no máximo **25** tentativas úteis (k = 0 não altera o texto). Em média testa-se **metade** das chaves, cerca de **13** tentativas [STA][BIS].
>
> **(d)** **Simétrica** (a mesma chave cifra e decifra), de **substituição** e **monoalfabética**. Por usar um único alfabeto de substituição, ela **preserva as estatísticas** do texto claro: a letra mais frequente do texto claro continua sendo a mais frequente no texto cifrado, só que deslocada. Comparando as frequências do texto cifrado com um modelo da língua, as chaves mais prováveis aparecem primeiro, e isso **reduz o número de tentativas** [BIS].
>
> **Critério:** (a) 0,4 · (b) 0,2 · (c) 0,2 · (d) 0,2.
> 📚 *Fonte: [BIS] §10.1.1, §10.2, §10.2.2 · [STA] §2.1*

---

## Questão 7 (Identificação, autenticação e autorização, discursiva)
Um aplicativo bancário funciona assim: o cliente **informa o CPF**; em seguida **digita a senha** e um **código enviado por SMS ao celular cadastrado**; depois de entrar, ele **pode consultar o saldo e fazer transferências**, mas **não pode aprovar empréstimos**, função restrita ao papel de gerente.

**(a)** Identifique no fluxo as etapas de **identificação**, **autenticação** e **autorização**, definindo cada uma.
**(b)** O login é **autenticação multifator**? Classifique cada fator segundo os meios de autenticação de Stallings.
**(c)** Qual **política de controle de acesso** e qual **princípio de projeto** aparecem na restrição de aprovar empréstimos?

**Sua resposta:**


> [!success]- Gabarito
> **(a)**
> - **Identificação**: informar o **CPF**, ou seja, declarar quem é. O FIPS 200 e o NIST SP 800-171 pedem **identificar** usuários, processos ou dispositivos.
> - **Autenticação**: **senha + código SMS**, que **verificam** a identidade declarada. É o processo de estabelecer confiança na identidade (NIST SP 800-63-3), verificando que as credenciais são válidas; Bishop fala em **vincular uma identidade a um sujeito**. É **pré-requisito** para o acesso.
> - **Autorização**: poder consultar e transferir, mas **não aprovar empréstimos**. É a **concessão de direitos/permissões** para acessar recursos [STA §4.1].
>
> **(b)** **Sim, é MFA**, porque combina meios de **tipos diferentes**: a **senha** é algo que o indivíduo **sabe**; o **celular** que recebe o código é algo que ele **possui** (token). (Se fosse senha + pergunta secreta, **não** seria MFA [BIS §13.9].)
>
> **(c)** **RBAC** (controle de acesso baseado em **papéis**): a permissão está no **papel "gerente"**, não no indivíduo. Princípio: **menor privilégio**, em que cada usuário tem só os privilégios necessários à sua função [STA §1.4, §4.5]. (A MFA em si ilustra a **separação de privilégio**.)
>
> **Critério:** (a) 0,5 · (b) 0,3 · (c) 0,2.
> 📚 *Fonte: [STA] §1.3, §1.4, §3.1, §4.1, §4.5 · [BIS] §13.1, §13.9*

---

## Questão 8 (Autenticação e controle de acesso, múltipla escolha)
Assinale a alternativa **correta**:

a) Autorização é a verificação de que as credenciais de um usuário são válidas.
b) No controle de acesso obrigatório (MAC), o dono de um recurso pode, por vontade própria, conceder acesso a outros usuários.
c) Pelo princípio *fail-safe defaults*, o padrão é permitir o acesso, e o mecanismo lista as exceções proibidas.
d) Segundo Bishop, além do que a entidade sabe, tem e é, a **localização** ("onde a entidade está") também pode ser fonte de autenticação.
e) Identidade e autenticação são sinônimos: ambas significam a representação de uma entidade no computador.

**Sua resposta:**


> [!success]- Gabarito
> **d)** Bishop lista quatro fontes: o que a entidade **sabe**, **tem**, **é** e **onde está** [BIS §13.1].
> - a) Errada: essa é a definição de **autenticação**. Autorização é a **concessão de direito/permissão** [STA §4.1].
> - b) Errada: isso descreve o **DAC**. No MAC, quem tem acesso **não pode** repassá-lo por vontade própria [STA §4.1].
> - c) Errada: *fail-safe defaults* decide por **permissão**; **o padrão é não ter acesso** [STA §1.4].
> - e) Errada: **identidade** é a representação de uma entidade; **autenticação** é a vinculação de uma identidade a um sujeito [BIS §15.1, §13.1].
> 📚 *Fonte: [BIS] §13.1, §15.1 · [STA] §1.4, §4.1*

---

## Questão 9 (Não repúdio e assinatura digital, discursiva)
**(a)** O que é **repúdio** e o que é **não repúdio**?
**(b)** Alice e Bob trocam mensagens autenticadas com um **MAC** calculado com uma chave secreta compartilhada. Esse esquema garante **não repúdio**? Justifique.
**(c)** Explique como a **assinatura digital** resolve esse problema, indicando **qual chave** é usada para **assinar** e qual para **verificar**.
**(d)** A assinatura digital garante **confidencialidade**? Justifique.

**Sua resposta:**


> [!success]- Gabarito
> **(a)** **Repúdio**: uma entidade **nega falsamente** a responsabilidade por um ato, ou seja, nega ter **enviado** ou **recebido** dados. É uma ação de **engano**, ameaça à integridade [STA Tab. 1.2][BIS §1.2]. **Não repúdio**: o serviço que impede essa negação. A criptografia o fornece contra o **repúdio de origem** [BIS §10.1].
>
> **(b)** **Não.** O MAC garante **integridade** e **autenticação de origem** (o receptor sabe que a mensagem não foi alterada e que veio de quem tem a chave), mas **os dois conhecem a chave**. Bob não consegue **provar a um terceiro (juiz)** que não foi ele mesmo quem gerou a mensagem [BIS §10.5][STA §2.2].
>
> **(c)** A assinatura usa **criptografia de chave pública**. O signatário calcula o **hash** da mensagem e assina com sua **chave PRIVADA**, que **só ele possui**. Qualquer um (inclusive um juiz) verifica com a **chave PÚBLICA do signatário**. Pela FIPS 186-4, isso fornece **autenticação de origem, integridade e não repúdio do signatário**. Bishop observa que esse não repúdio é **técnico**: prova que a chave foi usada, e a alegação de chave roubada exige evidências adicionais.
>
> **(d)** **Não.** A mensagem fica protegida contra **alteração**, mas não contra **escuta**; qualquer um que tenha a chave pública do emissor verifica (e "decifra") a assinatura [STA §2.4].
>
> **Critério:** (a) 0,2 · (b) 0,3 · (c) 0,3 · (d) 0,2.
> 📚 *Fonte: [STA] §2.2, §2.4, Tab. 1.2 · [BIS] §1.2, §10.1, §10.5*

---

## Questão 10 (Certificados digitais, discursiva)
**(a)** Qual problema da criptografia de chave pública motivou a criação dos **certificados digitais**?
**(b)** O que um certificado contém e **quem o assina, com qual chave**? Como um usuário verifica um certificado?
**(c)** Diferencie certificado **expirado** de **revogado** e explique **CRL** e **OCSP**.

**Sua resposta:**


> [!success]- Gabarito
> **(a)** Qualquer um pode **forjar o anúncio de uma chave pública**, fingindo ser Bob. Até a fraude ser descoberta, o falsificador **lê as mensagens cifradas destinadas a Bob** e **usa a chave forjada para se autenticar** como ele [STA §2.4].
>
> **(b)** O certificado contém a **chave pública + o ID do dono**, informações sobre o **emissor** e o **período de validade**, com tudo **assinado pela Autoridade Certificadora (CA)** usando a **chave privada da CA**. No X.509v3, também número de série, algoritmo de assinatura, DN do emissor e do sujeito, extensões e assinatura [STA][BIS]. **Verificação:** o usuário calcula o **hash** do certificado (sem a assinatura), verifica a assinatura com a **chave pública da CA** e confere o **período de validade** [STA][BIS]. Quando o usuário não conhece a CA, usa uma **cadeia de certificados** até uma **âncora de confiança** [BIS].
>
> **(c)**
> - **Expirado**: acabou o período de validade, e esse é o **único motivo**. **Revogado**: foi **cancelado antes do prazo** por outro motivo (ex.: **chave comprometida** ou mudança da vinculação sujeito-chave).
> - **CRL**: lista, **assinada pelo emissor**, com os **números de série e as datas** dos certificados revogados, além da data da lista e da próxima.
> - **OCSP**: consulta **online** do status (**good / revoked / unknown**), que reduz o atraso da CRL. É útil quando o tempo é crítico.
>
> **Critério:** (a) 0,2 · (b) 0,4 · (c) 0,4.
> 📚 *Fonte: [STA] §2.4 · [BIS] §11.4.2, §11.4.3, §11.5.2*
