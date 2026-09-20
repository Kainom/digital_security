# Questões: Tríade CIA (Confidencialidade, Integridade, Disponibilidade)

> [!info] Como usar
> Escreva sua resposta no espaço **Sua resposta**. O gabarito fica **oculto**: clique em **Gabarito** para expandir **só depois de responder**. Depois peça ao agente para corrigir.
> Resumo de apoio: [[01-triade-cia]]

---

## Questão 1 (Discursiva)
Apresente a definição de **segurança computacional** do NIST e explique por que confidencialidade, integridade e disponibilidade são chamadas de "tríade CIA".

**Sua resposta:**


> [!success]- Gabarito
> **NIST (NISTIR 7298):** "medidas e controles que garantem a confidencialidade, a integridade e a disponibilidade dos ativos de sistemas de informação, incluindo hardware, software, firmware e a informação processada, armazenada e comunicada".
> Os três conceitos formam a **tríade CIA** porque são os **objetivos fundamentais de segurança** tanto para **dados** quanto para **serviços de informação e computação**. A FIPS 199 os lista como os três objetivos de segurança da informação e dos sistemas.
> 📚 *Fonte: [STA] §1.1*

---

## Questão 2 (Discursiva)
Segundo a **FIPS 199**, defina cada pilar da CIA e diga o que caracteriza a **perda** de cada um.

**Sua resposta:**


> [!success]- Gabarito
> - **Confidencialidade:** preservar restrições autorizadas de acesso e divulgação, incluindo a proteção da privacidade pessoal e da informação proprietária. **Perda = divulgação não autorizada.**
> - **Integridade:** proteger contra modificação ou destruição imprópria, incluindo garantir **não repúdio e autenticidade**. **Perda = modificação ou destruição não autorizada.**
> - **Disponibilidade:** garantir acesso e uso oportunos e confiáveis da informação. **Perda = interrupção do acesso ou uso.**
> 📚 *Fonte: [STA] §1.1*

---

## Questão 3 (Múltipla escolha)
Segundo Stallings, o conceito de **confidencialidade** abrange:

a) confidencialidade de dados e integridade de sistema
b) confidencialidade de dados e privacidade
c) privacidade e autenticidade
d) sigilo e disponibilidade
e) integridade de origem e privacidade

**Sua resposta:**


> [!success]- Gabarito
> **b)** Confidencialidade de **dados** (não disponibilizar a não autorizados) e **privacidade** (o indivíduo controla o que é coletado sobre ele, por quem e a quem é revelado).
> 📚 *Fonte: [STA] §1.1*

---

## Questão 4 (Discursiva)
Bishop divide a integridade em **integridade de dados** e **integridade de origem**. Explique a diferença e dê o exemplo do jornal.

**Sua resposta:**


> [!success]- Gabarito
> - **Integridade de dados:** o **conteúdo** da informação não foi alterado indevidamente.
> - **Integridade de origem:** a **fonte** do dado está correta. Bishop diz que ela é **frequentemente chamada de autenticação**.
> - **Exemplo:** um jornal publica uma informação vazada da Casa Branca **exatamente como recebeu** (integridade de dados preservada), mas **atribui a uma fonte errada** (integridade de origem corrompida).
> 📚 *Fonte: [BIS] §1.1.2*

---

## Questão 5 (Discursiva)
Explique as duas classes de mecanismos de integridade de Bishop e diferencie as **duas situações** que a prevenção precisa tratar.

**Sua resposta:**


> [!success]- Gabarito
> - **Prevenção:** mantém a integridade **bloqueando** (1) tentativas **não autorizadas** de alterar dados (ex.: invasor mexendo na contabilidade) e (2) tentativas de alterar dados **de maneiras não autorizadas** por alguém que tem alguma autorização (ex.: contador que desvia dinheiro e esconde a transação). Autenticação e controle de acesso param o caso (1); o caso (2) exige controles muito diferentes.
> - **Detecção:** **não impede** a violação, apenas **informa** que a integridade não é mais confiável, analisando eventos do sistema ou os próprios dados.
> 📚 *Fonte: [BIS] §1.1.2*

---

## Questão 6 (Múltipla escolha)
Associe cada cenário ao pilar **principal** violado (C = confidencialidade, I = integridade, D = disponibilidade):

1. Um aluno invade o sistema e altera suas próprias notas.
2. Um atacante captura pacotes numa rede Wi-Fi e lê e-mails alheios.
3. Um serviço de autenticação sai do ar por sobrecarga de requisições.
4. Uma enfermeira autorizada falsifica deliberadamente os dados de alergia de um paciente.

a) 1-C, 2-I, 3-D, 4-I
b) 1-I, 2-C, 3-D, 4-I
c) 1-I, 2-C, 3-I, 4-C
d) 1-D, 2-C, 3-D, 4-I
e) 1-I, 2-D, 3-C, 4-I

**Sua resposta:**


> [!success]- Gabarito
> **b)**
> 1. Alterar notas = **falsificação** → integridade.
> 2. Capturar pacotes = **interceptação** → confidencialidade.
> 3. Sobrecarga = **obstrução**/DoS → disponibilidade.
> 4. Falsificar dados de alergia (exemplo de Stallings de requisito **alto** de integridade) → integridade.
> 📚 *Fonte: [STA] §1.1 (exemplos) e Tab. 1.2*

---

## Questão 7 (Discursiva)
Diferencie **sigilo**, **confidencialidade** e **privacidade** segundo Anderson e explique a frase "privacidade é sigilo em benefício do indivíduo; confidencialidade é sigilo em benefício da organização".

**Sua resposta:**


