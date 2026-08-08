	push {lr}
	bl fetch_082316e4
	cmp r0, #0
	beq _080EDDDA
	bl FUN_080edda0
	cmp r0, #0
	bne _080EDDDE
_080EDDDA:
	movs r0, #0
	b _080EDDF2
_080EDDDE:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #1
	cmp r0, #0
	bgt _080EDDF0
	movs r1, #0
_080EDDF0:
	adds r0, r1, #0
_080EDDF2:
	pop {r1}
	bx r1
	.align 2, 0
