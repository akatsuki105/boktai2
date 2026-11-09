	push {r4, r5, lr}
	adds r4, r2, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r3, _0818F95C @ =0x00000F34
	adds r0, r2, r3
	movs r5, #0
	ldrsh r3, [r0, r5]
	cmp r3, r1
	blt _0818F960
	strh r1, [r0]
	movs r0, #0xf3
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r0, #0xff
	b _0818F970
	.align 2, 0
_0818F95C: .4byte 0x00000F34
_0818F960:
	rsbs r1, r1, #0
	cmp r3, r1
	bgt _0818F972
	strh r1, [r0]
	movs r3, #0xf3
	lsls r3, r3, #4
	adds r1, r2, r3
	movs r0, #1
_0818F970:
	strb r0, [r1]
_0818F972:
	ldr r5, _0818F990 @ =0x00000F34
	adds r1, r2, r5
	movs r3, #0xf3
	lsls r3, r3, #4
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r4, r0
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0818F990: .4byte 0x00000F34
