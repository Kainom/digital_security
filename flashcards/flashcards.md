# Flashcards: Segurança Digital

> **Como usar:** leia a pergunta, responda em voz alta ou no papel e **clique no card para revelar a resposta**. Cada resposta traz a fonte (siglas em [[00-indice]]).

---

## 1. Tríade CIA

> [!question]- Qual a definição NIST de segurança computacional?
> Medidas e controles que garantem a **confidencialidade, integridade e disponibilidade** dos ativos de sistemas de informação (hardware, software, firmware e informação processada, armazenada e comunicada). *[STA §1.1]*

> [!question]- Segundo a FIPS 199, o que caracteriza a PERDA de cada pilar da CIA?
> - **Confidencialidade:** divulgação não autorizada da informação.
> - **Integridade:** modificação ou destruição não autorizada da informação.
> - **Disponibilidade:** interrupção do acesso ou do uso da informação ou do sistema.
> *[STA §1.1]*

> [!question]- Quais dois conceitos Stallings inclui em "confidencialidade"?
> **Confidencialidade de dados** (não revelar a não autorizados) e **privacidade** (o indivíduo controla o que é coletado sobre ele e a quem é revelado). *[STA §1.1]*

> [!question]- Quais dois conceitos Stallings inclui em "integridade"?
> **Integridade de dados** (alterações só de forma especificada e autorizada) e **integridade de sistema** (o sistema cumpre sua função sem manipulação não autorizada). *[STA §1.1]*

> [!question]- Para Bishop, quais as duas faces da integridade?
> **Integridade de dados** (conteúdo) e **integridade de origem** (a fonte dos dados, chamada de **autenticação**). Ex.: jornal que publica o vazamento corretamente, mas atribui à fonte errada. *[BIS §1.1.2]*

> [!question]- Quais as duas classes de mecanismos de integridade (Bishop)?
> **Prevenção** (bloqueia mudanças não autorizadas ou feitas de maneira não autorizada) e **detecção** (apenas informa que a integridade não é mais confiável). *[BIS §1.1.2]*

> [!question]- Como Bishop define disponibilidade e qual o ataque típico?
> Capacidade de **usar** a informação ou o recurso desejado. Ataque típico: **negação de serviço (DoS)**, o mais difícil de detectar. *[BIS §1.1.3]*

> [!question]- Diferencie sigilo, confidencialidade e privacidade (Anderson).
> **Sigilo:** efeito técnico dos mecanismos que limitam o acesso. **Confidencialidade:** *obrigação* de proteger segredos alheios. **Privacidade:** *direito* de proteger a própria informação pessoal. *[AND §1.7]*

> [!question]- Quais os três níveis de impacto da FIPS 199?
> **Baixo** (efeito limitado), **moderado** (efeito sério) e **alto** (efeito severo ou catastrófico). *[STA §1.1]*

> [!question]- Quais as quatro consequências de ameaça da RFC 4949 e o que cada uma atinge?
> **Divulgação não autorizada** → confidencialidade; **engano** → integridade; **interrupção** → disponibilidade ou integridade do sistema; **usurpação** → integridade do sistema. *[STA Tab. 1.2]*

> [!question]- Um sistema "corrompido", "vazando" ou "indisponível" viola qual pilar?
> Corrompido → **integridade**; vazando → **confidencialidade**; indisponível ou lento → **disponibilidade**. *[STA §1.1]*

> [!question]- Ataque ativo × passivo?
> **Ativo:** tenta alterar recursos ou afetar sua operação. **Passivo:** tenta aprender ou usar informação sem afetar recursos. *[STA §1.1]*

---

## 2. Hashing

> [!question]- O que é uma função hash?
> Função que recebe uma mensagem de **tamanho variável** e produz um **resumo de tamanho fixo** H(M), uma "impressão digital" dos dados. **Não usa chave secreta.** *[STA §2.2]*

> [!question]- Quais as 6 propriedades de uma função hash segura (Stallings)?
> 1. Aceita entrada de qualquer tamanho. 2. Saída de tamanho fixo. 3. Fácil de calcular. 4. **Resistente à pré-imagem** (unidirecional). 5. **Resistente à 2ª pré-imagem** (colisão fraca). 6. **Resistente a colisões** (colisão forte). *[STA §2.2]*

> [!question]- Diferença entre resistência à 2ª pré-imagem e resistência a colisões?
> **2ª pré-imagem:** dado um **x específico**, é inviável achar y ≠ x com H(y) = H(x). **Colisão:** é inviável achar **qualquer par** (x, y) com H(x) = H(y). *[STA §2.2][BIS §10.4]*

