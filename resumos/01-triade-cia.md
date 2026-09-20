# Tríade CIA: Confidencialidade, Integridade e Disponibilidade

> Fontes: [STA] §1.1, §1.2 · [BIS] §1.1, §1.2, §1.3 · [AND] §1.7 · [AT01] Q1

## 1. O que é segurança computacional

**Definição NIST (NISTIR 7298), citada em [STA] §1.1:**
> Medidas e controles que garantem a **confidencialidade**, a **integridade** e a **disponibilidade** dos ativos de sistemas de informação, incluindo hardware, software, firmware e a informação processada, armazenada e comunicada.

- Esses três objetivos formam a **tríade CIA** (*Confidentiality, Integrity, Availability*) e são os **objetivos fundamentais de segurança**, tanto para dados quanto para serviços de informação e computação [STA].
- Para Bishop, *"a segurança computacional se apoia em confidencialidade, integridade e disponibilidade"*. A **interpretação** de cada aspecto muda conforme as necessidades, os costumes e as leis da organização [BIS §1.1].
- A norma **FIPS 199** usa os três como objetivos de segurança e define o que significa **perder** cada um [STA].

---

## 2. Confidencialidade

### Definições
| Fonte | Definição |
|---|---|
| [STA] | Engloba dois conceitos: **Confidencialidade de dados**, que garante que informação privada ou confidencial não seja disponibilizada nem revelada a indivíduos não autorizados; e **Privacidade**, que garante que o indivíduo controle ou influencie qual informação sobre ele é coletada e armazenada, por quem, e a quem pode ser revelada. |
| FIPS 199 [STA] | Preservar as restrições autorizadas de acesso e divulgação, incluindo meios de proteger a privacidade pessoal e a informação proprietária. |
| [BIS] | **Ocultação** (*concealment*) de informação ou de recursos. |

> **Perda de confidencialidade = divulgação não autorizada da informação** (FIPS 199).

### Pontos importantes (Bishop)
- A necessidade vem de instituições com informação sensível (governo, indústria). O primeiro trabalho formal em segurança computacional veio da tentativa militar de impor o princípio da **"necessidade de saber" (*need to know*)**.
- **Mecanismos de controle de acesso** dão suporte à confidencialidade. A **criptografia** é um deles: transforma os dados para torná-los incompreensíveis. Só que a **chave criptográfica passa a ser mais um dado a proteger**.
  - Ex.: cifrar uma declaração de imposto de renda. Se alguém ler a chave quando ela for digitada e tiver acesso ao arquivo cifrado, a confidencialidade foi comprometida.
- A confidencialidade também vale para a **existência** do dado, que às vezes revela mais que o próprio dado (ex.: saber que uma pesquisa foi feita).
- **Ocultação de recursos**: organizações escondem configuração de rede e quais sistemas usam.
- Todos os mecanismos dependem de serviços de suporte do sistema (kernel etc.). Ou seja, **confidencialidade depende de suposições e de confiança**.

### Sigilo × Confidencialidade × Privacidade (Anderson)
| Termo | Significado |
|---|---|
| **Sigilo (*secrecy*)** | Termo de engenharia: o efeito dos mecanismos (criptografia, controle de acesso) que limitam quantos principais acessam a informação. |
| **Confidencialidade** | **Obrigação** de proteger os segredos de outra pessoa ou organização que você conhece. |
| **Privacidade** | **Capacidade/direito** de proteger sua informação pessoal e de impedir invasões do seu espaço pessoal. Não se aplica a pessoas jurídicas. |

> *"Privacidade é sigilo em benefício do indivíduo; confidencialidade é sigilo em benefício da organização."* [AND §1.7]
> Ex.: o paciente tem **direito à privacidade**; médicos e enfermeiros têm **dever de confidencialidade**.
> Além dos dados, às vezes é preciso proteger os **metadados** (quem falou com quem).

### Exemplos (níveis de impacto, [STA])
- **Alto:** notas dos alunos (reguladas por lei, a FERPA).
- **Moderado:** dados de matrícula.
- **Baixo:** listas de diretório (já públicas no site).
- [AT01]: um técnico de radiologia não deve acessar a área de laudos de um sistema PACS.

---

## 3. Integridade

### Definições
| Fonte | Definição |
|---|---|
| [STA] | **Integridade de dados**: informação e programas só são alterados de forma especificada e autorizada. **Integridade de sistema**: o sistema executa sua função pretendida sem prejuízo, livre de manipulação não autorizada, deliberada ou acidental. |
| FIPS 199 [STA] | Proteger contra **modificação ou destruição imprópria** da informação, incluindo garantir o **não repúdio** e a **autenticidade**. |
| [BIS] | **Confiabilidade** (*trustworthiness*) dos dados ou recursos, normalmente expressa como impedir mudanças impróprias ou não autorizadas. |

