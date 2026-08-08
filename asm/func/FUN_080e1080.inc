	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r0, #0
	mov r8, r0
_080E1090:
	ldr r0, [r6]
	bl FUN_080edce8
	adds r4, r0, #0
	cmp r4, #0
	beq _080E10F2
	ldrh r0, [r4]
	str r0, [r6]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E10E8
	movs r2, #0
	ldrsh r1, [r5, r2]
	movs r2, #8
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bgt _080E10E8
	adds r0, r1, #0
	movs r2, #0
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	movs r2, #8
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _080E10E8
	movs r0, #4
	ldrsh r1, [r5, r0]
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bgt _080E10E8
	adds r0, r1, #0
	movs r2, #4
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	movs r2, #0xc
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _080E10E8
	adds r0, r4, #0
	b _080E10F4
_080E10E8:
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #0x13
	ble _080E1090
_080E10F2:
	movs r0, #0
_080E10F4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
