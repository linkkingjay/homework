(define (fast-* b n)
  (fast-*-iter 0 b n))

(define (fast-*-iter a b n)
  (cond ((= n 0) a)
        ((even? n) (fast-*-iter a (double b) (halve n)))
        (else (fast-*-iter (+ a b) b (- n 1)))))

(define (even? n) 
 (= (remainder n 2) 0))
(define (double n)
  (* n 2))
(define (halve n)
  (/ n 2))
