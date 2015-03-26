(define (compose f g)
  (lambda (x) (f (g x))))

(define (inc x)
  (+ x 1))

((compose square inc) 6)
