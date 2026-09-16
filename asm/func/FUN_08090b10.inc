	push {lr}
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08090B2A
	movs r0, #0
	b _08090B34
_08090B2A:
	cmp r0, #5
	beq _08090B32
	movs r0, #1
	b _08090B34
_08090B32:
	movs r0, #2
_08090B34:
	pop {r1}
	bx r1
