#lang racket
(require math/array)

(define (make-round bx)
  (make-array (vector bx) 1))

(define af 
  (array #[#[1 0 3 2]
           #[2 0 3 1]
           #[3 0 2 1]
           #[3 1 2 0]]))

(define bf 
  (array #[#[0 3 2 1]
           #[0 1 2 3]
           #[3 1 0 2]
           #[2 1 0 3]]))

(define ma1
  (array #[#[2 3 1 0]
           #[0 2 3 1]
           #[1 2 3 0]]))

(define mb1
  (array #[#[0 1 2]
           #[0 1 2]
           #[1 2 0]
           #[0 2 1]]))

(define msolution
  (array #[0 0 1 0]))

(define solution
  (array #[0 0 3 2]))

(define (present-element? el arr ind)
    (if (< ind (array-size arr))
        (if (and (not (= el -1)) 
                 (= (array-ref arr (vector ind)) el))
            true
            (present-element? el arr (+ ind 1)))
        false))

(define (good-iter? sol ind)
    (if (= ind (- (array-size sol) 1))
        true
        (if (present-element? (array-ref sol 
                                         (vector ind)) 
                              sol (+ ind 1))
            false
            (good-iter? sol (+ ind 1)))))

(define (good-solution? sol)
    (good-iter? sol 0))

(define (find-duplicate-a-iter sol ind)
    (if (>= ind (- (array-size sol) 1))
        'not-found
        (if (present-element? (array-ref 
                               sol 
                               (vector ind))
                              sol
                              (+ ind 1))
            (array-ref sol (vector ind))
            (find-duplicate-a-iter sol (+ ind 1)))))

(define (find-duplicate-a sol) ; Поиск дублей в решении возвращает a
  (find-duplicate-a-iter sol 0))

(define (position-b-iter a-array a-el b-el ind)
    (if (= (array-ref a-array (vector a-el ind)) b-el)
        ind
        (position-b-iter a-array a-el b-el (+ ind 1))))

(define (position-b a-array a-el b-el) ; Поиск позиции b-el в рейтинге a-el 
    (position-b-iter a-array a-el b-el 0))

(define (best-b-iter a-arr sol a-el b curr)
    (cond
      [(= curr (array-size sol)) b]
      [(not (= (array-ref sol (vector b)) a-el))
       (best-b-iter a-arr sol a-el (+ b 1) (+ curr 1))]
      [(and (= (array-ref sol (vector curr)) a-el)
            (< (position-b a-arr a-el curr)
               (position-b a-arr a-el b)))
       (best-b-iter a-arr sol a-el curr (+ curr 1))]
      [else (best-b-iter a-arr sol a-el b (+ curr 1))]))

(define (best-b a-arr sol a-el)
  ; Поиск наилучшего элемента b с точки зрения a-el
  ; a-arr - массив с a, sol - текущее решение
    (best-b-iter a-arr sol a-el 0 1))

(define (next-a-ind-iter b-arr b a ind)
    (cond
      [(= ind (- (vector-ref (array-shape b-arr) 1) 1)) -1]
      [(= (array-ref b-arr (vector b ind)) a)
       (array-ref b-arr (vector b (+ ind 1)))]
      [else (next-a-ind-iter b-arr b a (+ ind 1))]))

(define (next-a b-arr b a) ; Поиск следующего элемента после a в предпочтении b
    (next-a-ind-iter b-arr b a 0))

(define (move-solution-iter b-arr sol b a result ind)
    (cond
      [(< ind 0) result]
      [(or (not (= (array-ref sol (vector ind)) a))
           (= ind b))
       (move-solution-iter b-arr sol b a (cons (array-ref sol (vector ind)) result) (- ind 1))]
      [else (move-solution-iter b-arr sol b a (cons (next-a b-arr ind a) result) (- ind 1))]))

(define (move-solution b-arr sol b) ; Сдвиг всех элементов ответа совпадающих с желанием b, кроме b
  (list->array (move-solution-iter b-arr sol b (array-ref sol (vector b)) (list) (- (array-size sol) 1))))

(define (base-solution-iter b-arr ind result)
    (if (< ind 0) result
        (base-solution-iter b-arr (- ind 1) (cons (array-ref b-arr (vector ind 0)) result))))

(define (base-solution b-arr)
    (list->array (base-solution-iter b-arr (- (vector-ref (array-shape b-arr) 0) 1) (list))))

(define (get-solution-iter a-arr b-arr sol)
    (cond
      [(good-solution? sol) sol]
      [else (get-solution-iter a-arr b-arr (move-solution b-arr sol (best-b a-arr sol (find-duplicate-a sol))))]))

(define (get-solution a-arr b-arr) ; Главная функция
    (get-solution-iter a-arr b-arr (base-solution b-arr)))