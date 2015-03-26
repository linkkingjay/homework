(load "1.42.scm") ;compose

(define (repeated f n)
  (if (> n 0)
      f
      (compose f (repeated f (- n 1)))))

((repeated square 2) 5)
