	push {lr}
	ldr r1, _08229F48 @ =gVblankFlag
	movs r0, #0
	str r0, [r1]
_08229F3C:
	ldr r0, [r1]
	cmp r0, #0
	beq _08229F3C
	pop {r0}
	bx r0
	.align 2, 0
_08229F48: .4byte gVblankFlag
