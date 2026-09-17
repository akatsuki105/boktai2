	push {lr}
	ldr r1, _0823D304 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldr r1, _0823D308 @ =0x00000948
	adds r2, r0, r1
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _0823D30C @ =0x0000270E
	cmp r1, r0
	bgt _0823D2FE
	adds r0, r3, #1
	strh r0, [r2]
_0823D2FE:
	pop {r0}
	bx r0
	.align 2, 0
_0823D304: .4byte 0x030046A0
_0823D308: .4byte 0x00000948
_0823D30C: .4byte 0x0000270E
