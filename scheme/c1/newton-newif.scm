(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
		(else else-clause)
		)
  )

(define epsilon 0.00001)

(define (sqr_converge guess sqr) 
  (if (< 
		(abs (- (* guess guess) sqr) )
		epsilon
		)
	#t #f
	)
  )

(define (sqr_iter guess sqr)
	(new-if (sqr_converge guess sqr)
	 	guess
		(sqr_iter (/ (+ guess (/ sqr guess) ) 2) sqr)
	)
)

(define (sqr_iter_2 guess sqr)
	(cond ( (sqr_converge guess sqr)
	 	guess)
		(else (sqr_iter_2 (/ (+ guess (/ sqr guess) ) 2) sqr))
	)
)

(define (sqr_root x)
 (sqr_iter 1.0 x)
)

(sqr_root 2) ; fail horribly