> [!question]- Hash fraco × hash forte?
> **Fraco:** satisfaz as propriedades 1 a 5. **Forte:** também satisfaz a 6 (resistência a colisões). *[STA §2.2]*

> [!question]- Por que colisões SEMPRE existem?
> **Princípio da casa dos pombos:** há mais entradas possíveis que saídas. Ex.: hash de 3 bits (8 valores) para 32 arquivos de 5 bits → pelo menos 4 arquivos por hash. *[BIS §10.4][AT03]*

> [!question]- Qual o esforço de força bruta contra um hash de n bits?
> Pré-imagem: **2ⁿ**. 2ª pré-imagem: **2ⁿ**. Colisão: **2ⁿᐟ²** (paradoxo do aniversário). *[STA §2.2][AND §5.3.1.2]*

> [!question]- Tamanhos e situação do MD5, SHA-1, SHA-2 e SHA-3?
> **MD5:** 128 bits, colisão em 2004. **SHA-1:** 160 bits, colisão em 2017. **SHA-2:** 256/384/512 bits (2002). **SHA-3:** Keccak (selecionado em 2012, padronizado em 2015). *[STA][AND §5.6.1][BIS]*

> [!question]- Diferença entre hash e MAC?
> O **MAC usa chave secreta compartilhada**: MAC = F(K, M). O **hash não usa chave**. *[STA §2.2]*

> [!question]- Qual a fórmula do HMAC?
> **HMAC-h(k, m) = h(k' ⊕ opad ‖ h(k' ⊕ ipad ‖ m))**. A força depende do hash h. *[BIS §10.4.1]*

> [!question]- Quais as 3 funções do salt?
> 1. Senhas iguais geram **hashes diferentes**. 2. Encarece o **dicionário offline** (fator 2ᵇ). 3. Esconde se a pessoa **reusou a senha** em vários sistemas. *[STA §3.2]*

> [!question]- O salt é secreto?
> **Não.** É guardado **em texto claro** junto do hash, no arquivo de senhas. *[STA §3.2]*

> [!question]- O que é uma rainbow table e qual a contramedida?
> **Pré-computação** de hashes de senhas prováveis (troca espaço por tempo). Contramedida: **salt grande e hash longo**. *[STA §3.2][BIS §13.4.1]*

> [!question]- Dicionário offline × online?
> **Offline:** o atacante tem o arquivo de hashes e testa na própria máquina. **Online:** só tem acesso à função de autenticação (tela de login). *[BIS §13.4]*

> [!question]- Por que hash não serve para comunicação secreta?
> Não tem chave: é público, determinístico e irreversível **para todos, inclusive o destinatário**. Falta a assimetria (segredo) que um canal secreto exige. *[AT03 Q2][BIS §10.4.1]*

---

## 3. Cifra de César

> [!question]- Qual o deslocamento usado por Júlio César e por Augusto?
> **Júlio:** 3 ('D' no lugar de 'A'). **Augusto:** 2 ('C' no lugar de 'A'). *[AND §5.2]*

> [!question]- Fórmulas de cifrar e decifrar da César?
> **E_k(m) = (m + k) mod 26** e **D_k(c) = (c − k) mod 26**, com A = 0 … Z = 25. *[BIS §10.1]*

> [!question]- Quantas chaves tem a cifra de César?
> **26** (k de 0 a 25), então a força bruta é trivial (~13 tentativas em média). *[BIS §10.1][STA §2.1]*

> [!question]- "HELLO" com k = 3 vira?
> **KHOOR**. *[BIS §10.1]*

> [!question]- A César é simétrica, de substituição ou de transposição? Mono ou polialfabética?
> **Simétrica**, de **substituição**, **monoalfabética**. *[BIS §10.2]*

> [!question]- Por que a César é vulnerável à análise de frequência?
> Por ser **monoalfabética**, **preserva as estatísticas** do texto claro. *[BIS §10.2.2.1]*

> [!question]- Por que a César não é de chave pública, se a chave de decifrar (26 − k) é diferente?
> Porque **26 − k se calcula trivialmente a partir de k**. Em chave pública, derivar a privada da pública precisa ser **inviável**. *[BIS §10.9][BIS §10.3]*

> [!question]- Decifre "KHOOR ZRUOG" (k = 3).
> **HELLO WORLD**. *[BIS §10.2.2]*

