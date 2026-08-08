	push {r4, lr}
	ldr r0, _080E0244 @ =0x0300017C
	ldr r0, [r0]
	cmp r0, #0
	beq _080E023C
	movs r4, #3
	movs r2, #0xf5
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #0xda
	lsls r3, r3, #1
	movs r2, #7
_080E022C:
	ldrb r0, [r1]
	cmp r0, #1
	bne _080E0234
	strb r4, [r1]
_080E0234:
	adds r1, r1, r3
	subs r2, #1
	cmp r2, #0
	bge _080E022C
_080E023C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E0244: .4byte 0x0300017C
