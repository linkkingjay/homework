(load "2.2-segment.scm")

(define (make-rectangle length-1 length-2 width-1 width-2)
  (cons (cons length-1 length-2)
        (cons width-1 width-2)))

(define (length1-of-rectangle r)
  (car (car r)))
(define (length2-of-rectangle r)
  (cdr (car r)))
(define (width1-of-rectangle r)
  (car (cdr r)))
(define (width2-of-rectangle r)
  (cdr (cdr r)))

(define (length-of-rectangle r)
  (length-of-segment (length1-of-rectangle r)))
(define (width-of-rectangle r)
  (length-of-segment (width1-of-rectangle r)))

(define (perimeter-rectangle r)
  (let ((length (length-of-rectangle r))
        (width (width-of-rectangle r)))
       ( * 2 (+ length width))))

(define (area-rectangle r)
  (* (length-of-rectangle r) (width-of-rectangle r)))


(define rect (make-rectangle
               (make-segment (make-point 1 4) (make-point 4 4))
               (make-segment (make-point 1 2) (make-point 4 2))
               (make-segment (make-point 1 2) (make-point 1 4))
               (make-segment (make-point 4 2) (make-point 4 4))))

(display (perimeter-rectangle rect))
(newline)
(display (area-rectangle rect))
