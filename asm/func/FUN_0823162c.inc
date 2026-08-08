	push {lr}
	sub sp, #8
	cmp r0, #0
	beq _0823164C
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	ldr r1, _08231648 @ =gVM
	str r0, [r1]
	cmp r0, #0
	beq _0823164C
	ldr r0, [sp, #4]
	b _0823164E
	.align 2, 0
_08231648: .4byte gVM
_0823164C:
	movs r0, #0
_0823164E:
	add sp, #8
	pop {r1}
	bx r1
