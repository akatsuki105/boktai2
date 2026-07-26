.syntax unified
	.thumb
	.macro glabel label
	.global \label
	.thumb_func
	\label:
	.endm
