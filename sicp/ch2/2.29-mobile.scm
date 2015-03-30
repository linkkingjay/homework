(define (make-mobile left right)
  (list left right))

(define (make-branch length structure)
  (list length structure))

(define (left-branch m)
  (car m))

(define (right-branch m)
  (cadr m))

(define (branch-length b)
  (car b))

(define (branch-structure b)
  (cadr b))

(define (total-weight m)
  (+ (branch-weight (left-branch m))
     (branch-weight (right-branch m))))

(define (branch-weight b)
  (if (hangs-another-mobile? b)
      (total-weight (branch-structure b))
      (branch-structure b)))

(define (hangs-another-mobile? b)
  (pair? (branch-structure b)))

(define mobile (make-mobile (make-branch 10 20)
                            (make-branch 10 25)))
