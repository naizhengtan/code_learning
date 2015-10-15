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
	(if (sqr_converge guess sqr)
	 	guess
		(sqr_iter (/ (+ guess (/ sqr guess) ) 2) sqr)
	)
)

(define (sqr_root x)
 (sqr_iter 1.0 x)
)

(sqr_root 2)
