	push {lr}
	adds r3, r0, #0
	movs r1, #0xbb
	lsls r1, r1, #4
	adds r0, r3, r1
	ldrh r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _081E4A8C
	movs r2, #0x1b
	cmp r0, #0x11
	bls _081E4A8C
	movs r2, #0x12
	cmp r0, #0x19
	bls _081E4A8C
	movs r2, #0xa
	cmp r0, #0x21
	bls _081E4A8C
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _081E4A8C
	movs r2, #0x12
_081E4A8C:
	movs r0, #0xbb
	lsls r0, r0, #4
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081E4AA4
	movs r0, #0
	strh r0, [r1]
_081E4AA4:
	ldr r1, _081E4AB4 @ =0x00000B48
	adds r0, r3, r1
	strh r2, [r0]
	adds r1, #0x40
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_081E4AB4: .4byte 0x00000B48
