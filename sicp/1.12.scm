(define (pascal-triangle x y)
  (if (or (= y 1) (= x y))
      1
      (+ (pascal-triangle (- x 1) y)
         (pascal-triangle (- x 1) (- y 1)))))
