(define (foreach func vlist)
  (if (null? vlist) #t
   (begin 
	 (func (car vlist))      
	 (foreach func (cdr vlist))
	))
)

(foreach (lambda (x) (newline) (display x))
  (list 57 321 88))
