	push {lr}
	ldr r0, _0804E44C @ =0x03002B58
	ldr r0, [r0]
	cmp r0, #0
	beq _0804E450
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r0, r1
	b _0804E452
	.align 2, 0
_0804E44C: .4byte 0x03002B58
_0804E450:
	movs r0, #0
_0804E452:
	pop {r1}
	bx r1
	.align 2, 0
