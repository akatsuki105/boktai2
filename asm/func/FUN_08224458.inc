	push {r4, r5, lr}
	ldr r0, _082244D8 @ =0x03000248
	ldr r4, [r0]
	cmp r4, #0
	bne _08224470
	ldr r0, _082244DC @ =0x0000BB34
	movs r1, #0
	bl Entity8AAB_Create
	adds r4, r0, #0
	cmp r4, #0
	beq _082244D2
_08224470:
	ldr r0, _082244E0 @ =0x00000F16
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _082244E4 @ =0x00000F18
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
	movs r1, #0xb0
	orrs r0, r1
	strh r0, [r5]
	ldrh r0, [r3]
	cmp r0, #3
	bne _082244C4
	ldrb r1, [r5]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _082244C4
	ldr r2, _082244E8 @ =0x00000DEC
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r2, _082244EC @ =0x00000F42
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _082244F0 @ =0x00000DF2
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_082244C4:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r4, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_082244D2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_082244D8: .4byte 0x03000248
_082244DC: .4byte 0x0000BB34
_082244E0: .4byte 0x00000F16
_082244E4: .4byte 0x00000F18
_082244E8: .4byte 0x00000DEC
_082244EC: .4byte 0x00000F42
_082244F0: .4byte 0x00000DF2
