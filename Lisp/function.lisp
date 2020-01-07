;function.lisp
;Andrew Bowerman

; The wizard cannot hide from Conan.

(defvar magic 1)

(defun smell_for_magic (n)
	(if (> n 10)
		(format t "~D motes swirl through the air. 'By Crom!' Conan shouts. 'The wizard is here!~%" n)
		(format t "~D motes twist in the wind. 'Show yourself wizard!' Conan shouts.~%" n)	
	)
)

(smell_for_magic magic)
(setq magic 11); The reek of blood magic grows wet and coppery in the night air.
(smell_for_magic magic)