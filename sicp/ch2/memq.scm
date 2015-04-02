(define (memq item x)
  (cond ((null? x) #f)
        ((eq? item (car x)) #t)
        (else (memq item (cdr x)))))

(memq 'apple '(apple pear peach))
