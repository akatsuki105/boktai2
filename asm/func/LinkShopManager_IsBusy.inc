	push {lr}
	ldr r0, _081E2398 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E23A2
	movs r1, #3
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E239C
	movs r0, #1
	b _081E239E
	.align 2, 0
_081E2398: .4byte 0x03002C6C
_081E239C:
	movs r0, #0
_081E239E:
	cmp r0, #0
	bne _081E23A6
_081E23A2:
	movs r0, #0
	b _081E23A8
_081E23A6:
	movs r0, #1
_081E23A8:
	pop {r1}
	bx r1
