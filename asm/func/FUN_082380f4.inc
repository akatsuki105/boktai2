	push {lr}
	ldr r0, _08238104 @ =0x030046BC
	ldrh r1, [r0]
	ldr r0, _08238108 @ =0x0000FFFF
	cmp r1, r0
	bne _0823810C
	movs r0, #0
	b _0823810E
	.align 2, 0
_08238104: .4byte 0x030046BC
_08238108: .4byte 0x0000FFFF
_0823810C:
	movs r0, #1
_0823810E:
	pop {r1}
	bx r1
	.align 2, 0
