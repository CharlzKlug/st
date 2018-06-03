(defun calc-b (i j mi mj a b ul ur ub ut)
  "Calculate free members"
  (+ (if (= (1+ j) mj) (* a ut) 0)
     (if (= (1- j) 0) (* a ub) 0)
     (if (= (1+ i) mi) (* b ur) 0)
     (if (= (1- i) 0) (* b ul) 0)))

(defun make-equation-coefs (oi oj mi mj a b)
  "Generate equation coefficients"
  (loop for j from (1- mj) downto 1
     append (loop for i from (1- mi) downto 1
	       collect (cond
			 ((and (= i oi) (or (= j (1+ oj)) (= j (1- oj))))
			  a)
			 ((and (= j oj) (or (= i (1+ oi)) (= i (1- oi))))
			  b)
			 ((and (= i oi) (= j oj))
			  (* -2 (+ a b)))
			 (t 0)))))

(defun make-equation-system (mi mj a b ul ur ub ut)
  "Make equation system matrix"
  (loop for j from (1- mj) downto 1
     append (loop for i from (1- mi) downto 1
	       collect (append (make-equation-coefs i j mi mj a b)
			       (list (- (calc-b i j mi mj a b ul ur ub ut)))))))

(defun make-no-zero (some-list other-lists index)
  "Correct lead zero for Gauss method"
  (if (eq (nth index some-list) 0)
      (if (not (eq (nth index (car other-lists)) 0))
	  (map 'list (lambda (a b) (+ a b)) some-list
	       (car other-lists))
	  (make-no-zero some-list (cdr other-lists) index))
      some-list))

(defun down-step (eq-matrix row index)
  "Solve column to down"
  (if (eq eq-matrix '())
      '()
      (cons (map 'list (lambda (a b)
			 (+ a (* (/ b (nth index row))
				 (- (nth index (car eq-matrix))))))
		 (car eq-matrix) row)
	    (down-step (cdr eq-matrix) row index))))

(defun down (eq-matrix row index)
  "Make upper-diagonal matrix"
  (if (eq eq-matrix '())
      (cons row eq-matrix)
      (let ((non-zero-row (make-no-zero row eq-matrix index)))
	(cons non-zero-row
	      (let ((tmp-eq-matr
		     (down-step eq-matrix non-zero-row index)))
		(down (cdr tmp-eq-matr) (car tmp-eq-matr)
		      (1+ index)))))))

(defun up-step (eq-matrix row index)
  "Solve column to up"
  (if (eq eq-matrix '())
      '()
      (cons (map 'list (lambda (a b)
			 (+ a (* (/ b (nth index row))
				 (- (nth index (car eq-matrix))))))
		 (car eq-matrix) row)
	    (up-step (cdr eq-matrix) row index))))

(defun up (eq-matrix row index)
  "Left only lead diagonal"
  (if (eq eq-matrix '())
      (cons row eq-matrix)
      (let ((non-zero-row (make-no-zero row eq-matrix index)))
	(cons non-zero-row
	      (let ((tmp-eq-matr
		     (up-step eq-matrix non-zero-row index)))
		(up (cdr tmp-eq-matr) (car tmp-eq-matr)
		    (1- index)))))))

(defun to-e-matrix (eq-matrix)
  "Make E-matrix"
  (loop for i from 0 to (1- (length eq-matrix))
     collect (map 'list (lambda (x)
			  (/ x (nth i (nth i eq-matrix))))
		  (nth i eq-matrix))))

(defun gauss-solve (eq-matrix)
  "Solve by Gauss-method"
  (let ((up-tri-rev (reverse (down (cdr eq-matrix)
				   (car eq-matrix) 0))))
    (to-e-matrix (reverse (up (cdr up-tri-rev)
			      (car up-tri-rev)
			      (1- (length up-tri-rev)))))))

(defun solve (eq-matrix)
  "Remove E-matrix from answer"
  (map 'list (lambda (x) (car (last x))) (gauss-solve eq-matrix)))

(defun calc-steps (mx my hx hy ul ur ub ut)
  "Generate dots results"
  (let* ((x-steps (/ mx hx))
	 (y-steps (/ my hy))
	 (result (solve (make-equation-system x-steps y-steps (* hx hx) (* hy hy) ul ur ub ut))))
    ((lambda (i j lst)
       (loop for mj from j downto 1
	  append (loop for mi from i downto 1
		    collect(let ((cv (car lst)))
			     (progn
			       (setf lst (cdr lst))
			       (list mi mj cv))))))
     (1- x-steps) (1- y-steps) result)))

(princ (calc-steps 2 3 0.4 0.5 20 100 0 50))

((4.0 5.0 73.55806)
 (3.0 5.0 58.856167)
 (2.0 5.0 48.200317)
 (1.0 5.0 37.14626)
 (4.0 4.0 78.77232)
 (3.0 4.0 61.390404)
 (2.0 4.0 47.02286)
 (1.0 4.0 33.811592)
 (4.0 3.0 77.97764)
 (3.0 3.0 59.21471)
 (2.0 3.0 44.038746)
 (1.0 3.0 31.414927)
 (4.0 2.0 72.0901)
 (3.0 2.0 51.434433)
 (2.0 2.0 37.06689)
 (1.0 2.0 27.129372)
 (4.0 1.0 54.867874)
 (3.0 1.0 33.828976)
 (2.0 1.0 23.17313)
 (1.0 1.0 18.456074))