> **Perda de integridade = modificação ou destruição não autorizada da informação** (FIPS 199).

### Integridade de dados × integridade de origem (Bishop)
- **Integridade de dados**: o **conteúdo** da informação.
- **Integridade de origem**: a **fonte** do dado, **geralmente chamada de autenticação**.
- Ex. do jornal: um jornal publica um vazamento da Casa Branca exatamente como recebeu, mas atribui à fonte errada. A **integridade dos dados foi preservada** e a **integridade da origem foi corrompida**.

### Classes de mecanismos de integridade (Bishop)
1. **Prevenção**: bloqueia (a) tentativas **não autorizadas** de alterar dados (invasor mexendo na contabilidade) e (b) tentativas de alterar dados **de maneiras não autorizadas** por quem tem alguma autorização (contador que desvia dinheiro e esconde a transação). Autenticação e controle de acesso param o caso (a); o caso (b) exige controles bem diferentes.
2. **Detecção**: não impede a violação. Apenas **informa que a integridade dos dados não é mais confiável**, analisando eventos do sistema ou o próprio dado.

> **Integridade é mais difícil de tratar que confidencialidade.** Na confidencialidade, o dado foi comprometido ou não foi. A integridade envolve **correção e confiabilidade**, e depende da origem, da proteção antes da chegada e da proteção na máquina atual [BIS].

### Autenticidade = integridade + frescor (Anderson)
Na literatura de protocolos, **autenticidade** = integridade **+ frescor (*freshness*)**: você fala com um principal genuíno, e não com uma **reprodução (replay)** de mensagens antigas. Ex.: um cheque de 7 meses não foi alterado (tem integridade), mas **não é mais válido**.

### Exemplos ([STA])
- **Alto:** informação de alergias de um paciente (erro pode matar). É preciso restaurar rápido e **rastrear o responsável**.
- **Moderado:** fórum de um site.
- **Baixo:** enquete anônima online.

---

## 4. Disponibilidade

### Definições
| Fonte | Definição |
|---|---|
| [STA] | Garante que os sistemas funcionem prontamente e que o serviço **não seja negado a usuários autorizados**. |
| FIPS 199 [STA] | Garantir **acesso e uso oportunos e confiáveis** da informação. |
| [BIS] | **Capacidade de usar** a informação ou o recurso desejado. |

> **Perda de disponibilidade = interrupção do acesso ou do uso da informação ou do sistema** (FIPS 199).

### Pontos importantes (Bishop)
- *"Um sistema indisponível é pelo menos tão ruim quanto nenhum sistema."*
- O aspecto que interessa à segurança: alguém pode **deliberadamente** negar acesso a dados ou serviços.
- Os projetos assumem um **modelo estatístico** de uso. O atacante manipula o uso (ex.: tráfego) para invalidar o modelo, e aí os mecanismos falham.
- **DoS (negação de serviço)** são os ataques mais difíceis de detectar, porque é preciso decidir se o padrão incomum é manipulação deliberada ou um evento atípico legítimo.
- Ex.: Anne compromete o servidor **secundário** de saldos de um banco. Um cúmplice derruba o **primário**, e os comerciantes passam a consultar o secundário, que aprova todos os cheques dela. Um ataque à disponibilidade serviu de apoio a uma fraude.

### Exemplos ([STA])
- **Alto:** serviço de autenticação de sistemas críticos.
- **Moderado:** site público de uma universidade.
- **Baixo:** lista telefônica online (existem alternativas).

---

## 5. Níveis de impacto (FIPS 199, [STA])
| Nível | Efeito adverso |
|---|---|
| **Baixo** | **Limitado**: degradação perceptível, danos e perdas pequenos. |
| **Moderado** | **Sério**: degradação significativa, dano significativo, sem risco de vida. |
| **Alto** | **Severo ou catastrófico**: a organização não consegue cumprir funções primárias, ou há risco de vida. |

---

## 6. Além da tríade ([STA] Fig. 1.1)
Dois conceitos adicionais aparecem com frequência:
- **Autenticidade**: ser genuíno, verificável e confiável. Verificar que os usuários são quem dizem ser e que cada entrada vem de uma fonte confiável.
- **Responsabilização (*accountability*)**: as ações de uma entidade podem ser **rastreadas unicamente** até ela. Dá suporte ao **não repúdio**, à dissuasão, ao isolamento de falhas, à detecção de intrusão e a ações legais.
- **A FIPS 199 inclui a autenticidade dentro da integridade.**

→ Detalhes em [[06-autenticidade-e-nao-repudio]].

