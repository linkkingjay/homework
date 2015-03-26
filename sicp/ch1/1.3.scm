(define (sum-of-max-two a b c)
  (cond ((and (>= a c) (>= b c)) (+ a b))
        ((and (>= a b) (>= c b)) (+ a c))
        ((and (>= b a) (>= c a)) (+ b c))))
