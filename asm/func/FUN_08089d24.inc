	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x5c
	ldrh r0, [r1]
	subs r0, #0x46
	movs r3, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _08089D46
	strh r3, [r1]
	movs r0, #2
	subs r1, #0xe
	strh r0, [r1]
	str r3, [r2, #0x64]
	b _08089D4C
_08089D46:
	ldr r0, [r2, #0x64]
	adds r0, #1
	str r0, [r2, #0x64]
_08089D4C:
	pop {r0}
	bx r0
