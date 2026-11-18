	push {lr}
	movs r2, #5
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0
	ldr r3, _081F6494 @ =0xFFFFFEDC
_081F6482:
	strb r1, [r0]
	adds r1, #8
	adds r0, r0, r3
	subs r2, #1
	cmp r2, #0
	bgt _081F6482
	pop {r0}
	bx r0
	.align 2, 0
_081F6494: .4byte 0xFFFFFEDC
