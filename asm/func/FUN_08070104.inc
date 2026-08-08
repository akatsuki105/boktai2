	push {lr}
	adds r3, r1, #0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	lsrs r1, r1, #4
	cmp r1, #1
	beq _0807011C
	cmp r1, #2
	beq _08070120
	b _08070124
_0807011C:
	ldrb r0, [r3, #4]
	b _08070122
_08070120:
	ldrb r0, [r3]
_08070122:
	subs r2, r2, r0
_08070124:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
