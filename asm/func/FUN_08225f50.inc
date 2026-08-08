	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r5, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08225F7C
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08225F78 @ =0x00000F14
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #1
	b _08225F7E
	.align 2, 0
_08225F78: .4byte 0x00000F14
_08225F7C:
	movs r0, #0
_08225F7E:
	cmp r0, #0
	beq _08226022
	bl FUN_080a6edc
	ldr r1, _08226028 @ =0x00000DF4
	adds r0, r5, r1
	bl FUN_080136b4
	ldr r0, _0822602C @ =0x00000D9C
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08226030 @ =0x00000F16
	adds r4, r5, r1
	ldrb r0, [r4]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r2, _08226034 @ =0x00000F18
	adds r3, r5, r2
	strh r0, [r3]
	movs r2, #1
	ldrb r1, [r4]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	ldrh r1, [r4]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	cmp r0, #3
	bne _08225FEE
	ldrb r1, [r4]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _08225FEE
	ldr r1, _08226038 @ =0x00000DEC
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _0822603C @ =0x00000F42
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08226040 @ =0x00000DF2
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
_08225FEE:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r5, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r7, #4
	ldr r4, _08226044 @ =FUN_08224dd0
	movs r6, #1
	adds r2, r5, #0
	adds r2, #0xc4
	movs r3, #0xf
_08226008:
	ldrb r1, [r2, #5]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0822601A
	str r4, [r2]
	adds r0, r6, #0
	orrs r0, r1
	strb r0, [r2, #5]
_0822601A:
	adds r2, #0xd8
	subs r3, #1
	cmp r3, #0
	bge _08226008
_08226022:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08226028: .4byte 0x00000DF4
_0822602C: .4byte 0x00000D9C
_08226030: .4byte 0x00000F16
_08226034: .4byte 0x00000F18
_08226038: .4byte 0x00000DEC
_0822603C: .4byte 0x00000F42
_08226040: .4byte 0x00000DF2
_08226044: .4byte FUN_08224dd0
