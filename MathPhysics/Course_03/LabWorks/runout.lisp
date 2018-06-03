(defun runthrough-iter (alpha beta matrix)
  "Iterative tridiagonal matrix algorithm"
  (let* ((current-row (car matrix))
	 (gamma (if (and (= (length current-row) 3)
			 (not (eq (cdr matrix) '())))
		    (car current-row)
		    (+ (cadr current-row) (* (car current-row) alpha))))
	 (new-alpha (if (eq (cdr matrix) '())
			0
			(- (/ (if (= (length current-row) 3)
				  (cadr current-row)
				  (caddr current-row))
			      gamma))))
	 (new-beta (/ (- (if (= (length current-row) 3)
			     (caddr current-row)
			     (cadddr current-row))
			 (if (and (= (length current-row) 3)
				  (not (eq (cdr matrix) '())))
			     0
			     (* (car current-row) beta)))
		      gamma)))
    (if (eq (cdr matrix) '())
	(list new-beta)
	(let ((next-result (runthrough-iter new-alpha new-beta (cdr matrix))))
	  (cons (+ (* new-alpha (car next-result))
		   new-beta)
		next-result)))))

(defun runthrough (matrix)
  "Tridiagonal matrix algorithm"
  (runthrough-iter 0 0 matrix))

(defun gen-matrix (fa fb fc ff u0 u1 x0 x1 h n matrix)
  "Iterative generate a tridiagonal matrix"
  (if (= n 0)
      matrix
    (let ((x (+ x0 (* n h))))
      (if (eq matrix '())
	  (gen-matrix fa fb fc ff u0 u1 x0 x1 h (- n 1) 
		      (list (list (funcall fa x)
				  (funcall fb x)
				  (- (funcall ff x)
				     (* (funcall fc x) u1)))))
	(if (= n 1)
	    (gen-matrix fa fb fc ff u0 u1 x0 x1 h (- n 1)
			(cons (list (funcall fb x)
				    (funcall fc x)
				    (- (funcall ff x)
				       (* (funcall fa x) u0)))
			      matrix))
	    (gen-matrix fa fb fc ff u0 u1 x0 x1 h (- n 1)
			(cons (list (funcall fa x)
				    (funcall fb x)
				    (funcall fc x)
				    (funcall ff x))
			      matrix)))))))

(defun make-matrix (fa fb fc ff u0 u1 x0 x1 n)
  "Generate tridiagonal matrix"
  (gen-matrix fa fb fc ff u0 u1 x0 x1 (/ (- x1 x0) (+ n 1)) n '()))

(defun afunc (x)
  "Full analytical function"
  (+ (* (exp (- x))
	(+ (* (/ 11 3)
	      (cos (* (sqrt 2)
		      x)))
	   (* (/ (* 29 (sqrt 2))
		 6)
	      (sin (* (sqrt 2)
		      x)))))
     (/ 4 3)))

(defun make-xes-iter (x1 h n result)
  "Iterative generate x-es list"
  (if (= n 0) result
      (make-xes-iter (- x1 h) h (- n 1) (cons (- x1 h) result))))

(defun make-xes (x0 x1 n)
  "Make x-es list"
  (make-xes-iter x1 (/ (- x1 x0) (+ n 1)) n '()))

(defun asolve (x-list)
  "Analytical function for x-es list"
  (map 'list (lambda (x) (afunc x)) x-list))

(defun max-of-list (some-list)
  "Find maximum element of a list"
  (reduce #'max some-list))

(defun demo (n)
  "Demonstrate solvetion of an differential equation"
  (let* ((h (/ 1 (+ n 1)))
	 (x-list (make-xes 0 1 n))
	 (asolve-list (asolve x-list))
	 (esolve-list (runthrough (make-matrix (lambda (x) (- 1 h))
					       (lambda (x) (- (* 3 h h) 2))
					       (lambda (x) (+ 1 h))
					       (lambda (x) (* 4 h h))
					       5 4.0275116 0 1 n))))
    (progn
      (princ (format nil "~A~%"
		     (map 'list (lambda (a b c) (list a b c))
			  x-list asolve-list esolve-list)))
      (princ (format nil "Maximum error: ~A~%"
		     (max-of-list
		      (map 'list
			   (lambda (a b) (abs (- a b)))
			   asolve-list esolve-list))))
      1)))

(demo 10)

;https://ideone.com/4koIeP
					;https://ideone.com/jAXjJA
((1/11 5.453951 5.457959) (2/11 5.739212 5.745851) (3/11 5.8773737 5.885476)
 (4/11 5.889765 5.8983727) (5/11 5.797015 5.805369) (6/11 5.6187015 5.626229)
 (7/11 5.373083 5.3793793) (8/11 5.0769053 5.081716) (9/11 4.745274 4.748472)
 (10/11 4.391587 4.3931527))
Maximum error: 0.008607864
