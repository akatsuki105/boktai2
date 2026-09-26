	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, [sp, #0x3c]
	ldr r7, [sp, #0x40]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	cmp r5, #0
	beq _080DA9F2
	cmp r6, #0x7f
	bne _080DAA6C
	cmp r4, #0
	bne _080DA9F6
_080DA9F2:
	movs r0, #0
	b _080DAB8C
_080DA9F6:
	cmp r2, #5
	bls _080DA9FC
	b _080DAB8C
_080DA9FC:
	lsls r0, r2, #2
	ldr r1, _080DAA08 @ =_080DAA0C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DAA08: .4byte _080DAA0C
_080DAA0C: @ jump table
	.4byte _080DAA24 @ case 0
	.4byte _080DAA30 @ case 1
	.4byte _080DAA48 @ case 2
	.4byte _080DAA3C @ case 3
	.4byte _080DAA54 @ case 4
	.4byte _080DAA60 @ case 5
_080DAA24:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080d99d4
	b _080DAB8C
_080DAA30:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080d99d4
	b _080DAB8C
_080DAA3C:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080d9a9c
	b _080DAB8C
_080DAA48:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080d99d4
	b _080DAB8C
_080DAA54:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080d99d4
	b _080DAB8C
_080DAA60:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080d99d4
	b _080DAB8C
_080DAA6C:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #1
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #2
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #4
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #5
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #3
	bl FUN_080d9a9c
	movs r2, #4
	ldrh r1, [r5, #2]
	ands r1, r2
	movs r3, #0
	cmp r1, #0
	beq _080DAAB6
	movs r3, #0xff
_080DAAB6:
	mov r1, r8
	cmp r1, #5
	bhi _080DAB8C
	lsls r0, r1, #2
	ldr r1, _080DAAC8 @ =_080DAACC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DAAC8: .4byte _080DAACC
_080DAACC: @ jump table
	.4byte _080DAAE4 @ case 0
	.4byte _080DAAFE @ case 1
	.4byte _080DAB26 @ case 2
	.4byte _080DAB3A @ case 3
	.4byte _080DAB5E @ case 4
	.4byte _080DAB76 @ case 5
_080DAAE4:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	str r7, [sp]
	str r3, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r6, #0
	ldr r3, [sp, #0x44]
	bl FUN_080d9b3c
	b _080DAB8C
_080DAAFE:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	str r7, [sp]
	str r3, [sp, #4]
	ldr r3, [sp, #0x38]
	str r3, [sp, #8]
	mov r3, sb
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r6, #0
	ldr r3, [sp, #0x44]
	bl FUN_080d9cec
	b _080DAB8C
_080DAB26:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	str r3, [sp]
	str r5, [sp, #4]
	movs r0, #1
	adds r3, r7, #0
	bl FUN_080d9f5c
	b _080DAB8C
_080DAB3A:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	str r3, [sp]
	ldr r6, [sp, #0x38]
	str r6, [sp, #4]
	mov r3, sb
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	movs r0, #7
	adds r3, r7, #0
	bl FUN_080da698
	b _080DAB8C
_080DAB5E:
	adds r0, r5, #0
	adds r0, #8
	ldrh r1, [r5]
	str r3, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r5, [sp, #8]
	ldr r2, [sp, #0x44]
	adds r3, r7, #0
	bl FUN_080da358
	b _080DAB8C
_080DAB76:
	adds r0, r5, #0
	adds r0, #8
	ldrh r1, [r5]
	str r3, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r5, [sp, #8]
	ldr r2, [sp, #0x44]
	adds r3, r7, #0
	bl FUN_080da4f8
_080DAB8C:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
