# Questões: Identificação, Autenticação e Autorização

> [!info] Como usar
> Escreva sua resposta no espaço **Sua resposta**. O gabarito fica **oculto**: clique em **Gabarito** para expandir **só depois de responder**. Depois peça ao agente para corrigir.
> Resumo de apoio: [[05-identificacao-autenticacao-autorizacao]]

---

## Questão 1 (Discursiva)
Diferencie **identificação**, **autenticação** e **autorização**, e explique em que **ordem** elas ocorrem. Ilustre com um login num sistema acadêmico.

**Sua resposta:**


> [!success]- Gabarito
> - **Identificação:** o usuário **declara** quem é (informa o ID/login). A FIPS 200 e o NIST SP 800-171 pedem **identificar** usuários, processos ou dispositivos.
> - **Autenticação:** o sistema **verifica** a identidade declarada, estabelecendo **confiança** nela (NIST SP 800-63-3), ou seja, verifica se as **credenciais são válidas** [STA §4.1]. Bishop: é a **vinculação de uma identidade a um sujeito**.
> - **Autorização:** **concessão de direito/permissão** para acessar um recurso [STA §4.1].
> - **Ordem:** identificar → autenticar (**pré-requisito** para o acesso) → autorizar/controlar o acesso. Stallings: primeiro se autentica (se pode acessar o sistema **de alguma forma**); depois o controle de acesso decide se o **acesso específico** é permitido.
> - **Exemplo:** o aluno digita a matrícula (identificação), digita a senha (autenticação) e o sistema permite ver as próprias notas, mas não lançar notas, que é função do professor (autorização).
> 📚 *Fonte: [STA] §1.3, §3.1, §4.1 · [BIS] §13.1*

---

## Questão 2 (Múltipla escolha)
Segundo Bishop, **autenticação** é:

a) a concessão de permissões a um sujeito
b) a vinculação de uma identidade a um sujeito
c) a representação de uma entidade no computador
d) o registro das ações de um usuário
e) a revisão independente de registros do sistema

**Sua resposta:**


> [!success]- Gabarito
> **b)** Def. 13-1 de Bishop. As outras: (a) autorização; (c) identidade (Def. 15-1); (d) e (e) auditoria/responsabilização.
> 📚 *Fonte: [BIS] §13.1, §15.1 · [STA] §4.1*

---

## Questão 3 (Discursiva)
Quais são os **quatro meios gerais** de autenticação segundo Stallings? Dê exemplos e cite a fonte adicional que Bishop acrescenta.

**Sua resposta:**


> [!success]- Gabarito
> 1. **Algo que o indivíduo sabe:** senha, PIN, respostas a perguntas.
> 2. **Algo que possui (token):** cartão eletrônico, smart card, chave física.
> 3. **Algo que é (biometria estática):** impressão digital, retina, face.
> 4. **Algo que faz (biometria dinâmica):** padrão de voz, caligrafia, ritmo de digitação.
>
> **Bishop** inclui **"onde a entidade está"** (localização, ex.: em frente a um terminal específico).
> 📚 *Fonte: [STA] §3.1 · [BIS] §13.1*

---

## Questão 4 (Múltipla escolha)
Qual das combinações abaixo **NÃO** constitui autenticação multifator?

a) Senha + código enviado por SMS ao celular
b) Cartão inteligente + PIN
c) Senha + resposta a uma pergunta secreta
d) Impressão digital + cartão de acesso
e) Senha + código gerado por aplicativo no smartphone

**Sua resposta:**


> [!success]- Gabarito
> **c)** Senha e pergunta secreta são **ambas "algo que a entidade sabe"**. Bishop dá exatamente esse exemplo: *"um mecanismo que pede senha e depois a resposta a uma pergunta **não é multifator**, pois usa apenas o que a entidade sabe"*. MFA exige **formas diferentes** de autenticação.
> 📚 *Fonte: [BIS] §13.9*

---

## Questão 5 (Discursiva, base na Atividade 01)
O que é **autenticação multifator (MFA)** e como ela contribui para a segurança? Relacione com um princípio fundamental de projeto seguro.

**Sua resposta:**


