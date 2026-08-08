	push {r4, r5, r6, lr}
	sub sp, #8
	adds r2, r0, #0
	add r6, sp, #4
	adds r4, r1, #0
	movs r5, #2
_08231600:
	adds r0, r2, #0
	mov r1, sp
	adds r2, r6, #0
	bl VM_Step
	adds r2, r0, #0
	ldr r0, [sp, #4]
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _08231600
	ldr r0, _08231628 @ =gVM
	str r2, [r0]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08231628: .4byte gVM
