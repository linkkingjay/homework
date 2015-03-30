(define (deep-reverse tree)
  (cond ((null? tree)
           '())
        ((not (pair? tree))
           tree)
        (else
          (reverse (list (deep-reverse (car tree))
                         (deep-reverse (cadr tree)))))))

(define x (list (list 1 2 ) (list 3 4)))
(deep-reverse x)
