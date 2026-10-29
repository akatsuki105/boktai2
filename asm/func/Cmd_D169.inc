	push {r4, r5, lr}
	ldr r0, _08224D0C @ =0x03000248
	ldr r4, [r0]
	cmp r4, #0
	bne _08224CA4
	ldr r0, _08224D10 @ =0x0000BB34
	movs r1, #0
	bl Entity8AAB_Create
	adds r4, r0, #0
	cmp r4, #0
	beq _08224D06
_08224CA4:
	ldr r0, _08224D14 @ =0x00000F16
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08224D18 @ =0x00000F18
	adds r3, r4, r1
	strh r0, [r3]
	movs r2, #2
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
	movs r1, #0xf0
	orrs r0, r1
	strh r0, [r5]
	ldrh r0, [r3]
	cmp r0, #3
	bne _08224CF8
	ldrb r1, [r5]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _08224CF8
	ldr r2, _08224D1C @ =0x00000DEC
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r2, _08224D20 @ =0x00000F42
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08224D24 @ =0x00000DF2
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_08224CF8:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r4, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08224D06:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08224D0C: .4byte 0x03000248
_08224D10: .4byte 0x0000BB34
_08224D14: .4byte 0x00000F16
_08224D18: .4byte 0x00000F18
_08224D1C: .4byte 0x00000DEC
_08224D20: .4byte 0x00000F42
_08224D24: .4byte 0x00000DF2
