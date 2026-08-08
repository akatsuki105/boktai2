	push {lr}
	adds r2, r0, #0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #1
	bls _08066D40
	cmp r0, #5
	bne _08066D5E
_08066D40:
	cmp r1, #0
	beq _08066D70
	cmp r1, #3
	beq _08066D70
	cmp r1, #6
	beq _08066D70
	cmp r1, #4
	bne _08066D74
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08066D70
	b _08066D74
_08066D5E:
	cmp r0, #4
	bne _08066D68
	cmp r1, #0
	beq _08066D70
	b _08066D74
_08066D68:
	cmp r1, #0
	beq _08066D70
	cmp r1, #4
	bne _08066D74
_08066D70:
	movs r0, #1
	b _08066D76
_08066D74:
	movs r0, #0
_08066D76:
	pop {r1}
	bx r1
	.align 2, 0
