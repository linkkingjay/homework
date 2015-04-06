(define (make-accumulator num)
  (lambda (x)
    (set! num (+ num x))
    num))

(define A (make-accumulator 5))
