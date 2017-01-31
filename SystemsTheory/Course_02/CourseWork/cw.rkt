#lang racket

(require math/array)

(define costs
  (array #[5 3 6 2 4]))

(define weights
  (array #[3 2 4 1 2]))

(define costss1
  (array #[5 6 2 3 1]))

(define costss2
  (array #[4 3 5 4 3]))

(define weights2
  (array #[3 2 4 2 1]))

(define tl1
  (list 1 2 5 4 3 2 1 0))

(define tl2
  (list 4 4 7 4 3 2 1 0))

(define (backpack costs weights maxweight item)
  (cond
    [(= item 0) (if (>= maxweight (array-ref weights (vector item)))
                    (cons (array-ref costs (vector item)) (list item))
                    (list 0))]
    [(= maxweight 0) (list 0)]
    [else (let ([old-cost (backpack costs weights maxweight (- item 1))]
                [new-cost (if (>= maxweight (array-ref weights (vector item)))
                              (cons (+ (array-ref costs (vector item))
                                       (car (backpack costs weights 
                                                      (- maxweight 
                                                         (array-ref weights 
                                                                    (vector item))) 
                                                      (- item 1))))
                                    (cons item (cdr (backpack costs weights 
                                                              (- maxweight 
                                                                 (array-ref weights 
                                                                            (vector item))) 
                                                              (- item 1)))))
                              (list 0))])
            (if (> (car old-cost) (car new-cost))
                old-cost
                new-cost))]))

(define (gte list1 list2)
  ; Больше либо равно
  (if (and (>= (car list1) (car list2))
           (>= (car (cdr list1)) (car (cdr list2))))
      true
      false))

(define (present-greater? el lst)
  ; Есть ли в lst элемент больший чем el
  (cond
    [(eq? lst '()) false]
    [(gte (car lst) el) true]
    [else (present-greater? el (cdr lst))]))

(define (select-best-iter list1 list2 result)
  ; Создание списка с наилучшими вариантами
  (cond
    [(and (eq? list1 '())
          (eq? list2 '())) result]
    [(eq? list1 '())
     (let ([element (car list2)]
           [new-list (cdr list2)]) 
       (if (present-greater? element result)
           (select-best-iter list1 new-list result)
           (select-best-iter list1 new-list (cons element result))))]
    [else
     (let ([element (car list1)]
           [new-list (cdr list1)])
       (if (present-greater? element list2)
           (select-best-iter new-list list2 result)
           (select-best-iter new-list list2 (cons element result))))]))

(define (select-best list1 list2)
  (select-best-iter list1 list2 '()))

(define (add-solution-iter sol-list cost1 cost2 item result)
  (cond
    [(eq? sol-list '()) result]
    [else
     (let ([solution (car sol-list)]) 
       (add-solution-iter (cdr sol-list) cost1 cost2 item 
                          (cons 
                           (cons (+ (car solution) 
                                    cost1) 
                                 (cons (+ (cadr solution) 
                                          cost2) 
                                       (cons item (cddr solution)))) 
                           result)))]))

(define (add-solution sol-list cost1 cost2 item)
  (add-solution-iter sol-list cost1 cost2 item '()))

(define (knapsack-bicrit costs1 costs2 weights maxweight item)
  (define (get-arr sa ind)
    (array-ref sa (vector ind)))
  (define (get-weight ind)
    (get-arr weights ind))
  (define (get-cost1 ind)
    (get-arr costs1 ind))
  (define (get-cost2 ind)
    (get-arr costs2 ind))
  (cond
    [(= item 0)
     (list (if (>= maxweight (get-weight item))
               (list (get-cost1 item) (get-cost2 item) item)
               (list 0 0)))]
    [(= maxweight 0)
     (list (list 0 0))]
    [(>= maxweight (get-weight item))
     (let ([old-sol (knapsack-bicrit costs1 costs2 weights maxweight (- item 1))]
           [new-sol (add-solution (knapsack-bicrit costs1 
                                                   costs2 
                                                   weights 
                                                   (- maxweight (get-weight item)) 
                                                   (- item 1))
                                  (get-cost1 item)
                                  (get-cost2 item)
                                  item)])
       (select-best old-sol new-sol))]
    [else (knapsack-bicrit costs1 costs2 weights maxweight (- item 1))]))

(define (main)
    (let ([n 0]
          [prices '()]
          [c1 '()]
          [tp 0]
          [tl 0]
          [c2 '()])
      (printf "Введите количество принтеров: ")
      (set! n (read))
      (for ([i n])
        (printf "Введите цену принтера N ~a: " i)
        (set! prices (cons (read) prices))
        (printf "Введите цену картриджа принтера N ~a: " i)
        (set! tp (read))
        (printf "Введите количество печатаемых листов принтера N ~a: " i)
        (set! tl (read))
        (set! c1 (cons (- 1 (/ tp tl)) c1))
        (printf "Введите критерий энергопотребления принтера N ~a: " i)
        (set! c2 (cons (read) c2)))
      (set! prices (reverse prices))
      (set! c1 (reverse c1))
      (set! c2 (reverse c2))
      (printf "Введите бюджет на закупку: ")
      (knapsack-bicrit (list->array c1) (list->array c2) (list->array prices) (read) (- n 1))))