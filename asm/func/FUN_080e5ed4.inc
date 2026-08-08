	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r4, r1, #0
	mov ip, r2
	mov r8, r3
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	movs r2, #8
	ldrsh r6, [r5, r2]
	subs r3, r0, r6
	movs r7, #0x20
	ldrsh r0, [r4, r7]
	movs r2, #0xc
	ldrsh r1, [r5, r2]
	mov sb, r1
	subs r2, r0, r1
	movs r1, #0x80
	lsls r1, r1, #5
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r0, r5, r7
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E5F2C
	ldrh r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080E5F4E
	adds r0, r3, #0
	muls r0, r3, r0
	adds r1, r2, #0
	muls r1, r2, r1
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	bgt _080E5F4E
_080E5F28:
	movs r0, #1
	b _080E5FD8
_080E5F2C:
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	subs r0, r0, r6
	cmp r0, #0
	bge _080E5F38
	rsbs r0, r0, #0
_080E5F38:
	cmp r0, ip
	bhi _080E5F4E
	movs r7, #0x10
	ldrsh r0, [r4, r7]
	mov r1, sb
	subs r0, r0, r1
	cmp r0, #0
	bge _080E5F4A
	rsbs r0, r0, #0
_080E5F4A:
	cmp r0, r8
	bls _080E5F28
_080E5F4E:
	cmp r3, #0
	bne _080E5F56
	cmp r2, #0
	beq _080E5FD6
_080E5F56:
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _080E5F80 @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r7, [sp, #0x1c]
	muls r0, r7, r0
	cmp r0, #0
	blt _080E5F84
	asrs r0, r0, #0x10
	b _080E5F8A
	.align 2, 0
_080E5F80: .4byte 0x085B0A08
_080E5F84:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_080E5F8A:
	adds r3, r0, #0
	ldr r0, _080E5FA4 @ =0x085B0A08
	ldrb r1, [r5, #5]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r7, [sp, #0x1c]
	muls r0, r7, r0
	cmp r0, #0
	blt _080E5FA8
	asrs r0, r0, #0x10
	b _080E5FAE
	.align 2, 0
_080E5FA4: .4byte 0x085B0A08
_080E5FA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_080E5FAE:
	movs r2, #0x10
	ldrsh r1, [r5, r2]
	adds r2, r3, #0
	cmp r3, #0
	bge _080E5FBA
	rsbs r2, r3, #0
_080E5FBA:
	cmp r2, #0xa
	ble _080E5FC0
	adds r1, r1, r3
_080E5FC0:
	strh r1, [r5, #0x10]
	movs r7, #0x14
	ldrsh r1, [r5, r7]
	adds r2, r0, #0
	cmp r0, #0
	bge _080E5FCE
	rsbs r2, r0, #0
_080E5FCE:
	cmp r2, #0xa
	ble _080E5FD4
	adds r1, r1, r0
_080E5FD4:
	strh r1, [r5, #0x14]
_080E5FD6:
	movs r0, #0
_080E5FD8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
