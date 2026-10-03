	push {lr}
	adds r2, r0, #0
	ldr r0, _0809B394 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0809B3A8
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0809B3A8
	ldr r1, [r0, #0x1c]
	cmp r1, #1
	bne _0809B3A8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0809B3A8
	ldr r1, _0809B398 @ =0x000009FE
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0809B3A8
	ldr r2, _0809B39C @ =0x00000201
	ldr r0, _0809B3A0 @ =0x030047A4
	ldr r1, _0809B3A4 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _0809B3A8
	movs r0, #1
	b _0809B3AA
	.align 2, 0
_0809B394: .4byte 0x030044E0
_0809B398: .4byte 0x000009FE
_0809B39C: .4byte 0x00000201
_0809B3A0: .4byte 0x030047A4
_0809B3A4: .4byte 0x030047A0
_0809B3A8:
	movs r0, #0
_0809B3AA:
	pop {r1}
	bx r1
	.align 2, 0
