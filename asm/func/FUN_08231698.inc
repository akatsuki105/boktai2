	push {r4, r5, lr}
	sub sp, #8
	add r4, sp, #4
	ldr r5, _082316B8 @ =gVM
_082316A0:
	mov r1, sp
	adds r2, r4, #0
	bl VM_Step
	ldr r1, [sp]
	cmp r1, #0
	bne _082316A0
	str r1, [r5]
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_082316B8: .4byte gVM
