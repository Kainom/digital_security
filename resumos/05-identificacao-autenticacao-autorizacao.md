# Identificação, Autenticação e Autorização

> Fontes: [STA] §1.3, §1.4, §3.1, §3.2, §4.1, §4.2, §4.5, §4.7 · [BIS] §13.1, §13.2, §13.9, §15.1, §15.3, §15.4 · [AND] §1.7 · [AT01] (MFA e fatores)

## 1. Visão geral: a sequência

```
IDENTIFICAÇÃO   →   AUTENTICAÇÃO   →   AUTORIZAÇÃO / CONTROLE DE ACESSO   →   AUDITORIA
"Quem você diz     "Prove que é       "O que você pode fazer?"            "O que você fez?"
 que é?"            você."
```

- **FIPS 200, requisito "Identificação e Autenticação"** [STA §1.3]: *identificar* usuários, processos que agem em nome deles ou dispositivos, e **autenticar (verificar)** essas identidades **como pré-requisito** para permitir acesso aos sistemas.
- **NIST SP 800-171** (Tab. 3.1 em [STA]), requisitos básicos:
  1. **Identificar** usuários, processos agindo em nome de usuários, ou dispositivos.
  2. **Autenticar (ou verificar)** essas identidades como **pré-requisito** para acesso.
- Stallings [§4.1]: *"O sistema precisa primeiro **autenticar** a entidade que busca acesso. Tipicamente, a autenticação determina se o usuário pode acessar o sistema **de alguma forma**. Depois, o **controle de acesso** determina se **o acesso específico solicitado** é permitido."*

---

## 2. Identidade e identificação

| Conceito | Definição |
|---|---|
| **Identidade** | *"Simplesmente a representação, no computador, de uma entidade."* [BIS Def. 15-1] |
| **Principal** | Uma **entidade única**. Uma identidade **especifica** um principal [BIS]. Anderson: entidade que **participa** de um sistema de segurança (pessoa, papel, equipamento, canal) [AND]. |
| **Sujeito** | Entidade capaz de acessar objetos. Normalmente equivale a um **processo** agindo por um usuário [STA §4.2]. |

**Para que serve a identidade (Bishop §15.1):**
1. **Responsabilização (*accountability*)**: rastrear o principal em cada ação (ligada a **logs e auditoria**).
2. **Controle de acesso**: base para decidir se um acesso é permitido.

**O que o ID faz num sistema com senha (Stallings §3.2):**
- determina **se o usuário está autorizado** a acessar o sistema;
- determina os **privilégios** do usuário (ex.: superusuário, convidado);
- é usado no **controle de acesso discricionário** (dar permissão listando IDs de outros usuários).

- Um mesmo principal pode ter **várias identidades**. Ex.: no UNIX, UID real, UID efetivo (usado no controle de acesso), UID salvo e UID de auditoria/login, que não pode ser alterado [BIS §15.3].
- Anderson: "identidade" costuma ser usada, de forma abusiva, só como **"nome"**.

---

## 3. Autenticação

### Definições
| Fonte | Definição |
|---|---|
| NIST SP 800-63-3 [STA §3.1] | **Processo de estabelecer confiança nas identidades de usuários** apresentadas eletronicamente a um sistema de informação. |
| [STA §4.1] | **Verificação de que as credenciais** de um usuário ou entidade **são válidas**. |
| [BIS Def. 13-1] | **Vinculação (*binding*) de uma identidade a um sujeito.** |

- O sistema usa a identidade autenticada para decidir se o indivíduo **está autorizado** a executar funções [STA §3.1].

### Modelo NIST SP 800-63-3 [STA Fig. 3.1]
1. **Registro:** o **requerente (*applicant*)** procura uma **autoridade de registro (RA)**, que atesta sua identidade para um **provedor de serviço de credencial (CSP)**. O requerente vira **assinante (*subscriber*)** e recebe uma **credencial**.
2. **Credencial:** estrutura de dados que **vincula de forma autoritativa uma identidade (e atributos) a um *token*** que o assinante possui.
3. **Autenticação:** o **reclamante (*claimant*)** prova ao **verificador (*verifier*)** que possui e controla o token.
4. O verificador passa uma **asserção** à **parte confiante (*relying party*, RP)**, que decide **acesso/autorização**.

