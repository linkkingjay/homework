(load "huffman.scm")
(define (generate-huffman-tree pairs)
  (successive-merge (make-leaf-set pairs)))

(define (successive-merge sorted-leaf-set)
  (if (> (length sorted-leaf-set) 2)
      (successive-merge
        (adjoin-set
          (make-code-tree
            (car sorted-leaf-set)
            (cadr sorted-leaf-set))
          (cddr sorted-leaf-set)))
      (make-code-tree
        (car sorted-leaf-set)
        (cadr sorted-leaf-set))))
