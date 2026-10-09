	push {lr}
	ldr r0, _080A0828 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _080A0816
	movs r1, #1
_080A0816:
	cmp r1, #0
	bne _080A0830
	ldr r0, _080A082C @ =0x03002C3C
	ldr r0, [r0]
	cmp r0, #0
	beq _080A0830
	ldrb r0, [r0, #0x1f]
	b _080A0832
	.align 2, 0
_080A0828: .4byte 0x03002B80
_080A082C: .4byte 0x03002C3C
_080A0830:
	movs r0, #0
_080A0832:
	pop {r1}
	bx r1
	.align 2, 0
