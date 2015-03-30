(define (square-tree tree)
  (map (lambda (sub-tree)
         (if (pair? sub-tree)
             (square-tree sub-tree)
             (square sub-tree)))
       tree))

(define (square-tree))
(square-tree
  (list 1
        (list 2 (list 3 4) 5)))
