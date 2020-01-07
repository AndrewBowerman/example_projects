;decisions.lisp
;Andrew Bowerman

; In which our hero sniffs the wind once for his foe...

(defvar magic 11)

(if (> magic 10)
	(format t "~D motes swirl through the air. 'By Crom!' Conan shouts. 'The wizard is here!" magic)
	(format t "~D motes twist in the wind. 'Show yourself wizard!' Conan shouts." magic)	
)