### Meios (fatores) de autenticação
| [STA §3.1], 4 meios | [BIS §13.1], 4 fontes | [AT01] |
|---|---|---|
| **Algo que o indivíduo sabe**: senha, PIN, respostas a perguntas | **O que a entidade sabe** | **Conhecimento** |
| **Algo que possui**: cartão, smart card, chave física (**token**) | **O que a entidade tem**: crachá, cartão | **Posse** |
| **Algo que é** (**biometria estática**): digital, retina, face | **O que a entidade é**: digitais, retina | **Inerência** |
| **Algo que faz** (**biometria dinâmica**): voz, caligrafia, ritmo de digitação | **Onde a entidade está**: em frente a um terminal específico (**localização**) | — |

**Problemas de cada um [STA]:** senhas podem ser adivinhadas ou roubadas; tokens podem ser forjados, roubados ou perdidos; biometria tem **falsos positivos/negativos**, aceitação, custo e conveniência.

### Autenticação multifator (MFA)
- **Usa mais de um dos meios** da lista [STA]. **A força cresce com o número de fatores**: dois fatores são mais fortes que um, três mais fortes que dois [STA].
- Bishop: MFA usa **duas formas diferentes** de autenticação.
  - ✅ Senha + código enviado ao smartphone = **MFA** (sabe + tem).
  - ❌ Senha + resposta a uma pergunta = **NÃO é MFA**, porque ambos são "o que sabe".
  - Ex.: **Verificação em 2 etapas do Google**: senha + código de 6 dígitos no celular ou app.
- NIST SP 800-171: usar MFA para acesso local e de rede a **contas privilegiadas** e acesso de rede a **não privilegiadas** [STA Tab. 3.1].
- Princípio **separação de privilégio**: exigir **vários atributos de privilégio** para acessar um recurso. *"Um bom exemplo é a autenticação multifator"* [STA §1.4].
- [AT01]: MFA é uma camada a mais além da senha e **minimiza riscos de erro humano, senhas fracas e dispositivos extraviados**.

### Níveis de garantia (*assurance*), NIST SP 800-63-3 [STA]
| Nível | Confiança | Exemplo |
|---|---|---|
| 1 | Pouca ou nenhuma | fórum de discussão (ID + senha) |
| 2 | Alguma | negócios com o público; protocolo seguro + um meio |
| 3 | Alta | advogado enviando patente; **pelo menos 2 fatores** |
| 4 | Muito alta | policial acessando base criminal; **múltiplos fatores + registro presencial** |

### Sistema de autenticação (Bishop §13.1), 5 componentes
- **A**: informação de autenticação (ex.: senhas aceitáveis);
- **C**: informação complementar que o sistema **armazena** (ex.: hash da senha);
- **F**: funções de complementação f: A → C (ex.: função hash);
- **L**: funções de autenticação l: A × C → {verdadeiro, falso} (ex.: login);
- **S**: funções de seleção, para criar/alterar A e C (ex.: `passwd`).

### Senha
- *"Informação associada a uma entidade que confirma a identidade dela"* [BIS Def. 13-2].
- Ataques e contramedidas [STA §3.2]: dicionário offline (proteger o arquivo, reemitir senhas); **ataque a conta específica** (**bloqueio de conta**, tipicamente **≤ 5 tentativas**); senha popular contra muitos IDs; adivinhação com dados pessoais; **sequestro de estação** (logout automático); erros do usuário (engenharia social, senhas padrão); **mesma senha em vários sistemas**; **monitoramento eletrônico** (cifrar a senha **não resolve**: a senha cifrada vira a própria senha e pode ser reutilizada).
- Senhas continuam populares porque biometria e smart card exigem software nos dois lados, tokens são caros, *single sign-on* cria ponto único de risco e gerenciadores têm suporte ruim entre plataformas [STA].

---

## 4. Autorização e controle de acesso

### Definições ([STA §4.1], base RFC 4949)
| Conceito | Definição |
|---|---|
| **Autenticação** | Verificação de que as **credenciais** de um usuário ou entidade são **válidas**. |
| **Autorização** | **Concessão de um direito ou permissão** a uma entidade do sistema para **acessar um recurso**. Determina **quem é confiável para um dado propósito**. |
| **Auditoria** | Revisão e exame **independentes** de registros e atividades, para testar controles, garantir conformidade, detectar violações e recomendar mudanças. |
| **Controle de acesso** | Implementa uma **política de segurança** que especifica **quem ou o quê** pode acessar **cada recurso** e **que tipo de acesso** é permitido. |

