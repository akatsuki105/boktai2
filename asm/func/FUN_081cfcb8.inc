	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081CFD2C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081CFD30
	movs r0, #6
	bl FUN_0808660c
	cmp r0, #0
	bne _081CFD30
	movs r0, #7
	bl FUN_0808660c
	cmp r0, #0
	bne _081CFD30
	bl FUN_080865c0
	adds r3, r0, #0
	cmp r3, #0
	beq _081CFD30
	mov r4, sp
	adds r2, r5, #0
	adds r2, #0x80
	ldrh r0, [r3]
	ldrh r1, [r2]
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
	bge _081CFD16
	rsbs r0, r0, #0
_081CFD16:
	cmp r0, #0x80
	bgt _081CFD30
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _081CFD24
	rsbs r0, r0, #0
_081CFD24:
	cmp r0, #0x80
	bgt _081CFD30
	movs r0, #1
	b _081CFD32
	.align 2, 0
_081CFD2C: .4byte 0x030047A4
_081CFD30:
	movs r0, #0
_081CFD32:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
