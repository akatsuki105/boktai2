	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _081D8D14 @ =0x03002BE0
	ldr r3, [r0]
	cmp r3, #0
	beq _081D8D18
	movs r0, #0x1c
	ldrsh r1, [r2, r0]
	movs r4, #0x2c
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8CCC
	rsbs r1, r1, #0
_081D8CCC:
	adds r0, r2, #0
	adds r0, #0x60
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081D8D18
	movs r0, #0x20
	ldrsh r1, [r2, r0]
	movs r4, #0x30
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8CE8
	rsbs r1, r1, #0
_081D8CE8:
	adds r0, r2, #0
	adds r0, #0x64
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081D8D18
	movs r0, #0x1e
	ldrsh r1, [r2, r0]
	movs r4, #0x2e
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D04
	rsbs r1, r1, #0
_081D8D04:
	adds r0, r2, #0
	adds r0, #0x62
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _081D8D18
	movs r0, #1
	b _081D8D1A
	.align 2, 0
_081D8D14: .4byte 0x03002BE0
_081D8D18:
	movs r0, #0
_081D8D1A:
	pop {r4}
	pop {r1}
	bx r1
