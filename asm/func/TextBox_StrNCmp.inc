	push {r4, r5, lr}
	adds r4, r0, #0
	movs r3, #0
	cmp r3, r2
	bge _08048C24
_08048BFE:
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08048C12
	ldrb r0, [r1]
	cmp r0, #0
	beq _08048C24
	movs r0, #1
	rsbs r0, r0, #0
	b _08048C26
_08048C12:
	ldrb r5, [r1]
	cmp r0, r5
	beq _08048C1C
	movs r0, #1
	b _08048C26
_08048C1C:
	adds r1, #1
	adds r3, #1
	cmp r3, r2
	blt _08048BFE
_08048C24:
	movs r0, #0
_08048C26:
	pop {r4, r5}
	pop {r1}
	bx r1
