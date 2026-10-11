	push {lr}
	ldr r0, _081E2470 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E247A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2474
	movs r0, #1
	b _081E2476
	.align 2, 0
_081E2470: .4byte 0x03002C6C
_081E2474:
	movs r0, #0
_081E2476:
	cmp r0, #0
	bne _081E247E
_081E247A:
	movs r0, #0
	b _081E2480
_081E247E:
	movs r0, #1
_081E2480:
	pop {r1}
	bx r1
