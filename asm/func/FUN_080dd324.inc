	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	cmp r1, #0
	beq _080DD35C
	ldr r3, _080DD358 @ =0x0000012F
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080DD35C
	movs r3, #0x99
	lsls r3, r3, #1
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _080DD35C
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080DD35C
	movs r0, #1
	b _080DD35E
	.align 2, 0
_080DD358: .4byte 0x0000012F
_080DD35C:
	movs r0, #0
_080DD35E:
	pop {r1}
	bx r1
	.align 2, 0
