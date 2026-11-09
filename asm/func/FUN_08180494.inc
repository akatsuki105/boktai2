	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	ldr r0, _081804B0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081804B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081804B6
	.align 2, 0
_081804B0: .4byte 0x0000046D
_081804B4:
	movs r0, #0
_081804B6:
	cmp r0, #0
	beq _081804C2
	adds r0, r4, #0
	movs r1, #0x12
	bl Enemy_PlayAnim
_081804C2:
	ldrh r0, [r5, #0x14]
	cmp r0, #1
	bne _081804D4
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	bne _081804D4
	ldr r0, _081804EC @ =0x000003D3
	bl PlaySound_082406e0
_081804D4:
	ldr r1, _081804F0 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081804E6
	ldr r0, _081804F4 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081804E6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081804EC: .4byte 0x000003D3
_081804F0: .4byte 0x0000046E
_081804F4: .4byte 0x0000046B