---

## 7. Vulnerabilidades ↔ CIA ([STA], citando NRC02)
| O sistema pode ficar... | Propriedade atingida |
|---|---|
| **Corrompido** (faz a coisa errada, dados alterados) | Integridade |
| **Vazando** (*leaky*: quem não deve obtém acesso) | Confidencialidade |
| **Indisponível ou muito lento** | Disponibilidade |

---

## 8. Ameaças, ataques e consequências

**Terminologia ([STA] Tab. 1.1 · [BIS] §1.2)**
- **Ameaça**: potencial violação de segurança. A violação não precisa acontecer para a ameaça existir [BIS].
- **Ataque**: ameaça executada (ação de ameaça) [STA]. **Atacante** (agente de ameaça): quem executa.
- **Vulnerabilidade**: fraqueza que pode ser explorada por uma fonte de ameaça.
- **Contramedida**: meio para lidar com um ataque (prevenir; se falhar, detectar e recuperar). Pode introduzir novas vulnerabilidades.
- **Risco**: função do impacto adverso e da probabilidade de ocorrência.

**Consequências de ameaças (RFC 4949, [STA] Tab. 1.2)**
| Consequência | Ações de ameaça | Propriedade ameaçada |
|---|---|---|
| **Divulgação não autorizada** | exposição, interceptação, inferência, intrusão | **Confidencialidade** |
| **Engano (*deception*)** | mascaramento, falsificação, **repúdio** | **Integridade** (dados/sistema) |
| **Interrupção (*disruption*)** | incapacitação, corrupção, obstrução | **Disponibilidade** ou integridade do sistema |
| **Usurpação** | apropriação indevida, uso indevido | **Integridade do sistema** |

- *Inferência*: ex. **análise de tráfego**, obtendo informação só pelo padrão de tráfego.
- *Incapacitação* ataca a **disponibilidade**. *Corrupção* ataca a **integridade do sistema**.

**Ameaças comuns e o serviço que as combate (Bishop)**
| Ameaça | Classe | Combatida por |
|---|---|---|
| Bisbilhotagem (*snooping*), escuta passiva | Divulgação (passiva) | Confidencialidade |
| Modificação/alteração, escuta ativa, *man-in-the-middle* | Engano/interrupção/usurpação (ativa) | Integridade |
| Mascaramento/*spoofing* | Engano e usurpação | Integridade (aqui chamada de **serviços de autenticação**) |
| Repúdio de origem | Engano | Mecanismos de integridade |
| Negação de recebimento | Engano | Integridade e disponibilidade |
| Atraso (*delay*) | Usurpação | Disponibilidade |
| Negação de serviço (DoS) | Usurpação | Disponibilidade |

> **Delegação ≠ mascaramento** [BIS]: na delegação todos sabem ("sou Thomas e tenho autorização para agir em nome de Susan"). No mascaramento Thomas finge ser Susan. Delegação não é violação.

**Tipos de ataque ([STA])**
- **Ativo**: tenta **alterar** recursos ou afetar sua operação.
- **Passivo**: tenta **aprender/usar** informação sem afetar recursos.
- **Interno (*insider*)**: tem autorização, mas usa de forma não aprovada. **Externo (*outsider*)**: usuário não autorizado.

---

## 9. Política × mecanismo e objetivos da segurança ([BIS] §1.3)
- **Política de segurança**: declaração do que é e do que não é permitido.
- **Mecanismo de segurança**: método, ferramenta ou procedimento para **impor** a política (pode ser não técnico).
- Ex.: Anna não protege seus arquivos e Bill os copia. **Houve violação**, porque a falha de Anna não autoriza Bill.
- Objetivos dos mecanismos: **prevenção** (o ataque falha), **detecção** (determinar que houve ataque e reportar) e **recuperação** (parar o ataque e reparar danos, ou continuar funcionando corretamente durante o ataque).

---

## ⚠️ Pegadinhas de prova
- **Confidencialidade ≠ privacidade.** Para Stallings a privacidade é um *sub-conceito* da confidencialidade; para Anderson, confidencialidade é *obrigação* e privacidade é *direito*.
- **Autenticação aparece dentro de integridade** (integridade de origem [BIS]; a FIPS 199 inclui autenticidade e não repúdio em integridade).
- **Criptografia garante confidencialidade, mas não é suficiente sozinha**: a chave vira mais um segredo a proteger [BIS].
- **DoS → disponibilidade**. **Falsificar notas no banco de dados → integridade** (falsificação). **Interceptar pacotes → confidencialidade**.
- "Integridade" tem duas faces em Stallings (**dados** e **sistema**) e duas em Bishop (**dados** e **origem**). Não confunda.
