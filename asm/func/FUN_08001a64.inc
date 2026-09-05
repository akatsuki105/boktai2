	push {lr}
	ldr r0, _08001A78 @ =gClock
	ldrb r0, [r0, #0xe]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08001A7C
	movs r0, #0x40
	b _08001A7E
	.align 2, 0
_08001A78: .4byte gClock
_08001A7C:
	movs r0, #0x20
_08001A7E:
	pop {r1}
	bx r1
	.align 2, 0
