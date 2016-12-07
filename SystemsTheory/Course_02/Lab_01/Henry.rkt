#lang racket
(require math/array)

(define (make-round bx)
  (make-array (vector bx) 1))

(define a 
  (array #[#[1 0 3 2]
           #[2 0 3 1]
           #[3 0 2 1]
           #[3 1 2 0]]))

(define b 
  (array #[#[0 3 2 1]
           #[0 1 2 3]
           #[3 1 0 2]
           #[2 1 0 3]]))

(define solution
  (array #[0 0 3 2]))

(define (present-element? el arr ind)
    (if (< ind (array-size arr))
        (if (= (array-ref arr (vector ind)) el) 
            true
            (present-element? el arr (+ ind 1)))
        false))