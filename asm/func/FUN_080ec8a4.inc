	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x18
	bl FUN_08230f94
	adds r5, r0, #0
	ldr r4, [r4, #0x18]
	b _080EC8F2
_080EC8B8:
	ldr r2, [r4, #4]
	ldrh r0, [r2]
	cmp r0, #2
	beq _080EC8DA
	cmp r0, #2
	bgt _080EC8CA
	cmp r0, #1
	beq _080EC8D0
	b _080EC8EE
_080EC8CA:
	cmp r0, #3
	beq _080EC8E4
	b _080EC8EE
_080EC8D0:
	ldrb r0, [r2, #2]
	adds r1, r2, #4
	bl FUN_080ec758
	b _080EC8EE
_080EC8DA:
	ldrb r0, [r2, #2]
	adds r1, r2, #4
	bl FUN_080ec79c
	b _080EC8EE
_080EC8E4:
	ldrb r0, [r2, #2]
	adds r1, r2, #6
	ldrh r2, [r2, #4]
	bl FUN_080ec848
_080EC8EE:
	adds r4, #8
	adds r0, r5, #0
_080EC8F2:
	subs r5, #1
	cmp r0, #0
	bgt _080EC8B8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
