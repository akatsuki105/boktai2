	push {lr}
	ldr r0, _082416AC @ =PTR_03001708
	ldr r1, [r0]
	cmp r1, #0
	beq _082416B4
	ldr r0, _082416B0 @ =0x0300486C
	ldrh r0, [r0]
	cmp r0, #0
	bne _082416B4
	ldrb r0, [r1, #0x19]
	cmp r0, #2
	bne _082416B4
	movs r0, #1
	b _082416B6
	.align 2, 0
_082416AC: .4byte PTR_03001708
_082416B0: .4byte 0x0300486C
_082416B4:
	movs r0, #0
_082416B6:
	pop {r1}
	bx r1
	.align 2, 0
