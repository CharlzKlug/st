#lang racket

(require math/array)

(define ma 
  (array #[#[5 4 8 3]
           #[3 2 4 1]
           #[2 1 6 7]
           #[1 3 2 8]]))

(define mb
  (array #[#[3 2 7 5]
           #[1 4 2 3]
           #[5 2 2 1]
           #[3 1 2 1]]))
  
; Вертикальный массив
(define va (array #[5 6 8 9]))

; Горизонтальный массив
(define ha (array #[0 3 0 0]))
  
(define (get-vert some-array)
  (array-axis-max some-array 1))

(define (present? a lst)
  (cond
    [(eq? lst '()) false]
    [(= a (car lst)) true]
    [else (present? a (cdr lst))]))

(define (by-column arr r c va ha cur res)
  (cond
    [(= r (vector-ref (array-shape arr) 0))
     (cons cur res)]
    [(= c (vector-ref (array-shape arr) 0))
     (if (not (= (length cur) (+ r 1)))
         res
         (by-column arr (+ r 1) 0 va ha cur res))]
    [(= (array-ref arr (vector r c)) (+ (array-ref va (vector r)) (array-ref ha (vector c))))
     (if (not (present? c cur))
         (by-column arr r (+ c 1) va ha cur (by-column arr (+ r 1) 0 va ha (cons c cur) res))
         (by-column arr r (+ c 1) va ha cur res))]
    [else (by-column arr r (+ c 1) va ha cur res)]))

(define testa
    (array #[#[6 1]
             #[7 5]]))

(define tva (array #[4 5]))

(define tha (array #[2 0]))

(define (efficiency k1 lst)
    (define (eff-iter k1 lst ef r)
      (cond
        [(eq? lst (list))
         ef]
        [else (eff-iter k1 (cdr lst) (+ ef (array-ref k1 (vector r (car lst)))) (- r 1))]))
    (eff-iter k1 lst 0 (- (vector-ref (array-shape k1) 0) 1)))

(define (maxel k-ar lst)
    (define (maxel-iter k-ar lst mmax r)
      (cond
        [(eq? lst (list)) mmax]
        [else
         (let ([cmax (array-ref k-ar (vector r (car lst)))])
           (if (> cmax mmax)
               (maxel-iter k-ar (cdr lst) cmax (- r 1))
               (maxel-iter k-ar (cdr lst) mmax (- r 1))))]))
    (maxel-iter k-ar lst (array-ref k-ar (vector (- (vector-ref (array-shape k-ar) 0) 1) (car lst))) (- (vector-ref (array-shape k-ar) 0) 1)))

(define (permutations k1 k2 r c cur res)
    (cond
      [(= r 0)
       (if (= c (vector-ref (array-shape k1) 0))
           res
           (permutations k1 k2 r (+ c 1) cur
                         (permutations k1 k2 (+ r 1) 0 (cons c cur) res)))]
      [(= r (vector-ref (array-shape k1) 0)) (cons (efficiency k1 cur) (cons (maxel k2 cur) (cons cur res)))]
      [(= c (vector-ref (array-shape k1) 0)) res]
      [else (if (present? c cur)
                (permutations k1 k2 r (+ c 1) cur res)
                (permutations k1 k2 (+ r 1) 0 (cons c cur)
                              (permutations k1 k2 r (+ c 1) cur res)))]))

(define (get-perm k1 k2)
    (permutations k1 k2 0 0 (list) (list)))

(define (get-max-sol lst)
    (define (get-max-iter m lst res)
      (cond
        [(eq? lst (list)) res]
        [(< m (car lst))
         (get-max-iter (car lst) (cdr (cdr (cdr lst))) (cons (car (cdr lst)) (cons (car (cdr (cdr lst))) (list))))]
        [(= m (car lst))
         (get-max-iter m (cdr (cdr (cdr lst))) (cons (car (cdr lst)) (cons (car (cdr (cdr lst))) res)))]
        [else (get-max-iter m (cdr (cdr (cdr lst))) res)]))
    (get-max-iter (car lst) lst (list)))

(define (min lst)
    (define (min-iter lst mmin res)
      (cond
        [(eq? lst (list))
         res]
        [(= mmin (car lst))
         (min-iter (cdr (cdr lst)) mmin (cons (reverse (car (cdr lst))) res))]
        [(> mmin (car lst))
         (min-iter (cdr (cdr lst)) (car lst) (cons (reverse (car (cdr lst))) (list)))]
        [else
         (min-iter (cdr (cdr lst)) mmin res)]))
    (min-iter lst (car lst) (list)))

(define (targeting a1 a2)
    (min (get-max-sol (get-perm a1 a2))))