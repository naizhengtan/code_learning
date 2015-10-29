(define zero (lambda (f) (lambda (x) x)))
(define one (lambda (f) (lambda (x) (f x))))
(define two (lambda (f) (lambda (x) (f (f x)))))

(define (myequal? x y) 
 (define (foo f) (+ 1 f))
	(= 
	 ((x foo) 1)
	 ((y foo) 1)
	))

(define (add1 n) (lambda (f) (lambda (x) (f ((n f) x)))))
(define (add n m) (lambda (f) (lambda (x) ((n f) ((m f) x)))))

(myequal? (add1 zero) one)
(myequal? (add1 (add1 zero)) two)
(myequal? (add1 zero) two)
(myequal? (add zero two) two)
(define three (add1 two))
(myequal? (add one two) three)
