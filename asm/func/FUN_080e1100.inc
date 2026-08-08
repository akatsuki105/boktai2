	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r6, r1, #0
	mov r8, r2
	movs r5, #0
_080E1110:
	mov r1, r8
	ldr r0, [r1]
	bl FUN_080edce8
	adds r4, r0, #0
	cmp r4, #0
	beq _080E119A
	movs r1, #0x80
	lsls r1, r1, #3
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080E1194
	ldrh r0, [r4]
	mov r7, r8
	str r0, [r7]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E1194
	mov r0, sb
	movs r1, #0
	ldrsh r3, [r0, r1]
	movs r7, #0
	ldrsh r2, [r6, r7]
	subs r0, r3, r2
	movs r7, #8
	ldrsh r1, [r4, r7]
	cmp r0, r1
	bgt _080E1194
	adds r0, r3, r2
	cmp r0, r1
	blt _080E1194
	mov r0, sb
	movs r1, #2
	ldrsh r3, [r0, r1]
	movs r7, #2
	ldrsh r2, [r6, r7]
	subs r0, r3, r2
	movs r7, #0xa
	ldrsh r1, [r4, r7]
	cmp r0, r1
	bgt _080E1194
	adds r0, r3, r2
	cmp r0, r1
	blt _080E1194
	mov r0, sb
	movs r1, #4
	ldrsh r3, [r0, r1]
	movs r7, #4
	ldrsh r2, [r6, r7]
	subs r0, r3, r2
	movs r7, #0xc
	ldrsh r1, [r4, r7]
	cmp r0, r1
	bgt _080E1194
	adds r0, r3, r2
	cmp r0, r1
	blt _080E1194
	adds r0, r4, #0
	b _080E119C
_080E1194:
	adds r5, #1
	cmp r5, #0x13
	ble _080E1110
_080E119A:
	movs r0, #0
_080E119C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
