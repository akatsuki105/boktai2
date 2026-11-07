	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0814E214 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814E218
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814E21A
	.align 2, 0
_0814E214: .4byte 0x0000046D
_0814E218:
	movs r0, #0
_0814E21A:
	cmp r0, #0
	beq _0814E226
	adds r0, r4, #0
	movs r1, #0xe
	bl Enemy_PlayAnim
_0814E226:
	ldr r1, _0814E240 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814E238
	ldr r0, _0814E244 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0814E238:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0814E240: .4byte 0x0000046E
_0814E244: .4byte 0x0000046B
