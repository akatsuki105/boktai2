	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x28
	lsls r1, r1, #5
	ldr r0, _0820FA24 @ =0x085AF0EC
	adds r4, r1, r0
	ldrh r3, [r5, #0x26]
	cmp r3, #0
	bne _0820FA0C
	movs r0, #0x14
	ldrsb r0, [r4, r0]
	movs r2, #0x15
	ldrsb r2, [r4, r2]
	movs r7, #0xd5
	lsls r7, r7, #2
	adds r1, r5, r7
	adds r0, #0x40
	adds r2, #0x54
	strh r0, [r1]
	strh r2, [r1, #2]
	strh r3, [r1, #4]
	strh r3, [r1, #6]
_0820FA0C:
	ldrh r0, [r4, #4]
	cmp r0, #2
	bne _0820FA28
	ldrh r1, [r4]
	movs r0, #0xd5
	lsls r0, r0, #2
	adds r3, r5, r0
	adds r0, r6, #0
	movs r2, #0x10
	bl FUN_08055e34
	b _0820FA3C
	.align 2, 0
_0820FA24: .4byte 0x085AF0EC
_0820FA28:
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r3, #0xd5
	lsls r3, r3, #2
	adds r0, r5, r3
	str r0, [sp]
	adds r0, r6, #0
	movs r3, #0x10
	bl FUN_08055dac
_0820FA3C:
	cmp r0, #0
	bge _0820FA46
	movs r0, #1
	rsbs r0, r0, #0
	b _0820FA70
_0820FA46:
	ldrb r1, [r4, #0xb]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0820FA58
	ldrh r1, [r4, #8]
	adds r0, r6, #0
	bl FUN_08055fbc
_0820FA58:
	adds r0, r6, #0
	movs r1, #2
	bl FUN_08055f5c
	ldrb r0, [r4, #0xa]
	ldr r7, _0820FA78 @ =0x00000366
	adds r1, r5, r7
	ldr r3, _0820FA7C @ =0x00000367
	adds r2, r5, r3
	bl FUN_0820efc4
	movs r0, #0
_0820FA70:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0820FA78: .4byte 0x00000366
_0820FA7C: .4byte 0x00000367
