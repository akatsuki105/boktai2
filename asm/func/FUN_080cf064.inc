	push {r4, lr}
	adds r3, r0, #0
	movs r0, #0xa3
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r3, #0x18]
	lsls r0, r0, #3
	ldr r1, _080CF0A8 @ =0x030044E0
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r0, [r0]
	ldrh r1, [r0, #0x14]
	ldr r2, _080CF0AC @ =0x00000456
	adds r0, r3, r2
	strb r1, [r0]
	ldr r0, _080CF0B0 @ =0x0000FFFF
	adds r4, r0, #0
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r2, r3, r1
	movs r1, #9
_080CF094:
	ldrh r0, [r2]
	orrs r0, r4
	strh r0, [r2]
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge _080CF094
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF0A8: .4byte 0x030044E0
_080CF0AC: .4byte 0x00000456
_080CF0B0: .4byte 0x0000FFFF
