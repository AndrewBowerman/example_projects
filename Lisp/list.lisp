;array.lisp
;Andrew Bowerman

; in which our hero spies an enemy caravan

(setf caravan '(2 0 1 6 3));create 5 wagons

(write caravan)

(write (cdr ( cdr (cdr caravan)))));find the second to last wagon

(write caravan)