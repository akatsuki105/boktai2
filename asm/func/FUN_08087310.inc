	push {r4, lr}
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r4, #0
	movs r3, #2
	strh r3, [r1]
	adds r2, #2
	adds r1, r0, r2
	strh r4, [r1]
	ldr r1, _080873A4 @ =0x000003DA
	adds r2, r0, r1
	movs r1, #0x40
	strh r1, [r2]
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #3
	strh r1, [r2]
	ldr r1, _080873A8 @ =0x000003DE
	adds r2, r0, r1
	movs r1, #6
	strh r1, [r2]
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r1, r0, r2
	strh r3, [r1]
	adds r2, #2
	adds r1, r0, r2
	strh r3, [r1]
	movs r3, #0xf9
	lsls r3, r3, #2
	adds r2, r0, r3
	movs r1, #0x3c
	strh r1, [r2]
	ldr r1, _080873AC @ =0x000003E6
	adds r2, r0, r1
	movs r1, #8
	strh r1, [r2]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r1, r0, r2
	strh r4, [r1]
	adds r3, #6
	adds r1, r0, r3
	movs r2, #0xff
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r4, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r4, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r4, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _080873B0 @ =0x000003FA
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080873A4: .4byte 0x000003DA
_080873A8: .4byte 0x000003DE
_080873AC: .4byte 0x000003E6
_080873B0: .4byte 0x000003FA
