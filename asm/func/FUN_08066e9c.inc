	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r5, [sp, #0x1c]
	ldr r6, [sp, #0x24]
	movs r7, #0
	ldrsh r0, [r1, r7]
	movs r7, #4
	ldrsh r1, [r1, r7]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp]
	ldrh r3, [r4, #0x24]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
	cmp r5, #0
	beq _08066ED0
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, [sp, #0x20]
	bl FUN_080613ec
_08066ED0:
	cmp r6, #0
	beq _08066EDA
	adds r0, r6, #0
	bl PlaySound_082406e0
_08066EDA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