> [!success]- Gabarito
> MFA é o uso de **mais de um dos meios de autenticação** (sabe, possui, é, faz). **A força cresce com o número de fatores**: dois fatores são mais fortes que um, três mais fortes que dois [STA]. Com várias camadas, o atacante precisa **saber e possuir mais** do que para enganar uma camada só [BIS]. Minimiza riscos de **erro humano, senhas fracas e dispositivos extraviados** [AT01].
> Princípio relacionado: **separação de privilégio**, que exige vários atributos de privilégio para acessar um recurso restrito. Stallings cita a MFA como "um bom exemplo" dele.
> 📚 *Fonte: [STA] §1.4, §3.1 · [BIS] §13.9 · [AT01]*

---

## Questão 6 (Discursiva)
Descreva o modelo de autenticação do **NIST SP 800-63-3**, explicando os papéis de **RA, CSP, assinante, credencial, reclamante, verificador e parte confiante**.

**Sua resposta:**


> [!success]- Gabarito
> - **Registro:** o **requerente** procura a **autoridade de registro (RA)**, que estabelece e atesta sua identidade para um **provedor de serviço de credencial (CSP)**. O requerente vira **assinante** do CSP.
> - **Credencial:** o CSP emite uma **credencial**, estrutura que **vincula de forma autoritativa uma identidade (e atributos) a um token** possuído pelo assinante.
> - **Autenticação:** o **reclamante** demonstra ao **verificador**, por um protocolo, que **possui e controla o token**. O verificador confirma que ele é o assinante da credencial.
> - **Asserção:** o verificador passa à **parte confiante (RP)** informações sobre a identidade, e a RP usa isso para decidir **acesso/autorização**.
> 📚 *Fonte: [STA] §3.1 (Fig. 3.1)*

---

## Questão 7 (Discursiva)
Defina **autenticação**, **autorização** e **auditoria** conforme Stallings (baseado na RFC 4949) e descreva como elas se relacionam com o controle de acesso.

**Sua resposta:**


> [!success]- Gabarito
> - **Autenticação:** verificação de que as **credenciais** de um usuário ou entidade são **válidas**.
> - **Autorização:** **concessão de direito ou permissão** a uma entidade para acessar um recurso; determina **quem é confiável para um dado propósito**.
> - **Auditoria:** revisão e exame **independentes** de registros e atividades, para testar a adequação dos controles, garantir conformidade, detectar violações e recomendar mudanças.
> - **Relação:** o sistema **autentica** a entidade; a **função de controle de acesso** consulta a **base de autorização** (mantida pelo administrador) para decidir se o acesso específico é permitido; a **auditoria** registra os acessos.
> 📚 *Fonte: [STA] §4.1 (Fig. 4.1)*

---

## Questão 8 (Múltipla escolha)
A política de controle de acesso em que **quem tem acesso pode, por vontade própria, conceder acesso a outra entidade** é:

a) MAC
b) RBAC
c) ABAC
d) DAC
e) Fail-safe

**Sua resposta:**


> [!success]- Gabarito
> **d) DAC (discricionário):** decide pela **identidade** e por regras de autorização. É "discricionário" porque a entidade pode **repassar** direitos por vontade própria.
> - **MAC:** compara **rótulos de segurança** com **habilitações**; quem tem acesso **não pode** repassá-lo.
> - **RBAC:** **papéis**.
> - **ABAC:** **atributos** do usuário, do recurso e do ambiente.
> 📚 *Fonte: [STA] §4.1*

---

## Questão 9 (Discursiva)
Explique o **princípio do menor privilégio** e por que o **RBAC** é um bom exemplo de sua aplicação.

**Sua resposta:**


> [!success]- Gabarito
> **Menor privilégio:** todo processo e todo usuário deve operar com o **menor conjunto de privilégios necessário** para a tarefa. Há um aspecto **temporal**: privilégios especiais (ex.: de administrador) só devem existir **quando necessários** e ser retirados nas atividades comuns.
> **RBAC:** os direitos são atribuídos a **papéis** (funções do trabalho), não a indivíduos. Cada papel recebe **só as permissões necessárias** para aquela função, e o usuário recebe o papel correspondente. Todos os usuários do mesmo papel têm o mesmo conjunto mínimo de direitos.
> 📚 *Fonte: [STA] §1.4, §4.5*

---

## Questão 10 (Discursiva)
Explique os princípios **fail-safe defaults** e **mediação completa** e sua relação com a autorização.

**Sua resposta:**


