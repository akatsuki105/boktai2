	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0817136C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08171370
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08171372
	.align 2, 0
_0817136C: .4byte 0x0000046D
_08171370:
	movs r0, #0
_08171372:
	cmp r0, #0
	beq _0817138E
	adds r0, r4, #0
	movs r1, #7
	bl Enemy_PlayAnim
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_0817138E:
	cmp r5, #0x28
	bne _081713A0
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081713A0:
	ldr r1, _081713BC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081713B6
	cmp r5, #0x78
	ble _081713B6
	ldr r0, _081713C0 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081713B6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081713BC: .4byte 0x0000046E
_081713C0: .4byte 0x0000046B
