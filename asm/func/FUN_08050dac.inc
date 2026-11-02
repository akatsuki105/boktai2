	push {r4, lr}
	bl FUN_0804f820
	adds r4, r0, #0
	cmp r4, #0
	beq _08050DE0
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	beq _08050DE0
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08050DE0
	adds r4, #0x3c
	ldrb r1, [r4, #6]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r4, #6]
	ldr r0, _08050DDC @ =0x0000010B
	bl PlaySound_082406e0
	ldrb r0, [r4, #6]
	b _08050DE2
	.align 2, 0
_08050DDC: .4byte 0x0000010B
_08050DE0:
	movs r0, #0
_08050DE2:
	pop {r4}
	pop {r1}
	bx r1