- **Fluxo [STA Fig. 4.1]:** o usuário se **autentica** → a **função de controle de acesso** consulta a **base de dados de autorização** (mantida pelo administrador de segurança) → permite ou nega → a **auditoria** registra os acessos.
- FIPS 200, **Controle de acesso**: limitar o acesso a **usuários autorizados** (e processos/dispositivos) e aos **tipos de transação e funções** que eles podem exercer [STA §1.3].

### Elementos (Stallings §4.2)
- **Sujeito** (acessa): classes **dono (owner)**, **grupo (group)** e **mundo (world)**.
- **Objeto** (recurso controlado): arquivos, registros, diretórios, programas, portas…
- **Direito de acesso**: **ler, escrever, executar, apagar, criar, pesquisar**.

### Políticas de controle de acesso (Stallings §4.1)
| Política | Decide com base em… | Característica |
|---|---|---|
| **DAC** (discricionário) | **identidade** do solicitante e regras de autorização | A entidade pode, **por vontade própria**, dar acesso a outra. Modelo tradicional (**matriz de acesso**) |
| **MAC** (obrigatório) | **rótulos de segurança** (sensibilidade) × **habilitações** (*clearances*) | Quem tem acesso **não pode repassá-lo** por vontade própria. Origem militar |
| **RBAC** (baseado em papéis) | **papéis** do usuário no sistema | Direitos são dados a **papéis**, e usuários são associados a papéis. Implementa bem o **menor privilégio** |
| **ABAC** (baseado em atributos) | **atributos** do usuário, do recurso e do **ambiente** | Mais flexível |

- As políticas **não são mutuamente exclusivas** [STA].
- **Grupo × papel**: grupo = **conjunto de principais**; **papel** = conjunto de **funções** assumidas por pessoas diferentes em sucessão [AND]. Papel = tipo de grupo que **liga a participação à função**: ao sair do papel, o principal perde os direitos [BIS §15.4].

### Princípios de projeto ligados à autorização ([STA §1.4], Saltzer e Schroeder)
- **Menor privilégio**: cada processo e usuário opera com o **menor conjunto de privilégios necessário**. Tem aspecto **temporal** (privilégio de admin só quando necessário). Ex.: RBAC.
- **Padrões à prova de falhas (*fail-safe defaults*)**: decidir por **permissão**, não por exclusão. **O padrão é não ter acesso.**
- **Mediação completa**: **todo acesso** deve ser verificado. Não se deve confiar em decisões guardadas em cache.
- **Separação de privilégio**: vários atributos para acessar (ex.: MFA).
- **Aceitabilidade psicológica**: segurança não deve atrapalhar demais, senão o usuário a desliga.

---

## 5. ICAM: Identidade, Credencial e Gerenciamento de Acesso ([STA] §4.7)
| Componente | Função |
|---|---|
| **Gerenciamento de identidade** | Atribuir atributos a uma identidade digital e ligá-la a um indivíduo ou entidade não pessoa (processo, dispositivo). Inclui cadastro, provisionamento, desprovisionamento e ciclo de vida (incluindo **revogação**) |
| **Gerenciamento de credencial** | Ciclo de vida da **credencial**: patrocínio → inscrição (prova de identidade) → produção → emissão → manutenção (revogação, reemissão, expiração, suspensão) |
| **Gerenciamento de acesso** | Recursos (regras), **privilégios** (atributos de direito) e **políticas** (o que é permitido) |
| **Federação de identidade** | Confiar em identidades emitidas por **outra organização** |

- **Credencial** = objeto ou estrutura que **vincula de forma autoritativa uma identidade a um token**. Exemplos: **smart cards, chaves criptográficas pública/privada e certificados digitais** [STA].

---

## ⚠️ Pegadinhas de prova
- **Identificar ≠ autenticar.** Dizer "sou o João" (login/ID) é identificação; **provar** com senha, token ou biometria é autenticação.
- **Autenticar ≠ autorizar.** Autenticar = **quem você é**. Autorizar = **o que você pode fazer**. A autorização **vem depois** e depende da identidade autenticada.
- **Senha + pergunta secreta NÃO é MFA** (dois fatores do mesmo tipo) [BIS].
- Bishop inclui **localização** ("onde a entidade está") como fonte de autenticação; Stallings inclui **biometria dinâmica** ("algo que faz").
- **Mascaramento** (fingir ser outro) é combatido por **serviços de autenticação** [BIS §1.2].
- Autorização se liga a **confidencialidade e integridade**: limitar quem lê protege a confidencialidade; limitar quem altera protege a integridade.
- O exemplo da [AT01] (técnico em radiologia × laudos PACS) é um caso de **autorização/controle de acesso** protegendo a **confidencialidade**.
