(load "accumulate.scm")
(define (count-leaves tree)
  (accumulate (lambda (x y)
                (+ 1 y))
              0
              (enumerate-tree tree)))

(count-leaves (list 1 (list 2 (list 3 4)) 5))
