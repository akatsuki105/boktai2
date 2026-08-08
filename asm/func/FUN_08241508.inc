	push {r4, r5, lr}
	ldr r5, _08241540 @ =0x00001804
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _08241538
	adds r0, r4, #0
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_08241424
	cmp r0, #0
	blt _08241538
	bl FUN_08231ca8
	adds r0, r4, #0
	bl FUN_082414a0
	cmp r0, #0
	bge _08241544
_08241538:
	movs r0, #1
	rsbs r0, r0, #0
	b _0824154A
	.align 2, 0
_08241540: .4byte 0x00001804
_08241544:
	adds r0, r4, #0
	bl Free
_0824154A:
	pop {r4, r5}
	pop {r1}
	bx r1
