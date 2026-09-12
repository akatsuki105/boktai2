	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x64]
	cmp r0, #0x59
	bls _08089F4E
	movs r1, #6
	adds r3, r2, #0
	adds r3, #0x4e
	movs r0, #0
	strh r1, [r3]
	b _08089F50
_08089F4E:
	adds r0, #1
_08089F50:
	str r0, [r2, #0x64]
	pop {r0}
	bx r0
	.align 2, 0
