	push {lr}
	lsls r2, r2, #4
	adds r2, r0, r2
	movs r0, #0
	ldrsh r3, [r1, r0]
	ldrb r0, [r2]
	lsls r0, r0, #8
	cmp r3, r0
	blt _08235956
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	cmp r3, r0
	bge _08235956
	movs r0, #4
	ldrsh r1, [r1, r0]
	ldrb r0, [r2, #1]
	lsls r0, r0, #8
	cmp r1, r0
	blt _08235956
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	cmp r1, r0
	bge _08235956
	movs r0, #1
	b _08235958
_08235956:
	movs r0, #0
_08235958:
	pop {r1}
	bx r1
