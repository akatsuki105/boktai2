	push {r4, lr}
	adds r3, r0, #0
	movs r4, #0x40
	adds r0, #0x38
	movs r2, #0x80
	movs r1, #3
_081E00FC:
	strh r2, [r0]
	strh r4, [r0, #2]
	adds r0, #0x60
	subs r2, #8
	subs r1, #1
	cmp r1, #0
	bge _081E00FC
	movs r4, #0x78
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0x80
	movs r1, #3
_081E0116:
	strh r2, [r0]
	strh r4, [r0, #2]
	adds r0, #0x60
	subs r2, #8
	subs r1, #1
	cmp r1, #0
	bge _081E0116
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
