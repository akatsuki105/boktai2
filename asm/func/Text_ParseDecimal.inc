	push {r4, lr}
	movs r4, #0
	movs r3, #1
	cmp r4, r1
	bge _08048C50
	subs r0, #1
	adds r2, r1, r0
_08048C3A:
	ldrb r0, [r2]
	subs r0, #0x30
	muls r0, r3, r0
	adds r4, r4, r0
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r3, r0, #1
	subs r2, #1
	subs r1, #1
	cmp r1, #0
	bne _08048C3A
_08048C50:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
