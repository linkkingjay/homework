(load "2.67.scm")
(define (encode message tree)
  (if (null? message)
      '()
      (append (encode-symbol (car message) tree)
              (encode (cdr message) tree))))

(define (encode-symbol symbol tree)
  (cond ((leaf? tree) '())
        ((symbol-in-tree? symbol (left-branch tree))
          (cons 0
                (encode-symbol symbol (left-branch tree))))
        ((symbol-in-tree? symbol (right-branch tree))
          (cons 1
                (encode-symbol symbol (right-branch tree))))
        (else
          (error "This symbol is not in the tree: " symbol))))

(define (symbol-in-tree? symbol tree)
  (not
    (false?
      (find (lambda (s)
              (eq? s symbol))
            (symbols tree)))))

(encode (list 'A 'D 'A 'B 'B 'C 'A) sample-tree) ; 0 1 1 0 0 1 0 1 0 1 1 1 0
