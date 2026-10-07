	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080865c0
	adds r2, r0, #0
	cmp r2, #0
	beq _081D8D86
	movs r0, #0x1c
	ldrsh r1, [r4, r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D3E
	rsbs r1, r1, #0
_081D8D3E:
	adds r0, r4, #0
	adds r0, #0x60
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _081D8D86
	movs r0, #0x20
	ldrsh r1, [r4, r0]
	movs r3, #4
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D5A
	rsbs r1, r1, #0
_081D8D5A:
	adds r0, r4, #0
	adds r0, #0x64
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _081D8D86
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _081D8D76
	rsbs r1, r1, #0
_081D8D76:
	adds r0, r4, #0
	adds r0, #0x62
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _081D8D86
	movs r0, #1
	b _081D8D88
_081D8D86:
	movs r0, #0
_081D8D88:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