> [!question]- Cifre "XYZ" com k = 3.
> **ABC** (dá a volta no alfabeto: 23+3 = 26 ≡ 0). *[BIS §10.1]*

> [!question]- Qual a relação entre a César e a Vigenère?
> A César é uma Vigenère com **chave fixa de uma letra** (D para Júlio). A Vigenère repete uma palavra-chave (polialfabética). *[AND §5.2.1]*

---

## 4. Princípios da criptografia

> [!question]- Criptografia, criptoanálise e criptologia?
> **Criptografia:** projetar cifras ("escrita secreta"). **Criptoanálise:** quebrá-las. **Criptologia:** estudo de ambas. *[AND §5.1][BIS §10.1]*

> [!question]- Quais os 5 elementos de um criptossistema (Bishop)?
> **(E, D, M, K, C)**: cifragem, decifragem, textos claros, chaves e textos cifrados. *[BIS Def. 10-1]*

> [!question]- O que diz o princípio de Kerckhoffs?
> A segurança **não pode depender de o adversário desconhecer o algoritmo**. Supõe-se que ele conhece E, D e K; só a **chave específica** é secreta. *[BIS §10.1.1]*

> [!question]- Confusão × difusão?
> **Confusão:** substitui partes do texto claro. **Difusão:** espalha o conteúdo pela mensagem. *[BIS §10.1]*

> [!question]- Quais os 3 tipos de ataque de Bishop?
> **Só texto cifrado**, **texto claro conhecido** e **texto claro escolhido**. *[BIS §10.1.1]*

> [!question]- Criptoanálise × força bruta?
> **Criptoanálise:** explora características do algoritmo. **Força bruta:** testa todas as chaves (em média metade). *[STA §2.1]*

> [!question]- Os 5 ingredientes da cifragem simétrica?
> Texto claro, algoritmo de cifragem, **chave secreta**, texto cifrado e algoritmo de decifragem. *[STA §2.1]*

> [!question]- Os 2 requisitos para uso seguro da cifragem simétrica?
> **Algoritmo forte** e **chave obtida e guardada com segurança** pelas duas partes. *[STA §2.1]*

> [!question]- Transposição × substituição?
> **Transposição:** reordena as letras (a frequência se mantém). **Substituição:** troca as letras (ex.: César). *[BIS §10.2]*

> [!question]- Chave pública: com qual chave cifrar para ter sigilo? E para ter autenticação?
> **Sigilo:** chave **pública do destinatário**. **Autenticação/integridade:** chave **privada do emissor**. *[STA §2.3]*

> [!question]- Três equívocos sobre criptografia de chave pública?
> Que é **mais segura** que a simétrica, que **tornou a simétrica obsoleta** e que **distribuir chaves ficou trivial**. Os três são falsos. *[STA §2.3]*

> [!question]- O que é um envelope digital?
> Cifra-se a mensagem com uma **chave simétrica de uso único**, e essa chave com a **chave pública do destinatário**. *[STA §2.4]*

---

## 5. Identificação, Autenticação e Autorização

> [!question]- Identificação × autenticação × autorização?
> **Identificação:** declarar quem é (ID). **Autenticação:** provar/verificar a identidade. **Autorização:** conceder direitos de acesso a recursos. *[STA §1.3, §3.1, §4.1]*

> [!question]- Definição de autenticação segundo Bishop?
> **A vinculação (binding) de uma identidade a um sujeito.** *[BIS Def. 13-1]*

> [!question]- Definição de autorização segundo Stallings?
> **Concessão de um direito ou permissão** a uma entidade para acessar um recurso. Determina **quem é confiável para um dado propósito**. *[STA §4.1]*

> [!question]- Os 4 meios de autenticação (Stallings)?
> Algo que **sabe** (senha), que **possui** (token), que **é** (biometria estática) e que **faz** (biometria dinâmica). *[STA §3.1]*

> [!question]- Qual fonte de autenticação Bishop inclui e Stallings não?
> **Onde a entidade está** (localização). *[BIS §13.1]*

> [!question]- Senha + pergunta secreta é MFA?
> **Não.** Os dois são "o que a entidade sabe". MFA exige **fatores de tipos diferentes**. *[BIS §13.9]*

> [!question]- Qual princípio de projeto a MFA exemplifica?
> **Separação de privilégio.** *[STA §1.4]*

> [!question]- Para que serve a identidade (Bishop)?
> **Responsabilização (accountability)** e **controle de acesso**. *[BIS §15.1]*

