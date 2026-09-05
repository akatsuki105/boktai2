	push {lr}
	ldr r2, [r0, #0x2c]
	movs r3, #0xcf
_08001A1E:
	strh r1, [r2]
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _08001A1E
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
