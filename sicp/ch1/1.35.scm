(load "fixed-point.scm")

(define (phi)
  (fixed-point (lambda (x) (+ 1 (/ 1 x)))
               1.0))
