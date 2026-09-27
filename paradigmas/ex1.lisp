
(defparameter resultado (+ 10 5))
(defparameter resultado2 (- 20 7))
(* resultado 2)

(format t "O resultado é: ~A~%" resultado2)

(let((nome "carla") (idade 120) (cidade "pindaiba"))
(format t "eie ~A de ~A anos, velha p crl, vive em ~A, vulgo fim do mundo~%" nome idade cidade))
;-------------------------------------------------------------------------------------------------

;Lógica: Se a lista for vazia, a soma é 0.
; Caso contrário, some o primeiro elemento com a soma do resto.
(defun soma(lst) 
  (cond ((null lst )0)
    t(+(car lst)(soma(cdr lst)))))

;----------------------------------------------------------------------
