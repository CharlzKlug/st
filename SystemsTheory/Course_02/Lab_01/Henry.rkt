#lang racket
(require math/array)

(define (make-round bx)
  (make-array (vector bx) 5))