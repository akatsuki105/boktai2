	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08132E08 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08132E0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08132E0E
	.align 2, 0
_08132E08: .4byte 0x0000046D
_08132E0C:
	movs r0, #0
_08132E0E:
	cmp r0, #0
	beq _08132E2A
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
_08132E2A:
	cmp r5, #0x28
	bne _08132E3C
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08132E3C:
	ldr r1, _08132E58 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08132E52
	cmp r5, #0x78
	ble _08132E52
	ldr r0, _08132E5C @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08132E52:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08132E58: .4byte 0x0000046E
_08132E5C: .4byte 0x0000046B
