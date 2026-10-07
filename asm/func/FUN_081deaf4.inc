	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _081DEB38 @ =0x030044D0
	movs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEB10
	movs r0, #1
	bl Sound_FadeOutBGM
_081DEB10:
	ldr r0, [r4, #0x34]
	cmp r0, #1
	bne _081DEB20
	movs r2, #4
	ldr r1, _081DEB3C @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081DEB20:
	adds r0, r4, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DEB40
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DEBB4
	.align 2, 0
_081DEB38: .4byte 0x030044D0
_081DEB3C: .4byte 0x030044BC
_081DEB40:
	movs r6, #0
	movs r3, #0
	ldrh r5, [r4, #0x1a]
	cmp r6, r5
	bge _081DEB82
	movs r7, #0xf0
	lsls r7, r7, #6
_081DEB4E:
	cmp r3, #0
	bge _081DEB5C
	ldr r2, _081DEB58 @ =0x0000FFFF
	b _081DEB64
	.align 2, 0
_081DEB58: .4byte 0x0000FFFF
_081DEB5C:
	ldr r2, [r4, #0x44]
	lsls r1, r3, #1
	adds r1, r1, r2
	ldrh r2, [r1]
_081DEB64:
	adds r1, r7, #0
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #6
	cmp r1, r2
	bne _081DEB74
	movs r1, #1
	b _081DEB76
_081DEB74:
	movs r1, #0
_081DEB76:
	cmp r1, #0
	beq _081DEB7C
	adds r6, #1
_081DEB7C:
	adds r3, #1
	cmp r3, r5
	blt _081DEB4E
_081DEB82:
	cmp r6, r5
	bne _081DEB98
	ldr r2, _081DEB94 @ =FUN_081debd4
	adds r0, r4, #0
	movs r1, #0xb
	bl Entity9A9F_SetState
	movs r0, #0
	b _081DEBB4
	.align 2, 0
_081DEB94: .4byte FUN_081debd4
_081DEB98:
	ldr r1, [r4, #0x34]
	cmp r1, #9
	bls _081DEBB4
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r4, #0
	adds r1, #0x42
	strh r2, [r1]
	ldr r3, _081DEBBC @ =0x030044BC
	movs r2, #5
	rsbs r2, r2, #0
	ldr r1, [r3]
	ands r1, r2
	str r1, [r3]
_081DEBB4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DEBBC: .4byte 0x030044BC
