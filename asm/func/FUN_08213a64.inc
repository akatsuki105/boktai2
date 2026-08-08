	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x78
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #1
	bne _08213B08
	ldr r0, _08213AA0 @ =0x030044E0
	ldrh r2, [r0, #2]
	ands r1, r2
	cmp r1, #0
	beq _08213AA4
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r1, #0x83
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #2
	cmp r0, #0
	bne _08213A9C
	movs r1, #1
_08213A9C:
	adds r0, r1, #0
	b _08213B28
	.align 2, 0
_08213AA0: .4byte 0x030044E0
_08213AA4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08213AB6
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #3
	b _08213B28
_08213AB6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08213ACC
	movs r1, #0x83
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _08213AE2
_08213ACC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08213AFC
	movs r2, #0x83
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08213AFC
_08213AE2:
	adds r2, r5, #0
	adds r2, #0x8e
	ldrh r0, [r2]
	movs r1, #1
	subs r1, r1, r0
	strh r1, [r2]
	adds r0, r4, #0
	bl FUN_0821397c
	movs r0, #0xdf
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08213AFC:
	adds r0, r5, #0
	adds r0, #0x20
	adds r1, r5, #0
	bl FUN_082372cc
	b _08213B1C
_08213B08:
	ldr r0, _08213B18 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08213B1C
	movs r0, #1
	b _08213B28
	.align 2, 0
_08213B18: .4byte 0x030044E0
_08213B1C:
	adds r1, r5, #0
	adds r1, #0x90
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
_08213B28:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
