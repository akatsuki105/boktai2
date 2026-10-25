	push {lr}
	adds r2, r0, #0
	cmp r1, #0x5f
	ble _08029A60
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029A3C
	ldr r1, _08029A38 @ =0x00000824
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #2
	bne _08029AAE
	b _08029A52
	.align 2, 0
_08029A38: .4byte 0x00000824
_08029A3C:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08029AAE
	ldr r1, _08029A5C @ =0x00000FD4
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029AAE
_08029A52:
	movs r0, #0xd2
	lsls r0, r0, #2
	bl PlaySound_0824078c
	b _08029AAE
	.align 2, 0
_08029A5C: .4byte 0x00000FD4
_08029A60:
	cmp r1, #0x3f
	ble _08029AA8
	adds r0, r2, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029A80
	ldr r1, _08029A7C @ =0x00000824
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #2
	bne _08029AAE
	b _08029A96
	.align 2, 0
_08029A7C: .4byte 0x00000824
_08029A80:
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08029AAE
	ldr r1, _08029AA0 @ =0x00000FD4
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029AAE
_08029A96:
	ldr r0, _08029AA4 @ =0x00000349
	bl PlaySound_0824078c
	b _08029AAE
	.align 2, 0
_08029AA0: .4byte 0x00000FD4
_08029AA4: .4byte 0x00000349
_08029AA8:
	ldr r0, _08029AB4 @ =0x0000034A
	bl PlaySound_0824078c
_08029AAE:
	pop {r0}
	bx r0
	.align 2, 0
_08029AB4: .4byte 0x0000034A
