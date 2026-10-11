	push {lr}
	ldr r0, _081E23F4 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	bne _081E23F8
	movs r0, #1
	rsbs r0, r0, #0
	b _081E2412
	.align 2, 0
_081E23F4: .4byte 0x03002C6C
_081E23F8:
	movs r1, #0x20
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2406
	movs r0, #1
	b _081E2408
_081E2406:
	movs r0, #0
_081E2408:
	cmp r0, #0
	bne _081E2410
	movs r0, #0
	b _081E2412
_081E2410:
	movs r0, #1
_081E2412:
	pop {r1}
	bx r1
	.align 2, 0
