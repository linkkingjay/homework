(load "set.scm")

(define (union-set set1 set2)
  (cond ((null? set1) set2)
        ((null? set2) set1)
        (else 
          (union-set
            (cdr set1)
            (adjoin-set (car set1) set2)))))

(define set1 (list 1 2 3 4 5))
(define set2 (list 3 4 5 6 7))

(union-set set1 set2)