> [!success]- Gabarito
> - **Fail-safe defaults:** decisões de acesso baseadas em **permissão**, não em exclusão; **o padrão é a falta de acesso**. Um erro num mecanismo que dá permissão explícita tende a **negar** acesso (falha segura e fácil de notar), enquanto um erro num mecanismo de exclusão tende a **permitir** acesso (falha que pode passar despercebida).
> - **Mediação completa:** **todo acesso** deve ser verificado pelo mecanismo de controle de acesso, sem confiar em decisões em **cache**. Se as decisões forem lembradas, é preciso propagar mudanças de autoridade.
> - **Relação:** os dois dizem **como** a autorização deve ser imposta: negar por padrão e verificar sempre.
> 📚 *Fonte: [STA] §1.4*

---

## Questão 11 (Discursiva)
Segundo Bishop, o que é **identidade** e quais são seus **dois usos principais**?

**Sua resposta:**


> [!success]- Gabarito
> **Identidade** é *"simplesmente a representação, no computador, de uma entidade"*. Um **principal** é uma entidade única, e a identidade **especifica** um principal.
> **Usos:**
> 1. **Responsabilização (*accountability*):** rastrear o principal em suas ações, ligada a **logs e auditoria**.
> 2. **Controle de acesso:** base para decidir se um acesso deve ser permitido.
> 📚 *Fonte: [BIS] §15.1*

---

## Questão 12 (Discursiva)
Cite **quatro** ataques contra autenticação por senha descritos por Stallings, com a contramedida de cada um.

**Sua resposta:**


> [!success]- Gabarito
> Quaisquer quatro:
> - **Dicionário offline:** proteger o arquivo de senhas, detecção de intrusão, reemitir senhas rapidamente.
> - **Ataque a conta específica:** **bloqueio da conta** após tentativas falhas (tipicamente ≤ 5).
> - **Senha popular contra vários IDs:** impedir senhas comuns; analisar IPs e cookies das requisições.
> - **Adivinhação contra um usuário:** treinamento e políticas de senha (tamanho, caracteres, troca).
> - **Sequestro de estação:** **logout automático** por inatividade.
> - **Erros do usuário** (anotar, compartilhar, engenharia social, senha padrão): treinamento, detecção de intrusão, senha + outro mecanismo.
> - **Mesma senha em vários dispositivos:** política que proíbe.
> - **Monitoramento eletrônico:** cifrar a senha **não resolve** (a senha cifrada vira a senha e pode ser reutilizada).
> 📚 *Fonte: [STA] §3.2*

---

## Questão 13 (Discursiva)
O que é uma **credencial** e quais exemplos Stallings cita? Quais etapas compõem o **gerenciamento de credenciais** no ICAM?

**Sua resposta:**


> [!success]- Gabarito
> **Credencial:** objeto ou estrutura de dados que **vincula de forma autoritativa uma identidade** (e opcionalmente atributos) **a um token** possuído e controlado pelo assinante. **Exemplos:** smart cards, chaves criptográficas pública/privada e **certificados digitais**.
> **Etapas:** (1) **patrocínio** (um responsável justifica a necessidade); (2) **inscrição** (prova de identidade, dados biográficos e biométricos); (3) **produção** (cifragem, assinatura digital, cartão); (4) **emissão**; (5) **manutenção** do ciclo de vida (revogação, reemissão, reinscrição, expiração, reset de PIN, suspensão, reativação).
> 📚 *Fonte: [STA] §4.7*

---

## Questão 14 (Múltipla escolha)
Segundo o NIST SP 800-63-3 (em Stallings), o nível de garantia que **exige pelo menos dois fatores** de autenticação, adequado a um advogado que envia informações confidenciais de patente, é o:

a) Nível 1
b) Nível 2
c) Nível 3
d) Nível 4
e) Nível 0

**Sua resposta:**


> [!success]- Gabarito
> **c) Nível 3:** alta confiança na identidade, exige **mais de um fator**. O **nível 4** exige múltiplos fatores **e registro presencial** (ex.: policial acessando base criminal).
> 📚 *Fonte: [STA] §3.1*

---

## Questão 15 (Discursiva)
Diferencie **grupo** e **papel** (*role*).

**Sua resposta:**


> [!success]- Gabarito
> - **Grupo:** um **conjunto de principais**, um atalho para dar direitos a vários principais ao mesmo tempo [AND][BIS].
> - **Papel:** um **conjunto de funções** assumidas por pessoas diferentes em sucessão (ex.: "o oficial de serviço") [AND]. Para Bishop, é um tipo de grupo que **liga a participação à função**: ao assumir o papel, o principal recebe os direitos; **ao deixá-lo, perde-os**.
> 📚 *Fonte: [AND] §1.7 · [BIS] §15.4*
