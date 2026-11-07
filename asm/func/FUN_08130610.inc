	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _08130696
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	bl FUN_08086878
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _0813063C
	bl Coffin_IsIdle
	cmp r0, #0
	bne _0813065C
_0813063C:
	ldr r0, _08130658 @ =0x00000662
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r2, r4, r1
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08130696
	.align 2, 0
_08130658: .4byte 0x00000662
_0813065C:
	ldr r2, _0813066C @ =0x00000662
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08130670
	subs r0, #1
	strh r0, [r1]
	b _08130696
	.align 2, 0
_0813066C: .4byte 0x00000662
_08130670:
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #4
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813068A
	movs r0, #1
	b _0813068C
_0813068A:
	movs r0, #0
_0813068C:
	cmp r0, #0
	bne _08130696
	adds r0, r5, #0
	bl FUN_08130508
_08130696:
	pop {r4, r5}
	pop {r0}
	bx r0
