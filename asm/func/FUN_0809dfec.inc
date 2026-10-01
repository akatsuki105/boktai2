	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809E004 @ =0x03000140
	ldr r1, [r0]
	cmp r1, #0
	beq _0809E02C
	adds r3, r1, #0
	adds r3, #0x26
	ldrb r0, [r3]
	cmp r0, #0
	bne _0809E00C
	b _0809E02C
	.align 2, 0
_0809E004: .4byte 0x03000140
_0809E008:
	movs r0, #1
	b _0809E02E
_0809E00C:
	movs r2, #0
	ldrb r0, [r3]
	cmp r2, r0
	bge _0809E02C
	adds r3, r0, #0
	adds r1, #0xc6
_0809E018:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809E024
	ldrh r0, [r1, #4]
	cmp r0, r4
	beq _0809E008
_0809E024:
	adds r1, #0xa8
	adds r2, #1
	cmp r2, r3
	blt _0809E018
_0809E02C:
	movs r0, #0
_0809E02E:
	pop {r4}
	pop {r1}
	bx r1
