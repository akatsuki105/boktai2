	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r0, _0817ECC8 @ =0x0000089E
	adds r2, r3, r0
	ldrb r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq _0817ECCC
	subs r0, #1
	strb r0, [r2]
	b _0817ECD4
	.align 2, 0
_0817ECC8: .4byte 0x0000089E
_0817ECCC:
	strb r1, [r2]
	ldr r2, _0817ECD8 @ =0x0000089D
	adds r0, r3, r2
	strb r1, [r0]
_0817ECD4:
	pop {r0}
	bx r0
	.align 2, 0
_0817ECD8: .4byte 0x0000089D
