	push {r4, r5, lr}
	ldr r0, _08224190 @ =0x03000248
	ldr r4, [r0]
	cmp r4, #0
	bne _08224128
	ldr r0, _08224194 @ =0x0000BB34
	movs r1, #0
	bl Entity8AAB_Create
	adds r4, r0, #0
	cmp r4, #0
	beq _0822418A
_08224128:
	ldr r0, _08224198 @ =0x00000F16
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _0822419C @ =0x00000F18
	adds r3, r4, r1
	strh r0, [r3]
	movs r2, #3
	ldrb r1, [r5]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	ldrh r1, [r5]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x70
	orrs r0, r1
	strh r0, [r5]
	ldrh r0, [r3]
	cmp r0, #3
	bne _0822417C
	ldrb r1, [r5]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _0822417C
	ldr r2, _082241A0 @ =0x00000DEC
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r2, _082241A4 @ =0x00000F42
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _082241A8 @ =0x00000DF2
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_0822417C:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r4, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_0822418A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08224190: .4byte 0x03000248
_08224194: .4byte 0x0000BB34
_08224198: .4byte 0x00000F16
_0822419C: .4byte 0x00000F18
_082241A0: .4byte 0x00000DEC
_082241A4: .4byte 0x00000F42
_082241A8: .4byte 0x00000DF2
