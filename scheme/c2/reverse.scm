(define (append blist elem)
 (if (null? blist)
  	 (cons elem '())
	 (cons (car blist) (append (cdr blist) elem)))
)
;(append (list 1 2 3) 4)

(define (reverse vlist)
  (if (null? (cdr vlist))
   	  vlist 
	  (append (reverse (cdr vlist)) (car vlist)))
)

(reverse (list 1 4 9 16 25))

