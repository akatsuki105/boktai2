	push {r4, lr}
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #0
	movs r2, #0
	strh r2, [r1]
	ldr r4, _080E49BC @ =0x0000048A
	adds r1, r0, r4
	strh r2, [r1]
	ldr r1, _080E49C0 @ =0x0000048C
	adds r0, r0, r1
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080E49BC: .4byte 0x0000048A
_080E49C0: .4byte 0x0000048C
