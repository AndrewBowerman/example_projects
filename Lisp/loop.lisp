;loop.lisp
;Andrew Bowerman

; Conan's hands close around the wizard's sinewy arms and the old man is yanked aloft,
; feet kicking uselessly in the air.

(setf wizard_teeth 20)

(defun headbutt (n) 
	(loop for a from 0 to n
		do (format t "~D teeth remain in the wizard's head.~%" (- n a))
	)
)

(headbutt wizard_teeth)