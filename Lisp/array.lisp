;array.lisp
;Andrew Bowerman

; in which our hero spies an enemy caravan

(setf caravan (make-array '(5)));create 5 wagons
;(setf random_state (make-random-state t))

(setf (aref caravan 0) 2);last param is value on index
(setf (aref caravan 1) 0)
(setf (aref caravan 2) 1)
(setf (aref caravan 3) 6)
(setf (aref caravan 4) 3)

(write caravan)

;attack 3 random wagons
(print (aref caravan (random 4)))
(print (aref caravan (random 4)))
(print (aref caravan (random 4)))