> [!success]- Gabarito
> - **Sigilo:** termo de engenharia, o **efeito dos mecanismos** (criptografia, controle de acesso) que limitam quantos principais acessam a informação.
> - **Confidencialidade:** **obrigação** de proteger os segredos de outra pessoa ou organização que você conhece.
> - **Privacidade:** **capacidade/direito** de proteger sua informação pessoal e de impedir invasões do seu espaço pessoal (não se aplica a empresas).
> - **Exemplo:** o paciente tem **direito à privacidade**, e por isso médicos e enfermeiros têm **dever de confidencialidade**.
> 📚 *Fonte: [AND] §1.7*

---

## Questão 8 (Discursiva)
Por que Bishop afirma que ataques de **negação de serviço** estão entre os mais difíceis de detectar?

**Sua resposta:**


> [!success]- Gabarito
> Os sistemas são projetados a partir de um **modelo estatístico** dos padrões de uso esperados. O atacante manipula o uso (ou parâmetros como o tráfego de rede) para que o modelo deixe de valer, e os mecanismos passam a operar num ambiente para o qual não foram projetados. O analista precisa decidir se o padrão incomum é **manipulação deliberada** ou um **evento atípico legítimo**, e uma tentativa deliberada pode parecer (ou ser) apenas um evento atípico.
> 📚 *Fonte: [BIS] §1.1.3*

---

## Questão 9 (Múltipla escolha)
Segundo a RFC 4949 (citada por Stallings), **mascaramento, falsificação e repúdio** são ações que levam à consequência:

a) divulgação não autorizada, que ameaça a confidencialidade
b) engano (*deception*), que ameaça a integridade
c) interrupção (*disruption*), que ameaça a disponibilidade
d) usurpação, que ameaça a disponibilidade
e) inferência, que ameaça a confidencialidade

**Sua resposta:**


> [!success]- Gabarito
> **b)** **Engano** é a circunstância em que uma entidade autorizada recebe dados falsos e acredita neles. É uma ameaça à **integridade** do sistema ou dos dados.
> 📚 *Fonte: [STA] Tab. 1.2*

---

## Questão 10 (Discursiva)
Além da tríade CIA, Stallings cita dois conceitos adicionais. Quais são eles? Defina-os.

**Sua resposta:**


> [!success]- Gabarito
> - **Autenticidade:** ser genuíno, verificável e confiável. É a confiança na validade de uma transmissão, mensagem ou originador, ou seja, verificar que os usuários são quem dizem ser e que cada entrada vem de fonte confiável.
> - **Responsabilização (*accountability*):** as ações de uma entidade podem ser **rastreadas unicamente** até ela. Dá suporte a **não repúdio**, dissuasão, isolamento de falhas, detecção de intrusão, recuperação e ação legal.
> - Observação: a **FIPS 199 inclui a autenticidade dentro da integridade**.
> 📚 *Fonte: [STA] §1.1*

---

## Questão 11 (Discursiva)
Relacione os três tipos gerais de **vulnerabilidade** de um sistema (NRC) com os pilares da CIA.

**Sua resposta:**


> [!success]- Gabarito
> - O sistema pode ser **corrompido** (faz a coisa errada, dados alterados) → **integridade**.
> - O sistema pode **vazar** (quem não deveria obtém acesso) → **confidencialidade**.
> - O sistema pode ficar **indisponível ou muito lento** → **disponibilidade**.
> 📚 *Fonte: [STA] §1.1*

---

## Questão 12 (Discursiva)
Bishop diz que a criptografia é um mecanismo de controle de acesso que apoia a confidencialidade, mas aponta uma limitação. Qual? Use o exemplo da declaração de imposto de renda.

**Sua resposta:**


> [!success]- Gabarito
> A criptografia transforma os dados para torná-los incompreensíveis, e a **chave** controla o acesso ao dado original. Só que **a chave passa a ser mais um dado a ser protegido**. No exemplo, cifrar a declaração impede a leitura por quem não tem a chave; mas, se alguém **ler a chave quando ela for digitada** no programa de decifragem e tiver acesso à declaração cifrada, a **confidencialidade estará comprometida**.
> 📚 *Fonte: [BIS] §1.1.1*

---

## Questão 13 (Múltipla escolha)
Sobre os níveis de impacto da FIPS 199, está **correto** afirmar:

a) O impacto "moderado" envolve perda de vidas.
b) O impacto "baixo" corresponde a um efeito adverso limitado.
c) Só existem dois níveis: baixo e alto.
d) Os níveis se aplicam apenas à confidencialidade.
e) O impacto "alto" corresponde a um efeito adverso sério, sem risco de vida.

**Sua resposta:**


> [!success]- Gabarito
> **b)** Baixo = efeito adverso **limitado**; moderado = **sério** (sem risco de vida); alto = **severo ou catastrófico** (pode envolver perda de vidas). Os níveis valem para a perda de **qualquer** dos três pilares.
> 📚 *Fonte: [STA] §1.1*

---

## Questão 14 (Discursiva, base na Atividade 01)
Dê **um exemplo** de uso para cada pilar da CIA e justifique qual propriedade o exemplo protege.

**Sua resposta:**


> [!success]- Gabarito
> Resposta pessoal. Exemplos aceitos (dos livros e da atividade):
> - **Confidencialidade:** notas dos alunos disponíveis só para o aluno, os pais e os funcionários que precisam delas [STA]; um técnico de radiologia não acessa a área de laudos de um PACS [AT01].
> - **Integridade:** dados de alergia de pacientes precisam ser corretos e atuais, com possibilidade de rastrear quem alterou [STA].
> - **Disponibilidade:** um serviço de autenticação de sistemas críticos precisa estar sempre no ar [STA]; o sistema não deve impedir um usuário legítimo de acessar o que lhe é permitido [AT01].
> 📚 *Fonte: [STA] §1.1 · [AT01] Q1*
