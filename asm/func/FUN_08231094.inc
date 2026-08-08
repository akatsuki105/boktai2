	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
_0823109A:
	cmp r2, r3
	bge _082310B4
	adds r0, r2, r3
	asrs r1, r0, #1
	lsls r0, r1, #3
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, r5
	bhs _082310B0
	adds r2, r1, #1
	b _0823109A
_082310B0:
	adds r3, r1, #0
	b _0823109A
_082310B4:
	lsls r0, r2, #3
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, r5
	beq _082310C2
	movs r0, #0
	b _082310C4
_082310C2:
	ldr r0, [r1, #4]
_082310C4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
