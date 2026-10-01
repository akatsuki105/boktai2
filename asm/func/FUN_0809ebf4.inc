	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x18]
	ldr r0, _0809EC08 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EC0C
	movs r0, #0
	b _0809EC12
	.align 2, 0
_0809EC08: .4byte 0x03002C68
_0809EC0C:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_0809EC12:
	cmp r0, #0
	beq _0809EC4E
	movs r1, #2
	ldr r0, _0809EC2C @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _0809EC30 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809EC34
	movs r0, #1
	b _0809EC36
	.align 2, 0
_0809EC2C: .4byte 0x030046A0
_0809EC30: .4byte 0x00000934
_0809EC34:
	movs r0, #0
_0809EC36:
	cmp r0, #0
	bne _0809EC58
	ldr r0, _0809EC54 @ =0x03000140
	ldr r0, [r0]
	cmp r0, #0
	beq _0809EC4E
	adds r0, r2, #0
	adds r0, #0x2c
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809EC58
_0809EC4E:
	movs r0, #0
	b _0809EC5A
	.align 2, 0
_0809EC54: .4byte 0x03000140
_0809EC58:
	movs r0, #1
_0809EC5A:
	pop {r1}
	bx r1
	.align 2, 0
