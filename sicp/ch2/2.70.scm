(load "2.68-encode.scm")
(load "2.69-generate-huffman-tree.scm")

(define pairs (list
                (list 'A 2)
                (list 'NA 16)
                (list 'BOOM 1)
                (list 'SHA 3)
                (list 'GET 2)
                (list 'YIP 9)
                (list 'JOB 2)
                (list 'WAH 1)))

(define tree (generate-huffman-tree pairs))

(newline)
(display (encode (list 'Get 'a 'job 'Sha
                       'na 'na 'na 'na 'na 'na 'na 'na
                       'Get 'a 'job 'Sha
                       'na 'na 'na 'na 'na 'na 'na 'na
                       'Wah 'yip 'yip 'yip 'yip 'yip 'yip 'yip 'yip 'yip
                       'Sha 'boom) tree))
