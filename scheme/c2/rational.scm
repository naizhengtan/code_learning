; helper
(define (gcd a b)
 (if (= b 0)
  a
  (gcd b (remainder a b))))

; data structure
 	(define (positive x)
	 (= (abs x) x))
	(define (samesymbole? x y)
	 (equal? (positive x) (positive y)))

(define (make-rat on od)
	(let ((n (abs on)) (d (abs od)))
		  (let ((gcdv (gcd n d)))
		  (let ((x (/ n gcdv))
	 	       (y (/ d gcdv)))
 				(cons (if (samesymbole? on od) x (- x)) y)
				)
		  )
	)
)

(define (number x) (car x))
(define (denom x) (cdr x))

; operations
(define (add x y)
 (make-rat (+ (* (number x) (denom y))
			  (* (denom x) (number x)))
           (* (denom x) (denom y))
 )
)

(define (sub x y)
 (make-rat (- (* (number x) (denom y))
			  (* (denom x) (number x)))
           (* (denom x) (denom y))
 )
)

(define (mul x y)
 (make-rat (* (number x) (number y))
  		   (* (denom x) (denom y))))

(define (div x y)
 (make-rat (* (number x) (denom y))
  		   (* (denom x) (number y))))

(define (equal x y)
 (if (= (* (number x) (denom y))
	    (* (denom x) (number y)))
  #t #f))

(define (print x)
 (newline)
 (display (number x))
 (display "/")
 (display (denom x)))

; test
(mul (make-rat (- 2) 3) (make-rat 1  2))
