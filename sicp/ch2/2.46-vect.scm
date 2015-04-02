(define (make-vect x y) (cons x y))
(define (xcor v) (car v))
(define (ycor v) (cdr v))

(define (add-vect v1 v2)
  (make-vect (+ (xcor v1) (xcor v2))
             (+ (ycor v1) (ycor v2))))

(define (sub-vect v1 v2)
  (make-vect (- (xcor v1) (xcor v2))
             (- (ycor v1) (ycor v2))))

(define (scale-vect v s)
  (make-vect (* (xcor v) s) (* (ycor v) s)))
