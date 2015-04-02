(define (split big-part small-part)
  (lambda (painter n)
    (if (= n 0)
        painter
        (let ((smaller ((split big-part small-part) (- n 1))))
          (big-part painter
                    (small-part smaller smaller))))))
