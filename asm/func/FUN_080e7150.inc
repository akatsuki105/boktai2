	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	adds r5, r1, #0
	movs r0, #0
	mov sb, r0
	ldr r7, _080E71FC @ =0x7FFFFFFF
	mov r3, sp
	ldr r4, _080E7200 @ =0x03002BE0
	movs r6, #3
_080E716A:
	ldr r0, [r4]
	cmp r0, #0
	beq _080E71AC
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	cmp r7, r1
	ble _080E71AC
	adds r7, r1, #0
	ldr r0, [r4]
	adds r0, #0x24
	mov sb, r0
_080E71AC:
	adds r4, #4
	subs r6, #1
	cmp r6, #0
	bge _080E716A
	mov r0, sb
	cmp r0, #0
	beq _080E71EC
	movs r6, #0x80
	lsls r6, r6, #5
	movs r5, #0xc0
	lsls r5, r5, #1
	add r5, r8
	ldrh r0, [r5]
	ands r0, r6
	cmp r0, #0
	beq _080E71E2
	movs r4, #0x97
	lsls r4, r4, #3
	add r4, r8
	ldr r0, [r4]
	bl FUN_080f8e3c
	ldrh r0, [r5]
	bics r0, r6
	movs r1, #0
	strh r0, [r5]
	str r1, [r4]
_080E71E2:
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, r8
	mov r1, sb
	str r1, [r0]
_080E71EC:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E71FC: .4byte 0x7FFFFFFF
_080E7200: .4byte 0x03002BE0
