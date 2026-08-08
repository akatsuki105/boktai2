	push {lr}
	adds r1, r0, #0
	ldr r2, _080726CC @ =0x000004AA
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080726D0
	adds r0, r1, #0
	bl FUN_08072650
	b _080726DA
	.align 2, 0
_080726CC: .4byte 0x000004AA
_080726D0:
	cmp r0, #2
	bne _080726DA
	adds r0, r1, #0
	bl FUN_0807268c
_080726DA:
	pop {r0}
	bx r0
	.align 2, 0
