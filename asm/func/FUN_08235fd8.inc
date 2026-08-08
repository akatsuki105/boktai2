	push {lr}
	adds r2, r0, #0
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08235FEA
	movs r0, #0
	b _08235FF2
_08235FEA:
	ldr r0, _08235FF8 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
_08235FF2:
	pop {r1}
	bx r1
	.align 2, 0
_08235FF8: .4byte 0x0000FFFD
