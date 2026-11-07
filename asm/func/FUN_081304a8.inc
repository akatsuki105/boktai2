	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	bl Coffin_GetPos
	adds r3, r0, #0
	cmp r3, #0
	beq _081304FE
	mov r4, sp
	adds r2, r5, #0
	adds r2, #8
	ldrh r0, [r3]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _081304E8
	rsbs r0, r0, #0
_081304E8:
	cmp r0, r6
	bgt _081304FE
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _081304F6
	rsbs r0, r0, #0
_081304F6:
	cmp r0, r7
	bgt _081304FE
	movs r0, #1
	b _08130500
_081304FE:
	movs r0, #0
_08130500:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
