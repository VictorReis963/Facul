; trabalho de xadrez - xeque do rei branco
; entrada: (chess (linha1 linha2 linha3 linha4 linha5 linha6 linha7 linha8))
;
; como executar (no terminal):
;   sbcl --script xeque.lisp
; ai o programa fica esperando a entrada, so digitar (ou colar) uma linha assim e apertar enter:
;   (chess ("........" "........" "........" "........" "t......R" "........" "........" "........"))
; nesse exemplo tem uma torre preta (t) na linha 5 dando xeque no rei branco (R) que ta na mesma linha,
; entao o programa deve responder T (verdadeiro)
;
; tambem da pra rodar sem precisar digitar na mao, mandando a entrada direto pelo pipe:
;   echo '(chess ("........" "........" "........" "........" "t......R" "........" "........" "........"))' | sbcl --script xeque.lisp

; converte uma linha pra lista de 8 chars
(defun linha-para-lista (linha)
  (if (numberp linha)
      (make-list linha :initial-element #\.)
      (loop for c across linha
            if (digit-char-p c)
              append (make-list (digit-char-p c) :initial-element #\.)
            else
              collect c)))

; cria a matriz 8x8
(defun monta-tabuleiro (linhas)
  (loop for l in linhas collect (linha-para-lista l)))

(defun pega-casa (tab l c)
  (nth c (nth l tab)))

(defun eh-preta (c)
  (and (not (char= c #\.)) (lower-case-p c)))

; acha onde ta o rei R
(defun acha-rei (tab)
  (dotimes (l 8)
    (dotimes (c 8)
      (if (char= (pega-casa tab l c) #\R)
          (return-from acha-rei (list l c))))))

; ve se o caminho entre duas casas ta livre
(defun caminho-livre (tab l1 c1 l2 c2)
  (let ((dl (signum (- l2 l1)))
        (dc (signum (- c2 c1)))
        (curr-l (+ l1 (signum (- l2 l1))))
        (curr-c (+ c1 (signum (- c2 c1)))))
    (loop while (or (/= curr-l l2) (/= curr-c c2)) do
      (if (not (char= (pega-casa tab curr-l curr-c) #\.))
          (return-from caminho-livre nil))
      (setf curr-l (+ curr-l dl))
      (setf curr-c (+ curr-c dc)))
    t))

; ve se a peca preta consegue atacar a casa do rei
(defun ataca (tipo l1 c1 l2 c2 tab)
  (let ((dl (- l2 l1))
        (dc (- c2 c1)))
    (cond
      ; peao preto
      ((char= tipo #\p)
       (and (= dl 1) (or (= dc 1) (= dc -1))))
      
      ; cavalo
      ((char= tipo #\c)
       (or (and (= (abs dl) 1) (= (abs dc) 2))
           (and (= (abs dl) 2) (= (abs dc) 1))))
      
      ; rei
      ((char= tipo #\r)
       (and (<= (abs dl) 1) (<= (abs dc) 1) (not (and (= dl 0) (= dc 0)))))
      
      ; bispo
      ((char= tipo #\b)
       (and (= (abs dl) (abs dc)) (caminho-livre tab l1 c1 l2 c2)))
      
      ; torre
      ((char= tipo #\t)
       (and (or (= dl 0) (= dc 0)) (caminho-livre tab l1 c1 l2 c2)))
      
      ; dama
      ((char= tipo #\d)
       (and (or (= dl 0) (= dc 0) (= (abs dl) (abs dc)))
            (caminho-livre tab l1 c1 l2 c2)))
      (t nil))))

; percorre o tabuleiro e testa se alguma peca preta ataca o rei
(defun rei-em-xeque (tab)
  (let* ((pos-rei (acha-rei tab))
         (l-rei (first pos-rei))
         (c-rei (second pos-rei)))
    ; se nao tem rei branco no tabuleiro, nao tem como estar em xeque
    (if (null pos-rei)
        (return-from rei-em-xeque nil))
    (dotimes (l 8)
      (dotimes (c 8)
        (let ((peca (pega-casa tab l c)))
          (when (eh-preta peca)
            (if (ataca peca l c l-rei c-rei tab)
                (return-from rei-em-xeque t))))))
    nil))

; main
(defun le-entrada-e-responde ()
  (let* ((entrada (read))
         (linhas (cadr entrada))
         (tab (monta-tabuleiro linhas)))
    (format t "~a~%" (rei-em-xeque tab))))

(le-entrada-e-responde)