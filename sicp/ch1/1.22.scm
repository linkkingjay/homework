(define (next-odd n)
  (if (odd? n)
      (+ n 2)
      (+ n 1)))

(define (continue-primes n count)
  (cond ((= count 0) (display "are primes."))
        ((prime? n)
           (display n)
           (newline)
           (continue-primes (next-odd n) (- count 1)))
        (else 
           (continue-primes (next-odd n) count))))

(define (search-for-primes n count)
  (let ((start-time (real-time-clock)))
     (continue-primes n count)
     (- (real-time-clock) start-time)))