> [!question]- DAC, MAC, RBAC e ABAC decidem com base em quê?
> **DAC:** identidade (o dono repassa direitos). **MAC:** rótulos × habilitações (não se repassa). **RBAC:** papéis. **ABAC:** atributos do usuário, do recurso e do ambiente. *[STA §4.1]*

> [!question]- O que é o princípio do menor privilégio?
> Todo processo e usuário opera com o **menor conjunto de privilégios necessário**, inclusive no **tempo**. *[STA §1.4]*

> [!question]- O que é "fail-safe defaults"?
> Decisões de acesso baseadas em **permissão**, não em exclusão: **o padrão é não ter acesso**. *[STA §1.4]*

> [!question]- O que é uma credencial?
> Estrutura que **vincula de forma autoritativa uma identidade a um token** do assinante (ex.: smart card, chaves, **certificados digitais**). *[STA §3.1, §4.7]*

---

## 6. Autenticidade e Não Repúdio

> [!question]- Defina autenticidade (Stallings).
> Propriedade de ser **genuíno e verificável**: os usuários são quem dizem ser e as entradas vêm de fonte confiável. *[STA §1.1]*

> [!question]- Defina responsabilização (accountability).
> As ações de uma entidade podem ser **rastreadas unicamente até ela**. Dá suporte ao **não repúdio**, à dissuasão, à forense e a ações legais. *[STA §1.1]*

> [!question]- O que é repúdio e em qual categoria de ameaça ele está?
> **Negar falsamente** ter enviado ou recebido dados. Categoria: **engano** (ameaça à integridade). *[STA Tab. 1.2][BIS §1.2]*

> [!question]- Quais serviços a assinatura digital fornece (FIPS 186-4)?
> **Autenticação de origem, integridade dos dados e não repúdio do signatário.** Não fornece confidencialidade. *[STA §2.4]*

> [!question]- Por que o MAC não fornece não repúdio?
> A chave é **compartilhada**: o receptor também poderia ter gerado o MAC, então não dá para provar a um terceiro quem criou a mensagem. *[BIS §10.5]*

> [!question]- Com qual chave se assina e com qual se verifica?
> Assina com a **chave privada do signatário** e verifica com a **chave pública do signatário**. *[STA §2.4]*

> [!question]- Por que se assina o hash e não o documento?
> Eficiência e segurança: Bishop mostra um ataque ao RSA quando se assina o documento em si. Exige hash **resistente a colisões** (exemplo do vale). *[BIS §10.5.2][STA §2.2]*

> [!question]- O não repúdio é absoluto?
> **Não, é técnico:** prova que a **chave** foi usada. A pessoa pode alegar **roubo da chave**, e isso exige evidência adicional. *[BIS §10.5]*

---

## 7. Certificados digitais

> [!question]- Que problema o certificado resolve?
> **Chaves públicas forjadas**: qualquer um pode anunciar uma chave como se fosse de Bob. *[STA §2.4]*

> [!question]- O que contém um certificado de chave pública?
> **Chave pública + ID do dono + dados do emissor + validade**, tudo **assinado pela CA**. *[STA §2.4]*

> [!question]- Como a CA assina e como o usuário verifica?
> **CA:** faz o hash do certificado e assina com a **chave privada da CA**. **Usuário:** refaz o hash e verifica com a **chave pública da CA**. *[STA §2.4]*

> [!question]- Qual o padrão de certificados e onde é usado?
> **X.509**, usado em TLS, IPsec, SSH e S/MIME. *[STA §2.4]*

> [!question]- CA × RA?
> **CA:** emite (e assina) certificados. **RA:** verifica a identidade de quem pede, por delegação da CA. *[BIS §11.4.3]*

> [!question]- O que é uma PKI?
> Infraestrutura que **gerencia chaves públicas e autoridades certificadoras**. *[BIS Def. 11-8]*

> [!question]- O que é certificação cruzada?
> Duas CAs **emitem certificados uma para a outra**. *[BIS Def. 11-7]*

> [!question]- O que é um certificado autoassinado / âncora de confiança?
> Emissor = sujeito, e a própria chave pública valida a assinatura. **Inicia a cadeia**. *[BIS §11.4.3]*

> [!question]- Expirado × revogado?
> **Expirado:** só acabou o prazo. **Revogado:** cancelado antes do prazo (ex.: **chave comprometida**). *[BIS §11.5.2]*

> [!question]- CRL × OCSP?
> **CRL:** lista **assinada** pelo emissor com os números de série revogados. **OCSP:** consulta **online**, que responde good, revoked ou unknown. *[BIS §11.5.2]*
